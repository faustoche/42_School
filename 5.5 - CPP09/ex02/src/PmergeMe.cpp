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

double PmergeMe::getTime() {
    struct timeval t;
    gettimeofday(&t, NULL);
    return (t.tv_sec * 1000000.0 + t.tv_usec);
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
** La suite de Jacobsthal est définie par : J(n) = J(n - 1) + 2 * J(n - 2)
** Si on doit générer des indices pour une liste de 0 éléments, on retourne une liste vide
** O
**
*/

std::vector<size_t> PmergeMe::generateJacobsthalIndices(size_t n) {
    if (n == 0)
		return (std::vector<size_t>());
    std::vector<size_t> indices; // liste finale à retourner
    std::vector<bool> used(n, false); // quels indices ont déjà été utilisés
    std::vector<size_t> jacobsthal; // valeur de la suite de Jacobsthal
    jacobsthal.push_back(1); // On commence la suite à 1 car 0 ne sert à rien dans notre cas
    if (n > 1)
		jacobsthal.push_back(1);
    size_t i = 2;
    while (jacobsthal.back() < n) // tant que notre suite en nombre est inférieur au nombre de chiffres que l'on veut trier
	{
        size_t next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2]; // on applique la suite 
        jacobsthal.push_back(next); // on ajoute l'élément correspondant dans notre vecteur
        i++;
    }
    for (size_t j = 1; j < jacobsthal.size(); j++)
	{
        size_t end = std::min(jacobsthal[j], n);
        size_t start = (j > 1) ? jacobsthal[j - 1] + 1 : 1; // on recupere les elements dans l'ordre inverse
        for (size_t k = end; k >= start && k >= 1; k--)
		{
            if (k - 1 < n && !used[k - 1]) // on evite les doublons en checkant used
			{
                indices.push_back(k - 1);
                used[k - 1] = true;
            }
        }
    }
    for (size_t i = 0; i < n; i++) // on ajoute les indices restants a notre liste
	{
        if (!used[i])
            indices.push_back(i);
    }
    return (indices);
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
