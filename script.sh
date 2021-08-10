#!/usr/bin/bash

name=$1
if [[ -n $name &&  ($# -eq 1) ]]; then
  cat $name | while read line;
  do
    ./push_swap $line | ./checker $line
  done

  cat $name | while read line; do
    ./push_swap $line | wc -l
  done
else
  echo "must have one filename parameter"
fi
