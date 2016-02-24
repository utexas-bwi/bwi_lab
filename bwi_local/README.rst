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

Compress and upload bag files to the main BWI server.  The bags are
normally stored in ``~/.ros/bwi/bwi_logging`` for the current user.
The compressed bags are stored in a subdirectory named ``compressed``,
and the uncompressed files deleted.

Usage
'''''
::

    $ bwi bags [options]

Options::

    -c  compress only, do not upload
    -d  directory containing bags (default: "~/.ros/bwi/bwi_logging")
    -h  [--help] print help message
    -n  dry run, do nothing
    -p  file name prefix, handle files matching "PREFIX_*.bag".
        (default is "bwi")
    -u  upload only, do not compress

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

    bwi list_bags

update_local
------------

Update ``/usr/local`` with files from the designated install
space.

Run this under the ``bwilab`` account, which should first have been
given access via the ``authorize`` script.


Usage
'''''
::

    bwi update_local ~/ws/install


.. _BWI: http://www.cs.utexas.edu/~larg/bwi_web/
.. _ROS: http:/ros.org
