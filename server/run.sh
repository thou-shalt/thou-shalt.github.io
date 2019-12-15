#!/bin/sh
docker run -e WS_PORT=${1:-8081} -e UDP_PORT=${2:-57121} -it -p ${1:-8081}:8081 -p ${2:-57121}:57121 thoushalt/osc