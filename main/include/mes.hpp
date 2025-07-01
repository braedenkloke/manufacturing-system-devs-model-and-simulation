#ifndef MES_HPP
#define MES_HPP

#include <iostream>
#include "cadmium/modeling/devs/atomic.hpp"
#include "constants.hpp"
#include "event.hpp"

using namespace cadmium;

struct MESState {
    double sigma;
    std::vector<int> ordersInProgress; // FIFO queue containing order IDs
    std::vector<int> completedOrders;
    bool cellIsIdle;

    explicit MESState(): sigma(infinity), cellIsIdle(true) {}
};

#ifndef NO_LOGGING
// Formats the state log.
std::ostream& operator<<(std::ostream &out, const MESState& state) {
    out << "State Log: "; 

    out << "ordersInProgress: ";
    out << "[ ";
    for (int i = 0; i < state.ordersInProgress.size(); i++) {
        out << state.ordersInProgress[i] << " ";
    }
    out << "] ";

    out << "completedOrders: "; 
    out << "[ ";
    for (int i = 0; i < state.completedOrders.size(); i++) {
        out << state.completedOrders[i] << " ";
    }
    out << "] ";

    out << "cellIsIdle: " << state.cellIsIdle;
    return out;
}
#endif

// Atomic DEVS model of a Manufacturing Execution System (MES).
class MES : public Atomic<MESState> {
public:
    Port<Event> placeOrder, enterCell, cellOperationEnd;

    MES(const std::string id) : Atomic<MESState>(id, MESState()) {
        // Input ports
        placeOrder = addInPort<Event>("placeOrder");
        cellOperationEnd = addInPort<Event>("cellOperationEnd");

        // Output ports
        enterCell = addOutPort<Event>("enterCell");
    }

    void internalTransition(MESState& state) const override {
        if (state.cellIsIdle && !state.ordersInProgress.empty()) {
            state.cellIsIdle = false;
        }

        state.sigma = infinity;
    }

    void externalTransition(MESState& state, double e) const override {
        // Handle new orders
        if (!placeOrder->empty()) {
            // Add order to end of queue
            int orderID = placeOrder->getBag().back().orderID;
            state.ordersInProgress.push_back(orderID);
        }
       
        // Handle completed orders
        if (!cellOperationEnd->empty()) {
            state.cellIsIdle = true;
            // Remove order from front of queue
            state.completedOrders.push_back(state.ordersInProgress.front());
            for (int i = 0; i < state.ordersInProgress.size() - 1; i++) {
                state.ordersInProgress[i] = state.ordersInProgress[i + 1];
            }
            state.ordersInProgress.pop_back();
        }
      
        // Allocate resources
        if (state.cellIsIdle && !state.ordersInProgress.empty()) {
            state.sigma = 0;
        }
    }
    
    void output(const MESState& state) const override {
        if (state.cellIsIdle && !state.ordersInProgress.empty()) {
            enterCell->addMessage(Event(state.ordersInProgress.front(), this->id, enterCellActivity));
        }
    }

    [[nodiscard]] double timeAdvance(const MESState& state) const override {     
        return state.sigma;
    }
};

#endif // MES_HPP
