#pragma once
#include "HPtypes.h" // accessing "hptypes.h file

class hp
{
public:
	//checking if the current hp is within max hp
	bool setMaxhp(hptype new_max_hp)
	{
		if (new_max_hp < 1)
		
			return false;
		Maxhp = new_max_hp;
			
			if (Currenthp > Maxhp)
			Currenthp = Maxhp;

			return true;
		}

	hptype getMaxhp() // getting Max hp from the private class
	{
		return Maxhp;
	}

	hptype getCurrenthp() // getting current hp from the private class
	{
		return Currenthp;
	}

	void damagetaken(hptype damage)
	{
		if (damage > Currenthp)
		{
			Currenthp = 0;
			return;
		}

		Currenthp = damage;
	}
	void healing(hptype heal)
	{
		if (Currenthp + heal > Maxhp)
		{
			Currenthp = Maxhp;
			return;
		}
		Currenthp += heal;
	}



private:
	hptype Maxhp; 
	hptype Currenthp; 
};