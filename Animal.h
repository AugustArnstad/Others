#pragma once
#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"
#include "math.h"


using namespace Graph_lib;


class Animal{
    private:

    protected:
        string name;
        int age;
    public:
        Animal(string name, int age) 
            :name{name}, age{age} {};
        virtual string toString() =0;  
};

class Dog : public Animal {
    private:
    protected:
    public:
        Dog(string name, int age)
            :Animal(name, age) {};
        string toString() const {
            return "Dog: " + name + ", " + to_string(age) + ".";
        };
};

class Cat : public Animal {
    private:
    protected:
    public:
        Cat(string name, int age)
            :Animal(name, age) {};
        string toString() const {
            return "Cat: " + name + ", " + to_string(age) + ".";
        };  
};

