# Smart Manufacturing System DEVS Model 
[DEVS](https://en.wikipedia.org/wiki/DEVS) model and [Cadmium](https://devssim.carleton.ca/) simulation 
of a [smart manufacturing](https://en.wikipedia.org/wiki/Smart_manufacturing) system.

# Background

## Smart Manufacturing System
The modeled system is based off the smart manufacturing system studied by [Friederich and Lazarova-Molnar (2024)](https://journals.sagepub.com/doi/full/10.1177/00375497241302866?casa_token=TZrSVjFZ1-YAAAAA%3AI2L_IkiDduYKh8NvE_x07_OGoQNQjjB3_x00TFNuzlrwdu8NNnzc1HG7uaIE3aYi7RN6gynVvqpXbQ).
It consists of a [manufacturing execution system (MES)](https://en.wikipedia.org/wiki/Manufacturing_execution_system)
which manages multiple production lines to complete orders placed by a customer.
Each production line has an [autonomous ground vehicle (AGV)](https://en.wikipedia.org/wiki/Unmanned_ground_vehicle) 
which transports raw materials to an [assembly cell](https://en.wikipedia.org/wiki/Cellular_manufacturing).

# Usage
With [Cadmium](https://devssim.carleton.ca/) installed, run
```
source build_sim.sh
./bin/smart_manufacturing_system
```
Your output will be placed in `out/output.csv`. 

With the default configuration, your output will look like this
```
INFO
sep=;
time;model_id;model_name;port_name;data
INITIAL STATES
0;1;cell;;State Log: phase: Idle 
0;2;mes;;State Log: ordersInProgress: [ ] completedOrders: [ ] cellIsIdle: 1
0;3;customer;;State Log: sigma: 0 orderPlacementTimes (in desc. order and relative to next order): [ 1 1 1 ]
START SIMULATION
0;2;mes;;State Log: ordersInProgress: [ 1 ] completedOrders: [ ] cellIsIdle: 1
0;3;customer;placeOrderEventPort;Event Log: orderID: 1
0;3;customer;;State Log: sigma: 1 orderPlacementTimes (in desc. order and relative to next order): [ 1 1 ]
0;1;cell;;State Log: phase: Busy 
0;2;mes;enterCell;Event Log: orderID: 1
0;2;mes;;State Log: ordersInProgress: [ 1 ] completedOrders: [ ] cellIsIdle: 0
1;2;mes;;State Log: ordersInProgress: [ 1 2 ] completedOrders: [ ] cellIsIdle: 0
...
15;1;cell;;State Log: phase: Busy 
15;2;mes;enterCell;Event Log: orderID: 4
15;2;mes;;State Log: ordersInProgress: [ 4 ] completedOrders: [ 1 2 3 ] cellIsIdle: 0
20;1;cell;cellOperationEnd;Event Log: orderID: 4
20;1;cell;;State Log: phase: Idle 
20;2;mes;;State Log: ordersInProgress: [ ] completedOrders: [ 1 2 3 4 ] cellIsIdle: 1
END SIMULATION
FINAL STATES
20;1;cell;;State Log: phase: Idle 
20;2;mes;;State Log: ordersInProgress: [ ] completedOrders: [ 1 2 3 4 ] cellIsIdle: 1
20;3;customer;;State Log: sigma: 2.14748e+09 orderPlacementTimes (in desc. order and relative to next order): [ ]
```
The output above has been modified slightly to improve readability.
The headers (i.e., INFO, INITIAL STATES, etc.) are not included in the Cadmium logs.

A complete sample of the logs above can also be found in [out/sample/output.csv](out/sample/output.csv).

For how to supply your own order inputs, 
refer to the README file in the [in/orders](in/orders) directory.

You can configure the simulation by modifying [main/main.cpp](main/main.cpp).

## Remote Simulation
Alternatively, you can run the simulation remotely on the [DEVSim servers](https://devssim.carleton.ca/). 

# Acknowledgements
- [Sanja Lazarova-Molnar](https://lazarova-molnar.net/) and the [SYDSEN Research Group](https://sydsen.aifb.kit.edu/) 
- [Gabriel Wainer](https://www.sce.carleton.ca/faculty/wainer/doku.php) and the [ARSLab](https://arslab.sce.carleton.ca/) 
- [Mitacs](https://www.mitacs.ca/our-programs/globalink-research-award/)

# See Also
- [Friederich, J. (2023). *Data-Driven Assessment of Reliability for Cyber-Physical Production Systems*.](https://portal.findresearcher.sdu.dk/en/publications/data-driven-assessment-of-reliability-for-cyber-physical-producti)
- [Cadmium Project Template](https://github.com/Sasisekhar/blank_project_rt)
- [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
- [hackergrrl/art-of-readme](https://github.com/hackergrrl/art-of-readme)

# License
[MIT](https://choosealicense.com/licenses/mit/)
