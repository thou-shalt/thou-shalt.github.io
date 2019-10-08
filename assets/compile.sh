#!/bin/bash
docker run -v $(pwd):/opt/hvcc/tmp sidec/hvcc-c2js:latest -o /opt/hvcc/tmp/ThouShalt -n ThouShalt /opt/hvcc/tmp/patch.pd
