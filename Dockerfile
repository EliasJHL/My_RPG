FROM ubuntu:latest

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install -y gcc make libcsfml-dev libx11-6
RUN export DISPLAY=:99
RUN sudo Xvfb -ac :99 -screen 0 1280x1024x24 > /dev/null 2>&1 &

COPY . /app
WORKDIR /app

RUN make

RUN make clean

CMD ["./my_rpg"]