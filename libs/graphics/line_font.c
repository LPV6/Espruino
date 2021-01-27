/*
 * This file is part of Espruino, a JavaScript interpreter for Microcontrollers
 *
 * Copyright (C) 2020 Gordon Williams <gw@pur3.co.uk>
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * ----------------------------------------------------------------------------
 * Machine generated line font header (by build_line_font.js)
 * ----------------------------------------------------------------------------
 */

// FIXME - no need for poly abstraction here - can save a few bytes/some CPU cycles

#ifndef NO_LINE_FONT
#include "graphics.h"

static const uint8_t vfFirstChar = 48;
static const uint8_t vfLastChar = 62;
#define VF_CHAR_WIDTH 13
#define VF_SCALE 16
#define VF_OFFSET_Y (-11) // on centerline
#define VF_CHAR_SPACING 1
static const uint8_t vfPolyVerts[] IN_FLASH_MEMORY = {
  92,80,83,97,214,226,223,209,92,
  196,110,
  79,82,225,
  222,227,
  105,92,80,83,97,123,183,222,227,
  105,92,80,83,97,136,148,146,
  148,162,214,226,223,209,196,
  68,144,183,188,
  147,225,
  84,79,144,148,162,214,226,223,209,
  145,148,162,214,226,223,209,157,82,
  79,84,123,198,224,
  148,136,97,83,80,92,131,145,148,162,214,226,223,209,157,145,
  225,149,97,83,80,92,144,158,161,149,
  133,146,
  211,224,
  97,157,227,
  118,123,
  183,188,
  92,162,222
};
static const uint8_t vfPolyLengths[] IN_FLASH_MEMORY = {
  9,2,3,2,9,8,7,4,2,9,9,5,16,10,2,2,3,2,2,3
};
static const uint8_t vfCharPolys[] IN_FLASH_MEMORY = {
  0,1,
  2,3,
  4,
  5,6,
  7,8,
  9,
  10,
  11,
  12,
  13,
  14,15,
  16,
  17,18,
  19
};
static const uint8_t vfCharLengths[] IN_FLASH_MEMORY = {
  2,2,1,2,2,1,1,1,1,1,2,0,1,2,1
};

static const uint8_t *vfGetPolyPtr(unsigned char index, int *polyLen) {
  if (index >= sizeof(vfPolyLengths)) return NULL;

  *polyLen = vfPolyLengths[index];
  const uint8_t *ptr = vfPolyVerts;
  for (unsigned char i=0; i < index; ++i) {
    ptr += vfPolyLengths[i];
  }
  return ptr;
}

static const uint8_t *vfGetCharPtr(char sch, int *charLen) {
  unsigned char ch = (unsigned char)sch;
  if (ch<vfFirstChar || ch>vfLastChar) return NULL;
  ch = (unsigned char)(ch - vfFirstChar);

  const uint8_t *ptr = vfCharPolys;
  for (unsigned char i=0; i < ch; ++i) {
    ptr += vfCharLengths[i];
  }
  *charLen = vfCharLengths[ch];
  return ptr;
}

// prints character
static void vfDrawCharPtr(JsGraphics *gfx, int x1, int y1, int xdx, int xdy, const uint8_t *charPtr, int charLen) {
  int w = 0;
  for (int i = 0; i < charLen; ++i) {
    int polyLen;
    const uint8_t *p = vfGetPolyPtr(charPtr[i], &polyLen);
    int linex, liney, lastx, lasty;
    for (int j = 0; j < polyLen; ++j) {
      uint8_t vertex = p[j];
      int vx = vertex % VF_CHAR_WIDTH;
      int vy = (vertex / VF_CHAR_WIDTH) + VF_OFFSET_Y;
      if (vx>w) w=vx;
      linex = x1 + (vx*xdx - vy*xdy)/VF_SCALE;
      liney = y1 + (vx*xdy + vy*xdx)/VF_SCALE;
      if (j)
        graphicsDrawLineAA(gfx, lastx, lasty, linex, liney);
      lastx = linex;
      lasty = liney;
    }
  }
}

// prints character. xdx/xdy are vectors for X (values are all x16)
void graphicsDrawLineChar(JsGraphics *gfx, int x1, int y1, int xdx, int xdy, char ch) {
  int charLen;
  const uint8_t *charPtr = vfGetCharPtr(ch, &charLen);
  if (charPtr)
    vfDrawCharPtr(gfx, x1, y1, xdx, xdy, charPtr, charLen);
}

#endif
