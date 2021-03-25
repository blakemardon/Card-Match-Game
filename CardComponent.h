#pragma once
#include "IClickable.h"
#include "IDrawable.h"
#include "Color.h"

enum class Facing
{
	Up,
	Down
};

class CardComponent : IClickable, IDrawable
{
public:
	CardComponent();
	void onClick();
	void checkClicked(int x, int y);
	void draw(int x, int y);
private:
	Facing face;
};

