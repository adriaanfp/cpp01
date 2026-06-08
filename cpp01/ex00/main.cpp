#include "Zombie.hpp"
#include <iostream>

int main(void)
{
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();

    std::cout << std::endl;

    randomChump("StackZombie");

    std::cout << std::endl;

    delete heapZombie;

    return (0);
}
