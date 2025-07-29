#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& other){
    (void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other){
    (void)other;
    return (*this);
}

double PmergeMe::getTime() {
    struct timeval t;
    gettimeofday(&t, NULL);
    return (t.tv_sec * 1000000.0 + t.tv_usec);
}

void PmergeMe::validateNumber(const std::string& s) {
    if (s.empty())
        throw std::runtime_error("Empty");
    for (size_t i = 0; i < s.length(); i++)
        if (!isdigit(s[i]))
            throw std::runtime_error("Invalid char");
    long val = std::strtol(s.c_str(), NULL, 10);
    if (val < 0 || val > INT_MAX)
        throw std::runtime_error("Out of range");
}

void PmergeMe::parseInput(char **args, std::vector<int>& input) {
    for (int i = 0; args[i]; ++i) {
        std::string s(args[i]);
        validateNumber(s);
        input.push_back(std::atoi(s.c_str()));
    }
}

void PmergeMe::printSequence(const std::string& label, const std::vector<int>& seq) {
    std::cout << label;
    for (size_t i = 0; i < seq.size(); ++i)
        std::cout << seq[i] << " ";
    std::cout << std::endl;
}

std::vector<size_t> PmergeMe::generateJacobsthalIndices(size_t n) {
    std::vector<size_t> indices;
    size_t j1 = 1, j2 = 1;
    indices.push_back(1);
    while (j1 < n) {
        indices.push_back(j1);
        size_t tmp = j1;
        j1 = j1 + 2 * j2;
        j2 = tmp;
    }
    for (size_t i = 1; i < n; ++i)
        if (std::find(indices.begin(), indices.end(), i) == indices.end())
            indices.push_back(i);
    return indices;
}

void PmergeMe::insertJacobsthal(std::vector<int>& sorted, const std::vector<int>& insertions) {
    std::vector<size_t> indices = generateJacobsthalIndices(insertions.size());
    for (size_t i = 0; i < indices.size(); ++i) {
        size_t idx = indices[i];
        if (idx >= insertions.size())
            continue;
        int val = insertions[idx];
        std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), val);
        sorted.insert(pos, val);
    }
}

void PmergeMe::fordJohnsonSort(std::vector<int>& data) {
    if (data.size() <= 1)
        return;

    std::vector<int> maxs, mins;
    size_t i = 0;
    for (; i + 1 < data.size(); i += 2) {
        if (data[i] > data[i + 1]) {
            maxs.push_back(data[i]);
            mins.push_back(data[i + 1]);
        } else {
            maxs.push_back(data[i + 1]);
            mins.push_back(data[i]);
        }
    }
    if (i < data.size())
        maxs.push_back(data[i]);

    fordJohnsonSort(maxs);
    insertJacobsthal(maxs, mins);

    data = maxs;
}

void PmergeMe::insertJacobsthal(std::deque<int>& sorted, const std::deque<int>& insertions) {
    std::vector<size_t> indices = generateJacobsthalIndices(insertions.size());
    for (size_t i = 0; i < indices.size(); ++i) {
        size_t idx = indices[i];
        if (idx >= insertions.size())
            continue;
        int val = insertions[idx];
        std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), val);
        sorted.insert(pos, val);
    }
}

void PmergeMe::fordJohnsonSort(std::deque<int>& data) {
    if (data.size() <= 1)
        return;

    std::deque<int> maxs, mins;
    size_t i = 0;
    for (; i + 1 < data.size(); i += 2) {
        if (data[i] > data[i + 1]) {
            maxs.push_back(data[i]);
            mins.push_back(data[i + 1]);
        } else {
            maxs.push_back(data[i + 1]);
            mins.push_back(data[i]);
        }
    }
    if (i < data.size())
        maxs.push_back(data[i]);

    fordJohnsonSort(maxs);
    insertJacobsthal(maxs, mins);
    data = maxs;
}

void PmergeMe::run(char **args) {
    std::vector<int> input;
    parseInput(args, input);

    std::vector<int> vec(input);
    std::deque<int> deq(input.begin(), input.end());

    printSequence("Before: ", input);

    double t0 = getTime();
    fordJohnsonSort(vec);
    double t1 = getTime();

    double t2 = getTime();
    fordJohnsonSort(deq);
    double t3 = getTime();

    printSequence("After: ", vec);

    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : " << (t1 - t0) << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque  : " << (t3 - t2) << " us" << std::endl;
}
