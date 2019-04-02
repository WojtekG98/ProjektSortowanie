#include "Testowanie.h"
#include "Algorytmy.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <chrono>
//#include <unistd.h>

using namespace std;

int main()
{
	long rowCount = 100;
	long colCount = 10000;
	int wybor = 0;
	float procent = 100;
	int** TablicaTablic = new int*[rowCount];
	fstream zapis;
	zapis.open("zapis.txt", ios::out);
	
	cout << "Wybierz wielkoœæ tablic: 1 - 10 000\n 2 - 50 000\n 3 - 100 000\n 4 - 500 000\n 5 - 1 000 000\n";
	cin >> wybor;
	switch (wybor)
	{
	case 1:
		colCount = 10000;
		break;
	case 2:
		colCount = 50000;
		break;
	case 3:
		colCount = 100000;
		break;
	case 4:
		colCount = 500000;
		break;
	case 5:
		colCount = 1000000;
		break;
	default:
		cout << "Bledny wybor\n";
		break;
	}
	
	for (int i = 0; i < rowCount; ++i)
		TablicaTablic[i] = new int[colCount];

	zapis << "100 Tablic " << colCount << " liczb\n";
	cout << "Wybierz przypadek: 1 - wszystkie elementy tablicy losowe,\n"
		<< "2 - % pocz¹tkowych elementów tablicy jest ju¿ posortowanych,\n"
		<< "3 - wszystkie elementy tablicy ju¿ posortowane ale w odwrotnej kolejnoœci\n";
	cin >> wybor;
	switch (wybor)
	{
	case 1:
		for (int i = 0; i < rowCount; i++)
			Losowo(TablicaTablic[i], colCount);
		zapis << "wszystkie elementy tablicy losowe\n";
		break;
	case 2:
		cout << "Podaj % tablicy jaki ma byc posortowany:";
		cin >> procent;
		for (int i = 0; i < rowCount; i++)
			Poprawnie(TablicaTablic[i], colCount, 100);
		zapis << procent << "% pocz¹tkowych elementów tablicy jest ju¿ posortowanych";
		break;
	case 3:
		for (int i = 0; i < rowCount; i++)
			Odwrotnie(TablicaTablic[i], colCount);
		zapis << "wszystkie elementy tablicy ju¿ posortowane ale w odwrotnej kolejnoœci.\n";
		break;
	default:
		cout << "Bledny wybor\n";
		for (int i = 0; i < rowCount; i++)
			Odwrotnie(TablicaTablic[i], colCount);
		zapis << "wszystkie elementy tablicy ju¿ posortowane ale w odwrotnej kolejnoœci.\n";
		break;
	}

	auto start = chrono::steady_clock::now();
	for (int i = 0; i < rowCount; i++)
	{
		//QuickSort(TablicaTablic[i], 0, colCount - 1);
		//ShellSort(TablicaTablic[i], colCount);
		//BubbleSort(TablicaTablic[i], colCount);
		MergeSort(TablicaTablic[i], 0, colCount - 1);
	}
	auto end = chrono::steady_clock::now();
	
	//zapis << "\nShellSort\n";
	//zapis << "\nQuicksort\n";
	zapis << "\nMergeSort\n";
	
	/*Sprawdzenie czy tablica rzeczywiscie posortowana*/
	for (int i = 0; i < rowCount; i++)
		if (!CzyPosortowane(TablicaTablic[i], colCount))
			zapis << "NIE POSORTOWANE!\n";
	/*Wypisywanie wartoœci tablicy do pliku "zapis.txt"*/
	
	//for (int j=0; j<rowCount; ++j)
		//for (int i = 0; i < colCount; i++)
		//{
			//zapis << TablicaTablic[j][i] << ", ";
			//if ((i+1) % 100 == 0)
				//zapis << endl;
		//}

	zapis << "Czas w milisekundach : "
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " ms" << endl;

	for (int i = 0; i < rowCount; ++i) {
		delete[] TablicaTablic[i];
	}
	delete[] TablicaTablic;

	return 0;
}
