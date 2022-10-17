#include "Engine.h"

using namespace std;

Engine::Engine(EngineType type, float volume, int power) : _type(type), _volume(volume), _power(power)
{ }

void Engine::SetType(EngineType type)
{
	_type = type;
}

void Engine::SetVolume(float volume)
{
	_volume = volume;
}

void Engine::SetPower(int power)
{
	_power = power;
}

EngineType Engine::GetType() const
{
	return _type;
}

float Engine::GetVolume() const
{
	return _volume;
}

int Engine::GetPower() const
{
	return _power;
}

void Engine::GetEngineInformation() const
{
	cout << "Information about car engine:" << endl << "engine type is " <<EnumToString(_type) << "; engine volume is " << _volume << "; engine power is " << _power << "." << endl;
}


string EnumToString(EngineType engineType)
{
	switch (engineType)
	{
	case EngineType::internalCombustionEngine:
		return "internal combustion engine";
	case EngineType::electricEngine:
		return "electric engine";
	default:
		return "";
	}
}