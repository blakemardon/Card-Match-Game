#include "Icon.h"

Icon::Icon(Icons iconName) : Icon(iconName, 1.0)
{
}

Icon::Icon(Icons iconName, float size) : Icon(iconName, size, Color(PaletteColors::Black))
{
}

Icon::Icon(Icons iconName, Color fill) : Icon(iconName, 1.0, fill)
{
}

Icon::Icon(Icons iconName, Color fill, Color lines) : Icon(iconName, 1.0, fill, lines)
{
}

Icon::Icon(Icons iconName, float size, Color fill) : Icon(iconName, size, fill, Color(PaletteColors::Black, 0.0))
{
}

Icon::Icon(Icons iconName, float size, Color fill, Color lines)
{
	this->sizeMultiplyer = size;
	this->fill = fill;
	this->lines = lines;
	this->iconName = iconName;
}

void Icon::draw(int x, int y)
{
	switch (iconName) {
	case Icons::Square:
		if (fill.getAlpha() != 0) {
			fill.applyColor();
			glBegin(GL_POLYGON);
			glVertex2i(x - (50 * sizeMultiplyer), y + (50 * sizeMultiplyer));
			glVertex2i(x + (50 * sizeMultiplyer), y + (50 * sizeMultiplyer));
			glVertex2i(x + (50 * sizeMultiplyer), y - (50 * sizeMultiplyer));
			glVertex2i(x - (50 * sizeMultiplyer), y - (50 * sizeMultiplyer));
			glEnd();
		}
		if (lines.getAlpha() != 0) {
			lines.applyColor();
			glBegin(GL_LINE_LOOP);
			glVertex2i(x - (50 * sizeMultiplyer), y + (50 * sizeMultiplyer));
			glVertex2i(x + (50 * sizeMultiplyer), y + (50 * sizeMultiplyer));
			glVertex2i(x + (50 * sizeMultiplyer), y - (50 * sizeMultiplyer));
			glVertex2i(x - (50 * sizeMultiplyer), y - (50 * sizeMultiplyer));
			glEnd();
		}
		break;
	case Icons::Triangle:
		if (fill.getAlpha() != 0) {
			fill.applyColor();
			glBegin(GL_POLYGON);
			glVertex2i(x, y + (50 * sizeMultiplyer));
			glVertex2i(x + (50 * sizeMultiplyer), y - (50 * sizeMultiplyer));
			glVertex2i(x - (50 * sizeMultiplyer), y - (50 * sizeMultiplyer));
			glEnd();
		}
		if (lines.getAlpha() != 0) {
			lines.applyColor();
			glBegin(GL_LINE_LOOP);
			glVertex2i(x, y + (50 * sizeMultiplyer));
			glVertex2i(x + (50 * sizeMultiplyer), y - (50 * sizeMultiplyer));
			glVertex2i(x - (50 * sizeMultiplyer), y - (50 * sizeMultiplyer));
			glEnd();
		}
		break;
	case Icons::Cat:
		if (fill.getAlpha() != 0) {
			fill.applyColor();
			glBegin(GL_TRIANGLE_STRIP); // This is needed to make the concave top of the head
			glVertex2i(x - (50 * sizeMultiplyer), y + (50 * sizeMultiplyer));
			glVertex2i(x - (50 * sizeMultiplyer), y - (50 * sizeMultiplyer));
			glVertex2i(x - (20 * sizeMultiplyer), y + (20 * sizeMultiplyer));
			glVertex2i(x + (50 * sizeMultiplyer), y - (50 * sizeMultiplyer));
			glVertex2i(x + (20 * sizeMultiplyer), y + (20 * sizeMultiplyer));
			glVertex2i(x + (50 * sizeMultiplyer), y + (50 * sizeMultiplyer));
			glEnd();
		}
		if (lines.getAlpha() != 0) {
			lines.applyColor();
			glBegin(GL_LINE_LOOP); //head outline
			glVertex2i(x - (50 * sizeMultiplyer), y + (50 * sizeMultiplyer));
			glVertex2i(x - (20 * sizeMultiplyer), y + (20 * sizeMultiplyer));
			glVertex2i(x + (20 * sizeMultiplyer), y + (20 * sizeMultiplyer));
			glVertex2i(x + (50 * sizeMultiplyer), y + (50 * sizeMultiplyer));
			glVertex2i(x + (50 * sizeMultiplyer), y - (50 * sizeMultiplyer));
			glVertex2i(x - (50 * sizeMultiplyer), y - (50 * sizeMultiplyer));
			glEnd();
			glBegin(GL_LINE_LOOP); //left eye
			glVertex2i(x - (20 * sizeMultiplyer), y + (10 * sizeMultiplyer));
			glVertex2i(x - (10 * sizeMultiplyer), y + (10 * sizeMultiplyer));
			glVertex2i(x - (10 * sizeMultiplyer), y + (0 * sizeMultiplyer));
			glVertex2i(x - (20 * sizeMultiplyer), y + (0 * sizeMultiplyer));
			glEnd();
			glBegin(GL_LINE_LOOP); //right eye
			glVertex2i(x + (20 * sizeMultiplyer), y + (10 * sizeMultiplyer));
			glVertex2i(x + (10 * sizeMultiplyer), y + (10 * sizeMultiplyer));
			glVertex2i(x + (10 * sizeMultiplyer), y + (0 * sizeMultiplyer));
			glVertex2i(x + (20 * sizeMultiplyer), y + (0 * sizeMultiplyer));
			glEnd();
			glBegin(GL_LINES);
			glVertex2i(x - (10 * sizeMultiplyer), y - (20 * sizeMultiplyer));
			glVertex2i(x - (40 * sizeMultiplyer), y - (0 * sizeMultiplyer));
			glVertex2i(x - (10 * sizeMultiplyer), y - (25 * sizeMultiplyer));
			glVertex2i(x - (40 * sizeMultiplyer), y - (25 * sizeMultiplyer));
			glVertex2i(x - (10 * sizeMultiplyer), y - (30 * sizeMultiplyer));
			glVertex2i(x - (40 * sizeMultiplyer), y - (50 * sizeMultiplyer));
			glVertex2i(x + (10 * sizeMultiplyer), y - (20 * sizeMultiplyer));
			glVertex2i(x + (40 * sizeMultiplyer), y - (0 * sizeMultiplyer));
			glVertex2i(x + (10 * sizeMultiplyer), y - (25 * sizeMultiplyer));
			glVertex2i(x + (40 * sizeMultiplyer), y - (25 * sizeMultiplyer));
			glVertex2i(x + (10 * sizeMultiplyer), y - (30 * sizeMultiplyer));
			glVertex2i(x + (40 * sizeMultiplyer), y - (50 * sizeMultiplyer));
			glEnd();
		}
		break;
	}

}
/* Template for making new icons
*
	case Icons:::
		if (fill.getAlpha() != 0) {
			fill.applyColor();

		}
		if (lines.getAlpha() != 0) {
			lines.applyColor();

		}
		break;
*/