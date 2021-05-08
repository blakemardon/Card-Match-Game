
#include "IDrawable.h"

void IDrawable::drawObjects()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < Drawables[i].size(); j++) {
			Drawables[i][j]->draw();
		}
	}
}

IDrawable::IDrawable()
{
	isVisable = true;
	xpos = 0;
	ypos = 0;
	drawDepth = -1;
}

IDrawable::~IDrawable()
{
	std::vector<IDrawable*>::iterator pos = std::find(Drawables[drawDepth].begin(), Drawables[drawDepth].end(), this);
	if (pos == Drawables[drawDepth].end()) {
		//draw depth was never set
	}
	else {
		Drawables[drawDepth].erase(std::remove(Drawables[drawDepth].begin(), Drawables[drawDepth].end(), this));
	}
	
}

void IDrawable::setX(int x)
{
	xpos = x;
}

void IDrawable::setY(int y)
{
	ypos = y;
}

void IDrawable::setVisible(bool val)
{
	isVisable = val;
}

void IDrawable::setDrawDepth(int depth)
{
	if (drawDepth == -1) {
		//draw depth was never set
	}
	else {
		std::vector<IDrawable*>::iterator pos = std::find(Drawables[drawDepth].begin(), Drawables[drawDepth].end(), this);
		if (pos == Drawables[drawDepth].end()) {
			// assignment operator construction
		}
		else {
			Drawables[drawDepth].erase(std::remove(Drawables[drawDepth].begin(), Drawables[drawDepth].end(), this));
		}
	}
	drawDepth = depth;
	Drawables[drawDepth].push_back(this);
}

//this is needed to initialize the array of drawable objects
bool IDrawable::init()
{
	for (int i = 0; i < 10; i++) {
		Drawables[i] = std::vector<IDrawable*>();
	}
	return true;
}

std::vector<IDrawable*> IDrawable::Drawables[10];
bool IDrawable::startup = init(); //dummy static variable used to call an initilaization function
