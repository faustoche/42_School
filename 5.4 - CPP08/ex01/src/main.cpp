#include "Span.hpp"

void printHeader(int i, std::string color, std::string reset, std::string testName)
{
	std::cout << color << "\n==================================================\n" << reset;
	std::cout << WHITE << "   TEST " << i << " : " << testName << RESET << std::endl;
	std::cout << color << "==================================================\n" << reset << std::endl;
}

int main(void)
{
	srand(time(NULL));
	{
		printHeader(1, GREEN, RESET, "BASIC CASES");
		Span vect1(10);
		vect1.addNumber(78);
		vect1.addNumber(53);
		vect1.addNumber(453);
		vect1.addNumber(7);
		vect1.addNumber(8);
		vect1.addNumber(3);
		vect1.addNumber(652);
		vect1.addNumber(6532365);
		vect1.addNumber(95);
		vect1.addNumber(26);
		std::cout << WHITE << "Shortest span is: " << RESET << vect1.shortestSpan() << std::endl;
		std::cout << WHITE << " Longest span is: " << RESET << vect1.longestSpan() << std::endl;
	}
	{
		printHeader(2, YELLOW, RESET, "SAME NUMBERS");
		Span vect2(10);
		vect2.addNumber(78);
		vect2.addNumber(78);
		vect2.addNumber(78);
		vect2.addNumber(78);
		vect2.addNumber(78);
		vect2.addNumber(78);
		vect2.addNumber(78);
		vect2.addNumber(78);
		vect2.addNumber(78);
		vect2.addNumber(78);
		std::cout << WHITE << "Shortest span is: " << RESET << vect2.shortestSpan() << std::endl;
		std::cout << WHITE << " Longest span is: " << RESET << vect2.longestSpan() << std::endl;
	}
	{
		printHeader(3, CYAN, RESET, "MAKING SURE FUNCTION WORKS WELL");
		Span vect2(2);
		vect2.addNumber(1);
		vect2.addNumber(78456);
		std::cout << WHITE << "Shortest span is: " << RESET << vect2.shortestSpan() << std::endl;
		std::cout << WHITE << " Longest span is: " << RESET << vect2.longestSpan() << std::endl;
	}
	{
		printHeader(4, PINK, RESET, "10K NUMBERS");
		std::vector<int> numbers;
		Span bigCont(10000);
		for (int i = 0; i < 10000; ++i)
			numbers.push_back(rand() % 50000);
		bigCont.addNumber(numbers.begin(), numbers.end());
		std::cout << WHITE << "Shortest span is: " << RESET << bigCont.shortestSpan() << std::endl;
		std::cout << WHITE << " Longest span is: " << RESET << bigCont.longestSpan() << std::endl;
	}
	{
		printHeader(5, ORANGE, RESET, "NO ELEMENTS - SHOULD THROW EXCEPTION");
		try {
			Span noElement(0);
			std::cout << WHITE << "Shortest span is: " << RESET << noElement.shortestSpan() << std::endl;
			std::cout << WHITE << " Longest span is: " << RESET << noElement.longestSpan() << std::endl;
		} catch (const std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	{
		printHeader(6, RED_BOLD, RESET, "1 ELEMENT - SHOULD THROW EXCEPTION");
		try {
			Span oneElement(1);
			std::cout << WHITE << "Shortest span is: " << RESET << oneElement.shortestSpan() << std::endl;
			std::cout << WHITE << " Longest span is: " << RESET << oneElement.longestSpan() << std::endl;
		} catch (const std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	{
		printHeader(7, MAGENTA, RESET, "ADDING NUMBERS WITH FULL CONTAINER");
		try {
			Span smallContainer(2);
			smallContainer.addNumber(5);
			smallContainer.addNumber(12);
			smallContainer.addNumber(87);
			smallContainer.addNumber(45634130);
		} catch (const std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	return (0);
}


// int main()
// {
// Span sp = Span(5);
// sp.addNumber(6);
// sp.addNumber(3);
// sp.addNumber(17);
// sp.addNumber(9);
// sp.addNumber(11);
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
// return 0;
// }