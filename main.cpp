//Krzysztof Gótrski 245079
#define _USE_MATH_DEFINES
#include <iostream>
#include <chrono>
#include <algorithm>
#include <cmath>
#include <fstream>
#include "metody.h"
using namespace std;

#define DataType int // definicja rodzaju danych np. int, duble, float

void check_if_open(std::ofstream& file)
{
	if (!file.is_open())
	{
		std::cout << "File is not open!\nProgram closing...";
		std::cin.get();
		exit(1);
	}
}

//wypisywanie pierwszej tablicy
template<typename E>
void control_cout(E tab, int size)
{
	for (int i = 0; i < size; i++) cout << tab[0][i] << endl;
}

template<typename E>
E create_table( int n_tab, int size)
{
	E** tab = new E* [n_tab];
	for (int i = 0; i < n_tab; i++) tab[i] = new E[size];
	return tab;
}

template<typename E>
void fill_table(E* tab, int n_tab, int size)
{
	for (int i = 0; i < n_tab; i++)
	{
		for (int j = 0; j < size; j++)  tab[i][j] = rand();
	}
}

template<typename E>
bool check_if_sorted(E tab, int size, int n_tab)
{
	for (int i = 0; i < n_tab; i++)
	{
		int* sorted = new int[size];
		for (int j = 0; j < size; j++) sorted[j] = tab[i][j];
		std::sort(sorted,sorted + size);

		for (int j = 0; j < size; j++) if( tab[i][j]!=sorted[j]) return false;
	}
	return true;
}

template<typename E>
void pre_sorted( E* tab, int n_tab, int size, int percent)
{
	if (percent == 1000) for (int i = 0; i < n_tab; i++) std::sort(tab[i], tab[i] + size, greater<int>());
else for (int i = 0; i < n_tab; i++) std::partial_sort(tab[i], tab[i] + (percent * size / 1000), tab[i] + size);

}

template<typename E>
void del_table(E* tab,int n_tab)
{
	for (int i = 0; i < n_tab; i++) delete[] tab[i];

	delete[] tab;
}


int main()
{
	int n_tab = 100; // definicja wielkosci ile tablic
	int size_table[5] = { 10000, 50000, 100000, 500000, 1000000 }; //rozmiary tablic
	int percent_table[8] = { 0, 250, 500, 750, 950, 990, 997, 1000 }; // stopnie posortowania

	///  ----- Wybor pliku dla danego sortowania  ----
	
std::ofstream file("Merge.txt");
	//std::ofstream file("Quick.txt");
//std::ofstream file("Intro.txt");
	check_if_open(file);

	///  ----- Nazwa Sortowania ----

	  file << "Merge Sort\n";
	//	file << "Quick Sort";
	//	file << "Intro Sort";
	for (int percent : percent_table)
	{
		file << percent << "\n";
		for (int size : size_table)
		{
			DataType** tab = new DataType * [n_tab];
			for (int i = 0; i < n_tab; i++) tab[i] = new DataType[size];
			fill_table(tab, n_tab, size);
			pre_sorted(tab, n_tab, size, percent);
			
			
			auto start = std::chrono::steady_clock::now();
			///   ----- wybor sortowanaia ----
			for (int j = 0; j < n_tab; j++) merge_sort(tab[j],0, size-1);
			//  for (int j = 0; j < n_tab; j++) quick_sort(tab[j],0, size-1);
			//for (int j = 0; j < n_tab; j++) intro_sort(tab[j], size);
			
			
			auto end = std::chrono::steady_clock::now();

			if (check_if_sorted(tab, size, n_tab) == false) cout << "blad sortowania!";
			std::chrono::duration<double> elapsed_seconds = end - start;
			std::cout << percent << "% " << "size:" << size << " elapsed time: " << elapsed_seconds.count() << "s\n";
			file  << elapsed_seconds.count() << "\n";
			del_table(tab, n_tab);
		}
		file << "\n";
	}


	file << "\n";
	file.close();
	std::cin.get();
	return 0;

}