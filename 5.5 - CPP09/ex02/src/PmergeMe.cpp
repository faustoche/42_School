#include "PmergeMe.hpp"


/*-------------- CONSTRUCTORS --------------*/

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& other){
	(void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other){
	(void)other;
	return (*this);
}

/*-------------- FUNCTIONS --------------*/

timestamp_t PmergeMe::getTime()
{
	struct timeval now;
	gettimeofday (&now, NULL);
	return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}

/*
** check if the string is empty or if a caractere is not a number
** convert the chain in long and check if the value is positif
*/

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

/*
** convert earch argument in string, check that is a whole number
** add the whole nimber to the vector
*/

void PmergeMe::parseInput(char **args, std::vector<int>& input) {
	for (int i = 0; args[i]; ++i) {
		std::string s(args[i]);
		validateNumber(s);
		input.push_back(std::atoi(s.c_str()));
	}
}

void PmergeMe::printSequence(const std::string& label, const std::vector<int>& seq)
{
	std::cout << label;
	for (size_t i = 0; i < seq.size(); ++i)
		std::cout << seq[i] << " ";
	std::cout << std::endl;
}

/*
** Check if the vector is already sorted
** Return true if sorted, else false
*/

bool PmergeMe::isSorted(const std::vector<int>& numbers) {
	for (size_t i = 1; i < numbers.size(); ++i) {
		if (numbers[i] < numbers[i - 1])
			return (false);
	}
	return (true);
}

/*
** Jacobsthal is defined by : J(n) = J(n - 1) + 2 * J(n - 2)
** While our suite of numbers are inferior to the number of digits we want to sort we do the sort with Jacobsthal
** We add the next Jacobsthal number
** We check if the numbers of Jacobsthal has been used or not
*/

std::vector<size_t> PmergeMe::generateJacobsthalIndices(size_t n) {
	if (n == 0)
		return (std::vector<size_t>());
	std::vector<size_t> finalIndex;
	std::vector<bool> used(n, false);
	std::vector<size_t> jacobsthal;
	jacobsthal.push_back(1);
	if (n > 1)
		jacobsthal.push_back(1);
	size_t i = 2;
	while (jacobsthal.back() < n)
	{
		size_t next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
		jacobsthal.push_back(next);
		i++;
	}
	for (size_t j = 1; j < jacobsthal.size(); j++)
	{
		size_t end = std::min(jacobsthal[j], n);
		size_t start = (j > 1) ? jacobsthal[j - 1] + 1 : 1;
		for (size_t k = end; k >= start && k >= 1; k--)
		{
			if (k - 1 < n && !used[k - 1])
			{
				finalIndex.push_back(k - 1);
				used[k - 1] = true;
			}
		}
	}
	for (size_t i = 0; i < n; i++)
	{
		if (!used[i])
			finalIndex.push_back(i);
	}
	return (finalIndex);
}

/*  ------- VECTOR VERSION ------- */
/*
** Inserting the value in the sorted array following Jacobsthal order
** We need to generate the most optimal order for insertion
** For each element, we check the size, and add the number at the right sorted position with lower_bound
** Finally, we insert it
*/

void PmergeMe::insertJacobsthal(std::vector<int>& sorted, const std::vector<int>& insertions) {
	std::vector<size_t> indices = generateJacobsthalIndices(insertions.size());
	for (size_t i = 0; i < indices.size(); ++i) {
		size_t index = indices[i];
		if (index >= insertions.size())
			continue ;
		int val = insertions[index];
		std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), val);
		sorted.insert(pos, val);
	}
}

/*
** Creating paires
** We separate min and max
** If we have an uneven number of element, we add the remaining one into maxs
** We sord the maxs and insert the min in the right order
*/

void PmergeMe::fordJohnsonSort(std::vector<int>& data) {
	if (data.size() <= 1)
		return ;
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

/*  ------- DEQUE VERSION ------- */
/*
** Inserting the value in the sorted array following Jacobsthal order
** We need to generate the most optimal order for insertion
** For each element, we check the size, and add the number at the right sorted position with lower_bound
** Finally, we insert it
*/

void PmergeMe::insertJacobsthal(std::deque<int>& sorted, const std::deque<int>& insertions) {
	std::vector<size_t> indices = generateJacobsthalIndices(insertions.size());
	for (size_t i = 0; i < indices.size(); ++i) {
		size_t idx = indices[i];
		if (idx >= insertions.size())
			continue ;
		int val = insertions[idx];
		std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), val);
		sorted.insert(pos, val);
	}
}

/*
** Creating paires
** We separate min and max
** If we have an uneven number of element, we add the remaining one into maxs
** We sord the maxs and insert the min in the right order
*/

void PmergeMe::fordJohnsonSort(std::deque<int>& data) {
	if (data.size() <= 1)
		return ;
	std::deque<int> maxs, mins;
	size_t i = 0;
	for (; i + 1 < data.size(); i += 2)
	{
		if (data[i] > data[i + 1])
		{
			maxs.push_back(data[i]);
			mins.push_back(data[i + 1]);
		}
		else
		{
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
	if (isSorted(input)){
		std::cout << GREEN << "Numbers are sorted" << RESET << std::endl;
		return ;
	}
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
