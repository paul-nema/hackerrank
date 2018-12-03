#!/bin/bash

for i in 0 1 2
do
    echo "Test ${i}"
    ./a.out < testcase${i}.sample > testcase${i}.out
    diff testcase${i}.out testcase${i}.answer
done
