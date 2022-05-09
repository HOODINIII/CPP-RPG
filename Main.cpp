#include <iostream>
#include "playercharacter.h"
int main()
{
	player p1(new Mage());

	for (int i = 0; i < 3; i++)
	{
		std::cout
			<< p1.getClassname()
			<< " Level " << p1.getCurrentlevel() << '\n'
			<< "- EXP:" << p1.getcurrentEXP() << '/' << p1.getxpforlevelup() << '\n'
			<< "- HP:" << p1.getCurrentHP() << '/' << p1.getMaxHP() << '\n'
			<< "- Damage:" << p1.getdamage() << '\n'
			<< "- Inteligence:" << p1.getinteligence() << '\n';
		p1.EXPgain(100u);
	}

	return 0;
}
