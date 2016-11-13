#!/bin/bash

echo "[ BSHS ] Kompilieren..."
i686-w64-mingw32-g++ -static-libgcc -o bin/ny6.exe main.cpp

echo " >> Fertig!"
