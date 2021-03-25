#pragma once
#include <GL/glut.h>

enum class PaletteColors {
	White,
	Yellow,
	Orange,
	Red,
	Magenta,
	Purple,
	Blue,
	Cyan,
	Green,
	DarkGreen,
	Brown,
	Tan,
	LightGrey,
	MediumGrey,
	DarkGrey,
	Black
};

class Color
{
public:
	static Color colorLookup(PaletteColors color);
	Color();
	Color(PaletteColors paletteColor);
	Color(PaletteColors paletteColor, float a);
	Color(float r, float g, float b);
	Color(float r, float g, float b, float a);
	Color(int r, int g, int b);
	Color(int r, int g, int b, int a);
	Color(int r, int g, int b, float a);
	void applyColor();
	void setColor(PaletteColors paletteColor);
	void setColor(PaletteColors paletteColor, float a);
	void setColor(float r, float g, float b);
	void setColor(float r, float g, float b, float a);
	void setColor(int r, int g, int b);
	void setColor(int r, int g, int b, int a);
	void setColor(int r, int g, int b, float a);
	float getRed();
	float getGreen();
	float getBlue();
	float getAlpha();
private:
	float r = 0;
	float g = 0;
	float b = 0;
	float a = 0;
};

inline void glClearColor(Color color) {
	glClearColor(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
}

inline void glColor(Color color) {
	glColor4f(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
}
