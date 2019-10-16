FROM ubuntu:18.04

RUN apt-get update && \
    apt-get -y install git python-pip build-essential openjdk-11-jdk-headless && \
    git clone --depth 1 https://github.com/sidec/hvcc.git /opt/hvcc && \
    git clone --depth 1 https://github.com/emscripten-core/emsdk.git /opt/hvcc/generators/c2js/emsdk && \
    cd /opt/hvcc &&  pip install -r requirements.txt && \
    cd /opt/hvcc/generators/c2js/emsdk && \
    sh emsdk install emscripten-1.37.38 && sh emsdk install clang-e1.37.38-64bit  && \
    sh emsdk activate emscripten-1.37.38 && sh emsdk activate clang-e1.37.38-64bit && \ 
    sh emsdk install node-8.9.1-64bit && sh emsdk activate node-8.9.1-64bit && \
    echo "JAVA = 'java'" >> /root/.emscripten

WORKDIR /opt/hvcc

ENTRYPOINT [ "/usr/bin/python2.7", "hvcc.py", "-g", "js"]
