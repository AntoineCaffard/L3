#!/bin/bash


if [ `expr $1 % 2` = 0 ]
then
	echo "$1 est pair"
else
	echo "$1 est impair"
fi

