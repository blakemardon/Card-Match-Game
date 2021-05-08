#pragma once
#include "IClickable.h"
#include "IDrawable.h"
#include "Color.h"
#include "Icon.h"
#include "CardMatch.h"

enum class Facing
{
	Up,
	Down
};

class CardComponent : public IClickable, public IDrawable
{
public:
	CardComponent(Icon &icon, int x, int y, double xScale, double yScale, CardMatch* game);
	void onClick();
	bool checkClicked(int x, int y);
	void draw(int x, int y);
	void draw();
	void flip();
private:
	Facing face;
	Icon icon;
	bool isVisable;
	float xMultiplyer;
	float yMultiplyer;
	CardMatch* currentGame;
};