#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <iostream>
#include <vector>
#include <deque>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <climits>
#include <ctime>
#include <utility>
#include <iomanip>

class PmergeMe 
{
    private :
        std::vector<int> a;
        std::deque<int> b;
    public :
        PmergeMe();
        PmergeMe(const PmergeMe &x);
        PmergeMe& operator=(const PmergeMe &x);
        ~PmergeMe();
        void check(int ac, char **av);
        void begin(void);
        void printVector(std::vector<int> &vec);
        void printDeque(std::deque<int> &deq);
        void sortVector(std::vector<int> &vec);
        void sortDeque(std::deque<int> &deq);
        void jacobSeq(int pendSize, std::vector<int> &order);
        void insertPendDeque(std::deque<int> &result, std::deque<int> &pend, int stray, bool hasStray);
        void insertPendVector(std::vector<int> &result, std::vector<int> &pend, int stray, bool hasStray);
};

#endif