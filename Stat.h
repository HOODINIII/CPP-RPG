#pragma once
#include "Stat_Type.h"
// class to inherit
class StatBlock
{
public:
	stats damage;
	stats inteligence;

	StatBlock()
	{
		damage = 1u;
		inteligence = 1u;
	}
};