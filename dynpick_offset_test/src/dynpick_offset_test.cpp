/*******************************************************************************
* Copyright (c) 2017, ROBOTIS CO., LTD.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* * Redistributions of source code must retain the above copyright notice, this
*   list of conditions and the following disclaimer.
*
* * Redistributions in binary form must reproduce the above copyright notice,
*   this list of conditions and the following disclaimer in the documentation
*   and/or other materials provided with the distribution.
*
* * Neither the name of ROBOTIS nor the names of its
*   contributors may be used to endorse or promote products derived from
*   this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

#include "dynpick_offset_test/dynpick_offset_test.h"

namespace robotis
{

ROBOTIS_TEST::ROBOTIS_TEST()
 : ros_node_()
{
  cnt_ = 0;

}

ROBOTIS_TEST::~ROBOTIS_TEST()
{

}

void ROBOTIS_TEST::initialize()
{
  l_foot_offset_clinet_ = ros_node_.serviceClient<std_srvs::Trigger>("/robotis/sensor/l_foot_ft_offset", 0);
  r_foot_offset_clinet_ = ros_node_.serviceClient<std_srvs::Trigger>("/robotis/sensor/r_foot_ft_offset", 0);
}

void ROBOTIS_TEST::offsetResponseLeftFoot()
{
  std_srvs::Trigger tr;

  // request

  // response
  if ( l_foot_offset_clinet_.call (tr) )
  {
    bool ok = tr.response.success;
    std::string msg = tr.response.message;

    if (ok == true)
      ROS_INFO("ok");

    ROS_INFO("msg: %s", msg.c_str());
  }
  else
    ROS_INFO("err");
}

void ROBOTIS_TEST::offsetResponseRightFoot()
{
  std_srvs::Trigger tr;

  // request

  // response
  if ( r_foot_offset_clinet_.call (tr) )
  {
    bool ok = tr.response.success;
    std::string msg = tr.response.message;

    if (ok == true)
      ROS_INFO("ok");

    ROS_INFO("msg: %s", msg.c_str());
  }
  else
    ROS_INFO("err");
}

void ROBOTIS_TEST::process()
{
  if (cnt_ < 10)
    ROS_INFO("cnt: %d", cnt_);

  if (cnt_ == 10)
  {
    ROS_INFO("Reset");
    offsetResponseLeftFoot();
    offsetResponseRightFoot();
  }

  cnt_++;
}

} // namespace thormang3
