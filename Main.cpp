#include <iostream>
#include "playercharacter.h"
int main()
{
	player p1(new knight());

	for (int i = 0; i < 1; i++)
	{
		std::cout
			<< p1.getClassName()
			<< "Knight" << " Level " << p1.getCurrentlevel() << '\n'
			<< "- EXP:" << p1.getCurrentEXP() << "/" << p1.getxpforlevelup() << '\n'
			<< "- Max HP:" << p1.getMaxHP << '\n'
			<< "- Damage:" << p1.getdamage() << '\n'
			<< "- Inteligence:" << p1.getinteligence() << '\n';
			p1.EXPgain(100u);
	}
	
	return 0;
}