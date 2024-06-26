#!/usr/bin/env node
/* This is a big hack - we take a hex file and turn it into 
Espruino commands that write the memory directly via JS. Can
be used to do bootloader updates/etc.

ASSUMES 4K PAGES
*/

var PAGESIZE = 4096;

if (process.argv.length!=3) {
  console.error("USAGE: hextojs.js inputfile.hex");
  process.exit(1);
}

var inputFile = process.argv[2];

var hex = require("fs").readFileSync(inputFile).toString().split("\n");
function parseLines(dataCallback) {
  var addrHi = 0;
  hex.forEach(function(hexline) {
    if (DEBUG) console.log(hexline);
    var bytes = hexline.substr(1,2);
    var addrLo = parseInt(hexline.substr(3,4),16);
    var cmd = hexline.substr(7,2);
    if (cmd=="02") addrHi = parseInt(hexline.substr(9,4),16) << 4; // Extended Segment Address
    else if (cmd=="04") addrHi = parseInt(hexline.substr(9,4),16) << 16; // Extended Linear Address
    else if (cmd=="00") {
      var addr = addrHi + addrLo;
      var data = [];
      for (var i=0;i<16;i++) data.push(parseInt(hexline.substr(9+(i*2),2),16));
      dataCallback(addr,data);
    }
  });
}

console.log('var f = require("Flash");');
var erasedPages = [];
parseLines(function(addr, data) {
  var page = addr & ~(PAGESIZE-1);
  if (erasedPages.indexOf(page) < 0) {
    console.log('f.erasePage(0x'+page.toString(16)+');');
    erasedPages.push(page);
  }
});
parseLines(function(addr, data) {
  // don't output stuff which is all 255
  if (data.reduce((a,b)=>a+b) == data.length*255) return;    
  console.log('f.write(['+data+'],0x'+addr.toString(16)+');');
});
