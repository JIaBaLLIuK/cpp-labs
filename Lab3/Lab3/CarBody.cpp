#include "CarBody.h"

using namespace std;

CarBody::CarBody(int doorsAmount, int length, int width, int height) : _doorsAmount(doorsAmount), _length(length), _width(width), _height(height)
{ }

void CarBody::SetDoorsAmount(int doorsAmount)
{
	_doorsAmount = doorsAmount;
}

void CarBody::SetLength(int length)
{
	_length = length;
}

void CarBody::SetWidth(int width)
{
	_width = width;
}

void CarBody::SetHeight(int height)
{
	_height = height;
}

int CarBody::GetDoorsAmount() const
{
	return _doorsAmount;
}

int CarBody::GetLength() const
{
	return _length;
}

int CarBody::GetWidth() const
{
	return _width;
}

int CarBody::GetHeight() const
{
	return _height;
}

void CarBody::GetCarBodyInformation() const
{
	cout << "Information about car body:" << endl << "number of doors is " << _doorsAmount << "; length is " << _length << "; width is " << _width << "; height is " << _height << "." << endl;
}
