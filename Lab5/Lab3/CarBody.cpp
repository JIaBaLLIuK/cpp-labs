#include "CarBody.h"
#include "Exception.h"

using namespace std;

CarBody::CarBody(int doorsAmount, int length, int width, int height) : _doorsAmount(doorsAmount), _length(length), _width(width), _height(height)
{ }

void CarBody::SetDoorsAmount(int doorsAmount)
{
	if (doorsAmount < 1)
	{
		throw ArgumentOutOfRangeException<int>("doors amount can not be less then 1", doorsAmount, 2);
	}

	_doorsAmount = doorsAmount;
}

void CarBody::SetLength(int length)
{
	if (length < 2000)
	{
		throw ArgumentOutOfRangeException<int>("car length can not be less then 2000", length, 2);
	}
	
	_length = length;
}

void CarBody::SetWidth(int width)
{
	if (width < 1000)
	{
		throw ArgumentOutOfRangeException<int>("car width can not be less then 1000", width, 2);
	}
	
	_width = width;
}

void CarBody::SetHeight(int height)
{
	if (height < 800)
	{
		throw ArgumentOutOfRangeException<int>("car height can not be less then 800", height, 2);
	}
	
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
