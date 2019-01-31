#!/bin/bash

if [ $# -eq 0 ]
then
    echo "missing input file"
    $0 --help   #   call self with usage option

    exit
fi

while [ -n "$1" ]; do # while loop starts
    case "$1" in
        -h | -? | --help)
            echo "Usage:  setup.sh inputSourceFile"
            exit
            ;;
        *)
            if [ -n $1 ]; then
                inputFile=$1
            else
                echo "File: $1 does not exist"
                echo "Usage:"
                echo "setup.sh inputSourceFile"

                exit
            fi
            ;;
    esac

    shift
done

pwd=`pwd`
base=`basename $pwd`
parsed=${base:1}
firstLetter=${base:0:1}
lowerFirst=${firstLetter,,}
programName=$lowerFirst$parsed.cpp

if [ -e $inputFile ]
then
    clang-format $inputFile > $programName
    rm -f $inputFile
else
    echo "File $inputFile does not exist"
fi
