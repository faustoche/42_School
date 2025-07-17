#include "MutantStack.hpp"
#include "MutantStack.tpp"


void printHeader(int i, std::string color, std::string reset, std::string testName)
{
	std::cout << color << "\n==================================================\n" << reset;
	std::cout << WHITE << "   TEST " << i << " : " << testName << RESET << std::endl;
	std::cout << color << "==================================================\n" << reset << std::endl;
}

template<typename Stack>
void printStack(Stack &stack)
{
	typename Stack::iterator it_beg = stack.begin();
	typename Stack::iterator it_end = stack.end();
	std::cout << WHITE << "[STACK CONTENT]" << RESET << std::endl;
	while (it_beg != it_end)
	{
		std::cout << *it_beg << std::endl;
		++it_beg;
	}
	std::cout << std::endl;
}

// Push : new element on top of the stack
// Pop : remove element on top of the stack

int main()
{
	srand(time(NULL));
	{
		printHeader(1, GREEN, RESET, "BASIC TEST");
		MutantStack<int> monster;
		monster.push(5);
		monster.push(17);
		std::cout << GREEN << " Top before pop: " << RESET << monster.top() << std::endl;
		std::cout << GREEN << "Size before pop: " << RESET << monster.size() << std::endl;
		monster.pop();
		std::cout << GREEN << "  Top after pop: " << RESET << monster.top() << std::endl;
		std::cout << GREEN << " Size after pop: " << RESET << monster.size() << std::endl;
		// monster.push(3);
		// monster.push(5);
		// monster.push(737);
		// monster.push(0);
	}
	{
		printHeader(2, YELLOW, RESET, "INCREMENTING WITH ITERATOR");
		MutantStack<int> monster;
		for (int i = 0; i < 5; i++)
		monster.push(i * 10);
		std::cout << YELLOW << "Before incrementing each element:" << RESET << std::endl;
		std::cout << std::endl;
		printStack(monster);
		for (MutantStack<int>::iterator it = monster.begin(); it != monster.end(); ++it)
			*it += 1;
		std::cout << YELLOW << " After incrementing each element:" << RESET << std::endl;
		std::cout << std::endl;
		printStack(monster);
	}
	{
		printHeader(3, MAGENTA, RESET, "EMPTY STACK ITERATION");
		MutantStack<int> empty;
		std::cout << MAGENTA << "Size: " << RESET << empty.size() << std::endl;
		std::cout << std::endl;
		printStack(empty);
	}
	{
		printHeader(4, RED_BOLD, RESET, "ADD DUPLICATES OVER AND OVER");
		MutantStack<int> dupStack;
		for (int i = 0; i < 5; ++i)
			dupStack.push(42);
		printStack(dupStack);
	}
	{
		printHeader(5, ORANGE, RESET, "TRYING WITH CHAR");
		MutantStack<char> stackChar;
		stackChar.push('A');
		stackChar.push('B');
		stackChar.push('C');
		std::cout << ORANGE << "Top of the stack: " << RESET << stackChar.top() << std::endl;
		std::cout << std::endl;
		printStack(stackChar);
	}
	std::cout << std::endl;
	return (0);
}

/* Main du sujet */

// int main()
// {
// MutantStack<int> mstack;
// mstack.push(5);
// mstack.push(17);
// std::cout << mstack.top() << std::endl;
// mstack.pop();
// std::cout << mstack.size() << std::endl;
// mstack.push(3);
// mstack.push(5);
// mstack.push(737);
// //[...]
// mstack.push(0);
// MutantStack<int>::iterator it = mstack.begin();
// MutantStack<int>::iterator ite = mstack.end();
// ++it;
// --it;
// while (it != ite)
// {
// std::cout << *it << std::endl;
// ++it;
// }
// std::stack<int> s(mstack);
// return 0;
// }
