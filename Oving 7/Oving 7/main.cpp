#include "Simple_window.h"
#include "Emoji.h"

// Size of window and emoji radius
constexpr int xmax = 750;
constexpr int ymax = 200;
constexpr int emojiRadius = 50;

void DrawEmojies(Vector_ref<Emoji>& emojis, Graph_lib::Window& win);

int main()
{
	using namespace Graph_lib;

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	Simple_window win{tl, xmax, ymax, win_label};
	Vector_ref<Emoji> emoji;
	emoji.push_back(new EmptyFace(Point{ 100, 100 }, emojiRadius));
	emoji.push_back(new SmileyFace(Point{ 210, 100 }, emojiRadius));
	emoji.push_back(new SadFace(Point{ 320, 100 }, emojiRadius));
	emoji.push_back(new AngryFace(Point{ 430, 100 }, emojiRadius));
	emoji.push_back(new WinkingFace(Point{ 540, 100 }, emojiRadius));
	emoji.push_back(new AwkwardFace(Point{ 650, 100 }, emojiRadius));
	
	DrawEmojies(emoji, win);

	win.wait_for_button();
}

void DrawEmojies(Vector_ref<Emoji>& emojis, Graph_lib::Window & win)
{
	for (const auto e : emojis) 
	{
		e->attach_to(win);
	}
}
