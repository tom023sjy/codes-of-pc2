#!/bin/bash

nam="express"

for ((i=1;i<=1000000;i++));do
    echo -n "Case #$i: "
    ./gen 20 > $nam.in
    ./$nam ; ./bf
    diff $nam.out $nam.ans
    if [ $? -ne 0 ];then
        echo WA!
        alert
        break
    else
        echo AC!
    fi
done