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

static const uint8_t vfFirstChar = 33;
static const uint8_t vfLastChar = 96;
#define VF_CHAR_WIDTH 13
#define VF_SCALE 16
#define VF_OFFSET_Y (-11) // on centerline
#define VF_CHAR_SPACING 1
static const uint8_t vfPolyVerts[] IN_FLASH_MEMORY = {
  81,185,
  211,224,
  80,119,
  83,122,
  80,223,
  83,226,
  118,123,
  183,188,
  110,97,83,80,92,118,175,201,213,210,196,183,
  55,81,
  212,238,
  222,84,
  91,79,80,94,107,119,118,104,91,
  199,187,188,202,215,227,226,212,199,
  227,105,92,80,82,96,109,183,209,223,225,188,
  82,95,119,
  82,94,211,225,
  81,95,212,224,
  132,83,
  80,135,
  94,198,
  143,149,
  199,212,237,
  144,149,
  212,211,224,225,212,
  84,97,209,222,
  92,80,83,97,214,226,223,209,92,
  196,110,
  79,82,225,
  222,227,
  105,92,80,83,97,123,183,222,227,
  105,92,80,83,97,136,148,146,
  148,162,214,226,223,209,196,
  68,144,183,188,
  147,225,
  84,79,144,148,162,214,226,223,209,196,
  145,148,162,214,226,223,209,157,82,
  79,84,123,198,224,
  148,136,97,83,80,92,131,145,148,162,214,226,223,209,157,145,
  225,149,97,83,80,92,144,158,161,149,
  133,146,
  198,211,236,
  97,157,227,
  92,162,222,
  105,92,80,83,97,123,159,185,
  105,92,80,83,97,214,226,223,209,170,158,159,173,225,
  222,157,81,82,162,227,
  148,144,
  222,79,83,97,136,148,162,214,226,222,
  110,97,83,80,92,209,223,226,214,201,
  222,79,83,97,214,226,222,
  84,79,222,227,
  222,79,84,
  110,97,83,80,92,209,223,226,214,162,160,
  79,222,
  84,227,
  79,83,
  81,224,
  222,226,
  79,84,214,226,223,209,196,
  144,146,201,227,
  84,97,146,
  79,222,227,
  222,79,133,134,84,227,
  222,79,227,84,
  222,79,83,97,136,148,144,
  209,92,80,83,97,214,226,223,209,
  225,186,
  146,201,227,
  110,97,83,80,92,118,188,214,226,223,209,196,
  78,84,
  84,214,226,223,209,79,
  84,162,225,224,157,79,
  84,227,173,172,222,79,
  79,92,214,227,
  78,91,159,97,84,
  159,224,
  79,84,222,227,
  82,80,223,225,
  80,82,225,223,
  144,81,148,
  29,42,70
};
static const uint8_t vfPolyLengths[] IN_FLASH_MEMORY = {
  2,2,2,2,2,2,2,2,12,2,2,2,9,9,12,3,4,4,2,2,2,2,3,2,5,4,9,2,3,2,9,8,7,4,2,10,9,5,16,10,2,3,3,3,8,14,6,2,10,10,7,4,3,11,2,2,2,2,2,7,4,3,3,6,4,7,9,2,3,12,2,6,6,6,4,5,2,4,4,4,3,3
};
static const uint8_t vfCharPolys[] IN_FLASH_MEMORY = {
  0,1,
  2,3,
  4,5,6,7,
  8,9,10,
  11,12,13,
  14,
  15,
  16,
  17,
  18,19,
  20,21,
  22,
  23,
  24,
  25,
  26,27,
  28,29,
  30,
  31,32,
  33,34,
  35,
  36,
  37,
  38,
  39,
  40,1,
  40,41,
  42,
  6,7,
  43,
  44,1,
  45,
  46,7,
  47,48,
  49,
  50,
  51,23,
  52,23,
  53,
  54,55,23,
  56,57,58,
  59,
  54,60,61,
  62,
  63,
  64,
  26,
  65,
  66,67,
  65,68,
  69,
  70,57,
  71,
  72,
  73,
  74,25,
  75,76,
  77,
  78,
  74,
  79,
  80,
  29,
  81
};
static const uint8_t vfCharLengths[] IN_FLASH_MEMORY = {
  2,2,4,3,3,1,1,1,1,2,2,1,1,1,1,2,2,1,2,2,1,1,1,1,1,2,2,1,2,1,2,1,2,2,1,1,2,2,1,3,3,1,3,1,1,1,1,1,2,2,1,2,1,1,1,2,2,1,1,1,1,1,1,1
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
