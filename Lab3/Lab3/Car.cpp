#include "Car.h"

using namespace std;

Car::Car(const string& brand) : _brand(brand)
{ }

Car::Car(const std::string& brand, EngineType engineType, float volume, int power, int doorsAmount, int length, int width, int height, const std::string& color) :
	Engine(engineType, volume, power), CarBody(doorsAmount, length, width, height), Color(color), _brand(brand)
{ }

void Car::GetCarInformation() const
{
	cout << "Car brand is " << _brand << "." << endl;
	GetColorInformation();
	GetCarBodyInformation();
	GetEngineInformation();
}
