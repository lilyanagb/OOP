#pragma once

class Vector4D {
private:
	double v[4];
	const int _size = 4;
public:
	Vector4D();
	Vector4D(double, double, double, double);
	Vector4D(const Vector4D&);
	void setArray(double newArray[]);

	Vector4D operator+(const Vector4D&) const;
	Vector4D operator-(const Vector4D&) const;
	Vector4D operator* (const Vector4D&) const;
	Vector4D operator/ (const Vector4D&) const;

	Vector4D& operator += (const Vector4D&);
	Vector4D& operator -= (const Vector4D&);
	Vector4D& operator *= (const Vector4D&);
	Vector4D& operator /= (const Vector4D&);

	Vector4D operator*(double) const;
	Vector4D& operator *= (double);

	bool operator==(const Vector4D&) const;
	bool operator!=(const Vector4D&) const;

	bool operator< (const Vector4D&) const;
	bool operator> (const Vector4D&) const;
	bool operator<=(const Vector4D&) const;
	bool operator>=(const Vector4D&) const;

	Vector4D& operator= (const Vector4D&);

	Vector4D operator-() const;
	bool operator!() const;
	double& operator[](unsigned int);

	//void copyArray(const Vector4D&);
	//void print();
};

