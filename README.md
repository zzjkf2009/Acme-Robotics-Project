# Acme-Robotics-Project
[![Build Status](https://travis-ci.org/zzjkf2009/Acme-Robotics-Project.svg?branch=master)](https://travis-ci.org/zzjkf2009/Acme-Robotics-Project)

[![Coverage Status](https://coveralls.io/repos/github/zzjkf2009/Acme-Robotics-Project/badge.svg?branch=master)](https://coveralls.io/github/zzjkf2009/Acme-Robotics-Project?branch=master)
---
## Overview

This is an exercise project to design a path planning components using high-quality software engineering practices. This project used WeightedA* graph search algorithm to find an optimal path from start node to goal node. Opencv library was used to draw the map and the path to provide a intuitive graph for user.
---
## Product backlog

### See at

https://docs.google.com/a/terpmail.umd.edu/document/d/1LW1pP-xllGP9OCM-kl9K2X37rjcMR1een2A6PK8dGJ0/edit?usp=sharing (Only can be viewed by people from University of Maryland)
---
## LICENSE
### See at

https://github.com/zzjkf2009/Acme-Robotics-Project/blob/master/LICENSE
---
## Build

Run as fellow:
```
* mkdir build
* cd build
* cmake ..
* make
```
---
## Demo
After the build process, run the executable demo program below, the path from start to goal node should be given if there
is one.
run:
```
./build/app/shell-app
```
A demo map image is like:

![alt text](https://github.com/zzjkf2009/Acme-Robotics-Project/blob/master/Results/map.jpg "demo map")

Start node (5,4)
goal node (9,5)
Path Output: 
```
---->>>> (5,4) ---->>>> (6,3) ---->>>> (6,2) ---->>>> (7,1) ---->>>> (8,2) ---->>>> (8,3) ---->>>> (8,4) ---->>>> (9,5)
```
---
## Test
After the build process, run the demo Test program
run:
```
./build/test/cpp-test
```
---
## Installation
- Checkout the repo (and submodules)
```
$ git clone --recursive https://github.com/zzjkf2009/Acme-Robotics-Project.git
```
---
## Documentation
follow the instruction below to generate doxygen documentation
before donig it, make sure you install the doxygen by doing
```
$ sudo apt-get install doxygen
$ sudo apt-get install graphviz
```
First, generate a project-specific congfiuration doc
```
$ doxygen -g my_proj.conf 
```
Then modify the congfiuration doc in text editor and specify the root directory that contains the project's source files.
Last, run below to generate html and Latex format files
```
$ doxygen my_proj.conf 
```
