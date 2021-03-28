#include "IClickable.h"

IClickable::IClickable()
{
	clickables.push_back(this);
}

IClickable::~IClickable()
{
	clickables.erase(std::remove(clickables.begin(), clickables.end(), this));
}

void IClickable::setClickable(bool clickable)
{
	this->isClickable = clickable;
}

void IClickable::triggerClicks(int x, int y)
{
	triggerClicks(x, y, false);
}

void IClickable::triggerClicks(int x, int y, bool deep)
{
	for (int i = 0; i < clickables.size(); i++) {
		if (clickables[i]->checkClicked(x , y)) {
			clickables[i]->onClick();
			if (!deep) {
				return;
			}
		}
	}
}

std::vector<IClickable*> IClickable::clickables = std::vector<IClickable*>();