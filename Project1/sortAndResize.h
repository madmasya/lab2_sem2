#pragma once
#include "worker.h"

void sortMas(Worker** mas, int maslength)
{
	while (maslength--)
	{
		bool swapped = false;

		for (int i = 0; i < maslength; i++)
		{
			if (mas[i]->getSurname() > mas[i + 1]->getSurname())
			{
				std::swap(mas[i], mas[i + 1]);
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}
}

Worker** resizeArray(Worker** mas, int& capacity, int countOfWorkers)
{
	int newSize = capacity + 1;
	Worker** biggerArray = new Worker * [newSize];

	for (int i = 0; i < countOfWorkers; i++)
	{
		biggerArray[i] = mas[i]->clone();
	}

	for (int i = 0; i < countOfWorkers; i++)
	{
		delete mas[i];
	}
	delete[] mas;
	capacity = newSize;
	mas = biggerArray;
	return mas;
}