#pragma once

#include <string>
#include <iostream>

class Pizza
{
public:
	virtual std::string getDescription() = 0;
	virtual double getPrice() = 0;
};

class PlainPizza : public Pizza
{
public:
	PlainPizza() { std::cout << "Adding dough"; }

	std::string getDescription() override { return "Thin dough"; }
	double getPrice() override { return 4.00; }
};

class ToppingDecorator : public Pizza
{
public:
	ToppingDecorator() {}
	ToppingDecorator(Pizza *p) : mPizza(p) {}

	std::string getDescription() override { return mPizza->getDescription(); }
	double getPrice() override { return mPizza->getPrice(); }
protected:
	Pizza *mPizza;
};

class Mozarella : public ToppingDecorator
{
public:
	Mozarella() {}
	Mozarella(Pizza *p) : ToppingDecorator(p) { std::cout << "\nAdding mozzarella"; }

	std::string getDescription() override { return mPizza->getDescription(); +", Mozzarella"; }
	double getPrice() override { return mPizza->getPrice() + 0.50; }
};

class TomatoSauce : public ToppingDecorator
{
public:
	TomatoSauce() {}
	TomatoSauce(Pizza *p) : ToppingDecorator(p) { std::cout << "\nAdding tomato sauce"; }

	std::string getDescription() override { return mPizza->getDescription(); +", Tomato sauce"; }
	double getPrice() override { return mPizza->getPrice() + 2.50; }
};

/*
Pizza *p = new TomatoSauce(new Mozarella(new PlainPizza()));
std::cout << "\nPizza consists of " << p->getDescription() << " and it costs " << p->getPrice();
delete p;
*/