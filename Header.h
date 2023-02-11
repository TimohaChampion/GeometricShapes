#pragma once
#define _USE_MATH_DEFINES
#include<iostream>
#include<fstream>
#include"Header.h"
using namespace std;

class Shape abstract {
public:
	virtual ~Shape() = 0 {};
	virtual double area() = 0;
	virtual void show() = 0;
	virtual void save() = 0;
	virtual void load() = 0;
};
class Square :public Shape {
public:
	int l;
	Square(int width) :l{ width } {};
	double area()override {
		return pow(l, 2);
	}
	void show()override {
		cout << "Square: " << area() << endl;
	}
	void save() override {
		fstream f;
		f.open("file.txt", ios::app | ios::out);
		if (f.is_open()) {
			f << "Square:" << area() << endl;
			f.close();
		}
		else {
			cout << "Error Square!" << endl;
		}
	}
	void load()override {
		fstream f;
		string str;
		f.open("file.txt", ios::in);
		if (f.is_open()) {
			while (!f.eof()) {
				f >> str;
				if (str[0] == 'S')break;

			}
			cout << str << endl;
			f.close();
		}
		else {
			cout << "Error Square!" << endl;
		}
	}
};

class Rectangle :public Shape {
public:
	int width, height;
	Rectangle(int width, int height) :width{ width }, height{ height } {};
	double area()override {
		return width * height;
	}
	void show()override {
		cout << "Rectangle: " << area() << endl;
	}
	void save() override {
		fstream f;
		f.open("file.txt", ios::app | ios::out);
		if (f.is_open()) {
			f << "Rectangle:" << area() << endl;
			f.close();
		}
		else {
			cout << "Error Rectangle!" << endl;
		}
	}
	void load()override {
		fstream f;
		string str;
		f.open("file.txt", ios::in);
		if (f.is_open()) {
			while (!f.eof()) {
				f >> str;
				if (str[0] == 'R')break;

			}
			cout << str << endl;
			f.close();
		}
		else {
			cout << "Error Rectangle!" << endl;
		}
	}
};

class Circle :public Square {
public:
	Circle(int diametr) :Square(diametr) {};
	double area()override {
		return M_PI * pow(l / 2, 2);
	}
	void show()override {
		cout << "Circle: " << area() << endl;
	}
	void save() override {
		fstream f;
		f.open("file.txt", ios::app | ios::out);
		if (f.is_open()) {
			f << "Circle:" << area() << endl;
			f.close();
		}
		else {
			cout << "Error Circle!" << endl;
		}
	}
	void load()override {
		fstream f;
		string str;
		f.open("file.txt", ios::in);
		if (f.is_open()) {
			while (!f.eof()) {
				f >> str;
				if (str[0] == 'C')break;

			}
			cout << str << endl;
			f.close();
		}
		else {
			cout << "Error Circle!" << endl;
		}
	}
};

class Ellipse :public Rectangle {
public:
	Ellipse(int width, int height) :Rectangle(width, height) {};
	double area()override {
		return M_PI * width * height / 4;
	}
	void show()override {
		cout << "Ellipse: " << area() << endl;
	}
	void save() override {
		fstream f;
		f.open("file.txt", ios::app | ios::out);
		if (f.is_open()) {
			f << "Ellipse:" << area() << endl;
			f.close();
		}
		else {
			cout << "Error Ellipse!" << endl;
		}
	}
	void load()override {
		fstream f;
		string str;
		f.open("file.txt", ios::in);
		if (f.is_open()) {
			while (!f.eof()) {
				f >> str;
				if (str[0] == 'E')break;

			}
			cout << str << endl;
			f.close();
		}
		else {
			cout << "Error Ellipse!" << endl;
		}
	}
};
