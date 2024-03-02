#Program to check whether a word is present in a file
#!/bin/bash

read -p "Enter the filename:-" filename
read -p "Enter the word to search:-" search

if [ -e "$filename" ]; then
  if grep -q "$search" "$filename";then
    echo "The word '$search' is found in '$filename'. "
  else
    echo "The word '$search' is not found in '$filename'. "
  fi
else
  echo "File '$filename' is not found. "
if
