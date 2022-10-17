#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>

enum class EngineType
{
	internalCombustionEngine,
	electricEngine,
};

class Engine
{
private:
	EngineType _type;
	float _volume;
	int _power;
public:
	Engine() = default;
	Engine(EngineType, float, int);
	~Engine() = default;
	void SetType(EngineType);
	void SetVolume(float);
	void SetPower(int);
	EngineType GetType() const;
	float GetVolume() const;
	int GetPower() const;
	void GetEngineInformation() const;
};

std::string EnumToString(EngineType);

#endif
