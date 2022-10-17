#include "Color.h"

using namespace std;

Color::Color(const std::string& color) : _color(color)
{ }

void Color::SetColor(const string& color)
{
	_color = color;
}

string Color::GetColor() const
{
	return _color;
}

void Color::GetColorInformation() const
{
	cout << "Car color is " << _color << "." << endl;
}
