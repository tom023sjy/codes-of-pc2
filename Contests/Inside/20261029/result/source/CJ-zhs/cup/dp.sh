#!/bin/bash

nam="cup"

rand(){
    echo $(((RANDOM*32768+RANDOM)%($2-$1+1)+$1))
}


for ((i=1;i<=1000000;i++));do
    echo -n "Case #$i: "
    ./gen $(rand 1 10) 30 > $nam.in
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