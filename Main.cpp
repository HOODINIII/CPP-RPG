#include <iostream>
#include "knight.h"
#include "Mage.h"
#include "Preist.h"
int main()
{
	knight knight1;
	Mage mage1;
	Preist preist1;

	for (int i = 0; i < 1; i++)
	{
		std::cout
			<< "Knight" << " Level " << knight1.getCurrentlevel() << '\n'
			<< "- EXP:" << knight1.getCurrentEXP() << "/" << knight1.getxpforlevelup() << '\n'
			<< "- Max HP:" << knight1.getMaxhp() << '\n'
			<< "- Damage:" << knight1.getdamage() << '\n'
			<< "- Inteligence:" << knight1.getinteligence() << '\n';
			knight1.EXPgain(100u);
	}
	
	return 0;
}