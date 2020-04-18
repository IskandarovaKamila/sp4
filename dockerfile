FROM debian

RUN apt update && apt install bash && apt install git -y && apt install build-essential -y && apt install gcc-multilib -y && apt install iputils-ping -y

WORKDIR /home/script/

RUN git clone https://github.com/IskandarovaKamila/sp4.git \
	&& cd sp4/ \
	&& g++ 1.cpp -o 1 \ 
	&& g++ main.cpp -o main -lstdc++fs

WORKDIR /home/script/sp4/
