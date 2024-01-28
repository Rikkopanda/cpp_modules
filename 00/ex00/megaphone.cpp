#include <iostream>
#include <string>     // std::char_traits

void	ft_toupper(char *c)
{
	if (*c >= 97 && *c <= 122)
		*c -= 32;
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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
			ft_toupper(&argv[i][j]);
		}
		std::cout << argv[i];
	}
	std::cout << "\n";

	return 0;
}
