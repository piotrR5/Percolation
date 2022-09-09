#! /bin/bash
echo compiling
g++ main.cpp src/p.cpp -o percolation -lfmt
if test -f "percolation"; then
    echo compilation complete
else
    echo compilation failed
fi
