#pragma once
#include "Stat_Type.h"
// class to inherit
class statblock
{
	stats damage;				//private variables
	stats inteligence;
public:							//construct
	statblock()
	{
		damage = 1u;
		inteligence = 1u;
	}

	statblock(stats dmg, stats intel)
	{
		damage = dmg;
		inteligence = intel;
	}
	stats getdamage() 
	{
		return damage;
	}
	stats getinteligence()
	{
		return inteligence;
	}

protected:
	void inccreasestats(stats dmg, stats intel)
	{
		damage += dmg;
		inteligence += intel;
	}

};