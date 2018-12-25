#include "color.h"

Color::Color(int r, int g, int b)
{
	_r = r;
	_g = g;
	_b = b;
}

Color::Color(const Color& other) : _r(other._r), _g(other._g), _b(other._b)
{
	
}

int Color::getR() const
{
	return _r;
}

int Color::getG() const
{
	return _g;
}

int Color::getB() const
{
	return _b;
}

Color Color::operator*(float scalar) const
{
	return Color(_r * scalar, _g * scalar, _b * scalar);

}

int Color::toInt() const
{
	return (_r << 16) + (_g << 8) + (_b);
}

