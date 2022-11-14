# NavDemo

## Intro

NavDemo uses C++ to implement smiple graphic demonstration of robot path planning algorithms. Mobile robot path planning problem include **global path plan** for lager scale static map naviagtion; **local path plan** for small scale dynamic obstacle avoidance; **path optimizer** for smooth sharp turns in the path. 

A Chinese version of the introduction is [here](Docs/Intro/Intro.md)

## Getting Started

It is recommand to use this repo in Linux.

### Dependencies

- [OpenCV 4.x](https://opencv.org/releases/)
- [Eigen 3.x](https://eigen.tuxfamily.org/index.php?title=Main_Page)

If eigen is not found when compiling. Try to put Eigen to /usr/local with the following code:

```
sudo cp eigen3/Eigen/ /usr/include/ -r 
```

### Clone 

```
git clone https://github.com/Alexbeast-CN/NavDemo.git
cd NavDemo
```

## Licensing

This repository is subject to GNU General Public License version 3 or later due to its dependencies.