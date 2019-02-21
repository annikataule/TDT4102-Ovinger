#pragma once
class Emoji
{
public:
	virtual void Emoji::attach_to(Graph_lib::Window&) = 0;
	Emoji(const Emoji&) = delete;
	Emoji& operator=(const Emoji&) = delete;
	Emoji() {}
	virtual ~Emoji();
};

