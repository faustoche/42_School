#include "rpn.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <expression>" << std::endl;
		return (1);
	}

	rpn rpnn = rpn();

	try
	{
		std::cout << rpnn.result(argv[1]) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
