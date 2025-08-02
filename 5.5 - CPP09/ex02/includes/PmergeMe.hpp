#ifndef PMERGEME_HPP
#define PMERGEME_HPP

/*-------------- INCLUDES --------------*/

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <climits>
#include <sys/time.h>
#include "colors.hpp"

typedef unsigned long long timestamp_t;

/*-------------- CLASS --------------*/

class PmergeMe
{
private:
	static void parseInput(char **args, std::vector<int>& input);
	static void validateNumber(const std::string& s);
	static timestamp_t getTime();
	static std::vector<size_t> generateJacobsthalIndices(size_t n);
	static void printSequence(const std::string& label, const std::vector<int>& seq);
	static bool isSorted(const std::vector<int>& numbers);

	// vector
	static void fordJohnsonSort(std::vector<int>& data);
	static void insertJacobsthal(std::vector<int>& sorted, const std::vector<int>& insertions);

	// deque
	static void fordJohnsonSort(std::deque<int>& data);
	static void insertJacobsthal(std::deque<int>& sorted, const std::deque<int>& insertions);

public:
	static void run(char **args);
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe(); 
};

#endif
