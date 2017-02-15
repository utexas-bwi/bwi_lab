Overview
========

This ROS_ package provides administration scripts and other programs
for managing the systems and networks of the Building-Wide
Intelligence (BWI_) project of the University of Texas at Austin.

These scripts run using the current user's account, with no additional
permissions, and hence no new security requirements.

Scripts
=======

authorize_local
---------------

Modify certain directories within ``/usr/local`` so the ``bwilab``
user can install things there.

**Note**: you *must* use sudo to run this command.

Example
'''''''
::

    $ sudo bwi authorize_local

bags
----

Compress and upload files matching ``$PREFIX_*.bag`` to the main BWI
server.  These bags are normally stored in ``~/.ros/bwi/bwi_logging``.
Successfully uploaded compressed bags are either deleted or optionally
saved in a subdirectory named ``kept``.

Usage
'''''
::

    $ bwi bags [options] PREFIX

Options::

    -c  compress only, do not upload
    -d  directory containing bags (default: "~/.ros/bwi/bwi_logging")
    -h  print help message
    -k  keep the compressed files after uploading"
    -n  dry run, only prints bag info for the selected files
    -u  upload only, do not compress
    -w  number of seconds to wait before starting

Example
'''''''

Upload the bags that are normally collected for all robot runs::

    $ bwi bags bwi

Upload extra bags collected for some specific experiment, which may be
much larger than our default message topics::

    $ bwi bags -k extra

The ``-k`` option causes all matching bags to be stored in
``~/.ros/bwi/bwi_logging/kept`` after being sucessfully uploaded.

Wait 20 seconds before staring the upload::

    $ bwi bags -w20 bwi

bwi
---

Run any script installed in the ``/usr/local/lib/bwi_local`` directory
within the current user environment.  No additional permissions are
requested or required.  This script is installed in
``/usr/local/bin``, which is generally included in every user's
command ``$PATH``, so it can run the other scripts with or without a
ROS environment.

Usage
'''''
::

    $ bwi script_name [ args ]

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

distance_traveled
-----------------

Prints the time comsumed and distance traveled for one or more ROS bag
files listed on the command line. Invalid files, or names not ending
in ".bag" are reported as having zero duration and zero distance.

Usage
'''''
::

    $ bwi distance_traveled bag1 [bag2 ...]

Example
'''''''
::

    $ bwi distance_traveled bwi_2016-01-06-11-13-34.bag
      time: 2:04:08  distance: 2999.99  filename: bwi_2016-01-06-11-13-34.bag

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

list_bags
'''''''''

List bag files saved in BWI logging directories.

Usage
'''''
::

    $ bwi list_bags

update_local
------------

Update ``/usr/local`` with files from the designated install
space.

Run this under the ``bwilab`` account, which should first have been
given access via the ``authorize`` script.


Example
'''''''
::

    $ bwi update_local ~/ws/install

yaml_index
----------

Creates a YAML index file containing the time comsumed and distance
traveled for one or more ROS bag files listed on the command
line. Invalid files, or names not ending in ".bag" are ignored.

Usage
'''''
::

    $ bwi yaml_index outfile.yaml bag1 [bag2 ...]

Examples
''''''''
::

    $ bwi yaml_index index.yaml bwi_2016-09*.bag

This creates an ``index.yaml`` file in the current directory,
containing data for all bags in that directory created in
September of 2016.

::

    $ bwi yaml_index master_2016.yaml */bwi_2016-*.bag

This ``master_2016.yaml`` index will contain data for all bags created
in any subdirectory during 2016. Bag files are typically stored in a
folder under the robot name. The unlikely possibility that two robots
might create a bag file in the same second of the same day is ignored.


.. _BWI: http://www.cs.utexas.edu/~larg/bwi_web/
.. _ROS: http:/ros.org
