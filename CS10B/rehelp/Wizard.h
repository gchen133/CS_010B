#include "Character.h"

#ifndef __WIZARD_H__
#define __WIZARD_H__

class Wizard : public Character {
 private:
	int rank;

 public:
 	Wizard(const string &name_in, double health_in, double attackStrength_in, int rank_in);
 	int getRank() const;
 	virtual void attack(Character &opponent);
 };

#endif
