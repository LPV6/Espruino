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

#include "jswrap_font_architekt12.h"
#include "jswrap_graphics.h"

// Neubau Architekt Light
// 12 pixels total height, 9 pixels cap height
// ASCII numbers and capitals (no lowercase characters)

static const unsigned char fontBitmap[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63, 252, 240, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63, 0, 0, 0, 0, 0, 63, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 3, 3, 0, 63, 255, 240, 3, 3, 0, 63, 255, 240, 3, 3, 0, 0,
0, 0, 0, 0, 0, 31, 208, 208, 52, 48, 112, 240, 48, 60, 52, 52, 112, 31, 31,
208, 0, 0, 0, 0, 0, 0, 15, 193, 240, 15, 207, 0, 0, 53, 0, 1, 211, 240, 15,
3, 240, 0, 0, 0, 0, 1, 64, 31, 219, 208, 52, 124, 48, 45, 253, 48, 11, 71,
208, 0, 13, 176, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63, 64, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 255, 244, 29, 0, 29, 52, 0, 7, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 52, 0, 7, 29, 0, 29, 7, 255, 244, 0, 0, 0, 0, 0,
0, 0, 0, 0, 36, 96, 0, 29, 208, 0, 43, 96, 0, 29, 208, 0, 36, 96, 0, 0, 0, 0,
0, 0, 0, 0, 12, 0, 0, 12, 0, 3, 255, 240, 0, 12, 0, 0, 12, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 6, 0, 0, 248, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12, 0,
0, 12, 0, 0, 12, 0, 0, 12, 0, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 240, 0, 7, 64, 0, 125,
0, 1, 208, 0, 31, 64, 0, 0, 0, 0, 0, 0, 0, 31, 255, 208, 48, 29, 48, 48, 116,
48, 49, 208, 48, 31, 255, 208, 0, 0, 0, 0, 0, 0, 48, 0, 48, 48, 0, 48, 63,
255, 240, 0, 0, 48, 0, 0, 48, 0, 0, 0, 0, 0, 0, 29, 7, 240, 48, 28, 48, 48,
52, 48, 48, 112, 48, 31, 208, 48, 0, 0, 0, 0, 0, 0, 28, 0, 208, 48, 48, 48,
48, 48, 48, 48, 48, 48, 31, 223, 208, 0, 0, 0, 0, 0, 0, 63, 255, 0, 0, 3, 0,
0, 3, 0, 0, 63, 240, 0, 3, 0, 0, 0, 0, 0, 0, 0, 63, 240, 208, 48, 48, 48, 48,
48, 48, 48, 48, 48, 48, 31, 208, 0, 0, 0, 0, 0, 0, 0, 191, 208, 11, 240, 48,
61, 48, 48, 0, 48, 48, 0, 31, 208, 0, 0, 0, 0, 0, 0, 48, 0, 0, 48, 0, 240,
48, 15, 64, 48, 244, 0, 63, 64, 0, 0, 0, 0, 0, 0, 0, 31, 223, 208, 48, 48,
48, 48, 48, 48, 48, 48, 48, 31, 223, 208, 0, 0, 0, 0, 0, 0, 31, 208, 0, 48,
48, 0, 48, 49, 240, 48, 63, 128, 31, 248, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 3, 192, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 3, 192,
248, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0, 125, 0, 1, 215, 64, 3, 65, 192,
7, 0, 208, 13, 0, 112, 0, 0, 0, 0, 0, 0, 3, 3, 0, 3, 3, 0, 3, 3, 0, 3, 3, 0,
3, 3, 0, 0, 0, 0, 0, 0, 0, 13, 0, 112, 7, 0, 208, 3, 65, 192, 1, 215, 0, 0,
125, 0, 0, 40, 0, 0, 0, 0, 31, 0, 0, 48, 0, 0, 48, 28, 240, 48, 112, 0, 31,
208, 0, 0, 0, 0, 0, 0, 0, 29, 31, 208, 48, 48, 48, 48, 47, 240, 48, 0, 48,
31, 255, 208, 0, 0, 0, 0, 0, 0, 7, 255, 240, 29, 3, 0, 52, 3, 0, 29, 3, 0, 7,
255, 240, 0, 0, 0, 0, 0, 0, 63, 255, 240, 48, 48, 48, 48, 48, 48, 48, 48, 48,
31, 223, 208, 0, 0, 0, 0, 0, 0, 31, 255, 208, 48, 0, 48, 48, 0, 48, 48, 0,
48, 28, 0, 208, 0, 0, 0, 0, 0, 0, 63, 255, 240, 48, 0, 48, 48, 0, 48, 52, 0,
112, 31, 255, 208, 0, 0, 0, 0, 0, 0, 63, 255, 240, 48, 48, 48, 48, 48, 48,
48, 48, 48, 48, 48, 48, 0, 0, 0, 0, 0, 0, 63, 255, 240, 48, 48, 0, 48, 48, 0,
48, 48, 0, 48, 48, 0, 0, 0, 0, 0, 0, 0, 31, 255, 208, 48, 0, 48, 48, 16, 48,
48, 48, 48, 28, 63, 240, 0, 0, 0, 0, 0, 0, 63, 255, 240, 0, 48, 0, 0, 48, 0,
0, 48, 0, 63, 255, 240, 0, 0, 0, 0, 0, 0, 48, 0, 48, 48, 0, 48, 63, 255, 240,
48, 0, 48, 48, 0, 48, 0, 0, 0, 0, 0, 0, 48, 0, 208, 48, 0, 48, 48, 0, 48, 48,
0, 48, 63, 255, 240, 0, 0, 0, 0, 0, 0, 63, 255, 240, 0, 48, 0, 0, 116, 0, 1,
221, 0, 63, 71, 240, 0, 0, 0, 0, 0, 0, 63, 255, 240, 0, 0, 48, 0, 0, 48, 0,
0, 48, 0, 0, 48, 0, 0, 0, 0, 0, 0, 63, 255, 240, 7, 64, 0, 1, 244, 0, 7, 64,
0, 63, 255, 240, 0, 0, 0, 0, 0, 0, 63, 255, 240, 7, 208, 0, 0, 116, 0, 0, 31,
64, 63, 255, 240, 0, 0, 0, 0, 0, 0, 31, 255, 208, 48, 0, 48, 48, 0, 48, 48,
0, 48, 31, 255, 208, 0, 0, 0, 0, 0, 0, 63, 255, 240, 48, 48, 0, 48, 48, 0,
48, 48, 0, 31, 208, 0, 0, 0, 0, 0, 0, 0, 31, 255, 208, 48, 0, 48, 48, 3, 240,
48, 0, 48, 31, 255, 208, 0, 0, 0, 0, 0, 0, 63, 255, 240, 48, 48, 0, 48, 60,
0, 48, 55, 0, 31, 209, 240, 0, 0, 0, 0, 0, 0, 31, 209, 208, 48, 112, 48, 48,
48, 48, 48, 28, 48, 29, 7, 208, 0, 0, 0, 0, 0, 0, 48, 0, 0, 48, 0, 0, 63,
255, 240, 48, 0, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 63, 255, 208, 0, 0, 48, 0, 0,
48, 0, 0, 48, 63, 255, 208, 0, 0, 0, 0, 0, 0, 63, 255, 64, 0, 1, 208, 0, 0,
48, 0, 1, 208, 63, 255, 64, 0, 0, 0, 0, 0, 0, 63, 255, 240, 0, 7, 64, 0, 61,
0, 0, 7, 64, 63, 255, 240, 0, 0, 0, 0, 0, 0, 63, 71, 240, 1, 221, 0, 0, 116,
0, 1, 221, 0, 63, 71, 240, 0, 0, 0, 0, 0, 0, 63, 64, 0, 1, 208, 0, 0, 127,
240, 1, 208, 0, 63, 64, 0, 0, 0, 0, 0, 0, 0, 48, 1, 240, 48, 15, 112, 48,
116, 48, 55, 208, 48, 61, 0, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63, 255, 252, 48,
0, 12, 48, 0, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 31, 64, 0, 1, 208, 0, 0, 125, 0,
0, 7, 64, 0, 1, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 12, 48, 0, 12, 63,
255, 252, 0, 0, 0, 0, 0, 0, };


/*JSON{
  "type" : "method",
  "class" : "Graphics",
  "name" : "setFontArchitekt12",
  "generate" : "jswrap_graphics_setFontArchitekt12",
  "params" : [
    ["scale","int","(optional) If >1 the font will be scaled up by that amount"]
  ],
  "return" : ["JsVar","The instance of Graphics this was called on, to allow call chaining"],
  "return_object" : "Graphics"
}
Set the current font to Neubau Architekt 12 (no lowercase glyphs)
*/
JsVar *jswrap_graphics_setFontArchitekt12(JsVar *parent, int scale) {
  if (scale<1) scale=1;
  JsVar *bitmap = jsvNewNativeString(fontBitmap, sizeof(fontBitmap));
  JsVar *widths = jsvNewFromInteger(7);
  JsVar *r = jswrap_graphics_setFontCustom(parent, bitmap, 32, widths, 12 + (scale<<8) + (2<<16)); // 2 bit
  jsvUnLock2(bitmap, widths);
  return r;
}