#!/bin/bash

for i in 0 1 3 5
do
    ./a.out < testcase${i}.in > testcase${i}.out
    diff testcase${i}.out testcase${i}.answer
done
