#pragma once

#include <iostream>
#include <vector>
#include <string>

class Subject;

class Observer
{
public:
	virtual void notify() = 0;
};

class Subject
{
	//----------------------------------------------------------------------
public:
	// These functions are all implemented by a concrete sibling class.
	void setVal(int v) { value = v; notifyObservers(); }
	int getVal() { return value; }
private:
	int value;
	//----------------------------------------------------------------------

public:
	void registerObserver(Observer *o) { mObservers.push_back(o); }
	void unRegisterObserver(Observer *o) { mObservers.erase(std::find(mObservers.begin(), mObservers.end(), o)); }
private:
	void notifyObservers() { for (auto o : mObservers) o->notify(); }
private:
	std::vector<Observer*> mObservers;
};

class Console : Observer
{
public:
	Console() {}
	Console(Subject *s) { mSubject = s; mSubject->registerObserver(this); }
	void notify() override
	{
		std::cout << "Class Console was notified of a change in Subject's value.\n";
		std::cout << "The new value is " << mSubject->getVal() << ".\n";
		std::cout << "Whether or not this exact class is interested in the change of a concrete value\n";
		std::cout << "is not up for debate. It is notified of ALL VALUE CHANGES that happen in subject (subject may have multiple changing values).\n";
		std::cout << "e.g. an input class notifies all observers on any keypress while observer A may ONLY be interested in the pressing of the 'A' key\n";
		std::cout << "and observer B is interested ONLY in the pressing of the 'Z' key. Both classes get notified on both 'A' and 'Z' presses. If they\n";
		std::cout << "wish to use this information is up to them.\n";
	}
private:
	Subject *mSubject;
};

/*
Subject s;
Console o(&s);
Console o2(&s);
s.setVal(10);
*/