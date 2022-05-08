#pragma once
#include "HP.h"
#include "Stat.h"
#include "Levelling.h"


class Mage : public hp, public statblock, public Levelling
{
public:
	static const hptype BaseHP = 100u;				//using static constant to only intentiate once no matter the number of Mage.
	static const stats basedmg = 50u;					// Mage will spawn with hp of 100.
	static const stats baseintel = 50u;

	static const hptype HPincrease = 5u;
	static const stats dmgincrease = 5u;
	static const stats intelincrease = 5u;

	Mage() : hp(BaseHP, BaseHP), statblock(basedmg, baseintel)	//each Mage will start with similar stats
	{

	}
private:
	void levellingup() override
	{
		setMaxhp(HPincrease + getMaxhp());
		inccreasestats(dmgincrease, intelincrease);
	}
};