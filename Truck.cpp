#include "Truck.h"

void Truck::Input(std::istream& is)
{
	Car::Input(is);
	is >> max_weight_;
}

void Truck::Show(std::ostream& os)
{
	Car::Show(os);
	os << " " << max_weight_;
}
