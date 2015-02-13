#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

FILE *fl;

typedef struct
{
	char fio[30];
	unsigned char nomer_otdela;
	unsigned char doljnost;
	unsigned char data_nachala;
}
Workmen;
Workmen men[30];
char name[20];
int kolvo = 0;

int Menu();
void Nnf();
void Newf();
void Spisok();
void Opf();
void Resc();
void Resf();

int main()
{
	while (true)
	{
		switch (Menu())
		{
			case 1: Nnf(); break;
			case 2: Newf(); break;
			case 3: Spisok(); break;
			case 4: Opf(); break;
			case 5: Resc(); break;
			case 6: Resf(); break; 
			case 7: return 0;
			default: puts("Choose correctly!");
		}

		puts ("Press any key to continue");
		getch ();
		system ("cls");
	}
}

int Menu()
{
	cout << "Choose: " << endl;
	cout << "1. Enter file name" << endl; 
	cout << "2. New file" << endl;
	cout << "3. Vvesti spisok" << endl; 
	cout << "4. Open file" << endl; 
	cout << "5. Out result" << endl; 
	cout << "6. Out in file" << endl; 
	cout << "7. Exit" << endl;

	int i;
	cin >> i;
	return i;
}

void Nnf()
{
	cout <<"Enter file name" << endl;
	cin >> name;
}

void Newf()
{
	if ((fl = fopen(name, "wb")) == NULL)
	{
		cout << "Error" << endl;
		exit(1);
	}
	cout << "OK" << endl; 
	fclose(fl);
}

void Spisok()
{
	if ((fl = fopen(name, "rb+")) == NULL)
	{
		cout << "Error" << endl;
		exit(1);
	}
	cout << "Enter amout of workmen"<< endl;
	cin >> kolvo;
	for (int i = 0; i < kolvo; i ++)
	{
		cout << "Enter name: ";
		cin >> men[i].fio;
		cout << "Enter doljnost: ";
		cin >> men[i].doljnost;
		cout << "Enter date: ";
		cin >> men[i].data_nachala;
		cout << "Enter nomer otdela: ";
		cin >> men[i].nomer_otdela;
	}
}