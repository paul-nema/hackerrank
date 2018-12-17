#!/bin/bash

for i in A 0 3
do
    echo "Test ${i}"
    time ./a.out < testcase${i}.in > testcase${i}.out
    diff testcase${i}.out testcase${i}.answer | more
done
