#include "Distance.h"

Distance::Distance()
{
    feet = 0;
    inches = 0.0;    
}

Distance::Distance(unsigned ft, double in)
    : feet(ft),
      inches(in)
{
    init();
}

Distance::Distance(double in)
    : feet(0),
      inches(in)
{
    init();
}

unsigned Distance::getFeet() const
{
    return feet;
}

double Distance::getInches() const
{
    return inches;
}

double Distance::distanceInInches() const
{
    return feet * 12.0 +  inches;
}

double Distance::distanceInFeet() const
{
    return feet + inches / 12.0;
}

double Distance::distanceInMeters() const
{
    return distanceInInches() * 0.0254;
}

Distance Distance::operator+(const Distance &rhs) const
{
    double total_inches = distanceInInches() + rhs.distanceInInches();

    return Distance(total_inches);
}

Distance Distance::operator-(const Distance &rhs) const
{
    double difference_in_inches = distanceInInches() - rhs.distanceInInches();

    return Distance(difference_in_inches);
}

ostream & operator<<(ostream &out, const Distance &rhs)
{
    out << rhs.getFeet() << "' " << rhs.getInches() << '"';
    return out;
}

void Distance::init()
{
    if (inches < 0.0)
    {
        inches = -inches;
    }

    if (inches >= 12.0)
    {
        unsigned ft = inches / 12;    
        feet += ft;

        inches = inches - ft * 12.0;
    }
}

