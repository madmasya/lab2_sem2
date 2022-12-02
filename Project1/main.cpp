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
		cout << "===Выберите задание===" << endl
			<< "1) Задание 1" << endl
			<< "2) Задание 2" << endl
			<< "0) Выход" << endl << endl
			<< "Ваш выбор: ";
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
				cout << "===МЕНЮ===" << endl
					<< "1) Добавить работника" << endl
					<< "2) Удалить работника" << endl
					<< "3) Редактировать данные работника" << endl
					<< "4) Внести текущие данные в файл" << endl
					<< "5) Считать данные из файла" << endl
					<< "6) Вывести информацию о всех работниках в алфавитном порядке" << endl
					<< "7) Вывести фамилии тех работников, чей стаж выше введённого" << endl
					<< "0) Выход" << endl
					<< endl << "Ваш выбор: ";
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
						<< "Информация о работнике внесена успешно!" << endl;
					system("pause");
					break;
				}
				case '2': {
					system("cls");

					if (countOfWorkers == 0)
					{
						cout << "Пока в базе нет информации о работниках!" << endl;
						system("pause");
						break;
					}

					cout << "===Список работников===" << endl;

					for (int i = 0; i < countOfWorkers; i++)
					{
						cout << "Работник №" << i << ":" << endl;
						mas[i]->seeInformation();
						cout << endl;
					}

					cout << "Введите номер работника для удаления: ";
					unsigned short workerToDelete = input<unsigned short>();
					system("cls");
					if (workerToDelete < 0 || workerToDelete > countOfWorkers - 1)
					{
						cout << "Неверный ввод номера!" << endl;
						system("pause");
						break;
					}
					else mas[workerToDelete]->clearInformation();

					sortMas(mas, countOfWorkers);
					delete mas[capacity - 1];
					countOfWorkers--;
					capacity--;

					cout << "Удаление успешно произведено!" << endl;
					system("pause");
					break;
				}
				case '3': {
					system("cls");

					if (countOfWorkers == 0)
					{
						cout << "Пока в базе нет информации о работниках!" << endl;
						system("pause");
						break;
					}

					cout << "===Список работников===" << endl;

					for (int i = 0; i < countOfWorkers; i++)
					{
						cout << "Работник №" << i << ":" << endl;
						mas[i]->seeInformation();
						cout << endl;
					}

					cout << "Введите номер работника для редактирования: ";
					unsigned short workerToChange = input<unsigned short>();
					system("cls");
					if (workerToChange < 0 || workerToChange > countOfWorkers - 1)
					{
						cout << "Неверный ввод номера!" << endl;
						system("pause");
						break;
					}
					else mas[workerToChange]->changeInformation();

					sortMas(mas, countOfWorkers);
					cout << "Данные успешно изменены!" << endl;
					system("pause");
					break;
				}
				case '4': {
					system("cls");
					if (countOfWorkers == 0)
					{
						cout << "Пока Вы не ввели информации о работниках!" << endl;
						system("pause");
						break;
					}

					fstream file;
					file.open("base.txt");
					for (int i = 0; i < countOfWorkers; i++)
					{
						mas[i]->writeToFile(file);
					}
					cout << "Данные введены успешно!" << endl;
					system("pause");
					break;
				}
				case '5': {
					system("cls");
					fstream file;
					file.open("base.txt");
					if (file.peek() == EOF)
					{
						cout << "Файл пуст!" << endl;
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
					cout << "Данные считаны успешно!" << endl;
					system("pause");
					file.close();
					break;
				}
				case '6': {
					system("cls");

					if (countOfWorkers == 0)
					{
						cout << "Пока в базе нет информации о работниках!" << endl;
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
						cout << "Пока в базе нет информации о работниках!" << endl;
						system("pause");
						break;
					}

					cout << "Введите количество лет, больше которого должен быть стаж у работника: ";
					unsigned short userExp = NULL;
					userExp = input<unsigned short>();

					system("cls");

					bool flag = false;

					cout << "Работники, чей стаж превышает " << userExp << " лет:" << endl;

					for (int i = 0; i < countOfWorkers; i++)
					{
						if (mas[i]->isExpMoreThanUserExp(userExp))
						{
							mas[i]->seeSurname(); cout << "\t\tСтаж работника: " << mas[i]->getExp() << " лет" << endl;
							flag = true;
						}
					}

					cout << endl;

					if (flag == false) cout << "Работников, чей стаж выше введённого вами, в базе не найдено!" << endl;
					system("pause");
					break;
				}
				case '0': {
					system("cls");
					cout << "Возвращение в меню!" << endl;
					system("pause");
					break;
				}
				default:
				{
					system("cls");
					cout << "Ввод неверный!" << endl;
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
			cout << "Подождите, текст генерируется" << endl;
			system("main.py");
			cout << endl << "Текст сгенерирован!" << endl << endl;
			system("pause");
			system("cls");
			fstream file;
			file.open("text.txt", std::ios::in);
			if (!file.is_open())
			{
				file.close();
				cout << "Файл не может быть открыт!" << endl;
				break;
			}

			string readingString;

			cout << "Перед Вами текст. Предложения, не содержащие запятых, будут выделены ";
			SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			cout << "синим ";
			SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << "цветом." << endl << endl;

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

			cout << endl << "Текст был сгенерирован нейросетью ";
			SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "Балабоба.";
			SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			cout << endl << endl;

			file.close();
			system("pause");
			break;
		}
		case '0':{
			system("cls");
			cout << "До свидания!" << endl;
			system("pause");
			break;
		}
		default:{
			system("cls");
			cout << "Ввод неверный!" << endl;
			system("pause");
			break;
		}
		}
	}
	return 0;
}