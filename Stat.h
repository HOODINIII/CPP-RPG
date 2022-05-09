#pragma once
#include "Stat_Type.h"
#include <cstdint>
// class to inherit
typedef std::uint16_t stats;
class statblock
{
	stats damage;				//private variables
	stats inteligence;
	stats energy;
	stats mana;
public:							//construct
	statblock()
	{
		damage = 1u;
		inteligence = 1u;
		energy = 1u;
		mana = 1u;
	}

	statblock(stats dmg, stats intel, stats eng, stats manapool)
	{
		damage = dmg;
		inteligence = intel;
		energy = eng;
		mana = manapool;
	}
	stats getdamage() 
	{
		return damage;
	}
	stats getenergy()
	{
		return energy;
	}
	stats getmanapool()
	{
		return mana;
	}
	stats getinteligence()
	{
		return inteligence;
	}

protected:
	void inccreasestats(stats dmg, stats intel, stats eng, stats manapool)
	{
		damage += dmg;
		inteligence += intel;
		energy += eng;
		mana += manapool;
	}

};