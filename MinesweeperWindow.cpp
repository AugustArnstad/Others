#include "MinesweeperWindow.h"
#include "Tile.h"

MinesweeperWindow::MinesweeperWindow(Point xy, int width, int height, int mines, const string& title) :
	Graph_lib::Window{xy, width * cellSize, height*cellSize, title}, width{width}, height{height}, mines{mines},
	Result{Point {20, 75}, ""}, Feedback{Point{10, 125}, ""}, Start{Point{10, 245}, "Total mines: " + to_string(mines)}
	//Initialiser medlemsvariabler, bruker konstruktoren til Windowsklassen
{
	// Legg til alle tiles i vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			tiles.push_back(new Tile{ Point{j * cellSize, i * cellSize}, cellSize, cb_click });
			attach(tiles.back());
		}
	}

	//Legg til miner paa tilfeldige posisjoner
	for (int i{0}; i<mines; i++){
		int randomTile=rand()%tiles.size();
		if (tiles[randomTile].getMine()==true){
			randomTile=rand()%tiles.size();
		} else{
			tiles[randomTile].setMine(true);
		}
	}
	Start.set_color(Color::dark_blue);
	Start.set_font_size(20);
	attach(Start);
	Result.set_font_size(56);
	Result.set_label(winOrLose);
	Result.set_color(Color::green);
	attach(Result);

	// Fjern window reskalering
	resizable(nullptr);
	size_range(x_max(), y_max(), x_max(), y_max());
}


vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}
			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}
	return points;
}

void MinesweeperWindow::openTile(Point xy) {
	Tile& tileToOpen = at(xy);
	int allTiles=tiles.size()-mines;
	if ((tileToOpen.getState()==Cell::closed) && (keepGoing==false)){
		tileToOpen.open();
		openTiles+=1;
		if ((tileToOpen.getMine()==false)&&(openTiles<allTiles)){
			vector<Point> nearbyTiles = adjacentPoints(xy);
			int counter = countMines(nearbyTiles);
			if (counter>0){
				tileToOpen.setAdjMines(counter);
			} else{
				for (auto i : nearbyTiles){
					openTile(i);
				}
			}
		} else if((openTiles==allTiles) && (tileToOpen.getMine()==false)) {
				winOrLose="YOU WON BITCH";
				Result.set_label(winOrLose);
				Result.set_color(Color::green);
				redraw();
				keepGoing=true;
		}else{
			winOrLose="YOU LOSE BITCH";
			Result.set_label(winOrLose);
			Result.set_color(Color::red);
			redraw();
			keepGoing=true;
		}	
		flush();
	}
}

void MinesweeperWindow::flagTile(Point xy) {
	Tile& tileToFlag = at(xy);
	tileToFlag.flag();
	flagged+=1;
	int minesLeft=mines-flagged;
	string s = "Mines left: " + to_string(minesLeft);
	Feedback.set_label(s);
	Feedback.set_color(Color::dark_blue);
	Feedback.set_font_size(20);
	attach(Feedback);
	redraw();
	flush();
}

//Kaller openTile ved venstreklikk og flagTile ved hoyreklikk/trykke med to fingre paa mac
void MinesweeperWindow::click()
{
	Point xy{Fl::event_x(), Fl::event_y()};
	MouseButton mb = static_cast<MouseButton>(Fl::event_button());
	if (!inRange(xy)) {
		return;
	}
	switch (mb) {
	case MouseButton::left:
		openTile(xy);
		break;
	case MouseButton::right:
		flagTile(xy);
		break;
	}
	flush();
}

int MinesweeperWindow::countMines(vector<Point> coords) const{
	int mineCount{0};
	for (int i{0}; i<coords.size(); i++){
		const Tile& tileToCheck = at(coords[i]);
		if (tileToCheck.getMine()==true){
			mineCount+=1;
		}
	}
	return mineCount;
}