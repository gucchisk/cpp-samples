#!/bin/bash

g++ -c -o main.o main.cc
echo "compile: g++ -c -o main.o main.cc"

if [ "$(uname)" == 'Darwin' ]; then
    ld main.o -lc -lc++ -o hello
    echo "link: ld main.o -lc -lc++ -o hello"
elif [ "$(expr substr $(uname -s) 1 5)" == 'Linux' ]; then
    if [ -e /etc/redhat-release ]; then
	VERSION=$(rpm --eval %{centos_ver})
	if [ $VERSION -eq 6 ]; then
	    LIBDIR="/usr/lib/gcc/x86_64-redhat-linux/4.4.7"
	elif [ $VERSION -eq 7 ]; then
	    LIBDIR="/usr/lib/gcc/x86_64-redhat-linux/4.8.5"
	fi
    fi
    ld main.o /usr/lib64/{crt1.o,crti.o} $LIBDIR/{crtbegin.o,crtend.o} /usr/lib64/crtn.o -lc -lstdc++ -L$LIBDIR -o hello -dynamic-linker /lib64/ld-linux-x86-64.so.2
    echo "link: ld main.o /usr/lib64/{crt1.o,crti.o} $LIBDIR/{crtbegin.o,crtend.o} /usr/lib64/crtn.o -lc -lstdc++ -L$LIBDIR -o hello -dynamic-linker /lib64/ld-linux-x86-64.so.2"
fi

    
    
    
