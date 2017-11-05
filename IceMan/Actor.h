#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"

class StudentWorld;
class Iceman;

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp
class Actor : public GraphObject
{
	bool isAlive = true;

public:
	StudentWorld* myWorld = nullptr;

	bool getAlive()
	{
		return isAlive;
	}
	void Died()
	{
		isAlive = false;
	}

	Actor(int x, int y, int ID, Direction dir, double s, unsigned int d, StudentWorld *stu) :GraphObject(ID, x, y, dir, s, d), myWorld(stu) {
		setVisible(true);
	}
	StudentWorld *getStudentWorld();

	virtual void doSomething() = 0;

	virtual ~Actor() {};
};

class Iceman : public Actor
{
public:
	Iceman(int x, int y, StudentWorld *stu) : Actor(x, y, IID_PLAYER, right, 1.0, 0, stu) {
		setVisible(true);
	}

	void doSomething();
	virtual ~Iceman() {};
};

class Ice : public Actor
{
public:

	Ice(int x, int y, StudentWorld *stu) : Actor(x, y, IID_ICE, right, .25, 3, stu) {
		setVisible(true);
	}

	void doSomething();

	virtual ~Ice() {};
};
class Squirt :public Actor
{
public:
	Squirt(int x, int y, StudentWorld *stu) : Actor(x, y, IID_WATER_SPURT, right, 1.0, 1, stu) {}
	void doSomething() {
	};
	virtual ~Squirt() {};
};
class BarrelsOfOil : public Actor
{
public:
	BarrelsOfOil(int x, int y, StudentWorld *stu) : Actor(x, y, IID_BARREL, right, 1.0, 0, stu) {
		setVisible(false);
	}
	void doSomething() {
	};
	virtual ~BarrelsOfOil() {};
};
class Boulder : public Actor
{
public:
	Boulder(int x, int y, StudentWorld *stu) : Actor(x, y, IID_PLAYER, right, 1.0, 1, stu) {}
	void doSomething() {
	};
	virtual ~Boulder() {};
};
class GoldNugget : public Actor
{
public:
	GoldNugget(int x, int y, StudentWorld *stu) : Actor(x, y, IID_PLAYER, right, 1.0, 0, stu) {
		setVisible(false);
	}
	void doSomething() {
	};
	virtual ~GoldNugget() {};
};
class Sonarkits : public Actor
{
public:
	Sonarkits(int x, int y, StudentWorld *stu) : Actor(x, y, IID_PLAYER, right, 1.0, 0, stu) {}
	void doSomething() {
	};
	virtual ~Sonarkits() {};
};
class WaterRefill : public Actor
{
public:
	WaterRefill(int x, int y, StudentWorld *stu) : Actor(x, y, IID_PLAYER, right, 1.0, 0, stu) {}
	void doSomething() {
	};
	virtual ~WaterRefill() {};
};
class regularProtestor : public Actor
{
public:
	regularProtestor(int x, int y, StudentWorld *stu) : Actor(x, y, IID_PLAYER, right, 1.0, 0, stu) {}
	virtual void doSomething() {
	};
	virtual ~regularProtestor() {};
};
class HardcoreProtestor : public regularProtestor
{
public:
	HardcoreProtestor(int x, int y, StudentWorld *stu) : regularProtestor(x, y, stu) {}

	virtual void doSomething() {
	};
	virtual ~HardcoreProtestor() {};
};
#endif // ACTOR_H_
