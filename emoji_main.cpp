#include "Simple_window.h"
#include "Emoji.h"


// Size of window and emoji radius
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

int main()
{
	using namespace Graph_lib;

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	Simple_window win{tl, xmax, ymax, win_label};

	//emptyFace first({500, 300}, emojiRadius);
	//first.attach_to(win);

	Smiley smil({100, 100}, emojiRadius, {100, 95}, 80, 60, 240, 300);
	Luring lurifax({200, 100}, emojiRadius, {200, 95}, 80, 60, 240, 300);
	Sjokk wow({300, 100}, emojiRadius, {300, 125}, 10);
	Bitch AnneBorg({400, 100}, emojiRadius, {400, 95}, 80, 60, 240, 300);
	Mongo Gorm({500, 100}, emojiRadius, {500, 95}, 80, 60, 260, 300);


	smil.attach_to(win);
	lurifax.attach_to(win);
	wow.attach_to(win);
	AnneBorg.attach_to(win);
	Gorm.attach_to(win);

	win.wait_for_button();
}
