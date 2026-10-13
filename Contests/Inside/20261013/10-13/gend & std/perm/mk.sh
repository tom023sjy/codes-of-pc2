#!/bin/bash
set -e
echo "=== Compile generator ==="
g++ gen.cpp -o gen -std=c++14 -O2 -DNDEBUG

if [ -f "perm.cpp" ];then
    echo "=== Compile std perm.cpp ==="
    g++ perm.cpp -o perm_std -std=c++14 -O2 -DNDEBUG
else
    echo "Warning: perm.cpp not found, cannot generate .out files"
fi

echo "=== Run generator ==="
./gen
echo "Done!"
