#pragma once

// Include Graph_lib library files that holds declarations needed for Window,
// and Shape derivatives.
#include "Graph.h"
#include "GUI.h"



using namespace Graph_lib;

// An abstract class. Concrete classes derived from this base class
// has to implement the member function attach_to().
class Emoji
{
public:
	// Disable copying. Disable slicing, etc.
	Emoji(const Emoji&) = delete;
	Emoji& operator=(const Emoji&) = delete;

	// Deleting the copy constructor also deletes the default constructor.
	// Emoji needs a default constructor.
	Emoji() {}
	// Emoji() = default; // is an alternative way of achieving the same.

	// The pure virtual function that has to be overriden for a deriving class
	// to be instantiable. Every class deriving from Emoji is supposed to
	// attach all its Shapes to a window. This makes the class abstract.
	virtual void attach_to(Graph_lib::Window&) = 0;

	// Relevant because Vector_ref can own Emojis and automatically cleans up.
	// Subject will be visited later in the course.
	virtual ~Emoji() {}
};

class Face : public Emoji
{
	private:
		Circle face;
	public:
		Face(Point centre, int radii);
		virtual void attach_to(Graph_lib::Window&win) override = 0;
};

class emptyFace : public Face 
{
	private:
		Circle eye1;
		Circle eye2;
	public:
		emptyFace(Point center, int radii);
		void attach_to(Graph_lib::Window&win);
};


class Smiley : public emptyFace
{
	private:
	protected:
		Arc mouth;
	public: 
		Smiley(Point centre, int radii, Point centremouth, int width, int height, int startdegree, int enddegree);
		void attach_to(Graph_lib::Window&win);
};

class Luring : public Face
{
	private:
		Arc mouth;
		Arc wink;
		Circle eye;
	public: 
		Luring(Point centre, int radii, Point centremouth, int width, int height, int startdegree, int enddegree);
		void attach_to(Graph_lib::Window&win);
};

class Sjokk : public emptyFace
{
	private:
		Circle mouth;
	public: 
		Sjokk(Point centre, int radii, Point centremouth, int radiimouth);
		void attach_to(Graph_lib::Window&win);
};

class Bitch : public Smiley 
{
	private:
		Arc brow1;
		Arc brow2;
		//Arc mouth;
	public:
		Bitch(Point centre, int radii, Point centremouth, int width, int height, int startdegree, int enddegree);
		void attach_to(Graph_lib::Window&win);
};

class Mongo : public Face
{
	private:
		Circle eye1;
		Ellipse eye2;
		Arc mouth;
		Circle pupil;
	public:
		Mongo(Point centre, int radii, Point centremouth, int width, int height, int startdegree, int enddegree);
		void attach_to(Graph_lib::Window&win);
};