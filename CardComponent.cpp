#include "CardComponent.h"

CardComponent::CardComponent(Icon &icon, int x, int y)
{
	this->icon = icon;
	this->icon.setDrawDepth(4);
	this->face = Facing::Up;
	this->setDrawDepth(3);
	this->xpos = x;
	this->ypos = y;
	sizeMultiplyer = 1;
}

void CardComponent::onClick()
{
	flip();
}

bool CardComponent::checkClicked(int x, int y)
{
	if (x >= xpos - (50 * sizeMultiplyer) && x <= xpos + (50 * sizeMultiplyer)) {
		if (y >= ypos - (50 * sizeMultiplyer) && y <= ypos + (50 * sizeMultiplyer)) {
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
		glVertex2i(x - (50 * sizeMultiplyer), y + (50 * sizeMultiplyer));
		glVertex2i(x + (50 * sizeMultiplyer), y + (50 * sizeMultiplyer));
		glVertex2i(x + (50 * sizeMultiplyer), y - (50 * sizeMultiplyer));
		glVertex2i(x - (50 * sizeMultiplyer), y - (50 * sizeMultiplyer));
		glEnd();
	}
	else {
		icon.setVisible(false);
		glColor(PaletteColors::Blue);
		glBegin(GL_POLYGON);
		glVertex2i(x - (50 * sizeMultiplyer), y + (50 * sizeMultiplyer));
		glVertex2i(x + (50 * sizeMultiplyer), y + (50 * sizeMultiplyer));
		glVertex2i(x + (50 * sizeMultiplyer), y - (50 * sizeMultiplyer));
		glVertex2i(x - (50 * sizeMultiplyer), y - (50 * sizeMultiplyer));
		glEnd();
		glColor(PaletteColors::Yellow);
		glBegin(GL_LINE_LOOP);
		glVertex2i(x - (50 * sizeMultiplyer), y + (50 * sizeMultiplyer));
		glVertex2i(x + (50 * sizeMultiplyer), y + (50 * sizeMultiplyer));
		glVertex2i(x + (50 * sizeMultiplyer), y - (50 * sizeMultiplyer));
		glVertex2i(x - (50 * sizeMultiplyer), y - (50 * sizeMultiplyer));
		glEnd();
		glBegin(GL_LINES);
		glVertex2i(x - (50 * sizeMultiplyer), y + (30 * sizeMultiplyer));
		glVertex2i(x - (30 * sizeMultiplyer), y + (50 * sizeMultiplyer));

		glVertex2i(x - (50 * sizeMultiplyer), y - (10 * sizeMultiplyer));
		glVertex2i(x + (10 * sizeMultiplyer), y + (50 * sizeMultiplyer));

		glVertex2i(x - (50 * sizeMultiplyer), y - (50 * sizeMultiplyer));
		glVertex2i(x + (50 * sizeMultiplyer), y + (50 * sizeMultiplyer));

		glVertex2i(x - (10 * sizeMultiplyer), y - (50 * sizeMultiplyer));
		glVertex2i(x + (50 * sizeMultiplyer), y + (10 * sizeMultiplyer));

		glVertex2i(x + (30 * sizeMultiplyer), y - (50 * sizeMultiplyer));
		glVertex2i(x + (50 * sizeMultiplyer), y - (30 * sizeMultiplyer));

		glVertex2i(x + (30 * sizeMultiplyer), y + (50 * sizeMultiplyer));
		glVertex2i(x + (50 * sizeMultiplyer), y + (30 * sizeMultiplyer));

		glVertex2i(x - (10 * sizeMultiplyer), y + (50 * sizeMultiplyer));
		glVertex2i(x + (50 * sizeMultiplyer), y - (10 * sizeMultiplyer));

		glVertex2i(x - (50 * sizeMultiplyer), y + (50 * sizeMultiplyer));
		glVertex2i(x + (50 * sizeMultiplyer), y - (50 * sizeMultiplyer));

		glVertex2i(x - (50 * sizeMultiplyer), y + (10 * sizeMultiplyer));
		glVertex2i(x + (10 * sizeMultiplyer), y - (50 * sizeMultiplyer));

		glVertex2i(x - (50 * sizeMultiplyer), y - (30 * sizeMultiplyer));
		glVertex2i(x - (30 * sizeMultiplyer), y - (50 * sizeMultiplyer));

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
