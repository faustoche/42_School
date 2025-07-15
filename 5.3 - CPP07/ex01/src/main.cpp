#include "iter.hpp"

void printHeader(int i, std::string color, std::string reset, std::string testName)
{
	std::cout << color << "\n==================================================\n" << reset;
	std::cout << WHITE << "   TEST " << i << " : " << testName << RESET << std::endl;
	std::cout << color << "==================================================\n" << reset << std::endl;
}

void	random_int(int &i)
{
	i = std::rand() % 100;
}

void	random_char(char &c)
{
	c = std::rand() % 26 + 65;
}

void add_emoji(std::string &s)
{
	s += "🐸";
}

int	main(void)
{
	std::srand(time(NULL));
	{
		char	*mult_str = new char[20];
		printHeader(1, ORANGE, RESET, "MULTIPLE CHARS - INCREMENT ONLY 10");
		iter(mult_str, 20, &random_char);
		iter(mult_str, 20, &print_tab<const char>);
		std::cout << std::endl;
		iter(mult_str, 10, &increment<char>);
		iter(mult_str, 20, &print_tab<char>);
		std::cout << std::endl;
		delete[] mult_str;
	}
	{
		int		*mult_int = new int[20];
		printHeader(2, PINK, RESET, "MULTIPLE INTS - INCREMENT ONLY 10");
		iter(mult_int, 20, &random_int);
		iter(mult_int, 20, &print_tab<int>);
		std::cout << std::endl;
		iter(mult_int, 10, &increment<int>);
		iter(mult_int, 20, &print_tab<const int>);
		std::cout << std::endl;
		std::cout << std::endl;
		delete[] mult_int;
	}
	{
		std::string str_tab[5] = { "Baa", "Bee", "Boo", "Buu", "Bii"};
		printHeader(3, GREEN, RESET, "STRINGS");
		std::cout << "Before:" << std::endl;
		iter(str_tab, 5, print_tab<const std::string>);
		std::cout << std::endl;
		std::cout << "After:" << std::endl;
		iter(str_tab, 5, add_emoji);
		iter(str_tab, 5, print_tab<const std::string>);
		std::cout << std::endl;
	}
	{
		printHeader(3, YELLOW, RESET, "CONST INT");
		const int const_tab[5] = {42, 17, 99, 3, 75};
		iter(const_tab, 5, print_tab<const int>);
		//iter(const_tab, 5, add_emoji);
		// iter(const_tab, 5, print_tab<const int>);
		std::cout << std::endl;
		std::cout << std::endl;
	}
	return (0);
}
