Overview
========

This ROS_ package provides administration scripts and other programs
for managing the systems and networks of the Building-Wide
Intelligence (BWI_) project of the University of Texas at Austin.

These scripts run using the current user's account, with no additional
permissions, and hence no new security requirements.

Scripts
=======

bwi
---

Run any script installed in the ``/usr/local/lib/bwi_local`` directory
within the current user environment.  No additional permissions are
requested or required.

Usage
'''''

::
    bwi script_name [ args ]

clone_server
------------

Download all saved bag files from the BWI lab server under the current
directory.  This copies the bags using ``rsync``, which will not copy
previously cloned files again.

Example
'''''''

First, change to a directory where you want the bags copied, then run
the script::

    $ mkdir -p ~/logs
    $ cd ~/logs
    $ bwi clone_server

This creates a ``~/logs/robot`` directory containing subdirectories
named after each robot, which contain the bags for each robot.

keygen
------

Generate ssh keys for accessing the main BWI server without a
password.  This is intended for use of the local ``bwilab`` account on
each robot.  For that account, supply an empty passphrase, when
requested.

Example
'''''''

::
    $ bwi keygen

distance_traveled
-----------------

Prints the time comsumed and distance traveled for one or more ROS bag
files listed on the command line. Invalid files, or names not ending
in ".bag" are reported as having zero duration and zero distance.

Usage
'''''

::
    bwi distance_traveled bag1 [bag2 ...]

Example
'''''''

::
    $ bwi distance_traveled bwi_2016-01-06-11-13-34.bag
      time: 2:04:08  distance: 2999.99  filename: bwi_2016-01-06-11-13-34.bag


.. _BWI: http://www.cs.utexas.edu/~larg/bwi_web/
.. _ROS: http:/ros.org
