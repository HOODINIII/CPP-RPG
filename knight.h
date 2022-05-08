#pragma once
#include "HP.h"
#include "Stat.h"
#include "Levelling.h"


class knight : public hp , public statblock, public Levelling
{
public:
	static const hptype BaseHP = 100u;				//using static constant to only intentiate once no matter the number of knights.
	static const stats Basedmg = 60u;					// knights will spawn with hp of 100.
	static const stats Baseintel = 20u;

	static const hptype HPincrease = 5u;
	static const stats dmgincrease = 5u;
	static const stats intelincrease = 5u;

	knight() : hp(BaseHP, BaseHP), statblock(Basedmg, Baseintel)	//each knight will start with similar stats
	{

	}

private:
	
	void levellingup() override
	{
		setMaxhp(HPincrease + getMaxhp());
		inccreasestats(dmgincrease, intelincrease);
	}
};