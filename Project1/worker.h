#pragma once

#include "safeInput.h"
#include <string>
#include <iostream>
#include <fstream>

using std::cout; using std::cin; using std::endl; using std::string; using std::fstream;

class Worker
{
	string surname;
	string name;
	string patronymic;
	string job;
	unsigned short year;

public:
	Worker();
	Worker(string surname, string name, string partonymic, string job, int year);
	Worker(Worker& Worker);
	~Worker() {}

	string getSurname();
	void setSurname();

	string getName();
	void setName();

	string getPatronymic();
	void setPatronymic();

	string getJob();
	void setJob();

	unsigned short getYear();
	void setYear();

	void writeToFile(fstream& file);

	void readFromFile(fstream& file);

	void setInformation();

	void changeInformation();

	void seeInformation();

	void seeSurname();

	void clearInformation();

	Worker* clone();

	bool isExpMoreThanUserExp(int userExp);

	unsigned short getExp();
};