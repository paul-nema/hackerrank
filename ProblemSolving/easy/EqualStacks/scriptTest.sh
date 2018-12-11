#!/bin/bash

for i in 1
do
    echo "Test ${i}"
    ./a.out < testcase${i}.in > testcase${i}.out
    diff testcase${i}.out testcase${i}.answer
done
