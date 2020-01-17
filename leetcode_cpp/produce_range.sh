#!/bin/bash
echo $0
echo $1
echo $2
count=$1
while (($count<$2))
do 
  python3 produce_file.py $count
  echo $count
  let "count++"
done