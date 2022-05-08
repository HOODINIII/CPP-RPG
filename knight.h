#pragma once
using namespace std;
#include "HP.h"
#include "Stat.h"


class knight : public hp , public StatBlock
{
public:
	static const hptype Hpgrowth = 100u;				//using static constant to only intentiate once no matter the number of knights.
	static const stats damage = 50u;					// knights will spawn with hp of 100.
	static const stats inteligence = 50u;													

	knight() : hp(Hpgrowth, Hpgrowth)					//each knight will start with the
	{

	}
private:
};