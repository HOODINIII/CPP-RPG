#pragma once
#include "Stat_Type.h"
// class to inherit
class statblock
{
public:
	stats damage;
	stats inteligence;

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

};