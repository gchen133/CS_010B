#include <iostream>
#include "Warrior.h"

Warrior::Warrior(const string &name_in, double health_in, double attackStrength_in, const string& allegiance_in)
    : Character(WARRIOR, name_in, health_in, attackStrength_in),
      allegiance(allegiance_in)
{}

const string & Warrior::getAllegiance() const
{
    return allegiance;
}

// The warrior does not attack warriors that have the same allegiance.
// The damage done by the warrior is the percentage of the warrior's health 
// remaining (health / MAX_HEALTH) multiplied by the warrior's attack strength.
void Warrior::attack(Character &opponent)
{
    if (opponent.getType() == WARRIOR)
    {
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        if (opp.getAllegiance() == allegiance)
        {
             cout << "Warrior " << name << " does not attack Warrior " << opp.getName() << "." << endl;
             cout << "They share an allegiance with " << allegiance << "." << endl;
             return;
        }
    }

    double d = health / MAX_HEALTH * attackStrength;
    opponent.damage(d);

    cout << "Warrior " << name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
    cout << opponent.getName() << " takes " << (double)d << " damage." << endl;
}
