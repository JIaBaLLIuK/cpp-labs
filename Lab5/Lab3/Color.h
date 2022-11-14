#ifndef COLOR_H
#define COLOR_H

#include <iostream>

class Color
{
private:
	std::string _color;
public:
	Color() = default;
	explicit Color(const std::string&);
	~Color() = default;
	void SetColor(const std::string&);
	std::string GetColor() const;
	void GetColorInformation() const;
};

#endif
