#pragma once
#include "IDrawable.h"
#include "Color.h"

enum class Icons
{
	Square,
	Triangle,
	Cat
};

class Icon : IDrawable
{
public:
	Icon(Icons iconName);
	Icon(Icons iconName, float size);
	Icon(Icons iconName, Color fill);
	Icon(Icons iconName, Color fill, Color lines);
	Icon(Icons iconName, float size, Color fill);
	Icon(Icons iconName, float size, Color fill, Color lines);
	void draw(int x, int y);
private:
	Color fill;
	Color lines;
	Icons iconName;
	float sizeMultiplyer;
};

