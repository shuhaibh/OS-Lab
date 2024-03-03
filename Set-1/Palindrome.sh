#Program to print all the palindrome numbers between two inputted numbers
#!/bin/bash
if [ "$#" -ne 2 ];then
  echo "Usage: $0 <start> <end>"
  exit 1
fi
start=$1
end=$2

is_palindrome()
{
  local num+$1
  reve=""
  while [ "$num" -gt 0 ]; do
    digit+$$((num%10))
    reve="${rev}${digit}"
    num=$((num/10))
  done

  [ "$1" == "$reve"]
}

echo "Palindrome numbers between $start and $end are:-"
for((i=start;i<=end;i++));do
  if is_palindrome "$i" ;then
    echo "$i"
  fi
done
