#!/bin/bash

isNumber() {
    if [[ $1 =~ ^[0-9]+$ ]]; then
        return 0 # true
    else
        return 1 # false
    fi
}

read -p "Enter number: " input

while true; do
    if isNumber "$input"; then
        a=$input
        if (( a > 0 )); then
            break
        else 
            read -p "Invalid input, enter a positive number: " input
        fi
    else
        read -p "Please enter a valid number, no letters: " input
    fi
done

for (( i = 0; i < a; i++ )); do
    for (( j = 0; j <= i; j++)); do
        printf " # "
    done
    echo
done
