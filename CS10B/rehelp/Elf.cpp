#include <iostream>
#include "Elf.h"

Elf::Elf(const string &name_in, double health_in, double attackStrength_in, const string& familyName_in)
    : Character(ELF, name_in, health_in, attackStrength_in),
      familyName(familyName_in)
{}

const string & Elf::getFamilyName() const
{
    return familyName;
}

// The elf does not attack an elf from its own family.
// The damage done by the elf is the percentage of the elf's health
// remaining (health / MAX_HEALTH) multiplied by the elf's attack strength.
void Elf::attack(Character &opponent)
{
    if (opponent.getType() == ELF)
    {
        Elf &opp = dynamic_cast<Elf &>(opponent);
        if (opp.getFamilyName() == familyName)
        {
            cout << "Elf " << name << " does not attack Elf " << opponent.getName() << "." << endl;
            cout << "They are both members of the " << familyName << " family." << endl;
            return;
        }
    }

    double d = health / MAX_HEALTH * attackStrength;
    opponent.damage(d);

    cout << "Elf " << name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
    cout << opponent.getName() << " takes " << (double)d << " damage." << endl;
}
