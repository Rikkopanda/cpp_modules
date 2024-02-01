#include <iostream>
#include <string>

void	toupper(char *c)
{
	if (*c >= 97 && *c <= 122)
		*c -= 32;
}

int	main(int argc, char *argv[])
{
	std::string str;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}
	for (int i = 1; i < argc; i++)
	{
		str = argv[i];
		for (size_t j = 0; j < str.length(); j++)
		{
			toupper(&argv[i][j]);
		}
		std::cout << argv[i];
	}
	std::cout << std::endl;

	return 0;
}
