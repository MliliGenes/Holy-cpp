#!/bin/bash

echo "=== Test 1: Small sorted input ==="
./PmergeMe 1 2 3 4 5
echo ""

echo "=== Test 2: Small reverse input ==="
./PmergeMe 5 4 3 2 1
echo ""

echo "=== Test 3: Medium random input ==="
./PmergeMe 3 5 9 7 4 2 8 1 6
echo ""

echo "=== Test 4: Larger set (30 numbers) ==="
./PmergeMe 5 4 3 2 1 15 14 13 12 11 10 25 24 23 22 21 20 35 34 33 32 31 30 45 44 43 42 41 40
echo ""

echo "=== Test 5: 50 random numbers ==="
seq 1 100 | shuf | head -n 50 | tr '\n' ' ' | xargs ./PmergeMe
