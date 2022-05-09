#pragma once
#include <cstdint>
typedef std::uint16_t setting;
class Worldsetting
{
public:
	//checking if the current  is within max 
	bool setMax(setting new_max)
	{
		if (new_max < 1)
		
			return false;
		Max = new_max;
			
			if (Current > Max)
			Current = Max;

			return true;
		}

	setting getMax() // getting Max  from the private class
	{
		return Max;
	}

	setting getCurrent() // getting current  from the private class
	{
		return Current;
	}

	void reduce(setting damage)
	{
		if (damage > Current)
		{
			Current = 0;
			return;
		}

		Current -= damage;
	}
	void increase(setting heal)
	{
		if (Current + heal > Max)
		{
			Current = Max;
			return;
		}
		Current += heal;
	}

	//constructor default
	Worldsetting()
	{
		Current = 1;
		Max = 1;
	}
	Worldsetting(setting C, setting M)
	{
		Current = C;
		Max = M;
		if (Current > Max)
		{
			Current = Max;
		}

	}

private:
	setting Max; 
	setting Current; 
};