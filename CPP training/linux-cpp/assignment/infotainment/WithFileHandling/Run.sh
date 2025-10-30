#!/bin/bash

# Compile the C++ code
g++ -c -fPIC FileRead.cpp -o FileRead.o
if [ $? -eq 0 ]; then
    g++ -shared -o libFileRead.so FileRead.o
    if [ $? -eq 0 ]; then
        g++ main.cpp -L. -lFileRead -o exe
        if [ $? -eq 0 ]; then
            LD_LIBRARY_PATH=. ./exe
        else
            echo " Linking library failed"
        fi
    else
        echo "shared library creation failed"
    fi
else
    echo "Object file generation failed"
fi