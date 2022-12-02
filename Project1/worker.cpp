#include "worker.h"

Worker::Worker() : surname("nil"), name("nil"), patronymic("nil"), job("nil"), year(0) {}

Worker::Worker(string surname, string name, string partonymic, string job, int year) : surname(surname), name(name), patronymic(patronymic), job(job), year(year) {}

Worker::Worker(Worker& Worker) : surname(Worker.surname), name(Worker.name), patronymic(Worker.patronymic), job(Worker.job), year(Worker.year) {}

string Worker::getSurname() { return surname; }
void Worker::setSurname() {
	cout << "������� ������� ���������: ";
	surname = input<string>();
	cout << endl;
}

string Worker::getName() { return name; }
void Worker::setName() {
	cout << "������� ��� ���������: ";
	name = input<string>();
	cout << endl;
}

string Worker::getPatronymic() { return patronymic; }
void Worker::setPatronymic() {
	cout << "������� �������� ���������: ";
	patronymic = input<string>();
	cout << endl;
}

string Worker::getJob() { return job; }
void Worker::setJob() {
	cout << "������� ��������� ���������: ";
	job = input<string>();
	cout << endl;
}

unsigned short Worker::getYear() { return year; }
void Worker::setYear(){
	cout << "������� ���, � ������� �������� ��������� �� ������: ";
	year = input<unsigned short>();
	cout << endl;
}

void Worker::writeToFile(fstream& file)
{
	if (file.is_open())
	{
		file << surname << endl;
		file << name << endl;
		file << patronymic << endl;
		file << job << endl;
		file << year << endl;
	}
	else cout << "���� �� ����� ���� �������� ���������" << endl;
}

void Worker::readFromFile(fstream& file)
{
	if (file.is_open())
	{
		getline(file, surname);
		getline(file, name);
		getline(file, patronymic);
		getline(file, job);
		string yearStr;
		getline(file, yearStr);
		year = stoi(yearStr);
	}
	else cout << "���� �� ����� ���� �������� ���������" << endl;
}

void Worker::setInformation()
{
	this->setSurname();
	this->setName();
	this->setPatronymic();
	this->setJob();
	this->setYear();
}

void Worker::changeInformation()
{
	cout << "������� ����� ������:" << endl;
	this->setSurname();
	this->setName();
	this->setPatronymic();
	this->setJob();
	this->setYear();
}

void Worker::seeInformation()
{
	cout << "�������: " << surname << endl
		<< "���: " << name << endl
		<< "��������: " << patronymic << endl
		<< "���������: " << job << endl
		<< "��� ���������� �� ���������: " << year << endl;
}

void Worker::seeSurname()
{
	cout << surname;
}

void Worker::clearInformation()
{
	surname = "���";
}

Worker* Worker::clone()
{
	return new Worker(*this);
}

bool Worker::isExpMoreThanUserExp(int userExp) {
	int exp = 2022 - year;
	bool res;
	exp > userExp ? res = true : res = false; return res;
}

unsigned short Worker::getExp()
{
	return 2022 - this->getYear();
}