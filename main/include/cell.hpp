#ifndef CELL_HPP
#define CELL_HPP

#include <iostream>
#include "cadmium/modeling/devs/atomic.hpp"
#include "constants.hpp"
#include "event.hpp"

using namespace cadmium;

// Prefixed with class name to avoid namespace collisions from models with similarly named phases.
enum CellPhase {
    // Sorted alphabetically.
    cellBusy,
    cellIdle
};

struct CellState {
    CellPhase phase;
    double sigma;
    int orderID;
    double assemblyTime;

    explicit CellState(): phase(cellIdle), sigma(infinity), orderID(-1) {}
};

#ifndef NO_LOGGING
// Formats the state log.
std::ostream& operator<<(std::ostream &out, const CellState& state) {
    out << "State Log: ";
    out << "phase: ";
    if (state.phase == cellIdle) {
        out << "Idle ";
    } else if (state.phase == cellBusy) {
        out << "Busy ";
    }
    return out;
}
#endif

// Atomic DEVS model of an assembly cell in a production line.
// The cell receives commands from the MES to begin operation.
class Cell : public Atomic<CellState> {
public:
    Port<Event> enterCell, cellOperationEnd;

    // ARGUMENTS
    // id - Model name.
    // assemblyTime - Time in seconds it takes for the cell to assemble a product.
    Cell(const std::string id, double assemblyTime) : Atomic<CellState>(id, CellState()) {
        enterCell = addInPort<Event>("enterCell");
        cellOperationEnd = addOutPort<Event>("cellOperationEnd");

        state.assemblyTime = assemblyTime;
    }

    void internalTransition(CellState& state) const override {
        if (state.phase == cellBusy) {
            state.phase = cellIdle;
            state.sigma = infinity;
            state.orderID = -1;
        }
    }

    void externalTransition(CellState& state, double e) const override {
        if (state.phase == cellIdle && !enterCell->empty()) {
            state.phase = cellBusy;
            state.sigma = state.assemblyTime; 
            state.orderID = enterCell->getBag().back().orderID;
        }
    }
    
    void output(const CellState& state) const override {
        if (state.phase == cellBusy) {
            cellOperationEnd->addMessage(Event(state.orderID, cellOperationEndActivity));
        }
    }

    [[nodiscard]] double timeAdvance(const CellState& state) const override {     
        return state.sigma;
    }
};

#endif // CELL_HPP
