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

#include "jswrap_font_architekt15.h"
#include "jswrap_graphics.h"

static const unsigned char fontBitmap[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 2, 170, 146, 64, 31, 255, 207, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 84, 0, 0, 11, 240, 0, 0, 5, 0, 0, 0, 106, 0,
    0, 1, 252, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 176, 56, 0,
    47, 255, 254, 0, 111, 171, 228, 0, 44, 14, 0, 11, 255, 255, 128, 27, 234,
    249, 0, 7, 3, 64, 0, 0, 0, 0, 0, 64, 4, 0, 31, 224, 189, 0, 246, 208, 124,
    11, 131, 192, 184, 126, 7, 130, 244, 60, 15, 11, 0, 189, 15, 248, 0, 180,
    31, 128, 0, 0, 0, 0, 1, 64, 1, 0, 123, 128, 120, 1, 135, 11, 0, 3, 244, 224,
    0, 0, 29, 20, 0, 2, 195, 188, 0, 116, 28, 112, 7, 64, 47, 64, 0, 0, 0, 0, 0,
    0, 0, 1, 253, 31, 208, 15, 191, 251, 192, 56, 127, 11, 0, 251, 239, 188, 0,
    252, 15, 192, 0, 0, 127, 192, 0, 1, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 37, 0, 0, 1, 252, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 85, 64, 1, 255, 255, 208, 15, 85, 87, 192,
    36, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 64, 0,
    96, 15, 85, 87, 192, 31, 255, 254, 0, 5, 85, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 44, 0, 0, 31, 224, 0, 0, 63, 0, 0, 2, 239,
    0, 0, 6, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0, 3, 128, 0, 0, 14, 0,
    0, 42, 190, 164, 1, 255, 255, 240, 0, 3, 128, 0, 0, 14, 0, 0, 0, 52, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 144, 0, 0, 3, 244, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 56, 0, 0, 0, 224, 0,
    0, 3, 128, 0, 0, 14, 0, 0, 0, 56, 0, 0, 0, 224, 0, 0, 3, 64, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 60, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 80, 0, 0, 31, 192, 0, 1, 244, 0, 0, 47, 0,
    0, 3, 224, 0, 0, 62, 0, 0, 31, 208, 0, 0, 125, 0, 0, 0, 0, 0, 0, 0, 85, 84,
    0, 31, 255, 254, 0, 245, 95, 252, 3, 128, 248, 176, 14, 15, 130, 192, 57,
    244, 11, 0, 255, 255, 252, 0, 255, 255, 192, 0, 0, 0, 0, 16, 0, 1, 0, 224,
    0, 44, 3, 128, 0, 176, 15, 170, 171, 192, 63, 255, 255, 0, 0, 0, 44, 0, 0,
    0, 176, 0, 0, 1, 192, 0, 0, 0, 0, 45, 7, 252, 2, 244, 63, 240, 15, 3, 210,
    192, 56, 30, 11, 0, 224, 240, 44, 3, 219, 128, 176, 7, 252, 2, 192, 1, 64,
    1, 0, 0, 0, 0, 0, 16, 1, 0, 11, 192, 15, 128, 60, 4, 31, 0, 224, 176, 44, 3,
    130, 192, 176, 14, 11, 2, 192, 63, 255, 255, 0, 63, 239, 240, 0, 0, 0, 0, 0,
    1, 80, 0, 0, 191, 224, 0, 47, 215, 128, 3, 244, 14, 0, 5, 2, 255, 64, 0, 15,
    254, 0, 0, 3, 128, 0, 0, 13, 0, 0, 0, 0, 0, 21, 84, 16, 0, 255, 240, 248, 3,
    150, 193, 240, 14, 11, 2, 192, 56, 44, 11, 0, 224, 176, 44, 3, 129, 255,
    240, 13, 1, 255, 0, 0, 0, 0, 0, 0, 1, 64, 0, 1, 255, 224, 0, 127, 215, 192,
    15, 238, 11, 0, 120, 56, 44, 0, 0, 224, 176, 0, 3, 255, 192, 0, 3, 252, 0,
    0, 0, 0, 1, 0, 0, 0, 14, 0, 0, 0, 56, 0, 24, 0, 224, 7, 248, 3, 128, 190, 0,
    14, 31, 192, 0, 63, 244, 0, 0, 254, 0, 0, 0, 0, 0, 0, 0, 84, 84, 0, 47, 255,
    254, 0, 245, 249, 124, 3, 130, 192, 176, 14, 11, 2, 192, 56, 44, 11, 0, 255,
    255, 252, 0, 255, 191, 192, 0, 0, 0, 0, 1, 64, 0, 0, 191, 224, 0, 3, 215,
    192, 0, 14, 11, 1, 0, 56, 44, 189, 0, 224, 191, 208, 3, 255, 244, 0, 3, 253,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 36, 9, 0, 0, 240, 60,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 24, 36, 0, 0, 244, 253, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 2, 208, 0, 0, 31, 192, 0, 0, 243, 192, 0, 11, 71, 128, 0, 120, 15, 64,
    3, 192, 15, 0, 14, 0, 44, 0, 16, 0, 16, 0, 0, 0, 0, 0, 64, 16, 0, 11, 2,
    192, 0, 44, 11, 0, 0, 176, 44, 0, 2, 192, 176, 0, 11, 2, 192, 0, 44, 11, 0,
    0, 112, 28, 0, 0, 0, 0, 0, 4, 0, 4, 0, 176, 0, 176, 1, 224, 3, 192, 2, 208,
    61, 0, 3, 193, 224, 0, 7, 143, 0, 0, 11, 240, 0, 0, 15, 64, 0, 0, 0, 0, 0,
    16, 0, 0, 7, 208, 0, 0, 61, 0, 0, 0, 224, 24, 96, 3, 130, 242, 224, 14, 30,
    0, 0, 47, 240, 0, 0, 47, 64, 0, 0, 0, 0, 0, 0, 64, 84, 0, 47, 15, 253, 0,
    244, 185, 124, 3, 130, 234, 240, 14, 7, 255, 192, 56, 0, 11, 0, 255, 255,
    252, 0, 255, 255, 192, 0, 0, 0, 0, 0, 5, 84, 0, 6, 255, 252, 1, 254, 94, 64,
    15, 128, 56, 0, 56, 0, 224, 0, 254, 3, 128, 0, 127, 255, 208, 0, 27, 255,
    128, 0, 0, 0, 0, 85, 85, 84, 3, 255, 255, 240, 14, 87, 150, 192, 56, 14, 11,
    0, 224, 56, 44, 3, 128, 224, 176, 15, 255, 255, 192, 15, 251, 252, 0, 0, 0,
    0, 0, 21, 85, 0, 7, 255, 255, 128, 61, 85, 95, 0, 224, 0, 44, 3, 128, 0,
    176, 14, 0, 2, 192, 62, 0, 47, 0, 60, 0, 240, 0, 0, 0, 0, 5, 85, 85, 64, 63,
    255, 255, 0, 229, 85, 108, 3, 128, 0, 176, 14, 0, 2, 192, 56, 0, 11, 0, 255,
    255, 252, 0, 255, 255, 192, 0, 0, 0, 0, 47, 255, 255, 0, 255, 255, 252, 3,
    128, 224, 176, 14, 3, 130, 192, 56, 14, 11, 0, 224, 56, 44, 3, 128, 224,
    176, 4, 1, 0, 64, 0, 0, 0, 0, 191, 255, 244, 3, 255, 255, 208, 14, 11, 0, 0,
    56, 44, 0, 0, 224, 176, 0, 3, 130, 192, 0, 14, 11, 0, 0, 16, 4, 0, 0, 0, 0,
    0, 0, 21, 85, 0, 7, 255, 255, 128, 61, 85, 95, 0, 224, 0, 44, 3, 128, 144,
    176, 14, 3, 130, 192, 62, 15, 255, 0, 60, 63, 240, 0, 0, 0, 0, 1, 85, 85,
    64, 47, 255, 255, 0, 21, 121, 80, 0, 0, 224, 0, 0, 3, 128, 0, 0, 14, 0, 0,
    111, 255, 248, 1, 255, 255, 240, 0, 0, 0, 0, 16, 0, 1, 0, 224, 0, 44, 3,
    128, 0, 176, 15, 170, 171, 192, 63, 255, 255, 0, 224, 0, 44, 3, 128, 0, 176,
    13, 0, 1, 192, 0, 0, 0, 0, 64, 0, 64, 3, 128, 3, 224, 14, 0, 7, 192, 56, 0,
    11, 0, 224, 0, 44, 3, 128, 0, 176, 15, 255, 255, 192, 63, 255, 252, 0, 0, 0,
    0, 1, 255, 255, 240, 7, 255, 255, 128, 0, 14, 0, 0, 0, 124, 0, 0, 7, 252, 0,
    1, 188, 189, 0, 47, 192, 127, 0, 20, 0, 20, 0, 0, 0, 0, 1, 85, 85, 64, 47,
    255, 255, 0, 21, 85, 108, 0, 0, 0, 176, 0, 0, 2, 192, 0, 0, 11, 0, 0, 0, 44,
    0, 0, 0, 112, 0, 0, 0, 0, 5, 85, 85, 0, 191, 255, 252, 0, 190, 85, 64, 0,
    127, 64, 0, 0, 127, 0, 0, 11, 208, 0, 1, 255, 255, 224, 7, 255, 255, 192, 0,
    0, 0, 0, 21, 85, 84, 2, 255, 255, 240, 2, 249, 85, 0, 1, 253, 0, 0, 0, 190,
    0, 0, 0, 63, 64, 6, 255, 255, 128, 31, 255, 255, 0, 0, 0, 0, 0, 21, 85, 0,
    7, 255, 255, 128, 61, 85, 95, 0, 224, 0, 44, 3, 128, 0, 176, 14, 0, 2, 192,
    63, 255, 255, 0, 63, 255, 240, 0, 0, 0, 0, 5, 85, 85, 0, 63, 255, 254, 0,
    229, 181, 80, 3, 130, 192, 0, 14, 11, 0, 0, 56, 44, 0, 0, 191, 224, 0, 0,
    190, 0, 0, 0, 0, 0, 0, 1, 85, 80, 0, 127, 255, 248, 3, 213, 85, 240, 14, 0,
    27, 192, 56, 0, 255, 0, 224, 0, 44, 3, 255, 255, 240, 3, 255, 255, 0, 0, 0,
    0, 0, 85, 85, 80, 3, 255, 255, 224, 14, 91, 85, 0, 56, 44, 0, 0, 224, 188,
    0, 3, 130, 252, 0, 11, 254, 127, 64, 11, 224, 125, 0, 0, 0, 0, 0, 16, 1, 0,
    7, 248, 47, 64, 61, 180, 31, 0, 224, 240, 44, 3, 129, 224, 176, 15, 3, 194,
    192, 47, 67, 254, 0, 45, 7, 224, 0, 0, 0, 0, 4, 0, 0, 0, 56, 0, 0, 0, 224,
    0, 0, 3, 234, 170, 128, 15, 255, 255, 128, 56, 0, 0, 0, 224, 0, 0, 3, 64, 0,
    0, 0, 0, 0, 0, 5, 85, 80, 0, 191, 255, 248, 0, 85, 85, 240, 0, 0, 2, 192, 0,
    0, 11, 0, 0, 0, 44, 1, 191, 255, 240, 7, 255, 255, 0, 0, 0, 0, 0, 21, 80, 0,
    2, 255, 253, 0, 1, 85, 191, 64, 0, 0, 47, 0, 0, 0, 44, 0, 0, 11, 240, 6,
    255, 254, 0, 31, 255, 64, 0, 0, 0, 0, 0, 85, 85, 80, 11, 255, 255, 192, 5,
    85, 253, 0, 0, 47, 128, 0, 2, 252, 0, 0, 0, 189, 0, 27, 255, 254, 0, 127,
    255, 252, 0, 0, 0, 0, 1, 64, 1, 64, 47, 192, 127, 0, 27, 199, 208, 0, 7,
    252, 0, 0, 15, 208, 0, 0, 251, 224, 0, 111, 67, 248, 1, 244, 2, 240, 0, 0,
    0, 0, 31, 64, 0, 0, 127, 64, 0, 0, 15, 128, 0, 0, 15, 255, 192, 0, 126, 170,
    0, 11, 192, 0, 2, 252, 0, 0, 1, 64, 0, 0, 0, 0, 0, 0, 144, 0, 40, 3, 128, 7,
    240, 14, 1, 255, 192, 56, 47, 139, 0, 231, 240, 44, 3, 253, 0, 176, 15, 128,
    2, 192, 16, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 85, 84, 0, 191,
    255, 252, 2, 213, 85, 176, 6, 0, 1, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    64, 0, 0, 47, 128, 0, 0, 27, 192, 0, 0, 11, 208, 0, 0, 7, 208, 0, 0, 3, 224,
    0, 0, 3, 248, 0, 0, 2, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 128, 0, 96,
    11, 85, 86, 192, 47, 255, 255, 0, 21, 85, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0 };

/*JSON{
  "type" : "method",
  "class" : "Graphics",
  "name" : "setFontArchitekt15",
  "generate" : "jswrap_graphics_setFontArchitekt15",
  "params" : [
    ["scale","int","(optional) If >1 the font will be scaled up by that amount"]
  ],
  "return" : ["JsVar","The instance of Graphics this was called on, to allow call chaining"],
  "return_object" : "Graphics"
}
Set the current font
*/
JsVar *jswrap_graphics_setFontArchitekt15(JsVar *parent, int scale) {
  if (scale<1) scale=1;
  JsVar *bitmap = jsvNewNativeString(fontBitmap, sizeof(fontBitmap));
  JsVar *widths = jsvNewFromInteger(9);
  JsVar *r = jswrap_graphics_setFontCustom(parent, bitmap, 32, widths, 15 + (scale<<8) + (2<<16)); // 2 bit
  jsvUnLock2(bitmap, widths);
  return r;
}
