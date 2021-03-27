#pragma once
#include <vector>

class IDrawable
{
public:
	static void drawObjects();
	IDrawable();
	~IDrawable();
	virtual void draw() = 0;
	virtual void setX(int x) = 0;
	virtual void setY(int y) = 0;
	virtual void setVisible(bool val) = 0;
private:
	static std::vector<IDrawable*> Drawables;
protected:
	int xpos; 
	int ypos;
	bool isVisable;
};

