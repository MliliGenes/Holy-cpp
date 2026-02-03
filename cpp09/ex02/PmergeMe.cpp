#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
#include <set>
#include <sys/time.h>

// Print vector of integers
void printVector(const std::vector<int>& vec, const std::string& label) {
    std::cout << label;
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i];
        if (i < vec.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

// Print vector of pairs
void printPairs(const std::vector<std::pair<int, int> >& pairs, const std::string& label) {
    std::cout << label;
    for (size_t i = 0; i < pairs.size(); i++) {
        std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ")";
        if (i < pairs.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

double PmergeMe::getTime() {
    struct timeval time;
    gettimeofday(&time, NULL);
    return time.tv_sec * 1000000.0 + time.tv_usec;
}

size_t PmergeMe::jacobsthal(size_t n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    size_t prev2 = 0;
    size_t prev1 = 1;
    size_t current = 1;
    
    for (size_t i = 2; i <= n; i++) {
        current = prev1 + 2 * prev2;
        prev2 = prev1;
        prev1 = current;
    }
    
    return current;
}

std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t size) {
    std::vector<size_t> sequence;
    
    size_t index = 3;
    
    while (true) {
        size_t jacob = jacobsthal(index);
        if (jacob >= size)
            break;
        sequence.push_back(jacob);
        index++;
    }
    
    return sequence;
}

PmergeMe::PmergeMe() : vecTime(0), deqTime(0) {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    original = other.original;
    vec = other.vec;
    deq = other.deq;
    vecTime = other.vecTime;
    deqTime = other.deqTime;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        original = other.original;
        vec = other.vec;
        deq = other.deq;
        vecTime = other.vecTime;
        deqTime = other.deqTime;
    }
    return *this;
}

void PmergeMe::sort() {
    double start, end;
    
    // Time vector sorting
    start = getTime();
    fordJohnsonVector();
    end = getTime();
    vecTime = end - start;
    
    // TODO: Time deque sorting
    // start = getTime();
    // fordJohnsonDeque();
    // end = getTime();
    // deqTime = end - start;
}

bool PmergeMe::initialize(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: No input provided" << std::endl;
        return false;
    }
    return parseArguments(argc, argv);
}

bool PmergeMe::isValidNumber(const std::string& str) {
    if (str.empty())
        return false;
    
    if (str[0] == '-')
        return false;
    
    size_t start = 0;
    if (str[0] == '+')
        start = 1;
    
    if (start >= str.length())
        return false;
    
    for (size_t i = start; i < str.length(); i++) {
        if (!std::isdigit(str[i]))
            return false;
    }
    
    return true;
}

bool PmergeMe::parseArguments(int argc, char** argv) {
    std::set<int> seen;
    
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        
        // Validate format
        if (!isValidNumber(arg)) {
            std::cerr << "Error" << std::endl;
            return false;
        }
        
        std::stringstream ss(arg);
        long number;
        ss >> number;
        
        if (ss.fail()) {
            std::cerr << "Error" << std::endl;
            return false;
        }
        
        if (number <= 0 || number > 2147483647) { // INT_MAX
            std::cerr << "Error" << std::endl;
            return false;
        }
        
        int value = static_cast<int>(number);

        if (seen.find(value) != seen.end()) {
            std::cerr << "Error" << std::endl;
            return false;
        }
        seen.insert(value);

        original.push_back(value);
        vec.push_back(value);
        deq.push_back(value);
    }
    printVector(original, "Before: ");
    return true;
}

void PmergeMe::fordJohnsonVector() {
    if (vec.size() <= 1)
        return;

    int straggler = -1;
    std::vector<int> mainChain;
    std::vector<int> pend;
    std::vector<size_t> pendPairedPos;  // NEW: Track paired positions

    // Step 1: Create pairs
    std::vector<std::pair<int, int> > pairs = createPairsVector(straggler);
    
    // Step 2: Sort pairs by larger element
    std::sort(pairs.begin(), pairs.end(), comparePairs);

    // Step 3: Build main chain and pend with paired positions
    buildChainsVector(pairs, mainChain, pend, pendPairedPos);

    // TODO: rm later
    printVector(mainChain, "Main chain: ");
    printVector(pend, "Pend chain: ");

    // Step 4: Insert pend elements using Jacobsthal order
    insertPendVector(mainChain, pend, pendPairedPos);

    if (straggler != -1)
        binaryInsertVector(mainChain, straggler, 0, mainChain.size());

    // Update vec with sorted result
    vec = mainChain;
}

std::vector<std::pair<int, int> > PmergeMe::createPairsVector(int& straggler) {
    std::vector<std::pair<int, int> > pairs;
    
    for (size_t i = 0; i + 1 < vec.size(); i += 2) {
        int a = vec[i];
        int b = vec[i + 1];
        // One-liner: pair is always (min, max)
        pairs.push_back(a < b ? std::make_pair(a, b) : std::make_pair(b, a));
    }
    
    if (vec.size() % 2 == 1)
        straggler = vec[vec.size() - 1];
    
    return pairs;
}

bool PmergeMe::comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second < b.second;
}

void PmergeMe::sortPairsvector(std::vector<std::pair<int, int> >& pairs) {
    std::sort(pairs.begin(), pairs.end(), comparePairs);
}

void PmergeMe::buildChainsVector(const std::vector<std::pair<int, int> >& pairs, 
                            std::vector<int>& mainChain, 
                            std::vector<int>& pend,
                            std::vector<size_t>& pendPairedPos) {  // NEW!
    if (pairs.empty())
        return;
    
    // Add both elements from the first pair
    mainChain.push_back(pairs[0].first);
    mainChain.push_back(pairs[0].second);
    
    // Start from index 1
    for (size_t i = 1; i < pairs.size(); i++) {
        pend.push_back(pairs[i].first);           // Add smaller element
        pendPairedPos.push_back(mainChain.size()); // Remember position BEFORE adding larger
        mainChain.push_back(pairs[i].second);     // Add larger element
    }
}

void PmergeMe::insertPendVector(std::vector<int>& mainChain,
                                const std::vector<int>& pend,
                                const std::vector<size_t>& pendPairedPos) {  // NEW!
    if (pend.empty())
        return;
    
    std::vector<size_t> jacobSeq = generateJacobsthalSequence(pend.size());
    std::vector<bool> inserted(pend.size(), false);
    std::vector<size_t> pairedPos = pendPairedPos; // Copy to track updates
    
    // Step 1: Insert pend[0] first
    // pend[0]'s partner is at pairedPos[0]
    binaryInsertVector(mainChain, pend[0], 0, pairedPos[0] + 1);
    inserted[0] = true;
    
    // Update all paired positions after this insertion
    for (size_t i = 1; i < pairedPos.size(); i++) {
        if (pairedPos[i] >= pairedPos[0])
            pairedPos[i]++;  // Shift right because we inserted before it
    }
    
    // Step 2: Use Jacobsthal order
    size_t prevIndex = 0;
    
    for (size_t i = 0; i < jacobSeq.size(); i++) {
        size_t currentIndex = jacobSeq[i];
        if (currentIndex >= pend.size())
            currentIndex = pend.size() - 1;
        
        // Insert backwards from currentIndex to prevIndex + 1
        for (size_t j = currentIndex; j > prevIndex; j--) {
            if (j < pend.size() && !inserted[j]) {
                // Use the tracked paired position!
                binaryInsertVector(mainChain, pend[j], 0, pairedPos[j] + 1);
                inserted[j] = true;
                
                // Update positions for remaining elements
                for (size_t k = 0; k < pairedPos.size(); k++) {
                    if (!inserted[k] && pairedPos[k] >= pairedPos[j])
                        pairedPos[k]++;
                }
            }
        }
        
        prevIndex = currentIndex;
    }
    
    // Step 3: Insert any remaining
    for (size_t i = 0; i < pend.size(); i++) {
        if (!inserted[i]) {
            binaryInsertVector(mainChain, pend[i], 0, pairedPos[i] + 1);
        }
    }
}

void PmergeMe::binaryInsertVector(std::vector<int>& mainChain,
            int value,
            size_t left,
            size_t right) {
    // Binary search to find insertion position
    while (left < right) {
        size_t mid = left + (right - left) / 2;

        if (value < mainChain[mid])
            right = mid;      // Search left half
        else
            left = mid + 1;   // Search right half
    }

    // Insert at position 'left'
    mainChain.insert(mainChain.begin() + left, value);
}