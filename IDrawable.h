#pragma once
#include <vector>

class IDrawable
{
public:
	static void drawObjects();
	IDrawable();
	~IDrawable();
	virtual void draw() = 0;
	virtual void setX(int x);
	virtual void setY(int y);
	virtual void setVisible(bool val);
	virtual void setDrawDepth(int depth);
private:
	static std::vector<IDrawable*> Drawables[10];
	static bool startup; //dummy static variable used to call an initilaization function
	static bool init();
protected:
	int xpos; 
	int ypos;
	bool isVisable;
	int drawDepth;
};

