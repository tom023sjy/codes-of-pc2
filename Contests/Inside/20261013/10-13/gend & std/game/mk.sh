#!/bin/bash
set -e
echo "=== Compile generator ==="
g++ gen.cpp -o gen -std=c++14 -O2 -DNDEBUG

if [ -f "game.cpp" ];then
    echo "=== Compile std game.cpp ==="
    g++ game.cpp -o game_std -std=c++14 -O2 -DNDEBUG
else
    echo "Warning: game.cpp not found, cannot generate .out files"
fi

echo "=== Run generator ==="
./gen
echo "Done!"
