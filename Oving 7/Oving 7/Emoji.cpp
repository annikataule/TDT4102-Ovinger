#include "Emoji.h"

/*
 * Implement your emojis in this file.
 **/

// A yellow, empty face.
Face::Face(Point c, int r) : faceMask{c, r}
{
	faceMask.set_fill_color(Color::yellow);
	faceMask.set_color(Color::black);
	/* TODO:
	 *  - add member initializer list
	 *  - implement the constructor. I.e. fill color
	 **/

	cout << "Not yet implemented\n";
}

void Face::attach_to(Graph_lib::Window& win)
{
	win.attach(faceMask);
}

/* TODO:
 *  - define more emojis.
 **/

EmptyFace::EmptyFace(Point p, int r, bool upSideDown) : Face( p, r )
{
	int offset = int(1 / 4 * r * sqrt(2));
	if (upSideDown)
		offset *= -1;

	int eyeR = r / 4;

	Point left { p.x - offset, p.y - offset };
	Point right { p.x + offset, p.y - offset };

	//Circle leftEye { left, eyeR };
	//Circle rightEye { right, eyeR };

	//leftEye.set_fill_color(Color::black);
	//rightEye.set_fill_color(Color::black);

	//eyes.push_back(leftEye);
	//eyes.push_back(rightEye);

	
}

void EmptyFace::attach_to(Graph_lib::Window & win)
{
	Face::attach_to(win);
	//win.attach(eyes[0]);
	Circle leftE{ left, eyeR };
	Circle rightE{ right, eyeR };
	win.attach(leftE);
	win.attach(rightE);
}
