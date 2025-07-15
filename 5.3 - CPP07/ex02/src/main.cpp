#include "Array.hpp"
#include <iostream>
#include <string>

void printHeader(int i, std::string color, std::string reset, std::string testName)
{
	std::cout << color << "\n==================================================\n" << reset;
	std::cout << WHITE << "   TEST " << i << " : " << testName << RESET << std::endl;
	std::cout << color << "==================================================\n" << reset << std::endl;
}

void	random_int(Array<int> &i){
	i = std::rand() % 100;
}

void	print_int(Array<int> &array){
	for (int i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

void	print_str(Array<std::string> &array){
	for (int i = 0; i < array.size(); i++)
		std::cout << i << ": " << array[i] << std::endl;
}

/* 
** Necessary to write Array<std::string> cause it's a class template
** We need to specifiy the type wwe want to use
*/

int main(void)
{
	srand(time(NULL));
	printHeader(1, GREEN, RESET, "ARRAY OF SIZE 30");
	Array<int>	int_array(30);
	for (int i = 0; i < int_array.size(); i++)
		int_array[i] = std::rand() % 100;
	print_int(int_array);

	printHeader(2, BLUE_BRIGHT, RESET, "DEEP COPY CHECK");
	Array<int> copy_array = int_array;
	int_array[0] = 999;
	std::cout << "Original: " << int_array[0] << " | Copy: " << copy_array[0] << std::endl;

	printHeader(3, CYAN, RESET, "ARRAY OF STRINGS");
	Array<std::string>	str_array(3);
	str_array[0] = "Hello";
	str_array[1] = "my";
	str_array[2] = "friends";
	print_str(str_array);

	printHeader(4, MAGENTA, RESET, "DEEP COPY WITH STRINGS");
	Array<std::string> str_copy = str_array;
	str_array[1] = "buddies";
	std::cout << "Original: " << str_array[1] << ", Copy: " << str_copy[1] << std::endl;

	printHeader(5, RED_BOLD, RESET, "OUT OF RANGE EXCEPTION");
	try {
		std::cout << str_array[10] << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}
	return (0);
}


/**************************************************/
/*                MAIN'S SUBJECT                  */
/**************************************************/

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;
//     return 0;
// }
