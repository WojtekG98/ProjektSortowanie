#ifndef TESTOWANIE_H
#define TESTOWANIE_H
#include <cstdlib>
#include <ctime>


template <class Type>
bool CzyPosortowane(Type tab[], int size) {
	bool wynik = true;
	for (int i = 0; i < size - 1; i++)
		if (tab[i] > tab[i + 1])
			wynik = false;
	return wynik;
}

template <class Type>
void Odwrotnie(Type tab[], int size)
{
	for (int i = 0; i < size; i++)
		tab[i] = size - i;
}

template <class Type>
void Poprawnie(Type tab[], int size, float procent)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		if (i < size*procent / 100)
			tab[i] = i;
		else
			tab[i] = rand();
}

template <class Type>
void Losowo(Type *tab, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		tab[i] = rand();
}

#endif