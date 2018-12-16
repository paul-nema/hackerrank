#!/bin/bash

for i in 1 2 3
do
    echo "Test ${i}"
    ./a.out < testcase${i}.in > testcase${i}.out
    diff testcase${i}.out testcase${i}.answer | more
done

for i in A B
do
    echo "Test ${i}"
    ./a.out < testcase${i}.in > testcase${i}.out
    diff testcase${i}.out testcase${i}.answer | more
done
