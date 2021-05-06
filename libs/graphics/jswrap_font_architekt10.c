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

#include "jswrap_font_architekt10.h"
#include "jswrap_graphics.h"

// NB ARCHITEKT LIGHT
// 10 pixels total height, 8 pixels cap height
// RB tweaked font again 2021-01-25

static const unsigned char fontBitmap[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 63, 243, 1, 85, 16, 0, 0, 0, 0, 0, 0, 0, 3, 208, 0, 0,
0, 3, 208, 0, 0, 0, 0, 0, 0, 12, 48, 3, 255, 192, 12, 48, 3, 255, 192, 12, 48,
0, 0, 0, 29, 13, 3, 180, 112, 241, 195, 199, 13, 48, 28, 125, 0, 65, 64, 45, 7,
3, 114, 208, 45, 240, 0, 118, 224, 44, 55, 3, 2, 224, 12, 60, 3, 189, 112, 51,
227, 2, 227, 224, 0, 51, 0, 0, 0, 0, 0, 0, 0, 0, 61, 0, 2, 64, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 63, 255, 3, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 3, 3, 255,
240, 0, 0, 0, 0, 0, 13, 28, 0, 115, 64, 47, 254, 0, 119, 64, 13, 28, 0, 0, 0, 0,
192, 0, 12, 0, 63, 255, 1, 93, 80, 0, 192, 0, 4, 0, 0, 0, 0, 0, 0, 0, 1, 192, 0,
244, 0, 0, 0, 0, 0, 0, 128, 0, 12, 0, 0, 192, 0, 12, 0, 0, 192, 0, 4, 0, 0, 0,
0, 0, 0, 0, 15, 0, 0, 240, 0, 0, 0, 0, 0, 0, 15, 0, 3, 144, 0, 224, 0, 120, 0,
61, 0, 1, 0, 0, 31, 253, 3, 151, 176, 112, 227, 7, 56, 48, 47, 254, 0, 85, 64,
48, 3, 7, 0, 48, 127, 255, 1, 85, 112, 0, 3, 0, 0, 16, 28, 31, 3, 71, 112, 112,
211, 7, 28, 48, 47, 3, 0, 64, 16, 28, 13, 3, 64, 112, 112, 195, 7, 12, 48, 47,
254, 0, 81, 64, 1, 244, 1, 251, 64, 52, 52, 0, 15, 240, 0, 52, 0, 0, 0, 63, 142,
7, 92, 112, 112, 195, 7, 12, 48, 112, 190, 1, 1, 64, 0, 125, 0, 126, 176, 61,
195, 1, 12, 48, 0, 190, 0, 1, 64, 48, 0, 7, 0, 16, 112, 47, 7, 31, 0, 127, 64,
1, 64, 0, 31, 125, 3, 93, 112, 112, 195, 7, 12, 48, 47, 190, 0, 81, 64, 31, 64,
3, 108, 0, 112, 195, 7, 15, 224, 63, 224, 0, 80, 0, 0, 0, 0, 0, 0, 3, 207, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 192, 60, 244, 0, 0, 0, 0, 0, 0, 144, 0,
47, 64, 7, 29, 1, 208, 180, 56, 2, 192, 0, 0, 0, 0, 0, 115, 64, 7, 52, 0, 115,
64, 7, 52, 0, 0, 0, 56, 2, 193, 208, 180, 7, 29, 0, 47, 64, 0, 144, 0, 0, 0, 28,
0, 3, 64, 0, 112, 179, 7, 45, 16, 47, 0, 0, 64, 0, 24, 125, 3, 78, 176, 112,
255, 7, 5, 112, 63, 255, 0, 85, 64, 1, 255, 2, 251, 80, 116, 52, 7, 131, 64, 31,
255, 0, 5, 80, 63, 255, 7, 93, 112, 112, 195, 7, 76, 112, 31, 125, 0, 81, 64,
31, 253, 3, 149, 176, 112, 3, 7, 0, 48, 44, 14, 0, 64, 64, 63, 255, 7, 85, 112,
112, 3, 7, 128, 176, 31, 253, 0, 85, 64, 63, 255, 7, 93, 112, 112, 195, 7, 12,
48, 112, 195, 1, 4, 16, 63, 255, 7, 93, 80, 112, 192, 7, 12, 0, 112, 192, 1, 4,
0, 31, 253, 3, 149, 176, 112, 3, 7, 12, 48, 56, 255, 0, 69, 64, 63, 255, 1, 93,
80, 0, 192, 0, 12, 0, 63, 255, 1, 85, 80, 32, 2, 7, 0, 48, 127, 255, 7, 85, 112,
112, 3, 1, 0, 16, 48, 13, 7, 0, 112, 112, 3, 7, 0, 48, 127, 254, 1, 85, 64, 63,
255, 1, 93, 80, 0, 192, 0, 127, 0, 61, 47, 1, 0, 16, 63, 255, 1, 85, 112, 0, 3,
0, 0, 48, 0, 3, 0, 0, 16, 63, 255, 2, 229, 80, 7, 192, 0, 184, 0, 63, 255, 1,
85, 80, 63, 255, 2, 229, 80, 7, 192, 0, 11, 128, 63, 255, 1, 85, 80, 31, 253, 3,
85, 112, 112, 3, 7, 0, 48, 47, 254, 0, 85, 64, 63, 255, 7, 93, 80, 112, 192, 7,
12, 0, 47, 128, 0, 80, 0, 31, 253, 3, 149, 112, 112, 47, 7, 0, 112, 47, 254, 0,
85, 64, 63, 255, 7, 93, 80, 112, 192, 7, 15, 0, 47, 175, 0, 80, 16, 29, 13, 3,
180, 176, 113, 195, 7, 13, 48, 44, 125, 0, 64, 64, 48, 0, 7, 0, 0, 127, 255, 7,
85, 80, 112, 0, 1, 0, 0, 63, 253, 1, 85, 176, 0, 3, 0, 0, 112, 63, 254, 1, 85,
64, 63, 208, 1, 91, 208, 0, 11, 0, 3, 208, 63, 228, 1, 84, 0, 63, 255, 1, 87,
224, 1, 244, 0, 11, 128, 63, 255, 1, 85, 80, 60, 15, 0, 179, 128, 2, 224, 0,
179, 128, 61, 31, 1, 64, 80, 61, 0, 1, 120, 0, 2, 255, 0, 121, 80, 61, 0, 1, 64,
0, 16, 2, 7, 2, 240, 112, 247, 7, 184, 48, 124, 3, 1, 0, 16, 0, 0, 0, 0, 0, 63,
255, 3, 0, 48, 0, 0, 0, 0, 0, 52, 0, 1, 224, 0, 3, 192, 0, 11, 0, 0, 31, 0, 0,
16, 0, 0, 0, 0, 0, 48, 3, 3, 255, 240, 0, 0, 0, 0, 0 };


/*JSON{
  "type" : "method",
  "class" : "Graphics",
  "name" : "setFontArchitekt10",
  "generate" : "jswrap_graphics_setFontArchitekt10",
  "params" : [
    ["scale","int","(optional) If >1 the font will be scaled up by that amount"]
  ],
  "return" : ["JsVar","The instance of Graphics this was called on, to allow call chaining"],
  "return_object" : "Graphics"
}
Set the current font
*/
JsVar *jswrap_graphics_setFontArchitekt10(JsVar *parent, int scale) {
  if (scale<1) scale=1;
  JsVar *bitmap = jsvNewNativeString(fontBitmap, sizeof(fontBitmap));
  JsVar *widths = jsvNewFromInteger(6);
  JsVar *r = jswrap_graphics_setFontCustom(parent, bitmap, 32, widths, 10 + (scale<<8) + (2<<16)); // 2 bit
  jsvUnLock2(bitmap, widths);
  return r;
}