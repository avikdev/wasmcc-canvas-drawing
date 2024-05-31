#!/bin/sh

EMS_BINDIR="/Users/avikpaul/github/emsdk/upstream/emscripten"

${EMS_BINDIR}/emcmake cmake src-cc &&
${EMS_BINDIR}/emmake make all &&
cp -f dist/starter-wasm.js dist/starter-wasm.wasm src-fe/wasm
