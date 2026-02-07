#pragma once

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <sys/time.h>
#include <iomanip>

typedef std::string string;

class PmergeMe {
    private:
        // Store original input for display
        std::vector<int> original;
        
        // Two containers for sorting
        std::vector<int> vec;
        std::deque<int> deq;
        
        // Timing variables
        double vecTime;
        double deqTime;

        // ===== HELPER METHODS =====
        
        bool isValidNumber(const std::string& str);
        bool parseArguments(int argc, char** argv);
        
        double getTime();
        
        void printSequence(const std::vector<int>& sequence, const std::string& label);
        
        // ===== JACOBSTHAL SEQUENCE =====
        
        std::vector<size_t> generateJacobsthalSequence(size_t size);
        size_t jacobsthal(size_t n);






        // ===== FORD-JOHNSON ALGORITHM FOR VECTOR =====
        
        void fordJohnsonVector();
        
        // Step 1: Create and sort pairs
        std::vector<std::pair<int, int> > createPairsVector(int& straggler);
        
        // Step 2: Recursively sort pairs by their larger element
        static bool comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b);
        void sortPairsvector(std::vector<std::pair<int, int> >& pairs);
        
        // Step 3: Build main chain and pend
        void buildChainsVector(const std::vector<std::pair<int, int> >& pairs,
                    std::vector<int>& mainChain,
                    std::vector<int>& pend,
                    std::vector<size_t>& pendPairedPos);
        
        // Step 4: Insert pend elements using Jacobsthal order
        void insertPendVector(std::vector<int>& mainChain,
                    const std::vector<int>& pend,
                    const std::vector<size_t>& pendPairedPos);
        
        // Binary insertion helper
        void binaryInsertVector(std::vector<int>& mainChain,
                            int value,
                            size_t left,
                            size_t right);





        // ===== FORD-JOHNSON ALGORITHM FOR DEQUE =====

        void fordJohnsonDeque();

        // Step 1: Create and sort pairs
        std::deque<std::pair<int, int> > createPairsDeque(int& straggler);

        // Step 2: Sort pairs by larger element (using std::sort, so these are no longer needed)
        // void mergeSortPairsDeque(std::deque<std::pair<int, int> >& pairs, int left, int right);
        // void mergePairsDeque(std::deque<std::pair<int, int> >& pairs, int left, int mid, int right);

        // Step 3: Build main chain and pend with paired position tracking
        void buildChainsDeque(const std::deque<std::pair<int, int> >& pairs,
                            std::deque<int>& mainChain,
                            std::deque<int>& pend,
                            std::vector<size_t>& pendPairedPos);

        // Step 4: Insert pend elements using Jacobsthal order with paired positions
        void insertPendDeque(std::deque<int>& mainChain,
                            const std::deque<int>& pend,
                            const std::vector<size_t>& pendPairedPos);

        // Binary insertion helper
        void binaryInsertDeque(std::deque<int>& mainChain,
                            int value,
                            size_t left,
                            size_t right);

    public:
        // Constructor
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();
        
        // Main public interface
        bool initialize(int argc, char** argv);
        void sort();
        void displayResults();
};
