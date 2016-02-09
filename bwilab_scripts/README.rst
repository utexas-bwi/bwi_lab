Overview
========

The `bwilab_scripts`_ ROS_ package provides administration scripts and
other programs for managing the systems and networks of the Building
Wide Intelligence project for the University of Texas at Austin.

Scripts
=======

distance_traveled
-----------------

Prints the time comsumed and distance traveled for one or more ROS bag
files listed on the command line. Invalid files, or names not ending
in ".bag" are reported as having zero duration and zero distance.

Usage
'''''
::
    rosrun bwilab_scripts distance_traveled bag1 [bag2 ...]

Example
'''''''
::
    $ rosrun bwilab_scripts distance_traveled bwi_2016-01-06-11-13-34.bag  
      time: 2:04:08  distance: 2999.99  filename: bwi_2016-01-06-11-13-34.bag

upload
------

Copies any newly-saved bag files in the current directory to the lab
server, optionally deleting the local copy afterwards. Only files with
names starting with ``bwi_`` and ending with ``.bag`` will be copied.

Files are stored in the ``~bwilab/robot/$HOSTNAME`` directory on the
server, and ``$HOSTNAME`` should be set to the part of the full domain
name preceding the first dot.  Files already present on the server are
neither sent or deleted.

You may specify at most one of these options::

    -d  delete files uploaded successfully (default)
    -h  print a help message
    -k  keep uploaded files

Usage
'''''

To upload and then delete all new bag files for the current user::

    cd ~/.ros/bwi/bwilab_scripts
    rosrun bwilab_scripts upload

To upload and keep any new bag files in the current directory::

    rosrun bwilab_scripts upload -k

To force a specific host name::

    HOSTNAME=bender rosrun bwilab_scripts upload


.. _`bwilab_scripts`: http://wiki.ros.org/bwilab_scripts
.. _ROS: http:/ros.org
.. _`rosbag`: http://wiki.ros.org/rosbag
