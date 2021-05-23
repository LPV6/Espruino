/*
 * This file is part of Espruino, a JavaScript interpreter for Microcontrollers
 *
 * Copyright (C) 2013 Gordon Williams <gw@pur3.co.uk>
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * ----------------------------------------------------------------------------
 * This file is designed to be parsed during the build process
 *
 * Contains Custom Fonts
 * ----------------------------------------------------------------------------
 */

#include "jswrap_font_grotesk16.h"
#include "jswrap_graphics.h"

// NB GROTESK R LIGHT
// 16 pixels total height, 12 pixels cap height
// 2021-01-23 RB tweaked font 
// 2021-05-23 RB extended to ISO8859-1 / ISO Latin (32-255)

static const unsigned char fontBitmap[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63, 255, 195, 192, 5, 85, 65, 64, 0,
0, 0, 0, 63, 128, 0, 0, 0, 0, 0, 0, 63, 128, 0, 0, 1, 0, 4, 0, 3, 0, 13, 0,
63, 255, 255, 192, 23, 85, 93, 64, 3, 0, 13, 0, 23, 85, 93, 64, 63, 255, 255,
192, 3, 0, 13, 0, 1, 0, 4, 0, 1, 144, 4, 0, 15, 252, 11, 64, 60, 13, 2, 192,
52, 15, 0, 192, 244, 11, 0, 252, 52, 7, 0, 192, 60, 3, 66, 192, 31, 2, 255,
128, 2, 0, 125, 0, 2, 160, 0, 0, 31, 253, 0, 0, 56, 15, 0, 64, 56, 11, 7,
192, 46, 173, 126, 0, 7, 247, 224, 0, 0, 47, 20, 0, 2, 246, 255, 128, 31, 67,
1, 192, 56, 7, 0, 192, 0, 2, 215, 128, 0, 1, 190, 0, 0, 64, 0, 0, 15, 253,
255, 0, 45, 15, 131, 192, 52, 7, 65, 192, 56, 15, 192, 192, 46, 45, 240, 192,
11, 248, 63, 192, 0, 7, 255, 0, 0, 1, 91, 0, 0, 0, 3, 192, 0, 0, 0, 0, 63,
208, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 255, 248, 0, 11, 144, 30, 0, 44, 0, 3,
128, 56, 0, 0, 192, 32, 0, 0, 128, 32, 0, 0, 128, 56, 0, 0, 192, 44, 0, 3,
128, 11, 64, 30, 0, 2, 255, 252, 0, 0, 0, 0, 0, 30, 192, 0, 0, 63, 64, 0, 0,
30, 192, 0, 0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0, 240, 0, 0, 21, 245, 64, 0, 63,
255, 192, 0, 21, 245, 64, 0, 0, 240, 0, 0, 0, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 15, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0, 0, 240,
0, 0, 0, 240, 0, 0, 0, 160, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 192, 0, 0,
0, 0, 0, 0, 7, 192, 0, 1, 254, 64, 0, 191, 144, 0, 31, 224, 0, 0, 40, 0, 0,
0, 0, 21, 80, 0, 11, 255, 254, 0, 29, 0, 3, 128, 56, 0, 1, 192, 52, 0, 0,
192, 56, 0, 1, 192, 30, 0, 11, 128, 7, 255, 253, 0, 0, 0, 0, 0, 0, 0, 0, 0,
32, 0, 0, 192, 48, 0, 0, 192, 48, 0, 0, 192, 63, 255, 255, 192, 21, 85, 85,
192, 0, 0, 0, 192, 0, 0, 0, 192, 0, 0, 0, 64, 0, 0, 0, 0, 11, 0, 2, 192, 45,
0, 11, 192, 56, 0, 61, 192, 48, 0, 240, 192, 52, 3, 192, 192, 45, 31, 0, 192,
11, 248, 0, 192, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 15, 0, 44, 0, 3, 192, 52, 1,
0, 192, 48, 7, 0, 192, 56, 11, 1, 192, 30, 111, 219, 192, 7, 244, 254, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 47, 192, 0, 11, 249, 192, 0, 62, 0, 192, 0, 0, 0,
192, 0, 0, 0, 192, 0, 0, 0, 192, 0, 0, 63, 255, 192, 0, 0, 0, 0, 0, 0, 0, 0,
63, 255, 10, 0, 48, 3, 7, 128, 48, 3, 1, 192, 48, 3, 0, 192, 48, 3, 1, 192,
48, 3, 131, 192, 48, 1, 254, 0, 0, 0, 20, 0, 0, 0, 0, 0, 7, 255, 253, 0, 30,
46, 11, 128, 60, 52, 1, 192, 52, 48, 0, 192, 56, 52, 1, 192, 29, 44, 3, 128,
11, 15, 255, 0, 0, 0, 80, 0, 0, 0, 0, 0, 48, 0, 0, 0, 48, 0, 0, 0, 48, 0, 11,
192, 48, 1, 253, 0, 48, 127, 128, 0, 59, 244, 0, 0, 62, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 11, 244, 255, 0, 46, 47, 215, 192, 52, 11, 1, 192, 48, 7, 0, 192,
52, 11, 1, 192, 45, 31, 199, 192, 11, 249, 255, 0, 0, 0, 0, 0, 0, 16, 0, 0,
11, 255, 2, 0, 29, 2, 195, 128, 56, 0, 209, 192, 52, 0, 224, 192, 56, 0, 209,
192, 30, 7, 203, 128, 7, 255, 253, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63, 15, 192,
0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 255, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 80, 0,
0, 0, 240, 0, 0, 3, 252, 0, 0, 7, 77, 0, 0, 15, 11, 0, 0, 28, 3, 64, 0, 56,
2, 192, 0, 32, 0, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 13, 0, 0, 7, 13, 0, 0,
7, 13, 0, 0, 7, 13, 0, 0, 7, 13, 0, 0, 7, 13, 0, 0, 7, 13, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 32, 0, 128, 0, 56, 2, 192, 0, 28, 3, 64, 0, 15, 15, 0, 0, 3, 93,
0, 0, 2, 252, 0, 0, 0, 240, 0, 0, 0, 80, 0, 0, 0, 0, 0, 11, 0, 0, 0, 45, 0,
0, 0, 56, 0, 0, 0, 52, 7, 195, 192, 56, 15, 0, 0, 46, 45, 0, 0, 11, 248, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 255, 253, 0, 15, 1, 11, 64, 60, 47, 194, 192,
52, 52, 224, 192, 52, 52, 224, 192, 44, 63, 194, 192, 15, 85, 235, 64, 2,
255, 213, 0, 0, 0, 0, 0, 0, 0, 7, 192, 0, 1, 254, 64, 0, 191, 184, 0, 27,
224, 52, 0, 63, 208, 52, 0, 1, 255, 184, 0, 0, 6, 253, 0, 0, 0, 27, 192, 0,
0, 0, 0, 63, 255, 255, 192, 48, 3, 0, 192, 48, 3, 0, 192, 48, 3, 0, 192, 48,
3, 0, 192, 52, 7, 0, 192, 45, 31, 130, 192, 11, 249, 255, 64, 0, 64, 20, 0,
0, 0, 0, 0, 3, 255, 253, 0, 15, 0, 11, 64, 60, 0, 2, 192, 52, 0, 0, 192, 56,
0, 0, 192, 44, 0, 2, 192, 15, 0, 11, 64, 2, 0, 5, 0, 0, 0, 0, 0, 63, 255,
255, 192, 52, 0, 0, 192, 52, 0, 0, 192, 52, 0, 0, 192, 52, 0, 0, 192, 44, 0,
2, 192, 30, 0, 7, 64, 7, 255, 254, 0, 0, 21, 80, 0, 0, 0, 0, 0, 63, 255, 255,
192, 53, 87, 85, 192, 52, 7, 0, 192, 52, 7, 0, 192, 52, 7, 0, 192, 52, 7, 0,
192, 52, 7, 0, 192, 52, 7, 0, 192, 0, 0, 0, 0, 0, 0, 0, 0, 63, 255, 255, 192,
53, 87, 85, 64, 52, 7, 0, 0, 52, 7, 0, 0, 52, 7, 0, 0, 52, 7, 0, 0, 52, 7, 0,
0, 52, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 255, 248, 0, 15, 149, 95, 0, 44,
0, 3, 192, 56, 0, 0, 192, 52, 7, 0, 192, 60, 7, 1, 192, 30, 7, 7, 128, 7, 7,
255, 192, 0, 0, 0, 0, 0, 0, 0, 0, 63, 255, 255, 192, 5, 87, 85, 64, 0, 7, 0,
0, 0, 7, 0, 0, 0, 7, 0, 0, 0, 7, 0, 0, 0, 7, 0, 0, 63, 255, 255, 192, 21, 85,
85, 64, 0, 0, 0, 0, 63, 255, 255, 192, 5, 85, 85, 0, 0, 0, 0, 192, 0, 0, 0,
192, 0, 0, 2, 192, 21, 85, 111, 64, 63, 255, 248, 0, 0, 0, 0, 0, 0, 0, 0, 0,
63, 255, 255, 192, 5, 87, 213, 64, 0, 15, 0, 0, 0, 61, 0, 0, 0, 251, 192, 0,
3, 193, 244, 0, 15, 0, 47, 0, 60, 0, 3, 192, 0, 0, 0, 0, 63, 255, 255, 192,
5, 85, 85, 192, 0, 0, 0, 192, 0, 0, 0, 192, 0, 0, 0, 192, 0, 0, 0, 192, 0, 0,
0, 192, 0, 0, 0, 192, 0, 0, 0, 0, 63, 255, 255, 192, 31, 229, 85, 64, 0, 190,
0, 0, 0, 11, 240, 0, 0, 0, 127, 64, 0, 0, 7, 192, 0, 0, 190, 0, 0, 15, 208,
0, 1, 253, 0, 0, 47, 229, 85, 64, 63, 255, 255, 192, 0, 0, 0, 0, 0, 0, 0, 0,
63, 255, 255, 192, 31, 85, 85, 64, 3, 224, 0, 0, 0, 125, 0, 0, 0, 11, 128, 0,
0, 1, 244, 0, 0, 0, 47, 0, 63, 255, 255, 192, 21, 85, 85, 64, 0, 0, 0, 0, 3,
255, 253, 0, 15, 0, 11, 64, 60, 0, 2, 192, 52, 0, 0, 192, 52, 0, 0, 192, 44,
0, 2, 192, 15, 64, 31, 64, 2, 255, 252, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63, 255,
255, 192, 48, 3, 0, 0, 48, 3, 0, 0, 48, 3, 0, 0, 48, 3, 0, 0, 52, 11, 0, 0,
45, 30, 0, 0, 11, 248, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 255, 253, 0, 15, 0,
11, 64, 60, 0, 2, 192, 52, 0, 0, 192, 52, 0, 0, 192, 44, 0, 2, 192, 15, 64,
31, 128, 2, 255, 253, 192, 0, 0, 0, 0, 0, 0, 0, 0, 63, 255, 255, 192, 48, 3,
0, 0, 48, 3, 0, 0, 48, 3, 0, 0, 48, 7, 0, 0, 52, 11, 208, 0, 45, 30, 253, 0,
11, 248, 11, 192, 0, 64, 0, 64, 1, 144, 4, 0, 15, 252, 11, 64, 60, 13, 2,
192, 52, 15, 0, 192, 52, 11, 0, 192, 52, 7, 0, 192, 60, 3, 66, 192, 31, 2,
255, 128, 2, 0, 125, 0, 0, 0, 0, 0, 48, 0, 0, 0, 48, 0, 0, 0, 48, 0, 0, 0,
63, 255, 255, 192, 48, 0, 0, 0, 48, 0, 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 63,
255, 253, 0, 0, 0, 11, 64, 0, 0, 2, 192, 0, 0, 0, 192, 0, 0, 0, 192, 0, 0, 2,
192, 0, 0, 11, 64, 63, 255, 253, 0, 0, 0, 0, 0, 63, 64, 0, 0, 7, 253, 0, 0,
0, 31, 244, 0, 0, 0, 127, 192, 0, 0, 127, 192, 0, 31, 244, 0, 7, 249, 0, 0,
62, 0, 0, 0, 63, 128, 0, 0, 6, 255, 144, 0, 0, 2, 255, 192, 0, 6, 255, 128,
27, 255, 128, 0, 63, 228, 0, 0, 1, 191, 248, 0, 0, 0, 127, 192, 0, 47, 254,
64, 63, 249, 0, 0, 40, 0, 0, 0, 60, 0, 2, 192, 15, 128, 31, 64, 1, 240, 184,
0, 0, 63, 208, 0, 0, 47, 208, 0, 1, 244, 248, 0, 15, 128, 31, 64, 60, 0, 2,
192, 60, 0, 0, 0, 11, 64, 0, 0, 1, 240, 0, 0, 0, 63, 170, 128, 0, 47, 255,
192, 1, 244, 0, 0, 11, 128, 0, 0, 60, 0, 0, 0, 16, 0, 0, 64, 52, 0, 7, 192,
52, 0, 62, 192, 52, 1, 240, 192, 52, 15, 128, 192, 52, 188, 0, 192, 55, 208,
0, 192, 62, 0, 0, 192, 20, 0, 0, 64, 0, 0, 0, 0, 63, 255, 255, 192, 53, 85,
85, 192, 52, 0, 0, 192, 16, 0, 0, 64, 62, 0, 0, 0, 11, 248, 0, 0, 0, 47, 224,
0, 0, 0, 191, 128, 0, 0, 2, 192, 16, 0, 0, 64, 52, 0, 0, 192, 53, 85, 85,
192, 63, 255, 255, 192, 0, 0, 0, 0, 0, 7, 128, 0, 0, 63, 0, 0, 2, 240, 0, 0,
47, 64, 0, 0, 62, 0, 0, 0, 7, 224, 0, 0, 0, 125, 0, 0, 0, 11, 128, 0, 0, 0,
0, 0, 0, 0, 0, 192, 0, 0, 0, 192, 0, 0, 0, 192, 0, 0, 0, 192, 0, 0, 0, 192,
0, 0, 0, 192, 0, 0, 0, 192, 0, 0, 0, 192, 0, 0, 0, 0, 36, 0, 0, 0, 62, 0, 0,
0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 31, 63, 192, 0, 60, 177, 192, 0,
48, 240, 192, 0, 48, 240, 192, 0, 52, 225, 192, 0, 62, 214, 192, 0, 15, 255,
192, 0, 0, 0, 0, 0, 0, 0, 0, 63, 255, 255, 192, 0, 30, 11, 64, 0, 56, 2, 192,
0, 48, 0, 192, 0, 48, 0, 192, 0, 56, 2, 192, 0, 31, 255, 64, 0, 0, 0, 0, 0,
1, 84, 0, 0, 31, 255, 64, 0, 56, 2, 192, 0, 48, 0, 192, 0, 48, 0, 192, 0, 56,
2, 192, 0, 28, 3, 64, 0, 0, 0, 0, 0, 1, 84, 0, 0, 31, 255, 64, 0, 56, 2, 192,
0, 48, 0, 192, 0, 48, 0, 192, 0, 56, 2, 192, 0, 46, 91, 64, 63, 255, 255,
192, 0, 0, 0, 0, 0, 1, 84, 0, 0, 31, 255, 64, 0, 56, 195, 192, 0, 48, 192,
192, 0, 48, 192, 192, 0, 56, 194, 192, 0, 30, 203, 64, 0, 7, 201, 0, 0, 48,
0, 0, 0, 48, 0, 0, 31, 255, 255, 192, 56, 48, 0, 0, 48, 48, 0, 0, 0, 1, 84,
0, 0, 31, 255, 77, 0, 56, 2, 199, 0, 48, 0, 195, 0, 48, 0, 195, 0, 52, 2,
195, 0, 29, 7, 159, 0, 63, 255, 248, 0, 0, 0, 0, 0, 0, 0, 0, 63, 255, 255,
192, 0, 30, 0, 0, 0, 56, 0, 0, 0, 48, 0, 0, 0, 48, 0, 0, 0, 60, 0, 0, 0, 15,
255, 192, 0, 0, 0, 0, 0, 0, 0, 0, 63, 63, 255, 192, 0, 0, 0, 0, 0, 0, 0, 2,
0, 0, 0, 7, 63, 63, 255, 254, 0, 0, 0, 0, 0, 0, 0, 0, 63, 255, 255, 192, 0,
0, 60, 0, 0, 0, 240, 0, 0, 2, 192, 0, 0, 7, 240, 0, 0, 29, 62, 0, 0, 56, 7,
192, 0, 0, 0, 0, 0, 0, 0, 0, 63, 255, 255, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0,
63, 255, 192, 0, 45, 0, 0, 0, 48, 0, 0, 0, 56, 0, 0, 0, 47, 255, 192, 0, 61,
85, 64, 0, 48, 0, 0, 0, 52, 0, 0, 0, 47, 255, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0,
63, 255, 192, 0, 30, 0, 0, 0, 56, 0, 0, 0, 48, 0, 0, 0, 48, 0, 0, 0, 56, 0,
0, 0, 31, 255, 192, 0, 0, 0, 0, 0, 1, 160, 0, 0, 15, 255, 0, 0, 60, 3, 192,
0, 48, 0, 192, 0, 48, 0, 192, 0, 56, 2, 192, 0, 30, 91, 64, 0, 7, 253, 0, 0,
0, 0, 0, 0, 63, 255, 255, 0, 30, 11, 128, 0, 56, 2, 192, 0, 48, 0, 192, 0,
48, 0, 192, 0, 60, 3, 192, 0, 15, 255, 0, 0, 0, 80, 0, 0, 1, 84, 0, 0, 15,
255, 0, 0, 60, 3, 192, 0, 48, 0, 192, 0, 48, 0, 192, 0, 56, 2, 192, 0, 46,
91, 149, 0, 63, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63, 255, 192, 0, 30, 0,
0, 0, 56, 0, 0, 0, 48, 0, 0, 0, 6, 4, 0, 0, 47, 203, 64, 0, 48, 210, 192, 0,
48, 224, 192, 0, 48, 176, 192, 0, 52, 112, 192, 0, 45, 59, 128, 0, 10, 30, 0,
0, 48, 0, 0, 0, 48, 0, 0, 63, 255, 255, 128, 0, 48, 1, 192, 0, 48, 0, 192, 0,
0, 0, 0, 0, 63, 254, 0, 0, 0, 7, 128, 0, 0, 1, 192, 0, 0, 0, 192, 0, 0, 1,
192, 0, 0, 7, 128, 0, 63, 255, 192, 0, 0, 0, 0, 0, 61, 0, 0, 0, 11, 224, 0,
0, 0, 127, 0, 0, 0, 7, 192, 0, 0, 127, 0, 0, 11, 224, 0, 0, 61, 0, 0, 0, 62,
0, 0, 0, 27, 249, 0, 0, 0, 47, 192, 0, 2, 255, 64, 0, 63, 128, 0, 0, 31, 248,
0, 0, 0, 111, 192, 0, 1, 255, 128, 0, 63, 208, 0, 0, 52, 1, 192, 0, 30, 11,
64, 0, 7, 253, 0, 0, 1, 244, 0, 0, 3, 252, 0, 0, 31, 15, 64, 0, 56, 2, 192,
0, 60, 0, 0, 0, 31, 208, 1, 0, 0, 190, 31, 0, 0, 11, 248, 0, 0, 63, 64, 0, 7,
244, 0, 0, 62, 0, 0, 0, 32, 0, 192, 0, 48, 7, 192, 0, 48, 30, 192, 0, 48,
184, 192, 0, 50, 208, 192, 0, 63, 64, 192, 0, 60, 0, 192, 0, 32, 0, 64, 0, 1,
0, 0, 0, 15, 0, 0, 11, 255, 255, 0, 46, 80, 87, 192, 52, 0, 0, 192, 32, 0, 0,
128, 0, 0, 0, 0, 63, 255, 255, 192, 5, 85, 85, 64, 32, 0, 0, 128, 52, 0, 0,
192, 62, 80, 87, 192, 11, 255, 254, 0, 0, 15, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
0, 0, 224, 0, 0, 2, 192, 0, 0, 0, 224, 0, 0, 0, 176, 0, 0, 0, 56, 0, 0, 0,
176, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28, 192, 0, 0,
127, 244, 0, 3, 255, 255, 0, 15, 236, 239, 192, 13, 28, 194, 192, 28, 28,
192, 208, 28, 28, 64, 208, 15, 192, 15, 192, 11, 192, 15, 128, 0, 0, 0, 241,
0, 0, 0, 251, 0, 0, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 15, 0, 0, 0, 11, 0, 10, 0, 31, 0, 31, 255, 253, 3, 255,
254, 64, 15, 74, 0, 0, 15, 5, 0, 0, 11, 0, 0, 0, 0, 0, 2, 226, 0, 0, 1, 253,
0, 0, 0, 16, 0, 0, 2, 226, 0, 0, 1, 253, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 160, 0, 0, 0, 240, 0, 0, 0, 80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
160, 0, 0, 0, 240, 0, 0, 0, 80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 160, 0, 0,
0, 240, 0, 0, 0, 80, 0, 16, 0, 0, 0, 56, 0, 0, 0, 52, 0, 0, 31, 255, 255,
234, 14, 113, 245, 0, 0, 52, 0, 0, 0, 52, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0,
56, 3, 192, 0, 52, 3, 192, 31, 251, 255, 255, 14, 113, 226, 154, 0, 52, 3,
192, 0, 52, 2, 128, 0, 0, 0, 0, 32, 0, 0, 0, 112, 0, 0, 0, 240, 0, 0, 0, 240,
0, 0, 0, 48, 0, 0, 0, 16, 0, 0, 0, 1, 255, 64, 0, 11, 230, 192, 116, 13, 3,
139, 224, 15, 254, 253, 0, 7, 47, 255, 224, 11, 245, 244, 48, 13, 3, 129,
224, 0, 1, 255, 64, 0, 0, 47, 208, 0, 0, 254, 176, 0, 2, 192, 112, 0, 2, 239,
192, 0, 0, 80, 0, 0, 16, 3, 164, 130, 254, 2, 252, 247, 95, 128, 56, 61, 7,
208, 44, 122, 1, 240, 44, 231, 128, 253, 184, 75, 244, 63, 240, 0, 0, 2, 64,
0, 0, 60, 0, 0, 0, 255, 0, 0, 3, 195, 192, 0, 5, 0, 80, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0, 127, 255, 64, 2, 250, 175, 224, 7,
0, 0, 244, 10, 0, 0, 56, 13, 0, 0, 44, 13, 0, 0, 56, 11, 0, 0, 56, 11, 255,
255, 248, 11, 86, 213, 184, 10, 2, 192, 56, 10, 2, 192, 56, 10, 3, 192, 56,
11, 15, 244, 56, 11, 192, 1, 248, 0, 0, 2, 144, 1, 224, 0, 0, 14, 248, 0, 0,
4, 52, 0, 0, 10, 4, 0, 0, 15, 116, 0, 0, 7, 128, 0, 0, 1, 224, 0, 0, 14, 248,
0, 0, 4, 52, 0, 0, 0, 0, 0, 0, 7, 244, 0, 0, 12, 184, 0, 0, 0, 16, 0, 0, 10,
4, 0, 0, 15, 116, 0, 0, 7, 128, 0, 0, 0, 0, 0, 0, 15, 20, 0, 0, 15, 240, 0,
0, 1, 0, 0, 0, 0, 2, 192, 0, 0, 2, 192, 0, 0, 2, 192, 0, 0, 2, 192, 0, 0, 2,
192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 192, 0, 0, 2,
192, 0, 0, 2, 192, 0, 0, 2, 192, 0, 0, 2, 192, 0, 0, 2, 192, 0, 0, 2, 192, 0,
0, 2, 192, 0, 0, 2, 192, 0, 0, 2, 192, 0, 0, 2, 192, 0, 0, 2, 192, 0, 0, 2,
192, 0, 0, 2, 192, 0, 0, 1, 64, 0, 0, 0, 0, 0, 36, 0, 0, 0, 112, 0, 0, 0, 48,
0, 0, 0, 60, 0, 0, 0, 116, 0, 0, 0, 15, 0, 0, 0, 12, 0, 16, 0, 14, 170, 224,
0, 14, 170, 224, 0, 12, 0, 16, 0, 15, 0, 0, 0, 8, 0, 80, 0, 15, 255, 224, 0,
7, 244, 80, 0, 0, 127, 128, 0, 0, 7, 208, 0, 0, 189, 0, 0, 11, 234, 224, 0,
15, 255, 224, 0, 8, 0, 16, 0, 1, 65, 129, 164, 1, 199, 248, 184, 0, 236, 60,
28, 0, 237, 15, 28, 1, 203, 199, 244, 0, 0, 0, 64, 0, 6, 0, 144, 0, 3, 215,
128, 0, 0, 190, 0, 0, 0, 40, 0, 0, 7, 255, 128, 0, 30, 70, 240, 0, 56, 0, 48,
0, 30, 70, 240, 0, 7, 255, 192, 0, 15, 235, 240, 0, 44, 192, 176, 0, 31, 192,
240, 0, 7, 199, 128, 8, 0, 0, 0, 13, 0, 0, 0, 95, 192, 0, 0, 255, 248, 0, 32,
152, 127, 64, 112, 0, 11, 255, 240, 80, 11, 150, 240, 248, 124, 0, 48, 159,
208, 0, 0, 15, 0, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 63, 63, 255, 192, 5, 21, 85, 64, 0, 0, 0, 0, 0, 7, 253,
0, 0, 30, 11, 128, 0, 56, 1, 192, 3, 240, 0, 252, 1, 116, 1, 208, 0, 44, 3,
192, 0, 15, 15, 0, 0, 0, 0, 0, 0, 7, 0, 192, 1, 175, 170, 192, 15, 255, 255,
192, 60, 7, 0, 192, 52, 7, 0, 192, 60, 6, 0, 192, 30, 0, 0, 192, 7, 0, 11,
192, 0, 17, 164, 64, 0, 63, 255, 192, 0, 60, 3, 192, 0, 48, 0, 192, 0, 48, 0,
192, 0, 56, 2, 192, 0, 62, 91, 192, 0, 59, 254, 192, 60, 48, 160, 0, 31, 112,
240, 0, 2, 240, 240, 0, 0, 62, 250, 128, 0, 47, 255, 192, 1, 244, 240, 0, 15,
240, 240, 0, 61, 48, 160, 0, 0, 0, 0, 0, 63, 240, 127, 192, 5, 64, 21, 64, 0,
0, 0, 0, 31, 255, 207, 64, 60, 244, 211, 192, 52, 112, 224, 192, 52, 48, 176,
192, 56, 48, 176, 192, 45, 56, 246, 192, 15, 31, 239, 64, 0, 0, 0, 0, 0, 0,
0, 0, 63, 0, 0, 0, 0, 0, 0, 0, 63, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 255,
244, 0, 7, 192, 46, 0, 14, 26, 71, 64, 45, 255, 250, 192, 59, 128, 29, 192,
55, 64, 13, 192, 59, 128, 29, 192, 45, 208, 58, 192, 14, 0, 7, 64, 7, 192,
46, 0, 0, 255, 244, 0, 0, 5, 0, 0, 5, 64, 0, 0, 55, 208, 0, 0, 51, 144, 0, 0,
47, 208, 0, 0, 0, 0, 0, 0, 0, 0, 80, 0, 0, 2, 248, 0, 0, 11, 95, 0, 0, 61,
83, 192, 0, 33, 248, 192, 0, 11, 94, 0, 0, 61, 7, 192, 0, 48, 0, 192, 0, 0,
80, 0, 0, 0, 240, 0, 0, 0, 240, 0, 0, 0, 240, 0, 0, 0, 240, 0, 0, 0, 240, 0,
0, 0, 240, 0, 0, 0, 191, 192, 0, 0, 21, 64, 0, 5, 0, 0, 0, 255, 244, 0, 7,
192, 46, 0, 15, 85, 91, 64, 47, 255, 255, 192, 59, 7, 1, 192, 55, 7, 0, 192,
59, 75, 209, 192, 46, 253, 191, 192, 14, 80, 11, 64, 7, 192, 46, 0, 0, 255,
244, 0, 0, 5, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 48, 0, 0, 0, 48, 0, 0, 0, 48, 0,
0, 0, 0, 0, 0, 0, 2, 160, 0, 0, 31, 253, 0, 0, 56, 15, 0, 0, 56, 11, 0, 0,
46, 173, 0, 0, 7, 244, 0, 0, 0, 32, 0, 128, 0, 48, 0, 192, 0, 48, 0, 192, 0,
112, 0, 192, 63, 255, 224, 192, 0, 48, 0, 192, 0, 48, 0, 192, 0, 48, 0, 192,
0, 16, 0, 64, 0, 1, 0, 0, 44, 15, 0, 0, 52, 127, 0, 0, 62, 231, 0, 0, 31, 70,
0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 60, 14, 0, 0, 52, 203, 0, 0, 63, 254, 0, 0, 15,
120, 0, 0, 2, 0, 0, 0, 11, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
63, 255, 255, 0, 0, 11, 128, 0, 0, 1, 192, 0, 0, 0, 192, 0, 0, 0, 192, 0, 0,
3, 192, 0, 63, 255, 192, 0, 21, 85, 64, 7, 244, 0, 0, 31, 253, 0, 0, 63, 255,
0, 0, 63, 255, 85, 64, 63, 255, 255, 192, 52, 7, 0, 0, 52, 7, 0, 0, 63, 255,
255, 192, 21, 85, 85, 64, 0, 0, 0, 0, 0, 15, 128, 0, 0, 0, 0, 0, 0, 0, 0, 28,
0, 0, 0, 254, 0, 0, 0, 61, 32, 0, 0, 0, 48, 0, 0, 0, 63, 255, 0, 0, 0, 0, 0,
0, 6, 0, 0, 0, 46, 192, 0, 0, 48, 208, 0, 0, 47, 192, 0, 0, 0, 0, 0, 0, 0,
48, 0, 192, 0, 61, 7, 192, 0, 11, 94, 0, 0, 34, 248, 128, 0, 60, 83, 192, 0,
15, 95, 0, 0, 2, 248, 0, 0, 0, 80, 0, 32, 0, 0, 0, 48, 0, 7, 192, 63, 255,
63, 0, 0, 2, 244, 0, 0, 31, 93, 0, 1, 251, 253, 0, 15, 194, 13, 0, 60, 0,
127, 128, 0, 0, 106, 128, 0, 0, 0, 0, 32, 0, 0, 0, 48, 0, 7, 192, 63, 255,
63, 0, 0, 2, 244, 0, 0, 31, 128, 192, 1, 251, 67, 192, 15, 199, 31, 192, 60,
3, 248, 192, 0, 1, 144, 64, 4, 4, 0, 0, 44, 13, 1, 192, 52, 203, 31, 64, 63,
255, 248, 0, 31, 127, 196, 0, 0, 190, 253, 0, 7, 215, 141, 0, 62, 0, 30, 64,
16, 0, 191, 192, 0, 0, 0, 0, 0, 0, 40, 0, 0, 2, 255, 64, 0, 3, 66, 192, 25,
27, 0, 192, 47, 62, 0, 192, 0, 0, 1, 192, 0, 0, 7, 128, 0, 0, 9, 0, 0, 0, 7,
192, 0, 1, 254, 64, 0, 191, 184, 0, 95, 224, 56, 0, 255, 208, 56, 0, 65, 255,
120, 0, 0, 7, 253, 0, 0, 0, 31, 192, 0, 0, 7, 192, 0, 1, 254, 64, 0, 191,
184, 0, 223, 224, 56, 0, 191, 208, 56, 0, 1, 255, 120, 0, 0, 7, 253, 0, 0, 0,
31, 192, 0, 0, 7, 192, 0, 1, 254, 64, 192, 191, 184, 0, 223, 224, 56, 0, 191,
208, 56, 0, 193, 255, 120, 0, 0, 7, 253, 0, 0, 0, 31, 192, 0, 0, 7, 192, 128,
1, 254, 64, 128, 191, 184, 0, 95, 224, 56, 0, 255, 208, 56, 0, 193, 255, 120,
0, 64, 7, 253, 0, 0, 0, 31, 192, 0, 0, 7, 192, 0, 1, 254, 64, 64, 191, 184,
0, 159, 224, 56, 0, 127, 208, 56, 0, 129, 255, 120, 0, 0, 7, 253, 0, 0, 0,
31, 192, 0, 0, 7, 192, 0, 1, 254, 64, 0, 191, 184, 0, 223, 224, 56, 0, 255,
208, 56, 0, 65, 255, 120, 0, 0, 7, 253, 0, 0, 0, 31, 192, 0, 0, 3, 192, 0, 0,
31, 0, 0, 0, 252, 0, 0, 11, 248, 0, 0, 61, 56, 0, 2, 240, 56, 0, 31, 64, 56,
0, 63, 255, 255, 192, 52, 7, 0, 192, 52, 7, 0, 192, 52, 7, 0, 192, 52, 7, 0,
192, 52, 7, 0, 192, 52, 7, 0, 192, 48, 7, 0, 192, 0, 0, 0, 0, 0, 0, 0, 0, 3,
255, 253, 0, 15, 0, 11, 64, 60, 0, 2, 200, 52, 0, 0, 238, 56, 0, 0, 254, 44,
0, 2, 196, 15, 0, 11, 64, 2, 0, 5, 0, 0, 0, 0, 0, 63, 255, 255, 192, 53, 91,
85, 192, 52, 7, 0, 192, 116, 7, 0, 192, 244, 7, 0, 192, 180, 7, 0, 192, 52,
7, 0, 192, 52, 7, 0, 192, 0, 0, 0, 0, 0, 0, 0, 0, 63, 255, 255, 192, 53, 91,
85, 192, 52, 7, 0, 192, 244, 7, 0, 192, 244, 7, 0, 192, 52, 7, 0, 192, 52, 7,
0, 192, 52, 7, 0, 192, 0, 0, 0, 0, 0, 0, 0, 0, 63, 255, 255, 192, 53, 91, 85,
192, 244, 7, 0, 192, 244, 7, 0, 192, 180, 7, 0, 192, 244, 7, 0, 192, 52, 7,
0, 192, 52, 7, 0, 192, 0, 0, 0, 0, 0, 0, 0, 0, 63, 255, 255, 192, 53, 91, 85,
192, 116, 7, 0, 192, 244, 7, 0, 192, 116, 7, 0, 192, 244, 7, 0, 192, 52, 7,
0, 192, 52, 7, 0, 192, 0, 0, 0, 0, 0, 0, 0, 0, 191, 255, 255, 192, 197, 85,
85, 64, 128, 0, 0, 0, 255, 255, 255, 192, 69, 85, 85, 64, 192, 0, 0, 0, 191,
255, 255, 192, 197, 85, 85, 64, 192, 0, 0, 0, 63, 255, 255, 192, 197, 85, 85,
64, 0, 7, 0, 0, 0, 7, 0, 0, 63, 255, 255, 192, 57, 91, 85, 192, 52, 7, 0,
192, 52, 1, 0, 192, 52, 0, 0, 192, 60, 0, 1, 192, 30, 0, 7, 128, 7, 255, 254,
0, 0, 42, 144, 0, 0, 0, 0, 0, 63, 255, 255, 192, 159, 85, 85, 64, 131, 224,
0, 0, 0, 125, 0, 0, 192, 11, 128, 0, 192, 1, 244, 0, 128, 0, 47, 0, 63, 255,
255, 192, 21, 85, 85, 64, 0, 0, 0, 0, 3, 255, 253, 0, 15, 0, 11, 64, 60, 0,
2, 192, 180, 0, 0, 192, 244, 0, 0, 192, 44, 0, 2, 192, 15, 64, 31, 64, 2,
255, 252, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 255, 253, 0, 15, 0, 11, 64, 124, 0,
2, 192, 244, 0, 0, 192, 116, 0, 0, 192, 44, 0, 2, 192, 15, 64, 31, 64, 2,
255, 252, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 255, 253, 0, 15, 0, 11, 64, 252, 0,
2, 192, 180, 0, 0, 192, 180, 0, 0, 192, 236, 0, 2, 192, 15, 64, 31, 64, 2,
255, 252, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 255, 253, 0, 207, 0, 11, 64, 124, 0,
2, 192, 116, 0, 0, 192, 244, 0, 0, 192, 236, 0, 2, 192, 79, 64, 31, 64, 2,
255, 252, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 255, 253, 0, 15, 0, 11, 64, 188, 0,
2, 192, 116, 0, 0, 192, 180, 0, 0, 192, 172, 0, 2, 192, 15, 64, 31, 64, 2,
255, 252, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 14, 11, 0, 0, 7, 253, 0, 0, 1, 244,
0, 0, 3, 252, 0, 0, 15, 15, 0, 0, 12, 3, 0, 0, 0, 0, 0, 3, 255, 254, 192, 15,
0, 31, 128, 60, 0, 250, 192, 52, 7, 192, 192, 52, 62, 0, 192, 46, 240, 2,
192, 31, 192, 31, 64, 62, 255, 252, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63, 255, 253,
0, 0, 0, 11, 64, 0, 0, 2, 192, 128, 0, 0, 192, 192, 0, 0, 192, 0, 0, 2, 192,
0, 0, 11, 64, 63, 255, 253, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63, 255, 253, 0, 0, 0,
11, 64, 64, 0, 2, 192, 192, 0, 0, 192, 64, 0, 0, 192, 0, 0, 2, 192, 0, 0, 11,
64, 63, 255, 253, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63, 255, 253, 0, 0, 0, 11, 64,
192, 0, 2, 192, 128, 0, 0, 192, 128, 0, 0, 192, 192, 0, 2, 192, 0, 0, 11, 64,
63, 255, 253, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63, 255, 253, 0, 0, 0, 11, 64, 128,
0, 2, 192, 128, 0, 0, 192, 64, 0, 0, 192, 128, 0, 2, 192, 0, 0, 11, 64, 63,
255, 253, 0, 0, 0, 0, 0, 60, 0, 0, 0, 15, 128, 0, 0, 65, 244, 0, 0, 192, 47,
255, 128, 64, 63, 170, 128, 1, 240, 0, 0, 15, 64, 0, 0, 60, 0, 0, 0, 0, 0, 0,
0, 63, 255, 255, 192, 5, 213, 121, 64, 0, 192, 56, 0, 0, 192, 56, 0, 0, 192,
56, 0, 0, 208, 56, 0, 0, 240, 176, 0, 0, 63, 224, 0, 0, 1, 0, 0, 0, 0, 0, 0,
7, 255, 255, 192, 31, 64, 0, 0, 56, 0, 0, 0, 52, 6, 0, 192, 52, 11, 0, 192,
44, 31, 131, 192, 15, 253, 255, 64, 0, 64, 20, 0, 0, 0, 5, 0, 0, 31, 63, 192,
0, 60, 176, 192, 14, 48, 176, 192, 11, 48, 176, 192, 1, 52, 241, 192, 0, 62,
235, 192, 0, 15, 255, 192, 0, 0, 0, 0, 0, 0, 5, 0, 0, 31, 63, 192, 0, 60,
176, 192, 7, 48, 176, 192, 14, 48, 176, 192, 4, 52, 241, 192, 0, 62, 235,
192, 0, 15, 255, 192, 0, 0, 0, 0, 0, 0, 5, 0, 0, 31, 63, 192, 3, 60, 177,
192, 15, 48, 240, 192, 14, 48, 240, 192, 7, 52, 225, 192, 0, 62, 235, 192, 0,
15, 255, 192, 0, 0, 0, 0, 0, 0, 5, 0, 6, 31, 63, 192, 15, 60, 176, 192, 28,
48, 176, 192, 15, 48, 176, 192, 7, 52, 241, 192, 14, 62, 235, 192, 0, 15,
255, 192, 0, 0, 0, 0, 0, 0, 5, 0, 0, 31, 63, 192, 21, 60, 176, 192, 63, 48,
176, 192, 21, 48, 176, 192, 63, 52, 241, 192, 0, 62, 235, 192, 0, 15, 255,
192, 0, 0, 0, 0, 0, 0, 5, 0, 0, 31, 63, 192, 0, 60, 177, 192, 63, 48, 240,
192, 63, 48, 240, 192, 29, 52, 225, 192, 0, 62, 235, 192, 0, 15, 255, 192, 0,
0, 0, 0, 0, 1, 10, 0, 0, 30, 63, 192, 0, 56, 176, 192, 0, 48, 240, 192, 0,
48, 240, 192, 0, 52, 226, 192, 0, 47, 255, 128, 0, 15, 255, 0, 0, 60, 243,
192, 0, 48, 240, 192, 0, 48, 240, 192, 0, 56, 242, 192, 0, 30, 251, 64, 0, 7,
233, 0, 0, 1, 160, 0, 0, 15, 255, 0, 0, 60, 3, 192, 0, 52, 0, 221, 0, 48, 0,
254, 0, 56, 2, 236, 0, 28, 3, 64, 0, 0, 0, 0, 0, 1, 160, 0, 0, 15, 255, 0, 0,
60, 179, 192, 13, 52, 176, 192, 11, 48, 176, 192, 2, 56, 178, 192, 0, 30,
251, 64, 0, 7, 229, 0, 0, 1, 160, 0, 0, 15, 255, 0, 0, 60, 179, 192, 7, 52,
176, 192, 15, 48, 176, 192, 8, 56, 178, 192, 0, 30, 251, 64, 0, 7, 229, 0, 0,
1, 160, 0, 0, 15, 255, 0, 3, 60, 179, 192, 15, 52, 176, 192, 14, 48, 176,
192, 7, 56, 178, 192, 0, 30, 251, 64, 0, 7, 229, 0, 0, 1, 160, 0, 0, 15, 255,
0, 21, 60, 179, 192, 63, 52, 176, 192, 21, 48, 176, 192, 63, 56, 178, 192, 0,
30, 251, 64, 0, 7, 229, 0, 11, 0, 0, 0, 14, 63, 255, 192, 11, 0, 0, 0, 3, 0,
0, 0, 15, 63, 255, 192, 13, 0, 0, 0, 8, 0, 0, 0, 15, 63, 255, 192, 3, 0, 0,
0, 63, 0, 0, 0, 0, 63, 255, 192, 63, 0, 0, 0, 0, 1, 160, 0, 0, 15, 255, 0, 0,
60, 3, 192, 0, 48, 0, 192, 1, 48, 0, 192, 3, 56, 2, 192, 7, 110, 91, 64, 63,
255, 255, 192, 3, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 63, 255, 192, 15, 30,
0, 0, 28, 56, 0, 0, 14, 48, 0, 0, 7, 52, 0, 0, 15, 44, 0, 0, 8, 15, 255, 192,
0, 0, 85, 64, 0, 1, 160, 0, 0, 15, 255, 0, 0, 60, 3, 192, 13, 52, 0, 192, 11,
48, 0, 192, 2, 56, 2, 192, 0, 30, 91, 64, 0, 7, 253, 0, 0, 1, 160, 0, 0, 15,
255, 0, 0, 60, 3, 192, 7, 52, 0, 192, 15, 48, 0, 192, 4, 56, 2, 192, 0, 30,
91, 64, 0, 7, 253, 0, 0, 1, 160, 0, 0, 15, 255, 0, 3, 60, 3, 192, 15, 52, 0,
192, 14, 48, 0, 192, 7, 56, 2, 192, 0, 30, 91, 64, 0, 7, 253, 0, 0, 1, 160,
0, 6, 15, 255, 0, 14, 60, 3, 192, 28, 52, 0, 192, 15, 48, 0, 192, 7, 56, 2,
192, 30, 30, 91, 64, 0, 7, 253, 0, 0, 1, 160, 0, 0, 15, 255, 0, 21, 60, 3,
192, 63, 52, 0, 192, 21, 48, 0, 192, 63, 56, 2, 192, 0, 30, 91, 64, 0, 7,
253, 0, 0, 0, 80, 0, 0, 0, 176, 0, 0, 0, 176, 0, 0, 4, 177, 0, 0, 63, 187,
192, 0, 0, 176, 0, 0, 0, 176, 0, 0, 0, 176, 0, 0, 0, 0, 0, 0, 1, 164, 0, 0,
15, 255, 192, 0, 60, 11, 192, 0, 48, 62, 192, 0, 50, 240, 192, 0, 63, 66,
192, 0, 62, 91, 64, 0, 7, 253, 0, 0, 0, 0, 0, 0, 63, 254, 0, 0, 0, 7, 128,
13, 0, 1, 192, 15, 0, 0, 192, 3, 0, 1, 192, 0, 0, 7, 128, 0, 63, 255, 192, 0,
0, 0, 0, 0, 0, 0, 0, 0, 63, 254, 0, 0, 0, 7, 128, 7, 0, 1, 192, 14, 0, 0,
192, 4, 0, 1, 192, 0, 0, 7, 128, 0, 63, 255, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0,
63, 254, 0, 2, 0, 7, 128, 11, 0, 1, 192, 14, 0, 0, 192, 11, 0, 1, 192, 2, 0,
7, 128, 0, 63, 255, 192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63, 254, 0, 0, 0, 7, 128,
63, 0, 1, 192, 0, 0, 0, 192, 63, 0, 1, 192, 0, 0, 7, 128, 0, 63, 255, 192, 0,
0, 0, 0, 0, 60, 0, 0, 0, 31, 208, 0, 3, 0, 190, 31, 15, 0, 11, 248, 12, 0,
63, 64, 0, 7, 244, 0, 0, 62, 0, 0, 0, 0, 0, 0, 63, 255, 255, 255, 5, 110, 91,
149, 0, 56, 2, 192, 0, 48, 0, 192, 0, 48, 0, 192, 0, 60, 3, 192, 0, 15, 255,
0, 0, 1, 164, 0, 0, 60, 0, 0, 0, 31, 208, 0, 63, 0, 190, 31, 4, 0, 11, 248,
63, 0, 63, 64, 21, 7, 244, 0, 0, 62, 0, 0, };

static const unsigned char fontWidths[] = { 5, 3, 4, 9, 9, 12, 10, 3, 6, 6,
3, 10, 3, 6, 3, 5, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 3, 3, 10, 9, 10, 8, 10, 8,
10, 9, 10, 10, 10, 10, 10, 3, 6, 9, 9, 13, 10, 10, 10, 10, 10, 9, 8, 10, 8,
11, 8, 8, 9, 5, 5, 5, 8, 10, 4, 9, 9, 8, 9, 8, 5, 9, 9, 3, 4, 9, 3, 11, 9, 8,
9, 9, 5, 8, 5, 9, 7, 9, 7, 7, 8, 6, 3, 6, 7, 4, 9, 0, 8, 8, 8, 13, 8, 8, 6,
13, 8, 8, 16, 0, 0, 0, 0, 3, 3, 7, 7, 0, 9, 16, 5, 15, 6, 4, 9, 0, 0, 11, 4,
3, 9, 8, 8, 8, 3, 9, 5, 13, 5, 8, 9, 0, 13, 6, 6, 9, 6, 5, 4, 9, 9, 3, 3, 4,
5, 8, 10, 9, 10, 8, 8, 8, 8, 8, 8, 8, 16, 9, 10, 10, 10, 10, 3, 3, 3, 3, 11,
10, 10, 10, 10, 10, 10, 7, 10, 10, 10, 10, 10, 8, 10, 9, 9, 9, 9, 9, 9, 9,
14, 8, 8, 8, 8, 8, 3, 3, 3, 3, 10, 9, 8, 8, 8, 8, 8, 9, 8, 9, 9, 9, 9, 7, 9,
7, };

/*JSON{
  "type" : "method",
  "class" : "Graphics",
  "name" : "setFontGrotesk16",
  "generate" : "jswrap_graphics_setFontGrotesk16",
  "params" : [
    ["scale","int","(optional) If >1 the font will be scaled up by that amount"]
  ],
  "return" : ["JsVar","The instance of Graphics this was called on, to allow call chaining"],
  "return_object" : "Graphics"
}
Set the current font
*/
JsVar *jswrap_graphics_setFontGrotesk16(JsVar *parent, int scale) {
  if (scale<1) scale=1;
  JsVar *bitmap = jsvNewNativeString(fontBitmap, sizeof(fontBitmap));
  JsVar *widths = jsvNewNativeString(fontWidths, sizeof(fontWidths));
  JsVar *r = jswrap_graphics_setFontCustom(parent, bitmap, 32, widths, 16 + (scale<<8) + (2<<16)); // 2 bit
  jsvUnLock2(bitmap, widths);
  return r;
}
