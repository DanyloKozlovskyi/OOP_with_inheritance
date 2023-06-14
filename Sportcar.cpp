#include "Sportcar.h"

double Sportcar::MaxSpeed() const
{
    return max_speed_;
}

void Sportcar::Input(std::istream& is)
{
    Car::Input(is);
    is >> max_speed_;
}

void Sportcar::Show(std::ostream& os)
{
    Car::Show(os);
    os << " " << max_speed_;
}
