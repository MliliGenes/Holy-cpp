#!/bin/bash

# Test with various sizes
for size in 10 25 50 100 150 200; do
    echo "Testing with $size elements..."
    
    # Generate random numbers and sort them
    input=$(seq 1 1000 | shuf | head -n $size | tr '\n' ' ')
    output=$(echo $input | xargs ./PmergeMe 2>&1)
    
    # Extract the "After:" line
    after_line=$(echo "$output" | grep "After:")
    sorted_nums=$(echo "$after_line" | sed 's/After:\t//')
    
    # Verify sorting
    is_sorted=true
    prev=-1
    for num in $sorted_nums; do
        if [ $prev -ge $num ]; then
            is_sorted=false
            echo "  ❌ FAILED: Found $prev before $num (not sorted!)"
            break
        fi
        prev=$num
    done
    
    if [ "$is_sorted" = true ]; then
        echo "  ✅ PASSED: Output is correctly sorted"
    fi
    
    # Show timing
    echo "$output" | grep "Time to process"
    echo ""
done
