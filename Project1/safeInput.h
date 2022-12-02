#pragma once
#include <iostream>

template <typename T>
T input()
{
	using std::cin;
	using std::cout;
	T input;
	while (1)
	{
		cin.unsetf(std::ios::skipws);
		cin >> input;
		if (cin.good())
		{
			cin.ignore(1000, '\n');
			return input;
		}
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "\n¬вод неверный!\n\n";
	}
}
