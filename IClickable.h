#pragma once
#include <vector>

class IClickable
{
public:
	IClickable();
	~IClickable();
	virtual void onClick() = 0;
	virtual bool checkClicked(int x, int y) = 0;
	void setClickable(bool clickable);
	static void triggerClicks(int x, int y);
	static void triggerClicks(int x, int y, bool deep);
private:
	static std::vector<IClickable*> clickables;
	bool isClickable;
};

