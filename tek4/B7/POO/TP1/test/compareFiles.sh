#!/bin/zsh

# Check if the correct number of arguments (two file paths) is provided
if [ "$#" -ne 2 ]; then
  echo "Usage: $0 file1 file2"
  exit 1
fi

file1="$1"
file2="$2"

# Use the 'diff' command to compare the two files
if diff "$file1" "$file2" >/dev/null; then
  echo "The files '$file1' and '$file2' are identical."
else
  echo "The files '$file1' and '$file2' are different."
fi
