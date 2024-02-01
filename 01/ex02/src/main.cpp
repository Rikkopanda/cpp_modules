/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:23:01 by rverhoev          #+#    #+#             */
/*   Updated: 2024/01/31 15:03:23 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
  std::string hi_brain= "HI THIS IS BRAIN";
  std::string *stringPTR = &hi_brain;
  std::string &stringREF = hi_brain;

  std::cout << &hi_brain << std::endl;
  std::cout << stringPTR << std::endl;
  std::cout << &stringREF << std::endl;

  std::cout << hi_brain << std::endl;
  std::cout << *stringPTR << std::endl;
  std::cout << stringREF << std::endl;

  return 0;
}


//int	main(int argc, char *argv[])
//{


//	return 0;
//}
