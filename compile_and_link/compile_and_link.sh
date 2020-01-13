#!/bin/bash

g++ -c -o main.o main.cc
echo "compile: g++ -c -o main.o main.cc"

if [ "$(uname)" == 'Darwin' ]; then
    ld main.o -lc -lc++ -o hello
elif [ "$(expr substr $(uname -s) 1 5)" == 'Linux' ]; then
    if [ -e /etc/redhat-release ]; then
	VERSION=$(rpm --eval %{centos_ver})
	if [ $VERSION -eq 6 ]; then
	    LIBDIR="/usr/lib/gcc/x86_64-redhat-linux/4.4.7"
	    LINKER="/lib64/ld-2.12.so"
	fi
    fi
    ld main.o /usr/lib64/{crt1.o,crti.o} $LIBDIR/{crtbegin.o,crtend.o} /usr/lib64/crtn.o -lc -lstdc++ -L$LIBDIR -o hello -dynamic-linker $LINKER
    echo "link: ld main.o /usr/lib64/{crt1.o,crti.o} $LIBDIR/{crtbegin.o,crtend.o} /usr/lib64/crtn.o -lc -lstdc++ -L$LIBDIR -o hello -dynamic-linker $LINKER"
fi

    
    
    
