#pragma once
#include <string>
#include <GL/glut.h>
#include "IDrawable.h"
#include "Color.h"

enum class Anchor {
	Left,
	Right,
	Center
};

class TextComponent : public IDrawable
{
public:
	TextComponent();
	TextComponent(std::string text);
	TextComponent(std::string text, int x, int y);
	TextComponent(std::string text, Color color);
	TextComponent(std::string text, int x, int y, Anchor anchor);
	TextComponent(std::string text, Color color, int x, int y, Anchor anchor);
	void draw();
	void setText(std::string text);
	void setAnchor(Anchor anchor);
private:
	void printString();
	std::string text = "";
	Color fontColor;
	Anchor anchor;

	static GLubyte characters[][13];
};

