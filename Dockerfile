FROM ubuntu:latest

WORKDIR /MolecularBox

COPY include ./include
COPY src ./src
COPY tests ./tests
COPY CMakeLists.txt .

COPY requirements_ubuntu.sh .
COPY build.sh .

RUN apt-get update
RUN apt-get install -y sudo 
RUN ./requirements_ubuntu.sh
RUN ./build.sh