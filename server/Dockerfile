FROM node:alpine
# docker run -e WS_PORT=8081 -e UDP_PORT=57121 -it -p 8081:8081 -p 57121:57121 thoushalt/osc


ENV UDP_PORT 57121
ENV WS_PORT 8081

RUN mkdir -p /opt/app

WORKDIR /opt/app

COPY index.js index.js
COPY package.json package.json

RUN apk add make g++ python linux-headers udev && npm install && \
    apk del make g++ python linux-headers udev

ENTRYPOINT node index.js
