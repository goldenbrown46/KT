#!/bin/bash
echo $#
echo $0
echo $1
echo $2
echo $3

if [ $# -ne 3 ]
then
	echo "incorrect count of args"
	exit 1
fi

ave=$((($1 + $2 + $3) / 3))
echo "avergae of args: $ave"
