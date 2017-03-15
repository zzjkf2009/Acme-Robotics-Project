# Acme-Robotics-Project
[![Build Status](https://travis-ci.org/zzjkf2009/Acme-Robotics-Project.svg?branch=master)](https://travis-ci.org/zzjkf2009/Acme-Robotics-Project)
[![Coverage Status](https://coveralls.io/repos/github/dpiet/cpp-boilerplate/badge.svg?branch=master)](https://coveralls.io/github/dpiet/cpp-boilerplate?branch=master)
---
## Overview
This is an exercise project to design a path planning components using high-quality software engineering practices. This project used WeightedA* graph search algorithm to find an optimal path from start node to goal node. Opencv library was used to draw the map and the path to provide a intuitive graph for user.

---
## Product backlog

### See at https://docs.google.com/a/terpmail.umd.edu/document/d/1LW1pP-xllGP9OCM-kl9K2X37rjcMR1een2A6PK8dGJ0/edit?usp=sharing (Only can be viewed by people from University of Maryland)
---
## LICENSE
### See at
https://github.com/zzjkf2009/Acme-Robotics-Project/blob/master/LICENSE
---
## Build
Run as fellow:
* mkdir build
* cd build
* cmake ..
* make
---
## Demo
After the build process, run the executable demo program below, the path from start to goal node should be given if there
is one.
run: ./build/app/shell-app

A demo map image is like:

![alt text](https://github.com/zzjkf2009/Acme-Robotics-Project/blob/master/Results/map.jpg "demo map")

---
## Test
After the build process, run the demo Test program
run: ./build/test/cpp-test
---
## Installation
- Checkout the repo (and submodules)
```
$ git clone --recursive https://github.com/zzjkf2009/Acme-Robotics-Project.git
