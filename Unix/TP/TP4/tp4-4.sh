#!/bin/bash

for (( i=2;i<$1;i++))
do
	if ((`expr $1 % $i` == 0))
	then
		echo False
		exit 0
	fi
done
echo True
exit 0

