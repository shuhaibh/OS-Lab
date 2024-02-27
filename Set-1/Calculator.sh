#PrograM to Implement a simple calculator 
#!/bin/bash
while :
do
  read -p "Enter first number:-" numi
  read -p "Enter Second number:-" num2
  echo "----CaLculator:----"
  echo "1)Add"
  echo "2)Subtract"
  echo "3)Multiply"
  echo "4)Divide"
  echo "5)Modulus"
  echo "6) Exit"
  read -p "Enter your cholce(1,2,3,4,5,6)" choice
  case $choice in
  1)
    result=$(($num1 + $nun2))
    echo "Result: $result"
    ;;
  2)
    result=$(($num1 - $nun2))
    echo "Result: $result"
    ;;
  3)
    result=$(($num1 * $nun2))
    echo "Result: $result"
    ;;
  4)
    result=$(($num1 / $nun2))
    echo "Result: $result"
    ;;
  5)
    result=$(($num1 % $nun2))
    echo "Result: $result"
    ;;
  6)
    echo "Exiting..."
    exit 0
    ;;
  *)
    echo "Invalid choice!"
    exit 1
    ;;
  esac
done
