//���� ������ ������ � ������� ������������� �������
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "windows.h"

void fileInsert(std::string way, int pos, std::string str);
const int takt = 100;
int timer = 0;//����������� ��������� �����



int main() {
	setlocale(LC_ALL, "Russian");
	int m, n;


	std::string path = "file.txt";
	std::fstream file;
	//����� fstream

	file.open(path, std::ios::app | std::ios::in);
	if (file.is_open()) {
		std::cout << "file opened\n";
		//������
		//file.seekp(1, std::ios::beg); //����������
		file << "open world\n";
		std::cout << "������ ��������\n";
		file.seekg(0, std::ios::beg);//����������� ������� ��� ���������� � ������ �����
		//����������
		std::cout << "���������� �����:\n";
		char sym;
		while (file.get(sym)) {
			std::cout << sym;
		}
	}
	else
		std::cout << "Error opened file!\n";

	file.close();


	//�������. ������ � ����

	std::cout << "������� ������: ";
	std::string str;
	getline(std::cin, str);
	std::cout << "������� ������� : ";
	std::cin >> n;
	fileInsert(path, n, str);

			//������: ���� �� �����
	std::ifstream in;
	in.open("date.txt");
	if (in.is_open()) {
		int day, month, year;
		std::string tmp;
		getline(in, tmp);
		day = stoi(tmp.substr(0, tmp.find('.')));// ����� �������� �� stoi(tmp);
		std::cout << "���� = " << day << '\n';
		month = stoi(tmp.substr(tmp.find('.') + 1));
		std::cout << "����� = " << month << '\n';
		year = stoi(tmp.substr(tmp.rfind('.') + 1));
		std::cout << "��� = " << year << '\n';
	}
	else
		std::cout << "������ �������� �����!\n";
	in.close();


			// ��� ���� Galaga
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



		//������� ��� ��������
		std::cout << "������� �����: \n";
		std::cin >> n;
		system("cls"); // ������ ������� �������
		std::cout << "����� ����� " << n << '\n';

		system("pause"); // "��� ����������� ������� ����� �������"





		return 0;
}

	//������ ������ � ����
	void fileInsert(std::string way, int pos, std::string str) {
		std::ifstream in;
		std::string temp;
		//���������� ���� � ������
		in.open(way);
		if (in.is_open()) {
			char tmp;
			while (in.get(tmp))
				temp += tmp;
		}
		in.close();
		//��������� ���������� str � ������
		temp.insert(pos, str);
		//�������� ���������� ����� �� ������
		std::ofstream out;
		out.open(way, std::ios::out);
		if (out.is_open())
			out << temp;
		out.close();
	}



















