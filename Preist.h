#pragma once
#include "HP.h"
#include "Stat.h"


class Preist : public hp, public statblock
{
public:
	static const hptype Hpgrowth = 100u;				//using static constant to only intentiate once no matter the number of Preist.
	static const stats basedmg = 10u;					// Preist will spawn with hp of 100.
	static const stats baseintel = 70u;

	Preist() : hp(Hpgrowth, Hpgrowth), statblock(basedmg, baseintel)	//each Preist will start with similar stats
	{

	}
private:
};