bwi_lab
=======

Administration scripts and other programs for managing the systems and
networks for the
[Building-Wide Intelligence lab](http://www.cs.utexas.edu/~larg/bwi_web/)
of the University of Texas at Austin.

Build
=====

Login as ``bwilab``. Create a catkin workspace with just this
repository, and build it.

```
 $ mkdir -p ~/ws/src
 $ cd ~/ws/src
 $ wstool init
 $ wstool set bwi_local --git https://github.com/utexas-bwi/bwi_lab.git
 $ wstool up
 $ cd ..
 $ catkin config --extend /opt/ros/indigo --install
 $ catkin build
```

Install
=======

Authorize ``bwilab`` group to update some selected ``/usr/local``
directories:

```
 $ cd /usr/local
 $ sudo chmod g+w bin lib lib/python2.7/dist-packages share
 $ sudo chgrp bwilab bin lib lib/python2.7/dist-packages share
```

Copy the built install directory into ``/usr/local``:

```
 $ find bin/ lib/ share/ | cpio -pvud /usr/local
```
