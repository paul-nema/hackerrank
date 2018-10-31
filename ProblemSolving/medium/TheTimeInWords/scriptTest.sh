#!/bin/bash

for i in {0..59};
do
    echo 10 > testcase.in
    echo $i >> testcase.in
    cat testcase.in
    ./a.out < testcase.in
    echo
done
