# PX4 Autopilot modified for fully actuated system

Modified version of the release version of the PX4-Autopilot firmware, using the existing control allocation matrix.

* Modify the controllers in the system to allow for flight with no tilt.
* Include the simulation documents for gazebo for the frames
* Tested in the pixhawk 6C

## Acknowledgment
The early version of this project started with inspiration from work published by the Airlab group and their implementation of a fully actuated multirotor shown [here](https://github.com/castacks/PX4-fully-actuated).
