#include "worker.h"
#include "sortAndResize.h"
#include <conio.h>
#include <Windows.h>
#include <sstream>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	char ansEx = '3';

	while (ansEx != '0')
	{
		system("cls");
		cout << "===�������� �������===" << endl
			<< "1) ������� 1" << endl
			<< "2) ������� 2" << endl
			<< "0) �����" << endl << endl
			<< "��� �����: ";
		ansEx = _getch();

		switch (ansEx)
		{
		case '1':
		{
			system("cls");
			char ansEx1 = '9';
			int countOfWorkers = 0;
			int capacity = 1;
			Worker** mas = new Worker * [capacity];
			while (ansEx1 != '0')
			{
				system("cls");
				sortMas(mas, countOfWorkers);
				cout << "===����===" << endl
					<< "1) �������� ���������" << endl
					<< "2) ������� ���������" << endl
					<< "3) ������������� ������ ���������" << endl
					<< "4) ������ ������� ������ � ����" << endl
					<< "5) ������� ������ �� �����" << endl
					<< "6) ������� ���������� � ���� ���������� � ���������� �������" << endl
					<< "7) ������� ������� ��� ����������, ��� ���� ���� ���������" << endl
					<< "0) �����" << endl
					<< endl << "��� �����: ";
				ansEx1 = _getch();
				switch (ansEx1)
				{
				case '1': {
					system("cls");
					if (countOfWorkers == capacity) mas = resizeArray(mas, capacity, countOfWorkers);
					countOfWorkers++;
					mas[countOfWorkers - 1] = new Worker;
					system("cls");
					mas[countOfWorkers - 1]->setInformation();
					cout << endl
						<< "���������� � ��������� ������� �������!" << endl;
					system("pause");
					break;
				}
				case '2': {
					system("cls");

					if (countOfWorkers == 0)
					{
						cout << "���� � ���� ��� ���������� � ����������!" << endl;
						system("pause");
						break;
					}

					cout << "===������ ����������===" << endl;

					for (int i = 0; i < countOfWorkers; i++)
					{
						cout << "�������� �" << i << ":" << endl;
						mas[i]->seeInformation();
						cout << endl;
					}

					cout << "������� ����� ��������� ��� ��������: ";
					unsigned short workerToDelete = input<unsigned short>();
					system("cls");
					if (workerToDelete < 0 || workerToDelete > countOfWorkers - 1)
					{
						cout << "�������� ���� ������!" << endl;
						system("pause");
						break;
					}
					else mas[workerToDelete]->clearInformation();

					sortMas(mas, countOfWorkers);
					delete mas[capacity - 1];
					countOfWorkers--;
					capacity--;

					cout << "�������� ������� �����������!" << endl;
					system("pause");
					break;
				}
				case '3': {
					system("cls");

					if (countOfWorkers == 0)
					{
						cout << "���� � ���� ��� ���������� � ����������!" << endl;
						system("pause");
						break;
					}

					cout << "===������ ����������===" << endl;

					for (int i = 0; i < countOfWorkers; i++)
					{
						cout << "�������� �" << i << ":" << endl;
						mas[i]->seeInformation();
						cout << endl;
					}

					cout << "������� ����� ��������� ��� ��������������: ";
					unsigned short workerToChange = input<unsigned short>();
					system("cls");
					if (workerToChange < 0 || workerToChange > countOfWorkers - 1)
					{
						cout << "�������� ���� ������!" << endl;
						system("pause");
						break;
					}
					else mas[workerToChange]->changeInformation();

					sortMas(mas, countOfWorkers);
					cout << "������ ������� ��������!" << endl;
					system("pause");
					break;
				}
				case '4': {
					system("cls");
					if (countOfWorkers == 0)
					{
						cout << "���� �� �� ����� ���������� � ����������!" << endl;
						system("pause");
						break;
					}

					fstream file;
					file.open("base.txt");
					for (int i = 0; i < countOfWorkers; i++)
					{
						mas[i]->writeToFile(file);
					}
					cout << "������ ������� �������!" << endl;
					system("pause");
					break;
				}
				case '5': {
					system("cls");
					fstream file;
					file.open("base.txt");
					if (file.peek() == EOF)
					{
						cout << "���� ����!" << endl;
						system("pause");
						file.close();
						break;
					}
					while (file.peek() != EOF)
					{
						if (countOfWorkers == capacity) mas = resizeArray(mas, capacity, countOfWorkers);
						countOfWorkers++;
						mas[countOfWorkers - 1] = new Worker;
						system("cls");
						mas[countOfWorkers - 1]->readFromFile(file);
					}
					cout << "������ ������� �������!" << endl;
					system("pause");
					file.close();
					break;
				}
				case '6': {
					system("cls");

					if (countOfWorkers == 0)
					{
						cout << "���� � ���� ��� ���������� � ����������!" << endl;
						system("pause");
						break;
					}

					for (int i = 0; i < countOfWorkers; i++)
					{
						mas[i]->seeInformation();
						cout << endl;
					}
					system("pause");
					break;
				}
				case '7': {
					system("cls");

					if (countOfWorkers == 0)
					{
						cout << "���� � ���� ��� ���������� � ����������!" << endl;
						system("pause");
						break;
					}

					cout << "������� ���������� ���, ������ �������� ������ ���� ���� � ���������: ";
					unsigned short userExp = NULL;
					userExp = input<unsigned short>();

					system("cls");

					bool flag = false;

					cout << "���������, ��� ���� ��������� " << userExp << " ���:" << endl;

					for (int i = 0; i < countOfWorkers; i++)
					{
						if (mas[i]->isExpMoreThanUserExp(userExp))
						{
							mas[i]->seeSurname(); cout << "\t\t���� ���������: " << mas[i]->getExp() << " ���" << endl;
							flag = true;
						}
					}

					cout << endl;

					if (flag == false) cout << "����������, ��� ���� ���� ��������� ����, � ���� �� �������!" << endl;
					system("pause");
					break;
				}
				case '0': {
					system("cls");
					cout << "����������� � ����!" << endl;
					system("pause");
					break;
				}
				default:
				{
					system("cls");
					cout << "���� ��������!" << endl;
					system("pause");
					break;
				}
				}
			}
			if (countOfWorkers != 0)
				for (int i = 0; i < capacity; i++)
					delete mas[i];
			delete[] mas;
			break;
		}
		case '2':{
			system("cls");
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			cout << "���������, ����� ������������" << endl;
			system("main.py");
			cout << endl << "����� ������������!" << endl << endl;
			system("pause");
			system("cls");
			fstream file;
			file.open("text.txt", std::ios::in);
			if (!file.is_open())
			{
				file.close();
				cout << "���� �� ����� ���� ������!" << endl;
				break;
			}

			string readingString;

			cout << "����� ���� �����. �����������, �� ���������� �������, ����� �������� ";
			SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			cout << "����� ";
			SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "������." << endl << endl;

			while (getline(file, readingString))
			{
				SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				std::stringstream stringStream(readingString);
				string word;
				string sentence;
				while (stringStream >> word)
				{
					sentence.append(word + ' ');
					if ((word[word.size() - 1] == '.') || (word[word.size() - 1] == '!') || (word[word.size() - 1] == '?'))
					{
						if (sentence.find(',') == string::npos)
						{
							SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
						}
						cout << sentence;
						sentence.clear();
						SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
					}
				}
				cout << endl;
			}

			cout << endl << "����� ��� ������������ ���������� ";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "��������.";
			SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << endl << endl;

			file.close();
			system("pause");
			break;
		}
		case '0':{
			system("cls");
			cout << "�� ��������!" << endl;
			system("pause");
			break;
		}
		default:{
			system("cls");
			cout << "���� ��������!" << endl;
			system("pause");
			break;
		}
		}
	}
	return 0;
}