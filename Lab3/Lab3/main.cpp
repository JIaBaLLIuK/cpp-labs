#include <iostream>
#include "Car.h"

using namespace std;

int main()
{
	Car renault("renault", EngineType::internalCombustionEngine, 4.5f, 150, 4, 4500, 1400, 1600, "red");
	renault.GetCarInformation();
	cout << "----------------------------------------------------------------" << endl;
	Car tesla("tesla");
	tesla.SetColor("black");
	tesla.SetDoorsAmount(4);
	tesla.SetLength(5000);
	tesla.SetHeight(1600);
	tesla.SetWidth(2000);
	tesla.SetType(EngineType::electricEngine);
	tesla.SetVolume(0.f);
	tesla.SetPower(550);
	tesla.GetCarInformation();
	return 0;
}
