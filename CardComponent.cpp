#include "CardComponent.h"

CardComponent::CardComponent(Icon &icon, int x, int y, double xScale, double yScale, CardMatch* game)
{
	this->icon = icon;
	this->icon.setDrawDepth(4);
	this->face = Facing::Up;
	this->setDrawDepth(3);
	this->xpos = x;
	this->ypos = y;
	xMultiplyer = xScale;
	yMultiplyer = yScale;
	currentGame = game;
}

void CardComponent::onClick()
{
	flip();
	currentGame->cardClicked(this);
}

bool CardComponent::checkClicked(int x, int y)
{
	if (x >= xpos - (50 * xMultiplyer) && x <= xpos + (50 * yMultiplyer)) {
		if (y >= ypos - (50 * xMultiplyer) && y <= ypos + (50 * yMultiplyer)) {
			return true;
		}
	}
	return false;
}

void CardComponent::draw(int x, int y)
{
	if (face == Facing::Up) {
		icon.setVisible(true);
		glColor(PaletteColors::White);
		glBegin(GL_POLYGON);
		glVertex2i(x - (50 * xMultiplyer), y + (50 * yMultiplyer));
		glVertex2i(x + (50 * xMultiplyer), y + (50 * yMultiplyer));
		glVertex2i(x + (50 * xMultiplyer), y - (50 * yMultiplyer));
		glVertex2i(x - (50 * xMultiplyer), y - (50 * yMultiplyer));
		glEnd();
	}
	else {
		icon.setVisible(false);
		glColor(PaletteColors::Blue);
		glBegin(GL_POLYGON);
		glVertex2i(x - (50 * xMultiplyer), y + (50 * yMultiplyer));
		glVertex2i(x + (50 * xMultiplyer), y + (50 * yMultiplyer));
		glVertex2i(x + (50 * xMultiplyer), y - (50 * yMultiplyer));
		glVertex2i(x - (50 * xMultiplyer), y - (50 * yMultiplyer));
		glEnd();
		glColor(PaletteColors::Yellow);
		glBegin(GL_LINE_LOOP);
		glVertex2i(x - (50 * xMultiplyer), y + (50 * yMultiplyer));
		glVertex2i(x + (50 * xMultiplyer), y + (50 * yMultiplyer));
		glVertex2i(x + (50 * xMultiplyer), y - (50 * yMultiplyer));
		glVertex2i(x - (50 * xMultiplyer), y - (50 * yMultiplyer));
		glEnd();
		glBegin(GL_LINES);
		glVertex2i(x - (50 * xMultiplyer), y + (30 * yMultiplyer));
		glVertex2i(x - (30 * xMultiplyer), y + (50 * yMultiplyer));

		glVertex2i(x - (50 * xMultiplyer), y - (10 * yMultiplyer));
		glVertex2i(x + (10 * xMultiplyer), y + (50 * yMultiplyer));

		glVertex2i(x - (50 * xMultiplyer), y - (50 * yMultiplyer));
		glVertex2i(x + (50 * xMultiplyer), y + (50 * yMultiplyer));

		glVertex2i(x - (10 * xMultiplyer), y - (50 * yMultiplyer));
		glVertex2i(x + (50 * xMultiplyer), y + (10 * yMultiplyer));

		glVertex2i(x + (30 * xMultiplyer), y - (50 * yMultiplyer));
		glVertex2i(x + (50 * xMultiplyer), y - (30 * yMultiplyer));

		glVertex2i(x + (30 * xMultiplyer), y + (50 * yMultiplyer));
		glVertex2i(x + (50 * xMultiplyer), y + (30 * yMultiplyer));

		glVertex2i(x - (10 * xMultiplyer), y + (50 * yMultiplyer));
		glVertex2i(x + (50 * xMultiplyer), y - (10 * yMultiplyer));

		glVertex2i(x - (50 * xMultiplyer), y + (50 * yMultiplyer));
		glVertex2i(x + (50 * xMultiplyer), y - (50 * yMultiplyer));

		glVertex2i(x - (50 * xMultiplyer), y + (10 * yMultiplyer));
		glVertex2i(x + (10 * xMultiplyer), y - (50 * yMultiplyer));

		glVertex2i(x - (50 * xMultiplyer), y - (30 * yMultiplyer));
		glVertex2i(x - (30 * xMultiplyer), y - (50 * yMultiplyer));

		glEnd();
	}
}

void CardComponent::draw()
{
	draw(xpos, ypos);
}

void CardComponent::flip()
{
	if (face == Facing::Up) {
		face = Facing::Down;
	}
	else {
		face = Facing::Up;
	}
}
