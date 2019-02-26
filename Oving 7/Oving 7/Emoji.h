#pragma once

// Include Graph_lib library files that holds declarations needed for Window,
// and Shape derivatives.
#include "Graph.h"
#include "GUI.h"

// This part is only relevant for non-Windows users in 2019.
// Windows users has Graph_lib::Arc, Mac don't.
#ifndef WIN32
#include "Graph_lib.h"
#endif

using namespace Graph_lib;

class Emoji
{
public:
	// Disable copying. Disable slicing, etc.
	Emoji(const Emoji&) = delete;
	Emoji& operator=(const Emoji&) = delete;

	Emoji() {}

	virtual void attach_to(Graph_lib::Window&) = 0;


	virtual ~Emoji() {}
};

// A yellow, empty face.
// An abstract class.
class Face : public Emoji
{
public:
	Face(const Face&) = delete;
	Face& operator=(const Face&) = delete;
	virtual ~Face() {}

	Face(Point c, int r);
	void attach_to(Graph_lib::Window& win) override;

private:
	Circle faceMask;
};


class EmptyFace  : public Face
{
public:
	EmptyFace(Point p, int r);
	void attach_to(Graph_lib::Window& win) override;
private:
	Circle leftEye;
	Circle rightEye;
};

class SmileyFace : public EmptyFace
{
public:
	SmileyFace(Point p, int r);
	virtual ~SmileyFace() {};
	void attach_to(Graph_lib::Window& win) override;
private:
	Arc Smile;
};


class SadFace : public EmptyFace
{
public:
	SadFace(Point p, int r);
	virtual ~SadFace() {};
	void attach_to(Graph_lib::Window& win) override;
private:
	Arc Sad;
};

class AngryFace : public EmptyFace
{
public:
	AngryFace(Point p, int r);
	virtual ~AngryFace() {};
	void attach_to(Graph_lib::Window& win) override;
private:
	int x1, y1;
	int x2, y2;
	Arc AngryOver;
	Line leftBrow, rightBrow;
};

class WinkingFace : public Face
{
public:
	WinkingFace(Point p, int r);
	void attach_to(Graph_lib::Window& win) override;
private:
	Circle leftEye;
	Arc smile;
	Open_polyline wink;
	int x1,x2;
	int y1, y2, y3;
};

class AwkwardFace : public Face
{
public:
	AwkwardFace(Point p, int r);
	void attach_to(Graph_lib::Window& win) override;
private:
	Circle leftEye, rightEye;
	Open_polyline mouth;
};