#!/bin/bash

# Compile the C++ files
g++ gen.cpp -o gen
g++ test.cpp -DLOCAL -o test
g++ brute.cpp -o brute

# Initialize test case counter
counter=0

# Function to run a single test case
run_test() {
    # Increment the counter
    ((counter++))
    
    # Generate the input
    ./gen
    
    # Run the real solution
    ./test
    
    # Run the brute force solution
    ./brute
    
    # Compare the outputs, ignoring whitespace and blank lines
    if ! diff --ignore-space-change --ignore-blank-lines test.out test2.out > /dev/null; then
        echo -e "\nMismatch found after $counter test cases!"
        echo -e "\nInput:"
        cat test.in
        echo -e "\nOutput from test.cpp:"
        cat test.out
        echo -e "\nOutput from brute.cpp:"
        cat test2.out
        exit 1
    fi
    
    # Print the number of test cases run so far
    echo "Test case $counter passed"
}

# Main loop for stress testing
while true; do
    run_test
done
