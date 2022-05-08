#pragma once
#include "HP.h"


class knight : public hp
{
public:
	static const hptype Hpgrowth = 100u; //using static constant to only intentiate once no matter the number of knights.
	// knights will also have hp growth of 100 unassinged.
	knight() : hp(Hpgrowth, Hpgrowth) //each knight will start with their max hp and current hp set to 100.
	{

	}
private:
};