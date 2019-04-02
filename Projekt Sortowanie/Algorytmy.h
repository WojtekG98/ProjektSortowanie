#ifndef ALGORYTMY_H
#define ALGORYTMY_H

#include <iostream>
#include "Testowanie.h"



template <class Type>
void BubbleSort(Type *tab, long size)
{
	while (!CzyPosortowane(tab, size))
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (tab[j] > tab[j + 1])
			{
				std::swap(tab[j], tab[j + 1]);
			}
		}
	}
}

template <class Type>
void Scal(Type *tab, long left, long middle, long right)
{
	Type *pom=new Type[right+1];
	int i = left; int j = middle + 1;
	for (int i = left; i <= right; i++)
		pom[i] = tab[i];
	for (int k = left; k <= right; k++)
		if (i <= middle)
			if (j <= right)
				if (pom[j] < pom[i])
					tab[k] = pom[j++];
				else
					tab[k] = pom[i++];
			else
				tab[k] = pom[i++];
		else
			tab[k] = pom[j++];
	delete[] pom;
}

template <class Type>
void MergeSort(Type *tab, long left, long right)
{
	if (right <= left) return;
	long middle = (right + left) / 2;
	MergeSort(tab, left, middle);
	MergeSort(tab, middle + 1, right);
	Scal(tab, left, middle, right);
}

template <class Type>
void ShellSort(Type *tab, int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i ++)
		{
			Type temp = tab[i];
			int j;
			for (j = i; j >= gap && tab[j - gap] > temp; j -= gap)
				tab[j] = tab[j - gap];
			tab[j] = temp;
		}
	}
}

template <class Type>
void QuickSort(Type *tab, int left, int right)
{
	int i = left;
	int j = right;
	Type x = tab[(left + right) / 2];
	while (i <= j)
	{
		while (tab[i] < x)
			i++;

		while (tab[j] > x)
			j--;

		if (i <= j)
		{
			std::swap(tab[i], tab[j]);
			i++;
			j--;
		}
	}

	if (left < j)
		QuickSort(tab, left, j);

	if (right > i)
		QuickSort(tab, i, right);
}
#endif
