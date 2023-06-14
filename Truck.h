#pragma once
#include "Car.h"
class Truck : public Car
{
private:
	double max_weight_;
public:
	void Input(std::istream& is)override;
	void Show(std::ostream& os)override;
};

