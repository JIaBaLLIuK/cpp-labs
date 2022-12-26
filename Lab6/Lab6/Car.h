#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <fstream>

using namespace std;

class Car
{
public:
	Car(int, int, int, int);
	~Car() = default;
	friend ofstream& operator << (ofstream&, Car&);
	friend ostream& operator << (ostream&, Car&);

private:
	char brand[20];
	int power;
	int length;
	int width;
	int height;
};

#endif