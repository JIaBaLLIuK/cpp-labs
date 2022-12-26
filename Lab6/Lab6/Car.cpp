#include "Car.h"

Car::Car(int power, int length, int width, int height) : power(power), length(length), width(width), height(height)
{
	cout << "Input car brand:" << endl;
	cin >> brand;
}

ofstream& operator<<(ofstream& file, Car& car)
{
	file << car.brand << endl << car.power << endl << car.length << endl << car.width << endl << car.height << endl;	
	return file;
}

ostream& operator<<(ostream& stream, Car& car)
{
	cout << car.brand << endl << car.power << endl << car.length << endl << car.width << endl << car.height << endl;
	return stream;
}
