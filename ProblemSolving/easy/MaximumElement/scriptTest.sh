#!/bin/bash

for i in 5
do
    echo "Test ${i}"
    ./a.out < testcase${i}.in > testcase${i}.out
    diff testcase${i}.out testcase${i}.answer | more
done
