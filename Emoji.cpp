#include "Emoji.h"

Face::Face(Point centre, int radii) : face{centre, radii} {
    face.set_fill_color(Color::yellow);
}

void Face::attach_to(Graph_lib::Window&win){
    win.attach(face);
}

emptyFace::emptyFace(Point centre, int radii)
    : Face{centre, radii}, eye1{{centre.x - 15, centre.y - 15},radii/5}, eye2{{centre.x + 15, centre.y - 15}, radii/5}{
        eye1.set_fill_color(Color::black);
        eye2.set_fill_color(Color::black);
}

void emptyFace::attach_to(Graph_lib::Window&win){
    Face::attach_to(win);
    win.attach(eye1);
    win.attach(eye2);
}    

//centremouth={500, 330}
//centreFace={500, 300}
//centreEye2={515, 275}
//widthMouth=25
//widt

Smiley::Smiley(Point centre, int radii, Point centremouth, int width, int height, int startdegree, int enddegree) 
    :
    emptyFace{centre, radii}, 
    mouth{centremouth, width, height, startdegree, enddegree} {
        mouth.set_color(Color::black);
        mouth.set_style(Line_style{Line_style::solid,2});
}

void Smiley::attach_to(Graph_lib::Window&win){
    emptyFace::attach_to(win);
    win.attach(mouth);
}

Luring::Luring(Point centre, int radii, Point centremouth, int width, int height, int startdegree, int enddegree) 
    :
    Face{centre, radii}, 
    mouth{centremouth, width, height, startdegree, enddegree},
    wink{{centre.x + 15, centre.y - 8}, width/3, height/3, startdegree-180, enddegree-180},
    eye{{centre.x - 15, centre.y - 15}, radii/5} {
        mouth.set_color(Color::black);
        mouth.set_style(Line_style{Line_style::solid,2});
        wink.set_color(Color::black);
        wink.set_style(Line_style{Line_style::solid,1});
        eye.set_fill_color(Color::blue);
}

void Luring::attach_to(Graph_lib::Window&win){
    Face::attach_to(win);
    win.attach(mouth);
    win.attach(wink);
    win.attach(eye);
}

Sjokk::Sjokk(Point centre, int radii, Point centremouth, int radiimouth) 
    :
    emptyFace{centre, radii}, 
    mouth{centremouth, radiimouth} {
        mouth.set_fill_color(Color::red);
        mouth.set_style(Line_style{Line_style::solid,2});
}

void Sjokk::attach_to(Graph_lib::Window&win){
    emptyFace::attach_to(win);
    win.attach(mouth);
}

Bitch::Bitch(Point centre, int radii, Point centremouth, int width, int height, int startdegree, int enddegree)
    : 
    Smiley{centre, radii, centremouth, width, height, startdegree, enddegree},
    //mouth{centremouth, width, height, startdegree, enddegree},
    brow1{{centre.x - 15, centre.y - 20}, width/3, height/3, startdegree-180, enddegree-180},
    brow2{{centre.x + 15, centre.y - 30}, width/3, height/3, startdegree-180, enddegree-180} {
        //mouth.set_color(Color::black);
        //mouth.set_style(Line_style{Line_style::solid, 2});
        brow1.set_color(Color::black);
        brow1.set_style(Line_style{Line_style::solid,3});
        brow2.set_color(Color::black);
        brow2.set_style(Line_style{Line_style::solid,3});
}

void Bitch::attach_to(Graph_lib::Window&win){
    Smiley::attach_to(win);
    //win.attach(mouth);
    win.attach(brow1);
    win.attach(brow2);
}

Mongo::Mongo(Point centre, int radii, Point centremouth, int width, int height, int startdegree, int enddegree)
    : 
    Face{centre, radii}, eye1{{centre.x - 15, centre.y - 15},radii/10}, 
    eye2{{centre.x + 15, centre.y - 15}, radii/5, radii/3}, 
    mouth{centremouth, width, height, startdegree, enddegree},
    pupil{{centre.x + 15, centre.y - 15}, radii/8} {
        eye1.set_fill_color(Color::black);
        eye2.set_fill_color(Color::white);
        mouth.set_color(Color::black);
        mouth.set_style(Line_style(Line_style::solid, 2));
        pupil.set_fill_color(Color::black);
}

void Mongo::attach_to(Graph_lib::Window&win){
    Face::attach_to(win);
    win.attach(eye1);
    win.attach(eye2);
    win.attach(mouth);
    win.attach(pupil);
}