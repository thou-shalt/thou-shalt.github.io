#!/bin/bash
docker run -v $(pwd):/opt/hvcc/tmp sidec/hvcc-c2js:latest -o /opt/hvcc/tmp/$1 -n $1 /opt/hvcc/tmp/$2 && \
    cp $1/js/$1.wasm $1/js/$1.asm.js ../

