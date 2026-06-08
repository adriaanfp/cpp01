#include <iostream>
#include <string>

int	main(void)
{
	std::string		brain = "HI THIS IS BRAIN";
	std::string*	stringPTR = &brain;
	std::string&	stringREF = brain;
 
	std::cout << "--- Memory addresses ---" << std::endl;
	std::cout << "Address of brain    : " << &brain     << std::endl;
	std::cout << "Address by stringPTR: " << stringPTR  << std::endl;
	std::cout << "Address by stringREF: " << &stringREF << std::endl;
 
	std::cout << std::endl;
 
	std::cout << "--- Values ---" << std::endl;
	std::cout << "Value of brain       : " << brain      << std::endl;
	std::cout << "Value via stringPTR  : " << *stringPTR << std::endl;
	std::cout << "Value via stringREF  : " << stringREF  << std::endl;
 
	return (0);
}