#include<iostream>
#include<fstream>
#include<string>
#include"Car.h"
#include"Sportcar.h"
#include"Truck.h"

void Fill(std::istream& is, Car**array_of_cars, int size_of_array_cars) {
	Car* temp_car = new Car;
	Sportcar* temp_sportcar = new Sportcar;
	Truck* temp_truck = new Truck;
	int temp;
	for (int i = 0; i < size_of_array_cars; ++i) {
		is >> temp;
		if (temp == 1) {
			temp_car->Input(is);
			array_of_cars[i] = new Car(*temp_car);
		}
		if (temp == 2) {
			temp_sportcar->Input(is);
			array_of_cars[i] = new Sportcar(*temp_sportcar);
		}
		if (temp == 3) {
			temp_truck->Input(is);
			array_of_cars[i] = new Truck(*temp_truck);
		}
	}
}

void OutputTheArray(Car** array_of_cars, int size_of_array_cars) {
	for (int i = 0; i < size_of_array_cars; ++i) {
		array_of_cars[i]->Show(std::cout);
		std::cout << "\n";
	}
}

Car* TheNewestCar(Car** array_of_cars, int size_of_array_cars) {
	Car* youngest = array_of_cars[0];
	for (int i = 1; i < size_of_array_cars; ++i) {
		if (array_of_cars[i]->Year() > youngest->Year()) {
			youngest = array_of_cars[i];
		}
	}
	return youngest;
}

Sportcar* TheHighestSpeed(Car** array_of_cars, int size_of_array_cars) {
	Sportcar* check_whether_car_is_sportcar = nullptr, * sportcar_with_max_speed = new Sportcar;
	int j = 0;
	while (check_whether_car_is_sportcar == nullptr) {
		check_whether_car_is_sportcar = dynamic_cast<Sportcar*>(array_of_cars[j]);
		++j;
	}
	for (int i = 0; i < size_of_array_cars; ++i) {
		check_whether_car_is_sportcar = dynamic_cast<Sportcar*>(array_of_cars[i]);
		if (check_whether_car_is_sportcar != nullptr) {
			if (sportcar_with_max_speed->MaxSpeed() < check_whether_car_is_sportcar->MaxSpeed()) {
				sportcar_with_max_speed = check_whether_car_is_sportcar;
			}
		}
	}
	return sportcar_with_max_speed;
}

int main() {
	int size_of_array_cars;
	std::ifstream ifs("data.txt");
	ifs >> size_of_array_cars;
	Car** array_of_cars = new Car * [size_of_array_cars];
	Fill(ifs, array_of_cars, size_of_array_cars);
	OutputTheArray(array_of_cars, size_of_array_cars);
	std::cout << "\n\n";

	Car* newest_car = TheNewestCar(array_of_cars, size_of_array_cars);
	newest_car->Show(std::cout);
	std::cout << "\n";

	Sportcar* sportcar_with_max_speed = TheHighestSpeed(array_of_cars, size_of_array_cars);
	sportcar_with_max_speed->Show(std::cout);
	std::cout << "\n";

}