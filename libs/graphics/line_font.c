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

#ifndef NO_LINE_FONT
#include "graphics.h"

static const uint8_t vfFirstChar = 48;
static const uint8_t vfLastChar = 62;
#define VF_CHAR_WIDTH 13
#define VF_SCALE 16
#define VF_OFFSET_Y (-2)
#define VF_CHAR_SPACING 1
static const uint8_t vfPolyVerts[] IN_FLASH_MEMORY = {
  80,83,97,214,226,223,209,92,92,
  110,196,
  79,82,225,
  222,227,
  80,83,97,123,183,222,227,105,92,
  80,83,97,136,148,146,105,92,
  148,162,214,226,223,209,196,
  68,144,183,188,
  147,225,
  79,84,209,223,226,214,162,148,144,
  82,145,148,162,214,226,223,209,157,
  79,84,123,198,224,
  80,83,97,136,148,145,157,209,223,226,214,162,148,145,131,92,
  80,83,97,149,225,149,161,158,144,92,
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

// prints character, returns width
static unsigned int vfDrawCharPtr(JsGraphics *gfx, int x1, int y1, int size, const uint8_t *charPtr, int charLen) {
  x1 = (x1<<4) - 8;
  y1 = (y1<<4) - 8;
  int w = 0;
  for (int i = 0; i < charLen; ++i) {
    int polyLen;
    const uint8_t *p = vfGetPolyPtr(charPtr[i], &polyLen);
    int linex, liney, lastx, lasty;
    for (int j = 0; j < polyLen; ++j) {
      uint8_t vertex = p[j];
      int vx = vertex % VF_CHAR_WIDTH;
      int vy = vertex / VF_CHAR_WIDTH;
      if (vx>w) w=vx;
      linex = (x1*16 + vx*size*256/VF_SCALE);
      liney = (y1*16 + (vy+VF_OFFSET_Y)*size*256/VF_SCALE);
      if (j) graphicsDrawLineAA(gfx, linex, liney, lastx, lasty);
      lastx = linex;
      lasty = liney;
    }
  }
  return (unsigned int)(((w+1+VF_CHAR_SPACING)*size*16/VF_SCALE+7)>>4);
}

// returns the width of a character
unsigned int graphicsLineCharWidth(JsGraphics *gfx, unsigned int size, char ch) {
  NOT_USED(gfx);
  int charLen;
  const uint8_t *charPtr = vfGetCharPtr(ch, &charLen);
  if (!charPtr) return (unsigned int)(size/2);
  int w = 0;
  for (int i = 0; i < charLen; ++i) {
    int polyLen;
    const uint8_t *p = vfGetPolyPtr(charPtr[i], &polyLen);
    for (int j = 0; j < polyLen; ++j) {
      uint8_t vertex = p[j];
      int vx = vertex % VF_CHAR_WIDTH;
      if (vx>w) w=vx;
    }
  }
  return ((unsigned int)(w+1+VF_CHAR_SPACING)*size*16/VF_SCALE+7)>>4;
}

// prints character, returns width
unsigned int graphicsDrawLineChar(JsGraphics *gfx, int x1, int y1, int size, char ch) {
  int charLen;
  const uint8_t *charPtr = vfGetCharPtr(ch, &charLen);
  if (!charPtr) return (unsigned int)(size/2);
  return vfDrawCharPtr(gfx, x1, y1, size, charPtr, charLen);
}

#endif
