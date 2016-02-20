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
Copies any newly-saved bag files in the current directory to the
server, optionally deleting the local copy afterwards. Only files with
names matching a specified prefix and ending with ``.bag`` will be
copied.

Files are stored in the ``~bwilab/robot/$HOSTNAME`` directory on the
server, and ``$HOSTNAME`` should be set to the part of the full domain
name preceding the first dot.  Files already present on the server are
neither sent or deleted.

Options::

    -h  print a help message
    -k  keep uploaded files
    -n  dry run, do nothing
    -p  file name prefix, handle files matching ``PREFIX_*.bag``
        (default is ``bwi``)

Usage
'''''

To upload and then delete all compressed bag files for the current user::

    cd ~/.ros/bwi/bwi_logging/compressed
    bwilab upload

To upload and keep any new bag files in the current directory::

    bwilab upload -k

To force a specific host name::

    HOSTNAME=bender bwilab upload

.. _BWI: http://www.cs.utexas.edu/~larg/bwi_web/
.. _ROS: http:/ros.org
