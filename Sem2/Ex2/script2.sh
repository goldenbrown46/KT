#!/bin/bash
echo $#
echo $0
echo $1
echo $2

if [ $# -ne 2 ]
then
	echo "error"
	exit 1
fi

name=$1$2

touch $name
cat $1 >> $name
cat $2 >> $name

