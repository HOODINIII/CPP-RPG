#pragma once
#include <cstdint>
#include "Stat_Type.h"
class Levelling
{
public:
	static const experience level2at = 100u; // xp required at level 2, xp require at level 3 with times this by 2 see below.
	Levelling()
	{
		Currentlevel = 1u;
		CurrentEXP = 0u;
		Maxlevels = 50;
		xpforlevelup = level2at;
	}

	void EXPgain(experience gained_exp)
	{
		CurrentEXP += gained_exp;
		while (Check_level_up()) {}
	}

	Levels getCurrentlevel()
	{
		return Currentlevel;
	}

	experience getCurrentEXP()
	{
		return CurrentEXP;
	}

	experience getxpforlevelup()
	{
		return xpforlevelup;
	}

	virtual void levellingup() = 0; // pure virtual functions allows the behaviour of the function to be changed in the derived classes.

protected:
	int Maxlevels;
	Levels Currentlevel;
	experience CurrentEXP; // using uint 64 as it will give highest value to make the xp system. the xp system will level up the class but each level will require more xp.
	experience xpforlevelup;


	bool Check_level_up()			//check to see if the player has any pending levels
	{
		static const Levels expmultiplyer = 2u; //xp multiplyer, times xp required by 2 everytime the player levels up.
		if (CurrentEXP > xpforlevelup)
		{
			Currentlevel++;
			levellingup(); //when leveled up the function should call pure virtual function
			xpforlevelup *= expmultiplyer;
			return true;
		}
		return false;
	}
};