#Program to print n terms of fibonacci series
#!/bin/bash
read -p "Enter the value of n:-"
fibonnaci()
{
  a=0
  b=0
  for((i=0;i<n;i++));do
    echo -n "$a "
    temp=$((a+b))
    a=$b
    b=$temp
  done
}
echo "Fibonacci series:"
fibonacci
echo ""
