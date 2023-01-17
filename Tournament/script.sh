#!/bin/bash

for((i = 1; i <= 1000000; i++))
do 
    echo "test $i"
    ./message < testyTurniej/in/in$i > output
    diff testyTurniej/out/out$i output || break
done