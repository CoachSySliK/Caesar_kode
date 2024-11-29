#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool symbol_uppercase (char symbol) {
	if (symbol >= 'A' && symbol <= 'Z')
		return true;
	return false;
}

bool symbol_lowercase (char symbol) {
	if (symbol >= 'a' && symbol <= 'z')
		return true;
	return false;
}

string encrypt_caesar (string text, int key) 
{
	for (int i = 0; i < text.length(); i++) {
		if (symbol_uppercase(text[i])) {
			text[i] += key;
			if (!symbol_uppercase(text[i]))
				text[i] -= 26;
		} else if (symbol_lowercase(text[i])) {
			text[i] += key;
			if (!symbol_lowercase(text[i]))
				text[i] -= 26;
		} else {
			continue;
		}
	}
	return text;
}

bool key_true (string key)
{
	for (int i = 0; i < key.length(); i++) {
		if (key[i] < '0' || key[i] > '9') {
			cout << "Ошибка! Некорректное значение\n";
			return false;
		}
	}
	return true;
}

int key_make (string key, int k) {
	for (int i = 0; i < key.length(); i++) {
		k += (key[key.length() - i - 1] - 48) * pow(10, i);
	}
	k %= 26;
	return k;
}

int main (void)
{
	string text;
	cout << "Введите текст: ";
	getline(cin, text);
	
	string key;
	do {
		cout << "Введите ключ: ";
		cin >> key;
	} while (!key_true(key));
	
	int k = 0;
	k = key_make(key, k);
	
	cout << "---Шифр Цезарь---" << endl;
	
	cout << encrypt_caesar(text, k);	
	
	return 0;
}