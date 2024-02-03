#include "Character.h"

Character::Character(HeroType type_in, const string &name_in, double health_in, double attackStrength_in)
    : type(type_in),
      name(name_in),
      health(health_in),
      attackStrength(attackStrength_in)
{}

HeroType Character::getType() const
{
    return type;
}

const string & Character::getName() const
{
    return name;
}

/* Returns the whole number of the health value (static_cast to int). */
int Character::getHealth() const
{
    return static_cast<int>(health);
}

/* Reduces health value by amount passed in. */
void Character::damage(double d)
{
    health -= d;
}

/* Returns true if getHealth() returns an integer greater than 0, otherwise false */
bool Character::isAlive() const
{
    if (getHealth() > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

