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

class Contact {


};



class PhoneBook {
	private:
		Contact contacts[8];
	public:
		

};


int	main(int argc, char *argv[])
{




	return 0;
}
