#pragma once
#include "HP.h"
#include "Stat.h"


class Mage : public hp, public statblock
{
public:
	static const hptype Hpgrowth = 100u;				//using static constant to only intentiate once no matter the number of Mage.
	static const stats basedmg = 50u;					// Mage will spawn with hp of 100.
	static const stats baseintel = 50u;

	Mage() : hp(Hpgrowth, Hpgrowth), statblock(basedmg, baseintel)	//each Mage will start with similar stats
	{

	}
private:
};