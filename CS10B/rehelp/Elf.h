#include "Character.h"

#ifndef __ELF_H__
#define __ELF_H__

class Elf : public Character {
 private:
	string familyName;

 public:
 	Elf(const string &name_in, double health_in, double attackStrength_in, const string& familyName_in);
	const string & getFamilyName() const;
 	virtual void attack(Character &opponent);
 };

#endif
