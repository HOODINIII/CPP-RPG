#pragma once
#include "Stat.h"
#include "Ability.h"
#include <cstdint>
#include <memory>
#include <string>
#include "Worldsetting.h"
#include <vector>
typedef std::uint64_t experience;
typedef std::uint16_t Levels;
class Playercharacter : public statblock
{
public:
	static const experience level2at = 100u; // xp required at level 2, xp require at level 3 with times this by 2 see below.
	Playercharacter() : statblock(0u, 0u, 0u, 0u)
	{
		Currentlevel = 1u;
		CurrentEXP = 0u;
		Maxlevels = 50;
		xpforlevelup = level2at;
		HP = std::make_unique<Worldsetting>();
	}

	void EXPgain(experience gained_exp)
	{
		CurrentEXP += gained_exp;
		while (Check_level_up()) {}
	}

	Levels getCurrentlevel()
	{
		return Currentlevel;
	}

	experience getCurrentEXP()
	{
		return CurrentEXP;
	}

	experience getxpforlevelup()
	{
		return xpforlevelup;
	}

	virtual void levellingup() = 0; // pure virtual functions allows the behaviour of the function to be changed in the derived classes.
	virtual std::string getClassname() = 0;
	std::unique_ptr<Worldsetting> HP;
	std::vector <ability> abilities;

protected:
	int Maxlevels;
	Levels Currentlevel;
	experience CurrentEXP; // using uint 64 as it will give highest value to make the xp system. the xp system will level up the class but each level will require more xp.
	experience xpforlevelup;


	bool Check_level_up()			//check to see if the player has any pending levels
	{
		static const Levels expmultiplyer = 2u; //xp multiplyer, times xp required by 2 everytime the player levels up.
		if (CurrentEXP > xpforlevelup)
		{
			Currentlevel++;
			levellingup(); //when leveled up the function should call pure virtual function
			xpforlevelup *= expmultiplyer;
			return true;
		}
		return false;
	}
};

#define LEVELLING HP->setMax(BaseHP); HP->increase(BaseHP); inccreasestats(Basedmg, Baseintel, Baseeng, Basemanapool); //using define macro so that we can use this code in any new classes without having to write up more code
//define macro for levelling up didnt end up working and would not solve no mater what I tried so I reverted to the previous code. hope to fix it in future.
class knight :public Playercharacter
{
public:
	static const setting BaseHP = 100u;				//using static constant to only intentiate once no matter the number of knights.
	static const stats Basedmg = 60u;					// knights will spawn with hp of 100.
	static const stats Baseintel = 20u;
	static const stats Baseeng = 100u;
	static const stats Basemanapool = 0u;


	knight() : Playercharacter()
	{
		LEVELLING;
	}
		

	std::string getClassname() override //make sure to name them right the next time so you dont have to spend time looking for errors. :(
	{
		return std::string("Knight");
	}
private:

	void levellingup() override					
	{
		HP->setMax((setting)((BaseHP/2.f) + HP->getMax())); //inner brackets are done first.
		HP->increase((setting)(BaseHP / 2.f));
		inccreasestats((stats)(Basedmg + 1u / 2.f),(stats)((Baseintel + 1u) / 2.f),(stats)(Baseeng + 1u / 2.f),(stats)(Basemanapool + 1u / 2.f));
	}
};

class Mage :public Playercharacter
{
public:
	static const setting BaseHP = 100u;				//using static constant to only intentiate once no matter the number of Mage.
	static const stats Basedmg = 50u;					// Mage will spawn with hp of 100.
	static const stats Baseintel = 50u;
	static const stats Baseeng = 0u;
	static const stats Basemanapool = 100u;


	Mage() : Playercharacter()
	{
		LEVELLING;
		abilities.emplace_back();
	}

	std::string getClassname() override
	{
		return std::string("Mage");
	}
private:
	void levellingup() override
	{
		HP->setMax((setting)((BaseHP/2.f) + HP->getMax()));
		HP->increase((setting)(BaseHP / 2.f));
		inccreasestats((stats)(Basedmg + 1u / 2.f),(stats)((Baseintel + 1u) / 2.f),(stats)(Baseeng + 1u / 2.f),(stats)((Basemanapool + 1u) / 2.f));
	}

};

class Preist :public Playercharacter
{
public:
	static const setting BaseHP = 100u;				//using static constant to only intentiate once no matter the number of Preist.
	static const stats Basedmg = 10u;					// Preist will spawn with hp of 100.
	static const stats Baseintel = 70u;
	static const stats Baseeng = 20u;
	static const stats Basemanapool = 80u;

	Preist() : Playercharacter()
	{
		LEVELLING;
	}

	std::string getClassname() override
	{
		return std::string("Preist");
	}
private:
	void levellingup() override
	{
		HP->setMax((setting)((BaseHP/2.f) + HP->getMax()));
		HP->increase((setting)(BaseHP / 2.f));
		inccreasestats((stats)(Basedmg + 1u / 2.f), (stats)((Baseintel + 1u) / 2.f), (stats)(Baseeng + 1u / 2.f), (stats)((Basemanapool + 1u) / 2.f));
	}
};

class player
{
private:
	Playercharacter* pcclass;

public:
	player() = delete;
	player(Playercharacter* pc) : pcclass(pc)
	{	}
	~player() { delete pcclass; pcclass = nullptr; } // if players want to change their character they can delete the player class and reset it with different character.
	std::string getClassname() { return pcclass->getClassname(); }
	Levels getCurrentlevel() { return pcclass->getCurrentlevel(); }
	experience getcurrentEXP() { return pcclass->getCurrentEXP(); }
	experience getxpforlevelup() { return pcclass->getxpforlevelup(); }
	setting getCurrentHP() { return pcclass->HP->getCurrent(); }
	setting getMaxHP() { return pcclass->HP->getMax(); }
	stats getdamage() { return pcclass->getdamage(); }
	stats getinteligence() { return pcclass->getinteligence(); }
	stats getmanapool() { return pcclass->getmanapool(); }
	stats getenergy() { return pcclass->getenergy(); }
	void EXPgain(experience amt) { return pcclass->EXPgain(amt); }
	void damagetaken(setting amt) { return pcclass->HP->reduce(amt); }
	void healing(setting amt) { return pcclass->HP->increase(amt); }



};