#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int symbol_true(const string ABC, char symbol)
{
	for (int i = 0; i < ABC.length(); i++)
	{
		if (symbol != ABC[i])
			continue;
		else
			return i;
	}
	return -1;
}

string encrypt_caesar(const string ABC, string text, int key)
//я объединил две функции в одну, для этого мне пришлось написать свой алфавит, и теперь возмодна смена регистра. Что бы регистр не менялся, надо делать два разных алфавита, вводить дополнительные переменные, проще было оставить как было, по отдельной функции на строчные и заглавные буквы.
{
	for (int i = 0; i < text.length(); i++)
	{
		if (symbol_true(ABC, text[i]) + 1)
		{
			cout << ABC.length() << endl;
			int k = symbol_true(ABC, text[i]) + key;
			cout << key << " : " << k << endl;
			if (k > ABC.length() - 1)
			{
				k -= ABC.length();
			}
			if (k < 0)
			{
				k += ABC.length();
			}
			cout << key << " : " << k << endl;
			text[i] = ABC[k];
		}
		else
		{
			continue;
		}
	}
	return text;
}

bool key_true(string key)
{
	int i = 0;
	if (key[0] == '-')
		++i;
	for (; i < key.length(); i++)
	{
		if (key[i] < '0' || key[i] > '9')
		{
			cout << "Ошибка! Некорректное значение\n";
			return false;
		}
	}
	return true;
}

int main(void)
{
	string text;
	cout << "Введите текст: ";
	getline(cin, text);

	string key;
	do
	{
		cout << "Введите ключ: ";
		cin >> key;
	} while (!key_true(key));

	int k = stoi(key);
	//это специально, потому что ключ может быть любой длины, за исключением ограничений на размер int
	k %= 26;

	cout << "---Шифр Цезарь---" << endl;

	const string ABC = {"ABCDEFGHIJKLMNOP"
						"QARSTUVWXYZ"
						"abcdefghijklmnop"
						"qrstuvwxyz"};

	cout << encrypt_caesar(ABC, text, k);

	return 0;
}