#include <iostream>
#include "knight.h"
#include "Mage.h"
#include "Preist.h"
int main()
{
	knight knight1;
	Mage mage1;
	Preist preist1;

	std::cout << "Knight\n"
		<< "- MaxHP: " << knight1.getMaxhp() << '\n'
		<< "- Damage: " << knight1.getdamage() << '\n'
		<< "- Intelegence: " << knight1.getinteligence() << '\n';
	return 0;
}