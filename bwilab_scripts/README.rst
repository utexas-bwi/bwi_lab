Overview
========

This ROS_ package provides administration scripts and other programs
for managing the systems and networks of the Building-Wide
Intelligence (BWI_) project of the University of Texas at Austin.

These scripts are authorized to run under the local ``bwilab`` user
account, which is configured to login to the BWI server without
requiring a password.  For security, these scripts should be kept
simple and do no more than necessary.

Scripts
=======

upload
------

Uploads files from the current directory to the main BWI lab server.

*This script is not normally run directly*.  Use the ``bags``
script from `bwi_local`_, instead.

The upload copies files matching ``$PREFIX_*.bag`` from the current
directory to the main BWI server.

Files on the server are stored in the ``~bwilab/robot/$HOSTNAME``
directory.  ``$HOSTNAME`` should be set to the robot's name; if not
defined, the output of the ``hostname`` command is used.  Files
already on the server will not be sent again.


Usage
'''''
::
 $ bwilab upload [options] PREFIX

Options::

    -h  print a help message
    -n  dry run, do no transfers

The ``PREFIX`` parameter is *required*.

All robot runs normally collect a moderate number of messages with the
``bwi`` prefix.  Those bags are always intended to be uploaded to the
server.  Extra bags may be collected for specific experiments. Because
they may be much larger than our ``bwi`` bags, they are normally
uploaded manually, when needed.

Examples
''''''''

To upload compressed bag files for the current user::

    $ cd ~/.ros/bwi/bwi_logging/compressed
    $ bwilab upload bwi

To Upload ``extra`` bags collected for some specific experiment::

    $ bwilab upload extra

To force a specific host name::

    $ HOSTNAME=bender bwilab upload bwi

.. _BWI: http://www.cs.utexas.edu/~larg/bwi_web/
.. _`bwi_local`: https://github.com/utexas-bwi/bwi_lab/tree/master/bwi_local
.. _ROS: http:/ros.org
