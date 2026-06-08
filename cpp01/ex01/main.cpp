#include "Zombie.hpp"
#include <iostream>
 
int	main(void)
{
	int		n = 5;
	Zombie*	horde = zombieHorde(n, "Brainless");
 
	std::cout << "--- Horde of " << n << " zombies ---" << std::endl;
	for (int i = 0; i < n; i++)
		horde[i].announce();
 
	std::cout << std::endl << "--- Destroying horde ---" << std::endl;
	delete[] horde;
 
	return (0);
}