#pragma once
#include "Car.h"
class Sportcar : public Car
{
private:
	double max_speed_;
public:
	double MaxSpeed()const;
	void Input(std::istream& is)override;
	void Show(std::ostream& os)override;
};

