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

	std::cout << "Mage\n"
		<< "- MaxHP: " << mage1.getMaxhp() << '\n'
		<< "- Damage: " << mage1.getdamage() << '\n'
		<< "- Intelegence: " << mage1.getinteligence() << '\n';

	std::cout << "Preist\n"
		<< "- MaxHP: " << preist1.getMaxhp() << '\n'
		<< "- Damage: " << preist1.getdamage() << '\n'
		<< "- Intelegence: " << preist1.getinteligence() << '\n';
	return 0;
}