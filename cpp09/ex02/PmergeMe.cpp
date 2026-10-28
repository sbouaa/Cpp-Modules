#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &x)
{
    *this = x;
}

void PmergeMe::check(int ac, char **av)
{
    int i = 1;
    while (i < ac)
    {
        if (!av[i])
            throw std::runtime_error("Error : Bad input!!");
        std::string t(av[i]);
        if (t.empty())
            throw std::runtime_error("Error : Bad input!!\n");
        if (t.find_first_not_of("0123456789+") != std::string::npos)
            throw std::runtime_error("Error : Not a Number!!\n");
        if (t[0] == '+')
        {
            if (t.size() == 1 || !std::isdigit(static_cast<unsigned char>(t[1])))
                throw std::runtime_error("Error : Not a Number!!\n");
        }
        std::istringstream ss(t);
        long v = 0;
        ss >> v;
        if (ss.fail() || !ss.eof())
            throw std::runtime_error("Error : Not a Number!!\n");
        if (v > INT_MAX)
            throw std::runtime_error("Error : too large integer!!\n");
        a.push_back(static_cast<int>(v));
        b.push_back(static_cast<int>(v));
        i++;
    }
    if (a.empty())
        throw std::runtime_error("Error : Empty container!!\n");
}

void PmergeMe::printVector(std::vector<int> &vec)
{
    for (size_t i = 0; i < vec.size(); i++)
        std::cout<<vec[i]<<" ";
    std::cout<<std::endl;
}

void PmergeMe::printDeque(std::deque<int> &deq)
{
    for (size_t i = 0; i < deq.size(); i++)
        std::cout<<deq[i]<<" ";
    std::cout<<std::endl;
}

void PmergeMe::jacobSeq(int pendSize, std::vector<int> &order)
{
    if (pendSize <= 0)
        return;
    std::vector<int> jacob;
    jacob.push_back(1);
    jacob.push_back(1);
    while (jacob[jacob.size() - 1] < pendSize)
    {
        int last = jacob[jacob.size() - 1];
        int prev = jacob[jacob.size() - 2];
        jacob.push_back(last + 2 * prev);
    }
    std::vector<bool> used(pendSize, false);
    used[0] = true;

    int prevBound = jacob[0];
    for (size_t k = 1; k < jacob.size(); k++)
    {
        int curBound = jacob[k];
        if (curBound > pendSize)
            curBound = pendSize;

        for (int idx = curBound; idx > prevBound; idx--)
        {
            if (!used[idx - 1])
            {
                order.push_back(idx - 1);
                used[idx - 1] = true;
            }
        }
        prevBound = jacob[k];
        if (jacob[k] >= pendSize)
            break;
    }
    for (int idx = 0; idx < pendSize; idx++)
    {
        if (!used[idx])
            order.push_back(idx);
    }
}

void PmergeMe::insertPendVector(std::vector<int> &result, std::vector<int> &pend, int stray, bool hasStray)
{
    std::vector<int> order;
    jacobSeq((int)pend.size(), order);

    for (size_t j = 0; j < order.size(); j++)
    {
        int value = pend[order[j]];
        std::vector<int>::iterator pos = std::upper_bound(result.begin(), result.end(), value);
        result.insert(pos, value);
    }
    if (hasStray)
    {
        std::vector<int>::iterator pos = std::upper_bound(result.begin(), result.end(), stray);
        result.insert(pos, stray);
    }
}

void PmergeMe::sortVector(std::vector<int> &vec)
{
    if (vec.size() < 2)
        return;
    std::vector<std::pair<int, int> > pairs;
    bool hasStray = false;
    int  stray = 0;
    size_t  i = 0;

    while (i + 1 < vec.size())
    {
        if (vec[i] > vec[i + 1])
            pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
        else
            pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
        i += 2;
    }

    if (vec.size() % 2 == 1)
    {
        hasStray = true;
        stray = vec[vec.size() - 1];
    }
    std::vector<int> mainChain;
    for (size_t j = 0; j < pairs.size(); j++)
        mainChain.push_back(pairs[j].first);

    if (mainChain.size() > 1)
        sortVector(mainChain);
    std::vector<int> pend(mainChain.size());
    std::vector<bool> used(pairs.size(), false);
    for (size_t j = 0; j < mainChain.size(); j++)
    {
        for (size_t k = 0; k < pairs.size(); k++)
        {
            if (!used[k] && pairs[k].first == mainChain[j])
            {
                pend[j] = pairs[k].second;
                used[k] = true;
                break;
            }
        }
    }
    std::vector<int> result;
    result.push_back(pend[0]);
    for (size_t j = 0; j < mainChain.size(); j++)
        result.push_back(mainChain[j]);
    insertPendVector(result, pend, stray, hasStray);
    vec = result;
}

void PmergeMe::insertPendDeque(std::deque<int> &result, std::deque<int> &pend, int stray, bool hasStray)
{
    std::vector<int> order;
    jacobSeq((int)pend.size(), order);

    for (size_t j = 0; j < order.size(); j++)
    {
        int value = pend[order[j]];
        std::deque<int>::iterator pos = std::upper_bound(result.begin(), result.end(), value);
        result.insert(pos, value);
    }
    if (hasStray)
    {
        std::deque<int>::iterator pos = std::upper_bound(result.begin(), result.end(), stray);
        result.insert(pos, stray);
    }
}

void PmergeMe::sortDeque(std::deque<int> &deq)
{
    if (deq.size() < 2)
        return;

    std::deque<std::pair<int, int> > pairs;
    bool hasStray = false;
    int  stray = 0;
    size_t  i = 0;

    for (; i + 1 < deq.size(); i += 2)
    {
        if (deq[i] > deq[i + 1])
            pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
        else
            pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
    }
    if (deq.size() % 2 == 1)
    {
        hasStray = true;
        stray = deq[deq.size() - 1];
    }

    std::deque<int> mainChain;
    for (int j = 0; j < (int)pairs.size(); j++)
        mainChain.push_back(pairs[j].first);
    if (mainChain.size() > 1)
        sortDeque(mainChain);

    std::deque<int> pend(mainChain.size());
    std::deque<bool> used(pairs.size(), false);
    for (size_t j = 0; j < mainChain.size(); j++)
    {
        for (size_t k = 0; k < pairs.size(); k++)
        {
            if (!used[k] && pairs[k].first == mainChain[j])
            {
                pend[j] = pairs[k].second;
                used[k] = true;
                break;
            }
        }
    }

    std::deque<int> result;
    result.push_back(pend[0]);
    for (int j = 0; j < (int)mainChain.size(); j++)
        result.push_back(mainChain[j]);

    insertPendDeque(result, pend, stray, hasStray);
    deq = result;
}

void PmergeMe::begin(void)
{
    std::vector<int> vec = a;
    std::deque<int>  deq = b;

    clock_t vecStart = clock();
    if (vec.size() > 1)
        sortVector(vec);
    clock_t vecEnd = clock();

    clock_t deqStart = clock();
    if (deq.size() > 1)
        sortDeque(deq);
    clock_t deqEnd = clock();

    std::cout << "Before: ";
    printVector(a);
    std::cout << "After:  ";
    printVector(vec);

    double vecTime = static_cast<double>(vecEnd - vecStart) / CLOCKS_PER_SEC * 1000000.0;
    double deqTime = static_cast<double>(deqEnd - deqStart) / CLOCKS_PER_SEC * 1000000.0;

    std::cout << std::fixed << std::setprecision(5)<< "Time to process a range of " << a.size()
              << " elements with std::vector : "<< vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << b.size()
              << " elements with std::deque : " << deqTime << " us" << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &x)
{
    if (this != &x)
    {
        a = x.a;
        b = x.b;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}