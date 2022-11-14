#ifndef CAR_BODY_H
#define CAR_BODY_H

#include <iostream>

class CarBody
{
private:
	int _doorsAmount;
	int _length;
	int _width;
	int _height;
public:
	CarBody() = default;
	CarBody(int, int, int, int);
	~CarBody() = default;
	void SetDoorsAmount(int);
	void SetLength(int);
	void SetWidth(int);
	void SetHeight(int);
	int GetDoorsAmount() const;
	int GetLength() const;
	int GetWidth() const;
	int GetHeight() const;
	void GetCarBodyInformation() const;
};

#endif
