/*
 * Copyright 2019 Xilinx, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "xf_integral_image_config.h"

void integral_accel(xf::cv::Mat<XF_8UC1, HEIGHT, WIDTH, NPC1>& _src, xf::cv::Mat<XF_32UC1, HEIGHT, WIDTH, NPC1>& _dst) {
    xf::cv::integral<XF_8UC1, XF_32UC1, HEIGHT, WIDTH, XF_NPPC1>(_src, _dst);
}
