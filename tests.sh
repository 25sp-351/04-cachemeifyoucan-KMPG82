#!/bin/bash

make

test_cases=(
  "1" "76" "34" "12" "77" "45" "23" "6" "34" "9" "15" "22" "53" "72"
)


for i in "${!test_cases[@]}"; 
do   
    output=$(echo "${test_cases[i]}" | ./policy_a options.txt)

    echo $((test_cases[i]))
    echo -e "${output}\n"
    
done

for i in "${!test_cases[@]}"; 
do   
    output=$(echo "${test_cases[i]}" | ./policy_b options.txt)

    echo $((test_cases[i]))
    echo -e "${output}\n"
    
done
