#include "Icon.h"


Icon::Icon() : Icon(Icons::Square, 0, 0) {

}

Icon::Icon(Icons iconName, int x, int y) : Icon(iconName,x ,y , 1.0)
{
}

Icon::Icon(Icons iconName, int x, int y, float size) : Icon(iconName, x, y, size, Color(PaletteColors::Black))
{
}

Icon::Icon(Icons iconName, int x, int y, Color fill) : Icon(iconName, x, y, 1.0, fill)
{
}

Icon::Icon(Icons iconName, int x, int y, Color fill, Color lines) : Icon(iconName, x, y, 1.0, fill, lines)
{
}

Icon::Icon(Icons iconName, int x, int y, float size, Color fill) : Icon(iconName, x, y, size, fill, Color(PaletteColors::Black, 0.0))
{
}

Icon::Icon(Icons iconName, int x, int y, float size, Color fill, Color lines)
{
	this->sizeMultiplyer = size;
	this->fill = fill;
	this->lines = lines;
	this->iconName = iconName;
	this->xpos = x;
	this->ypos = y;
	setDrawDepth(4);
}

void Icon::draw() {
	Icon::draw(xpos, ypos);
}

void Icon::draw(int x, int y)
{
	if (isVisable) {
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
				glBegin(GL_LINES); // wiskers
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
		case Icons::Bars:
			if (fill.getAlpha() != 0) {
				fill.applyColor();
				glBegin(GL_POLYGON);
				glVertex2i(x - (50 * sizeMultiplyer), y - (50 * sizeMultiplyer));
				glVertex2i(x - (50 * sizeMultiplyer), y + (0 * sizeMultiplyer));
				glVertex2i(x - (30 * sizeMultiplyer), y + (0 * sizeMultiplyer));
				glVertex2i(x - (30 * sizeMultiplyer), y - (50 * sizeMultiplyer));
				glEnd();
				glBegin(GL_POLYGON);
				glVertex2i(x - (10 * sizeMultiplyer), y - (50 * sizeMultiplyer));
				glVertex2i(x - (10 * sizeMultiplyer), y - (20 * sizeMultiplyer));
				glVertex2i(x + (10 * sizeMultiplyer), y - (20 * sizeMultiplyer));
				glVertex2i(x + (10 * sizeMultiplyer), y - (50 * sizeMultiplyer));
				glEnd();
				glBegin(GL_POLYGON);
				glVertex2i(x + (30 * sizeMultiplyer), y - (50 * sizeMultiplyer));
				glVertex2i(x + (30 * sizeMultiplyer), y + (50 * sizeMultiplyer));
				glVertex2i(x + (50 * sizeMultiplyer), y + (50 * sizeMultiplyer));
				glVertex2i(x + (50 * sizeMultiplyer), y - (50 * sizeMultiplyer));
				glEnd();
			}
			if (lines.getAlpha() != 0) {
				lines.applyColor();
				glBegin(GL_LINE_LOOP);
				glVertex2i(x - (50 * sizeMultiplyer), y - (50 * sizeMultiplyer));
				glVertex2i(x - (50 * sizeMultiplyer), y + (0 * sizeMultiplyer));
				glVertex2i(x - (30 * sizeMultiplyer), y + (0 * sizeMultiplyer));
				glVertex2i(x - (30 * sizeMultiplyer), y - (50 * sizeMultiplyer));
				glEnd();
				glBegin(GL_LINE_LOOP);
				glVertex2i(x - (10 * sizeMultiplyer), y - (50 * sizeMultiplyer));
				glVertex2i(x - (10 * sizeMultiplyer), y - (20 * sizeMultiplyer));
				glVertex2i(x + (10 * sizeMultiplyer), y - (20 * sizeMultiplyer));
				glVertex2i(x + (10 * sizeMultiplyer), y - (50 * sizeMultiplyer));
				glEnd();
				glBegin(GL_LINE_LOOP);
				glVertex2i(x + (30 * sizeMultiplyer), y - (50 * sizeMultiplyer));
				glVertex2i(x + (30 * sizeMultiplyer), y + (50 * sizeMultiplyer));
				glVertex2i(x + (50 * sizeMultiplyer), y + (50 * sizeMultiplyer));
				glVertex2i(x + (50 * sizeMultiplyer), y - (50 * sizeMultiplyer));
				glEnd();
			}
			break;
		case Icons::Envelope:
			if (fill.getAlpha() != 0) {
				fill.applyColor();
				glBegin(GL_POLYGON);
				glVertex2i(x - (50 * sizeMultiplyer), y - (30 * sizeMultiplyer));
				glVertex2i(x - (50 * sizeMultiplyer), y + (30 * sizeMultiplyer));
				glVertex2i(x + (50 * sizeMultiplyer), y + (30 * sizeMultiplyer));
				glVertex2i(x + (50 * sizeMultiplyer), y - (30 * sizeMultiplyer));
				glEnd();
			}
			if (lines.getAlpha() != 0) {
				lines.applyColor();
				glBegin(GL_LINE_LOOP);
				glVertex2i(x - (50 * sizeMultiplyer), y - (30 * sizeMultiplyer));
				glVertex2i(x - (50 * sizeMultiplyer), y + (30 * sizeMultiplyer));
				glVertex2i(x + (50 * sizeMultiplyer), y + (30 * sizeMultiplyer));
				glVertex2i(x + (50 * sizeMultiplyer), y - (30 * sizeMultiplyer));
				glEnd();
				glBegin(GL_LINE_LOOP);
				glVertex2i(x - (50 * sizeMultiplyer), y + (30 * sizeMultiplyer));
				glVertex2i(x + (0 * sizeMultiplyer), y - (0 * sizeMultiplyer));
				glVertex2i(x + (50 * sizeMultiplyer), y + (30 * sizeMultiplyer));
				glEnd();
			}
			break;
		case Icons::Circle:
			if (fill.getAlpha() != 0) {
				fill.applyColor();
				glBegin(GL_POLYGON);
				for (int i = 0; i < 180; i++) {
					glVertex2i(x + (cos(i * 3.14159 / 90) * 50 * sizeMultiplyer), y + (sin(i * 3.14159 / 90) * 50 * sizeMultiplyer));
				}
				glEnd();
			}
			if (lines.getAlpha() != 0) {
				lines.applyColor();
				glBegin(GL_LINE_LOOP);
				for (int i = 0; i < 180; i++) {
					glVertex2i(x + (cos(i * 3.14159 / 90) * 50 * sizeMultiplyer), y + (sin(i * 3.14159 / 90) * 50 * sizeMultiplyer));
				}
				glEnd();
			}
			break;
		case Icons::Female:
			if (fill.getAlpha() != 0) {
				fill.applyColor();
				glBegin(GL_POLYGON);
				for (int i = 0; i < 180; i++) {
					glVertex2i(x + (cos(i * 3.14159 / 90) * 30 * sizeMultiplyer), y + (20 * sizeMultiplyer + sin(i * 3.14159 / 90) * 30 * sizeMultiplyer));
				}
				glEnd();
			}
			if (lines.getAlpha() != 0) {
				lines.applyColor();
				glBegin(GL_LINE_LOOP);
				for (int i = 0; i < 180; i++) {
					glVertex2i(x + (cos(i * 3.14159 / 90) * 30 * sizeMultiplyer), y + (20 * sizeMultiplyer + sin(i * 3.14159 / 90) * 30 * sizeMultiplyer));
				}
				glEnd();
				glBegin(GL_LINE_LOOP);
				glVertex2i(x - (0 * sizeMultiplyer), y - (10 * sizeMultiplyer));
				glVertex2i(x - (0 * sizeMultiplyer), y - (50 * sizeMultiplyer));
				glEnd();
				glBegin(GL_LINE_LOOP);
				glVertex2i(x - (20 * sizeMultiplyer), y - (30 * sizeMultiplyer));
				glVertex2i(x + (20 * sizeMultiplyer), y - (30 * sizeMultiplyer));
				glEnd();
			}
			break;
		case Icons::Male:
			if (fill.getAlpha() != 0) {
				fill.applyColor();
				glBegin(GL_POLYGON);
				for (int i = 0; i < 180; i++) {
					glVertex2i(x + (10 * sizeMultiplyer + cos(i * 3.14159 / 90) * 35 * sizeMultiplyer), y + (10 * sizeMultiplyer + sin(i * 3.14159 / 90) * 35 * sizeMultiplyer));
				}
				glEnd();
			}
			if (lines.getAlpha() != 0) {
				lines.applyColor();
				glBegin(GL_LINE_LOOP);
				for (int i = 0; i < 180; i++) {
					glVertex2i(x + (10 * sizeMultiplyer + cos(i * 3.14159 / 90) * 35 * sizeMultiplyer), y + (10 * sizeMultiplyer + sin(i * 3.14159 / 90) * 35 * sizeMultiplyer));
				}
				glEnd();
				glBegin(GL_LINE_LOOP);
				glVertex2i(x - (50 * sizeMultiplyer), y - (50 * sizeMultiplyer));
				glVertex2i(x - (14 * sizeMultiplyer), y - (14 * sizeMultiplyer));
				glEnd();
				glBegin(GL_LINE_LOOP);
				glVertex2i(x - (50 * sizeMultiplyer), y - (30 * sizeMultiplyer));
				glVertex2i(x - (50 * sizeMultiplyer), y - (50 * sizeMultiplyer));
				glEnd();
				glBegin(GL_LINE_LOOP);
				glVertex2i(x - (30 * sizeMultiplyer), y - (50 * sizeMultiplyer));
				glVertex2i(x - (50 * sizeMultiplyer), y - (50 * sizeMultiplyer));
				glEnd();
			}
			break;
		case Icons::Card:
			if (fill.getAlpha() != 0) {
				fill.applyColor();
				glBegin(GL_POLYGON);
				glVertex2i(x - (50 * sizeMultiplyer), y - (30 * sizeMultiplyer));
				glVertex2i(x - (50 * sizeMultiplyer), y + (30 * sizeMultiplyer));
				glVertex2i(x + (50 * sizeMultiplyer), y + (30 * sizeMultiplyer));
				glVertex2i(x + (50 * sizeMultiplyer), y - (30 * sizeMultiplyer));
				glEnd();
			}
			if (lines.getAlpha() != 0) {
				lines.applyColor();
				glBegin(GL_LINE_LOOP);
				glVertex2i(x - (50 * sizeMultiplyer), y - (30 * sizeMultiplyer));
				glVertex2i(x - (50 * sizeMultiplyer), y + (30 * sizeMultiplyer));
				glVertex2i(x + (50 * sizeMultiplyer), y + (30 * sizeMultiplyer));
				glVertex2i(x + (50 * sizeMultiplyer), y - (30 * sizeMultiplyer));
				glEnd();
				glBegin(GL_POLYGON);
				glVertex2i(x - (45 * sizeMultiplyer), y + (20 * sizeMultiplyer));
				glVertex2i(x + (45 * sizeMultiplyer), y + (20 * sizeMultiplyer));
				glVertex2i(x + (45 * sizeMultiplyer), y - (0 * sizeMultiplyer));
				glVertex2i(x - (45 * sizeMultiplyer), y - (0 * sizeMultiplyer));
				glEnd();
			}
			break;
		case Icons::Smile:
			if (fill.getAlpha() != 0) {
				fill.applyColor();
				glBegin(GL_POLYGON);
				for (int i = 0; i < 180; i++) {
					glVertex2i(x + (cos(i * 3.14159 / 90) * 50 * sizeMultiplyer), y + (sin(i * 3.14159 / 90) * 50 * sizeMultiplyer));
				}
				glEnd();
			}
			if (lines.getAlpha() != 0) {
				lines.applyColor();
				glBegin(GL_LINE_LOOP);
				for (int i = 0; i < 180; i++) {
					glVertex2i(x + (cos(i * 3.14159 / 90) * 50 * sizeMultiplyer), y + (sin(i * 3.14159 / 90) * 50 * sizeMultiplyer));
				}
				glEnd();
				glBegin(GL_LINE_LOOP);
				for (int i = 0; i < 180; i++) {
					glVertex2i(x + (20 * sizeMultiplyer + cos(i * 3.14159 / 90) * 10 * sizeMultiplyer), y + (20 * sizeMultiplyer + sin(i * 3.14159 / 90) * 10 * sizeMultiplyer));
				}
				glEnd();
				glBegin(GL_LINE_LOOP);
				for (int i = 0; i < 180; i++) {
					glVertex2i(x - (20 * sizeMultiplyer + cos(i * 3.14159 / 90) * 10 * sizeMultiplyer), y + (20 * sizeMultiplyer + sin(i * 3.14159 / 90) * 10 * sizeMultiplyer));
				}
				glEnd();
				glBegin(GL_LINE_LOOP);
				for (int i = 105; i < 165; i++) {
					glVertex2i(x - (0 * sizeMultiplyer + cos(i * 3.14159 / 90) * 35 * sizeMultiplyer), y + (0 * sizeMultiplyer + sin(i * 3.14159 / 90) * 35 * sizeMultiplyer));
				}
				glEnd();

			}
			break;
		}
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