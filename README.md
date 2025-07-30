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
source run.sh
```

You output will be in `output_data/cleaned/'.

Your event log will look like this
```
TIMESTAMP,ORDER_ID,RESOURCE,ACTIVITY
0,1,mes,enter
5,1,cell,end
5,2,mes,enter
10,2,cell,end
10,3,mes,enter
15,3,cell,end
15,4,mes,enter
20,4,cell,end
```

Your state log will look like this
```
TIMESTAMP,RESOURCE,STATE
0,cell,idle
0,cell,busy
5,cell,idle
5,cell,busy
10,cell,idle
10,cell,busy
15,cell,idle
15,cell,busy
20,cell,idle
```

The headers were added for readability and are not included in the actual output.

For how to supply your own order inputs, 
refer to the README file in the [input_data/](input_data/) directory.

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
