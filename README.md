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
cat out/output.csv | grep orderID:1
```

You output will look like this
```
0,3,customer,placeOrder,orderID:1,eventID:1,resource:customer,activity:Place order,
0,2,mes,newOrder,orderID:1,eventID:2,resource:mes,activity:New order,
0,2,mes,enterCell,orderID:1,eventID:3,resource:mes,activity:Enter cell,
0,1,cell,cellOperationStart,orderID:1,eventID:4,resource:cell,activity:Cell operation start,
5,1,cell,cellOperationEnd,orderID:1,eventID:11,resource:cell,activity:Cell operation end,
5,2,mes,orderCompleted,orderID:1,eventID:12,resource:mes,activity:Order completed,
```

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
