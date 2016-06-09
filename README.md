Overview
========

This repository contains administration scripts and other programs for
managing the systems and networks for the
[Building-Wide Intelligence lab](http://www.cs.utexas.edu/~larg/bwi_web/)
of the University of Texas at Austin.

There are two catkin packages here:

 * [bwilab_scripts](https://github.com/utexas-bwi/bwi_lab/tree/master/bwilab_scripts)
   provides a carefully constrained ability to run a script under the
   ``bwilab`` user account.

 * [bwi_local](https://github.com/utexas-bwi/bwi_lab/tree/master/bwi_local)
   contains other administration scripts that depend upon the user's
   authorization.

Build
=====

Login as ``bwilab``. Create a catkin workspace with just this
repository, and build it.

```
 $ mkdir -p ~/ws/src
 $ cd ~/ws/src
 $ git clone https://github.com/utexas-bwi/bwi_lab.git
 $ cd ..
 $ catkin config --extend /opt/ros/$ROS_DISTRO --install
 $ catkin build
```

Install
=======

Source the newly-created install workspace, providing access to some
scripts that are useful for completing the installation.

```
 $ source install/setup.bash
```

If not already done on this system, authorize ``bwilab`` to update
some selected parts of ``/usr/local``:

```
 $ sudo install/lib/bwi_local/authorize_local
```

Copy the built install space into ``/usr/local``:

```
 $ rosrun bwi_local update_local install
```

Configure
=========

If not already done on this system, create ssh keys so the ``bwilab``
user can run selected commands on the BWI server:

```
 $ bwi keygen

```

Be sure to do that under the ``bwilab`` user account.
