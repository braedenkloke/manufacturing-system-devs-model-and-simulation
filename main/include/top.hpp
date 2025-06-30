#ifndef TOP_HPP
#define TOP_HPP

#include "cadmium/modeling/devs/coupled.hpp"
#include "customer.hpp"
#include "mes.hpp"
#include "cell.hpp"

using namespace cadmium;

struct TopCoupled : public Coupled {

    TopCoupled(const std::string& id, std::vector<int> orders, double cellAssemblyTime) : Coupled(id) {
        auto customer = addComponent<Customer>("customer", orders);
        auto mes = addComponent<MES>("mes");
        auto cell = addComponent<Cell>("cell", cellAssemblyTime);

        // Couple output ports to input ports
        addCoupling(customer->placeOrderEventPort, mes->placeOrder);
        
        addCoupling(mes->enterCell, cell->enterCell);

        addCoupling(cell->cellOperationEnd, mes->cellOperationEnd);
    }
};

#endif // TOP_HPP
