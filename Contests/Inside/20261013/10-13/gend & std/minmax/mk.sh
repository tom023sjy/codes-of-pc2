#!/bin/bash
set -e
# 编译数据生成器
g++ gen.cpp -o gen -std=c++14 -O2 -DNDEBUG
# 编译std（minmax.cpp）
g++ minmax.cpp -o std -std=c++14 -O2 -DNDEBUG
# 生成所有in
./gen
# 批量跑std生成out
for i in {1..25}; do
    ./std < minmax${i}.in > minmax${i}.out
done
echo "All done!"
