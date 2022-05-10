#include <iostream>
#include "playercharacter.h"
int main()
{
	player p1(new knight());

	//for (int i = 0; i < 3; i++)
	{
		std::cout
			<< p1.getClassname()
			<< " Level " << p1.getCurrentlevel() << '\n'
			<< "- EXP:" << p1.getcurrentEXP() << '/' << p1.getxpforlevelup() << '\n'
			<< "- HP:" << p1.getCurrentHP() << '/' << p1.getMaxHP() << '\n'
			<< "- Damage:" << p1.getdamage() << '\n'
			<< "- Mana:" << p1.getmanapool() << '\n'
			<< "- energy:" << p1.getenergy() << '\n';


		p1.EXPgain(100u);
	}


	player p2(new Mage());

	//for (int i = 0; i < 3; i++)
	{
		std::cout
			<< p2.getClassname()
			<< " Level " << p2.getCurrentlevel() << '\n'
			<< "- EXP:" << p2.getcurrentEXP() << '/' << p2.getxpforlevelup() << '\n'
			<< "- HP:" << p2.getCurrentHP() << '/' << p2.getMaxHP() << '\n'
			<< "- Damage:" << p2.getdamage() << '\n'
			<< "- Mana:" << p2.getmanapool() << '\n'
			<< "- energy:" << p2.getenergy() << '\n';


		p2.EXPgain(100u);
	}

	return 0;
}
