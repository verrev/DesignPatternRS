#pragma once

#include <string>
#include <iostream>

class SpeaksLanguage
{
public:
	virtual std::string getLanguage() = 0;
};

class SpeaksChinese : public SpeaksLanguage
{
public:
	std::string getLanguage() override { return "speaks chinese"; }
};

class SpeaksPortugese : public SpeaksLanguage
{
public:
	std::string getLanguage() override { return "speaks portugese"; }
};

class Person
{
public:
	Person() {}
	Person(std::string language) { if (language == "chinese") mLanguage = new SpeaksChinese; else mLanguage = new SpeaksPortugese; }
	~Person() { delete mLanguage; }
	void getType() { std::cout << "This person " << mLanguage->getLanguage() << ".\n"; }
private:
	SpeaksLanguage *mLanguage;
	int height, age;
	double weight;
};

/*
Person p("chinese");
Person p2("portugese");
p.getType();
p2.getType();
*/