//Этот проект создан с помощью классического шаблона
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "windows.h"

void fileInsert(std::string way, int pos, std::string str);
const int takt = 100;
int timer = 0;//отслеживает прошедшее время



int main() {
	setlocale(LC_ALL, "Russian");
	int m, n;


	std::string path = "file.txt";
	std::fstream file;
	//класс fstream

	file.open(path, std::ios::app | std::ios::in);
	if (file.is_open()) {
		std::cout << "file opened\n";
		//запись
		//file.seekp(1, std::ios::beg); //неработает
		file << "open world\n";
		std::cout << "данные записаны\n";
		file.seekg(0, std::ios::beg);//перемещение курсора для считывания в начало файла
		//считывание
		std::cout << "содиржимое файла:\n";
		char sym;
		while (file.get(sym)) {
			std::cout << sym;
		}
	}
	else
		std::cout << "Error opened file!\n";

	file.close();


	//Задание. Запись в файл

	std::cout << "Введите строку: ";
	std::string str;
	getline(std::cin, str);
	std::cout << "Введите позицию : ";
	std::cin >> n;
	fileInsert(path, n, str);

			//Задача: Дата из файла
	std::ifstream in;
	in.open("date.txt");
	if (in.is_open()) {
		int day, month, year;
		std::string tmp;
		getline(in, tmp);
		day = stoi(tmp.substr(0, tmp.find('.')));// можно заменить на stoi(tmp);
		std::cout << "День = " << day << '\n';
		month = stoi(tmp.substr(tmp.find('.') + 1));
		std::cout << "Месяц = " << month << '\n';
		year = stoi(tmp.substr(tmp.rfind('.') + 1));
		std::cout << "Год = " << year << '\n';
	}
	else
		std::cout << "Ошибка открытия файла!\n";
	in.close();


			// ДЛя игры Galaga
		char key;
		while (true) {
			if (_kbhit()) {
				key = _getch();
				switch (key) {
				case 'A':case'a':
					std::cout << "Left\n"; break;
				case 'D':case'd':
					std::cout << "Right\n"; break;
				}
			}
			Sleep(takt);
			timer += takt;
			if (timer >= 1000) {
				std::cout << ".\n";
				timer = 0;
			}
		}



		//функции для проектов
		std::cout << "Введите число: \n";
		std::cin >> n;
		system("cls"); // полная очистка консоли
		std::cout << "число равно " << n << '\n';

		system("pause"); // "Для продолжения нажмите любую клавишу"





		return 0;
}

	//запись строки в файл
	void fileInsert(std::string way, int pos, std::string str) {
		std::ifstream in;
		std::string temp;
		//записываем файл в строку
		in.open(way);
		if (in.is_open()) {
			char tmp;
			while (in.get(tmp))
				temp += tmp;
		}
		in.close();
		//вставляем содержимое str в строку
		temp.insert(pos, str);
		//заменяем содержимое файла на строку
		std::ofstream out;
		out.open(way, std::ios::out);
		if (out.is_open())
			out << temp;
		out.close();
	}



















