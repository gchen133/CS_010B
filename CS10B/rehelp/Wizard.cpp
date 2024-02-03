#include <iostream>
#include "Wizard.h"

Wizard::Wizard(const string &name_in, double health_in, double attackStrength_in, int rank_in)
    : Character(WIZARD, name_in, health_in, attackStrength_in),
      rank(rank_in)
{}

int Wizard::getRank() const
{
    return rank;
}

// When a wizard attacks another wizard, the damage done is the wizard's attack strength
// multiplied by the ratio of the attacking wizard's rank over the defending wizard's rank.
// The damage done to non-wizards is just the attack strength. The wizard's health is not
// taken into consideration.
void Wizard::attack(Character &opponent)
{
    double d = 0.0;

    if (opponent.getType() == WIZARD)
    {
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        d = attackStrength * rank / opp.getRank();
    }
    else
    {
        d = attackStrength;
    }

    opponent.damage(d);

    cout << "Wizard " << name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
    cout << opponent.getName() << " takes " << d << " damage." << endl;
}

