#include "Emoji.h"

/*
 * Implement your emojis in this file.
 **/

// A yellow, empty face.
Face::Face(Point c, int r) : faceMask{c, r}
{
	faceMask.set_fill_color(Color::yellow);
	faceMask.set_color(Color::black);
}

void Face::attach_to(Graph_lib::Window& win)
{
	win.attach(faceMask);
}

#pragma region EmptyFace

EmptyFace::EmptyFace(Point p, int r) : Face(p, r),
	leftEye{ Point{ p.x - r / 2, p.y - r / 8 }, r / 10 },
	rightEye{ Point { p.x + r / 2, p.y - r / 8 }, r / 10 }
{

	leftEye.set_fill_color(Color::black);
	rightEye.set_fill_color(Color::black);

	leftEye.set_color(Color::black);
	rightEye.set_color(Color::black);
}

void EmptyFace::attach_to(Graph_lib::Window & win)
{
	Face::attach_to(win);
	win.attach(leftEye);
	win.attach(rightEye);
}


#pragma endregion


#pragma region SmileyFace

SmileyFace::SmileyFace(Point p, int r) : EmptyFace{ p,r }, Smile{ Point{p.x, p.y + r / 10}, int(4 / 3 * r), r, 180, 360 }
{
	Smile.set_color(Color::black);
	Smile.set_style(Line_style(Line_style::solid, 4));
}

void SmileyFace::attach_to(Graph_lib::Window & win)
{
	EmptyFace::attach_to(win);
	win.attach(Smile);
}

#pragma endregion


#pragma region SadFace

SadFace::SadFace(Point p, int r) : EmptyFace{ p,r }, Sad{ Point{p.x, p.y + r - r / 3}, int(4 / 3 * r), r, 0, 180 }
{
	Sad.set_color(Color::black);
	Sad.set_style(Line_style(Line_style::solid, 4));
}

void SadFace::attach_to(Graph_lib::Window & win)
{
	EmptyFace::attach_to(win);
	win.attach(Sad);
}

#pragma endregion


#pragma region AngryFace

AngryFace::AngryFace(Point p, int r) : EmptyFace{ p,r }, 
	AngryOver{ Point{p.x, p.y + r - r / 3}, int(4 / 3 * r), r, 0, 180 },
	x1{3 * r / 5}, y1{ 4 * r / 5 },
	x2{r / 8}, y2{2 * r / 3},
	leftBrow{Point{p.x - x1, p.y - y1}, Point{p.x - x2, p.y - y2}},
	rightBrow{ Point{p.x + x1, p.y - y1}, Point{p.x + x2, p.y - y2} }
{
	AngryOver.set_color(Color::black);
	AngryOver.set_style(Line_style(Line_style::solid, 4));
	leftBrow.set_color(Color::black);
	leftBrow.set_style(Line_style(Line_style::solid, 4));
	rightBrow.set_color(Color::black);
	rightBrow.set_style(Line_style(Line_style::solid, 4));
}


void AngryFace::attach_to(Graph_lib::Window & win)
{
	EmptyFace::attach_to(win);
	win.attach(AngryOver);
	win.attach(leftBrow);
	win.attach(rightBrow);
}

#pragma endregion


#pragma region WinkingFace

WinkingFace::WinkingFace(Point p, int r) : Face(p, r),
	leftEye{ Point{ p.x - r / 2, p.y - r / 2 }, r / 10 },
	smile{ Point{p.x, p.y + r / 10}, int(4 / 3 * r), r, 180, 360 },
	x1{p.x + r / 6}, x2{p.x + 6* r / 10},
	y1{p.y - 7 * r / 10}, y2{ p.y - r / 2}, y3{ p.y - 3 * r / 10}
{

	leftEye.set_fill_color(Color::black);
	leftEye.set_color(Color::black);

	smile.set_color(Color::black);
	smile.set_style(Line_style(Line_style::solid, 4));

	wink.add(Point{ x2,y1 });
	wink.add(Point{ x1, y2 });
	wink.add(Point{ x2,y3 });
	wink.set_color(Color::black);
	wink.set_style(Line_style(Line_style::solid, 3));
}

void WinkingFace::attach_to(Graph_lib::Window & win)
{
	Face::attach_to(win);
	win.attach(leftEye);
	win.attach(smile);
	win.attach(wink);
}

#pragma endregion

AwkwardFace::AwkwardFace(Point p, int r) : Face{p, r},
	leftEye{Point{p.x - 4 * r / 5, p.y}, r / 10},
	rightEye{Point{p.x + 4 * r / 5, p.y}, r / 10}
{
	leftEye.set_fill_color(Color::black);
	rightEye.set_fill_color(Color::black);

	leftEye.set_color(Color::black);
	rightEye.set_color(Color::black);

	mouth.add(Point{ p.x - r / 2, p.y + r / 25 });
	mouth.add(Point{ p.x + r / 2, p.y + r / 25 });
	mouth.set_color(Color::black);
	mouth.set_style(Line_style(Line_style::solid, 3));
}

void AwkwardFace::attach_to(Graph_lib::Window & win)
{
	Face::attach_to(win);
	win.attach(leftEye);
	win.attach(rightEye);
	win.attach(mouth);
}
