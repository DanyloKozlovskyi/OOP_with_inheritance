#pragma once
#include<string>
#include<iostream>
class Car
{
protected:
	std::string marka_;
	int year_;
public:
	int Year()const;
	std::string Marka()const;
	virtual void Input(std::istream& is);
	virtual void Show(std::ostream& os);
};

