#!/bin/bash

$j = 1
for ((i=1;i<=100;i++))
do
        while (((`expr $j % 2` != 0) | (j != i)))
        do
                $j = `expr $j + 1`
        done
        if (( j = i )) 
        then
                echo i
                $j = 1
        fi
done

