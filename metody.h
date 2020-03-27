#pragma once
#ifndef metody_h
#define metody_h
#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
using namespace std;


template<typename E>
void merge(E *tab, int l, int m, int r);

template<typename E>
void merge_sort(E *tab, int l, int r);

template<typename E>
void quick_sort(E* tab, int l, int r);

template<typename E>
void insertion_sort(E* tab, int size);

template<typename E>
void intro_sort(E* data, int size);

template<typename E>
int partition(E* tab, int l, int r);

#endif 
