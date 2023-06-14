#include "Car.h"

int Car::Year() const
{
    return year_;
}

std::string Car::Marka() const
{
    return marka_;
}

void Car::Input(std::istream& is)
{
    is >> marka_;
    int a;
    is >> a;
    year_ = a;
}

void Car::Show(std::ostream& os)
{
    os << marka_;
    os << " " << year_;
}
