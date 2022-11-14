#ifndef CAR_H
#define CAR_H

#include "Engine.h"
#include "CarBody.h"
#include "Color.h"

class Car : public Engine, public CarBody, public Color
{
private:
	std::string _brand;
public:
	Car() = default;
	explicit Car(const std::string&);
	Car(const std::string&, EngineType, float, int, int, int, int, int, const std::string&);
	~Car() = default;
	void GetCarInformation() const;
};

#endif
