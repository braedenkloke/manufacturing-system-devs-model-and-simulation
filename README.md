# Manufacturing System DEVS Model and Simulation
[DEVS](https://en.wikipedia.org/wiki/DEVS) model and [Cadmium](https://devssim.carleton.ca/) simulation 
of a manufacturing system.

# Background

## Smart Manufacturing System
The modeled system is based off the smart manufacturing system studied by [Friederich and Lazarova-Molnar (2024)](https://journals.sagepub.com/doi/full/10.1177/00375497241302866?casa_token=TZrSVjFZ1-YAAAAA%3AI2L_IkiDduYKh8NvE_x07_OGoQNQjjB3_x00TFNuzlrwdu8NNnzc1HG7uaIE3aYi7RN6gynVvqpXbQ).
It consists of a [manufacturing execution system (MES)](https://en.wikipedia.org/wiki/Manufacturing_execution_system)
which manages a production line and processes orders placed by a customer.
Both the MES and customer are considered as stateless.

The current version consists of one production line with an [assembly cell](https://en.wikipedia.org/wiki/Cellular_manufacturing).
Future versions will include multiple production lines and [autonomous ground vehicles (AGVs)](https://en.wikipedia.org/wiki/Unmanned_ground_vehicle) that transport raw material to the assembly cells.

# Usage
With [Cadmium](https://devssim.carleton.ca/) installed, run
```
source build_sim.sh
./bin/manufacturing_system | grep -v customer | grep -v mes,,
```

You output will look like this, 
```
INITIAL STATE
0,1,cell,,stateLog,idle
START SIMULATION
0,1,cell,,stateLog,busy
0,2,mes,enterCell,eventLog,1,2,mes,enter,
5,1,cell,cellOperationEnd,eventLog,1,6,cell,end,
5,1,cell,,stateLog,idle
5,1,cell,,stateLog,busy
5,2,mes,enterCell,eventLog,2,7,mes,enter,
10,1,cell,cellOperationEnd,eventLog,2,8,cell,end,
10,1,cell,,stateLog,idle
10,1,cell,,stateLog,busy
10,2,mes,enterCell,eventLog,3,9,mes,enter,
15,1,cell,cellOperationEnd,eventLog,3,10,cell,end,
15,1,cell,,stateLog,idle
15,1,cell,,stateLog,busy
15,2,mes,enterCell,eventLog,4,11,mes,enter,
20,1,cell,cellOperationEnd,eventLog,4,12,cell,end,
20,1,cell,,stateLog,idle
END SIMULATION
FINAL STATE
20,1,cell,,stateLog,idle
```
The headers were added for readability and are not included in the actual output.
For logs written to standard out, 
state logs are displayed in yellow and event logs are displayed in green.

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
