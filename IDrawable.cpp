#include "IDrawable.h"

void IDrawable::drawObjects()
{
	for (int i = 0; i < Drawables.size(); i++) {
		Drawables[i]->draw();
	}
}

IDrawable::IDrawable()
{
	Drawables.push_back(this);
	isVisable = true;
	xpos = 0;
	ypos = 0;
}

IDrawable::~IDrawable()
{
	Drawables.erase(std::remove(Drawables.begin(), Drawables.end(), this));
}

std::vector<IDrawable*> IDrawable::Drawables = std::vector<IDrawable*>();
