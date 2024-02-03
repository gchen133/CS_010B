#include "Character.h"

#ifndef __WARRIOR_H__
#define __WARRIOR_H__

class Warrior : public Character {
 private:
	string allegiance;

 public:
 	Warrior(const string &name_in, double health_in, double attackStrength_in, const string& allegiance_in);
 	const string & getAllegiance() const;
 	virtual void attack(Character &opponent);
 };

#endif
