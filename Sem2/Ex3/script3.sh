#!/bin/bash
echo $#
echo $0
echo $1
echo $2

if [ $# -ne 2 ]
then
	echo "incorrect count of args"
	exit 1
fi

if [ -d $1 ]
then
	folder_owner=$(stat -c '%U' $1)
else
	echo "folder does not exist"
	exit 1
fi

if [ -e $2 ]
then
	file_owner=$(stat -c '%U' $2)
else
	echo "file does not exist"
	exit 1
fi

if [ $folder_owner = $file_owner ]
then
	cp $2 $1
else
	echo "different users"
fi
