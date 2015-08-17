#pragma once

#include <iostream>
#include <string>

class Animal
{
public:
	virtual std::string speak() = 0;
};

class LandAnimal : public Animal {};
class SeaAnimal : public Animal {};

class Cat : public LandAnimal
{
public:
	std::string speak() override { return "Meow"; }
};

class Dog : public LandAnimal
{
public:
	std::string speak() override { return "Woof"; }
};

class Octopus : public SeaAnimal
{
public:
	std::string speak() override { return "Blublubblub"; }
};

class Shark : public SeaAnimal
{
public:
	std::string speak() override { return "AAAARgh!"; }
};

class LandAnimalFactory;
class SeaAnimalFactory;

class AnimalFactory
{
public:
	static AnimalFactory *createAnimalFactory(std::string type);
public:
	virtual Animal *createAnimal(std::string type) = 0;
};

class SeaAnimalFactory : public AnimalFactory
{
public:
	Animal *createAnimal(std::string type) override
	{
		if (type == "Octopus") {
			return new Octopus;
		}
		else if (type == "Shark") {
			return new Shark;
		}
		else {
			return nullptr;
		}
	}
};

class LandAnimalFactory : public AnimalFactory
{
public:
	Animal *createAnimal(std::string type) override
	{
		if (type == "Cat") {
			return new Cat;
		}
		else if (type == "Dog") {
			return new Dog;
		}
		else {
			return nullptr;
		}
	}
};

/*
------------] This NEEDS to be defined in a CPP file [----------------

AnimalFactory *AnimalFactory::createAnimalFactory(std::string type)
{
if (type == "SeaAnimalFactory") {
return new SeaAnimalFactory;
}
else if (type == "LandAnimalFactory") {
return new LandAnimalFactory;
}
else {
return nullptr;
}
}

AnimalFactory *af = AnimalFactory::createAnimalFactory("SeaAnimalFactory");
Animal *a = af->createAnimal("Shark");
std::cout << a->speak();

delete af;
delete a;
*/

