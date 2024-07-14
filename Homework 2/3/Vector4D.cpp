#include "Vector4D.hpp"
#include <iostream>

Vector4D::Vector4D()
{
	for (int i = 0; i < _size; i++) {
		v[i] = 0;
	}
}

Vector4D::Vector4D(double x0, double x1, double x2, double x3)
{
	v[0] = x0;
	v[1] = x1;
	v[2] = x2;
	v[3] = x3;
}

Vector4D::Vector4D(const Vector4D& rhs) 
{
	for (int i = 0; i < _size; i++) {
		v[i] = rhs.v[i];
	}
}

void Vector4D::setArray(double newArray[])
{
	for (int i = 0; i < _size; i++) {
		v[i] = newArray[i];
	}
}

Vector4D Vector4D::operator+(const Vector4D& newVector) const
{
	Vector4D _Vector;
	_Vector = *this;
	_Vector.v[0] += newVector.v[0];
	_Vector.v[1] += newVector.v[1];
	_Vector.v[2] += newVector.v[2];
	_Vector.v[3] += newVector.v[3];

	return _Vector;
}

Vector4D Vector4D::operator-(const Vector4D& newVector) const
{
	Vector4D _Vector;
	_Vector = *this;
	_Vector.v[0] -= newVector.v[0];
	_Vector.v[1] -= newVector.v[1];
	_Vector.v[2] -= newVector.v[2];
	_Vector.v[3] -= newVector.v[3];

	return _Vector;
}

Vector4D Vector4D::operator*(const Vector4D& newVector) const
{
	Vector4D _Vector;
	_Vector = *this;
	_Vector.v[0] *= newVector.v[0];
	_Vector.v[1] *= newVector.v[1];
	_Vector.v[2] *= newVector.v[2];
	_Vector.v[3] *= newVector.v[3];

	return _Vector;
}

Vector4D Vector4D::operator/(const Vector4D& newVector) const
{
	Vector4D _Vector;
	_Vector = *this;
	_Vector.v[0] /= newVector.v[0];
	_Vector.v[1] /= newVector.v[1];
	_Vector.v[2] /= newVector.v[2];
	_Vector.v[3] /= newVector.v[3];

	return _Vector;
}

Vector4D& Vector4D::operator+=(const Vector4D& newVector)
{
	*this = *this + newVector;
	return *this;
}

Vector4D& Vector4D::operator-=(const Vector4D& newVector)
{
	*this = *this - newVector;
	return *this;
}

Vector4D& Vector4D::operator*=(const Vector4D& newVector)
{
	*this = *this * newVector;
	return *this;
}

Vector4D& Vector4D::operator/=(const Vector4D& newVector)
{
	*this = *this / newVector;
	return *this;
}

bool Vector4D::operator==(const Vector4D& newVector) const
{
	int counter = 0;
	for (int i = 0; i < _size; i++) {
		if (v[i] == newVector.v[i]) {
			counter++;
		}
	}
	if (counter == _size) {
		return true;
	}
	return false;
}

bool Vector4D::operator!=(const Vector4D& newVector) const
{
	int counter = 0;
	for (int i = 0; i < _size; i++) {
		if (v[i] == newVector.v[i]) {
			counter++;
		}
	}
	if (counter != _size) {
		return true;
	}
	return false;
}

bool Vector4D::operator<(const Vector4D& newVector) const
{
	for (int i = 0; i < _size; i++) {
		if (v[i] < newVector.v[i]) {
			return true;
		}
		else if (v[i] > newVector.v[i]) {
			return false;
		}
	}
	return false;
}

bool Vector4D::operator>(const Vector4D& newVector) const
{
	for (int i = 0; i < _size; i++) { // (1, 2, 3, 4) < (1, 2, 3 ,4)
		if (v[i] > newVector.v[i]) {
			return true;
		}
		else if (v[i] < newVector.v[i]) {
			return false;
		}
	}
	return false;
}

bool Vector4D::operator<=(const Vector4D& newVector) const
{
	for (int i = 0; i < _size; i++) { // (1, 2,  3 , 2) <=? (1, 2, 3 , 4)
		if (v[i] > newVector.v[i]) {
			return false;
		}
	}

	return true;
}

bool Vector4D::operator>=(const Vector4D& newVector) const
{
	for (int i = 0; i < _size; i++) {
		if (v[i] < newVector.v[i]) {
			return false;
		}
	}

	return true;
}

Vector4D& Vector4D::operator=(const Vector4D& rhs)
{
	if (&rhs != this)
	{
		for (int i = 0; i < _size; i++) {
			v[i] = rhs.v[i];
		}
	}
	return *this;
}

Vector4D Vector4D::operator-() const
{
	Vector4D _Vector;
	_Vector = *this;
	_Vector.v[0] = -v[0];
	_Vector.v[1] = -v[1];
	_Vector.v[2] = -v[2];
	_Vector.v[3] = -v[3];
	return _Vector;
}

bool Vector4D::operator!() const
{
	for (int i = 0; i < _size; i++) {
		if (v[i] != 0) {
			return false;
		}
	}
	return true;
}

Vector4D Vector4D::operator*(double scalar) const
{
	Vector4D _Vector;
	_Vector = *this;
	_Vector.v[0] = v[0] * scalar;
	_Vector.v[1] = v[1] * scalar;
	_Vector.v[2] = v[2] * scalar;
	_Vector.v[3] = v[3] * scalar;
	return _Vector;
}

Vector4D& Vector4D::operator*=(double scalar)
{
	*this = *this * scalar;
	return *this;
}

double& Vector4D::operator[](unsigned int idx)
{
	return v[idx];
}



//void Vector4D::print()
//{
//	for (int i = 0; i < _size; i++) {
//	
//		std::cout<< v[i] << " ";
//	}
//	std::cout << std::endl;
//}
