#pragma once
#include "IDrawable.h"
#include "Color.h"

enum class Icons
{
	Square,
	Triangle,
	Cat
};

class Icon : public IDrawable
{
public:
	Icon();
	Icon(Icons iconName, int x, int y);
	Icon(Icons iconName, int x, int y, float size);
	Icon(Icons iconName, int x, int y, Color fill);
	Icon(Icons iconName, int x, int y, Color fill, Color lines);
	Icon(Icons iconName, int x, int y, float size, Color fill);
	Icon(Icons iconName, int x, int y, float size, Color fill, Color lines);
	void draw();
	void draw(int x, int y);
private:
	Color fill;
	Color lines;
	Icons iconName;
	float sizeMultiplyer;
};

