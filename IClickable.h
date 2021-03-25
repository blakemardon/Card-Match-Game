#pragma once
class IClickable
{
public:
	virtual void onClick() = 0;
	virtual void checkClicked(int x, int y) = 0;
private:
	int topx;
	int lefty;
	int height;
	int length;
};

