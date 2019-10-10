FROM node:alpine

ENV UDP_PORT 57121
ENV WS_PORT 8081

RUN mkdir -p /opt/app

WORKDIR /opt/app

COPY index.js index.js 
COPY package.json package.json

RUN apk add make g++ python linux-headers udev && npm install 

ENTRYPOINT node index.js