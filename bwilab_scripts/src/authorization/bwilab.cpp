/*********************************************************************
* Software License Agreement (BSD License)
*
*  Copyright (C) 2016, Jack O'Quin
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*   * Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*   * Redistributions in binary form must reproduce the above
*     copyright notice, this list of conditions and the following
*     disclaimer in the documentation and/or other materials provided
*     with the distribution.
*   * Neither the name of the author nor other contributors may be
*     used to endorse or promote products derived from this software
*     without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
*  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
*  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
*  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
*  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
*  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
*  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
*  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
*  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*********************************************************************/


/** @file

@brief Run scripts under a different user ID.

This is a POSIX program for authorizing a constrained set of scripts
to run under the @c bwilab user account.

*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>

// Path to directory containing authorized scripts.
const std::string CMD_DIR("/usr/local/lib/bwilab_scripts");

int main(int argc, char *argv[])
{
  std::string exec_path = argv[0];

  if (argc < 2)
    {
      std::cerr << "usage: " << exec_path
                << " command [ args ]" << std::endl;
      return 9;
    }

  // std::cout << "Real UID: " << getuid()
  //           << ", effective UID: " << geteuid() << std::endl;

  std::string resolved_cmd_path = CMD_DIR + '/' + argv[1];
  // std::cout << "Command path: " << resolved_cmd_path << std::endl;

  // execute the desired program using the current environment
  int rc = execv(resolved_cmd_path.c_str(), argv+1);
  // execv SHOULD NOT return

  std::string error_str = "error: exec " + resolved_cmd_path + " failed";
  perror(error_str.c_str());
  return 1;
}
