#!/bin/bash
set -e
echo "=== Compile generator ==="
g++ gen.cpp -o gen -std=c++14 -O2 -DNDEBUG

if [ -f "maxmin.cpp" ];then
    echo "=== Compile std maxmin.cpp ==="
    g++ maxmin.cpp -o maxmin_std -std=c++14 -O2 -DNDEBUG
else
    echo "Warning: maxmin.cpp not found, cannot generate .out files"
fi

echo "=== Run generator ==="
./gen
echo "Done!"
