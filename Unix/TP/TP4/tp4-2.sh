#!/bin/bash

echo "$1 $2 $3"

if (( $1 >= $2 ))
then
	if (( $1 >= $3 ))
	then
		echo "$1"
	else
		echo "$3"
	fi
else
	if (( $2 > $3 ))
        then
                echo "$2"
        else
                echo "$3"
	fi
fi
			
