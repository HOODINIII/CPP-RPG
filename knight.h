#pragma once
#include "HP.h"
#include "Stat.h"


class knight : public hp , public statblock
{
public:
	static const hptype Hpgrowth = 100u;				//using static constant to only intentiate once no matter the number of knights.
	static const stats basedmg = 60u;					// knights will spawn with hp of 100.
	static const stats baseintel = 20u;													

	knight() : hp(Hpgrowth, Hpgrowth), statblock(basedmg, baseintel)	//each knight will start with similar stats
	{

	}
private:
};