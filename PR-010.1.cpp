#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void PrintTXT(string fname) // виведення файлу на екран
{
	ifstream fin(fname); // відкрили файл для зчитування
	string s; // прочитаний рядок
	while (getline(fin, s)) // поки можна прочитати рядок
	{
		cout << s << endl; // виводимо його на екран
	}
	cout << endl;
}

void FindComma(string fname, string gname) // сортування рядків текстового файлу
{
	ofstream g(gname); 
	string line= ""; 
	int row = -1, col=-1;
	int k=0;
	bool isFound = false;

		ifstream f(fname); // відкрили перший файл для зчитування
		if (f.is_open()) {
			while (getline(f, line)&&!isFound) // поки можна зчитувати рядки
			{
				for (int i = 0; i < line.size(); i++) {
					if (line[i] == ',') {
						k++;
					}
					if (k == 3) {
						col = i;
						isFound = true;
						break;

					}
				}
				row++;
			}

			if (g.is_open()) {
				g << row << " " << col << endl;
				g.close();
			}
			
			f.close();
		}
; 
}
int main()
{
	string fname, gname;
	cout << "Input name of input file: ";
	cin >> fname;
	cout << "Input name of output file: ";
	cin >> gname;
	FindComma(fname, gname);
	cout << "Content of input file: " << endl;
	PrintTXT(fname);
	cout << "Content of output file: " << endl;
	PrintTXT(gname);
	return 0;
}