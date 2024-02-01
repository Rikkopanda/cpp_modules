#include <string>
#include <iostream>

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

// std::string truncate(std::string str, size_t width, bool show_ellipsis=true)
// {
//     if (str.length() > width)
//         if (show_ellipsis)
//             return str.substr(0, width) + "...";
//         else
//             return str.substr(0, width);
//     return str;
// }
