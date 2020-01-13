#!/bin/bash

g++ -c -o main.o main.cc

if [ "$(uname)" == 'Darwin' ]; then
    ld main.o -lc -lc++ -o hello
elif [ "$(expr substr $(uname -s) 1 5)" == 'Linux' ]; then
    ld main.o -lc -lstdc++ -o hello
fi

    
    
    
