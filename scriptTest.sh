#!/bin/bash

#   For each *.answer file, find the input file
#   run it through a.out. Capture output in name.out
#   and diff it with the .answer file
for i in *.answer
do
    name=`echo $i | cut -d'.' -f1`
    echo ${name}
    ./a.out < ${name}.in > ${name}.out
    diff ${name}.out ${name}.answer
done
