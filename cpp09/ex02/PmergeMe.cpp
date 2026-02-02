#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
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
    return jacobsthal(n-1) + 2*jacobsthal(n-2);
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
    fordJohnsonVector();
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
        original.push_back(value);
        vec.push_back(value);
        deq.push_back(value);
    }
    printVector(original, "Before: ");
    return true;
}

void PmergeMe::fordJohnsonVector() {
    double start, end;

    start = getTime();

    //logic goes here i guess :')

    int straggler = -1;
    std::vector<int> mainChain;
    std::vector<int> pend;

    std::vector<std::pair<int, int> > pairs = createPairsVector(straggler);

    printPairs(pairs, "Pairs before sort: ");
    sortPairsvector(pairs);
    printPairs(pairs, "Pairs after sort: ");

    buildChainsVector(pairs, mainChain, pend);

    printVector(mainChain, "Main chain: ");
    printVector(pend, "Pend chain: ");

    end = getTime();
    vecTime = end - start;
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
            std::vector<int>& pend) {
    if (pairs.empty())
        return;
    mainChain.push_back(pairs[0].first);
    mainChain.push_back(pairs[0].second);
    for (size_t i = 1; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].second);
        pend.push_back(pairs[i].first); 
    }
}