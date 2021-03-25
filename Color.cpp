#include "Color.h"

Color Color::colorLookup(PaletteColors color)
{
	return Color();
}

Color::Color()
{
	setColor(0.0f, 0.0f, 0.0f, 1.0f);
}

Color::Color(PaletteColors paletteColor)
{
	setColor(paletteColor, 1.0f);
}

Color::Color(PaletteColors paletteColor, float a)
{
	setColor(paletteColor, a);
}

Color::Color(float r, float g, float b)
{
	setColor(r, g, b, 1.0f);
}

Color::Color(float r, float g, float b, float a)
{
	setColor(r, g, b, a);
}

Color::Color(int r, int g, int b)
{
	setColor(r, g, b);
}

Color::Color(int r, int g, int b, int a)
{
	setColor(r, g, b, 255);
}

Color::Color(int r, int g, int b, float a)
{
	setColor(r, g, b, a);
}

void Color::applyColor()
{
	glColor4f(this->r, this->g, this->b, this->a);
}

void Color::setColor(PaletteColors paletteColor)
{
	setColor(paletteColor, 1.0f);
}

void Color::setColor(PaletteColors paletteColor, float a)
{
	switch (paletteColor) {
	case PaletteColors::White:
		setColor(0xff, 0xff, 0xff, a);
		break;
	case PaletteColors::Yellow:
		setColor(0xff, 0xff, 0x00, a);
		break;
	case PaletteColors::Orange:
		setColor(0xff, 0x65, 0x00, a);
		break;
	case PaletteColors::Red:
		setColor(0xdc, 0x00, 0x00, a);
		break;
	case PaletteColors::Magenta:
		setColor(0xff, 0x00, 0x97, a);
		break;
	case PaletteColors::Purple:
		setColor(0x36, 0x00, 0x97, a);
		break;
	case PaletteColors::Blue:
		setColor(0x00, 0x00, 0xca, a);
		break;
	case PaletteColors::Cyan:
		setColor(0x00, 0x97, 0xff, a);
		break;
	case PaletteColors::Green:
		setColor(0x00, 0xa8, 0x00, a);
		break;
	case PaletteColors::DarkGreen:
		setColor(0x00, 0x65, 0x00, a);
		break;
	case PaletteColors::Brown:
		setColor(0x65, 0x36, 0x00, a);
		break;
	case PaletteColors::Tan:
		setColor(0x97, 0x65, 0x36, a);
		break;
	case PaletteColors::LightGrey:
		setColor(0xb9, 0xb9, 0xb9, a);
		break;
	case PaletteColors::MediumGrey:
		setColor(0x86, 0x86, 0x86, a);
		break;
	case PaletteColors::DarkGrey:
		setColor(0x45, 0x45, 0x45, a);
		break;
	case PaletteColors::Black:
		setColor(0x00, 0x00, 0x00, a);
		break;
	}
}

void Color::setColor(float r, float g, float b)
{
	setColor(r, g, b, 1.0f);
}

void Color::setColor(float r, float g, float b, float a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

void Color::setColor(int r, int g, int b)
{
	setColor(r, g, b, 255);
}

void Color::setColor(int r, int g, int b, int a)
{
	setColor(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
}

void Color::setColor(int r, int g, int b, float a)
{
	setColor(r / 255.0f, g / 255.0f, b / 255.0f, a);
}

float Color::getRed()
{
	return r;
}

float Color::getGreen()
{
	return g;
}

float Color::getBlue()
{
	return b;
}

float Color::getAlpha()
{
	return a;
}


