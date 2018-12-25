#ifndef COLOR_H
#define COLOR_H

class Color
{
	public:

		/** Create a new instance of Color. **/
		Color(int r, int g, int b);

		/** Copy constructor. **/
		Color(const Color& other);

		/** Get the R component of this color. **/
		int getR() const;

		/** Get the G component of this color. **/
		int getG() const;

		/** Get the B component of this color. **/
		int getB() const;
	
		Color operator*(float scalar) const;

		/** Return an RGB integer representation of this color.**/	
		int toInt() const;
	
	private:
		int _r, _g, _b;
};

const Color COLOR_DEFAULT = Color(0xff, 0x0, 0x0);
const Color COLOR_RED = Color(0xff, 0x0, 0x0);
const Color COLOR_GREEN = Color(0x0, 0xff, 0x0);
const Color COLOR_BLUE = Color(0x0, 0x0, 0xff);

#endif //COLOR_H

