#!/bin/bash
docker run -v $(pwd):/opt/hvcc/tmp sidec/hvcc-c2js:latest -o /opt/hvcc/tmp/$1 -n $1 /opt/hvcc/tmp/$2
