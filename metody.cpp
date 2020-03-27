#include "metody.h"


//template<typename E>
//void merge(E* tab, int l, int m, int r)
//{
//    int* t = new int[r+r];
//        int a, b, c;
//        for (a = l; a <= r; a++) t[a] = tab[a];    //Skopiowanie danych do tablicy pomocniczejdynamicznej
//
//        a = l; b = m + 1; c = l;
//
//        while (a <= m && b <= r) {             //Przenoszenie danych z sortowaniem ze zbiorów pomocniczych do tablicy g³ównej
//            if (t[a] < t[b])
//                tab[c++] = t[a++];
//            else
//                tab[c++] = t[b++];
//        }
//
//        while (a <= m) tab[c++] = t[a++]; //Wpisywanie pozostalych danych
//        delete[] t;
//    }
/// Merge SORT ///
template<typename E>
void merge(E* tab, int l, int m, int r)
{
    int* temp = new int[(r - l) + 1]; // utworzenie tablicy pomocniczej
    int i = l, j = m + 1, k = 0; // zmienne pomocnicze

    while (i <= m && j <= r)
    {
        if (tab[j] < tab[i])
        {
            temp[k] = tab[j];
            j++;
        }
        else
        {
            temp[k] = tab[i];
            i++;
        }
        k++;
    }

    if (i <= m)
    {
        while (i <= m)
        {
            temp[k] = tab[i];
            i++;
            k++;
        }
    }
    else
    {
        while (j <= r)
        {
            temp[k] = tab[j];
            j++;
            k++;
        }
    }

    for (i = 0; i <= r - l; i++) tab[l + i] = temp[i];
    // for (int i = 0; i <= r - l; i++) //delete[] temp;
    delete[] temp;
}
template<typename E>
void merge_sort(E* tab, int l, int r)
{
    if (l != r)
    {
        int m = (l + r) / 2;
        merge_sort(tab, l, m);
        merge_sort(tab, m+1, r);
        merge(tab, l, m , r);
    }
}

/// QUICK SORT ///
template<typename E>
void quick_sort(E* tab, int l, int r)
{
    int i = l, j = r;
    int tmp;
    int pivot = tab[(l + r) / 2];

    while (i <= j) 
    {
       while (tab[i] < pivot)  i++;
        while (tab[j] > pivot) j--;
                if (i <= j) 
        {

            tmp = tab[i];
           tab[i] = tab[j];
            tab[j] = tmp;
            i++;
            j--;

        }

    };

    if (l < j)
        quick_sort(tab, l, j);
    if (i < r)
        quick_sort(tab, i, r);
}


/// INTRO SORT ///
// w zasadzie to dzielenie tablicy na kawalki, male sa sortowane przez kopcowanie, duze quicksortem
template<typename E>
int partition(E* tab, int l, int r) {
    int i = l, j = r;
    int tmp;
    int pivot = tab[(l + r) / 2];

    while (i <= j)
    {
        while (tab[i] < pivot)  i++;
        while (tab[j] > pivot) j--;
        if (i <= j)
        {

            tmp = tab[i];
            tab[i] = tab[j];
            tab[j] = tmp;
            i++;
            j--;

        }

    };

	return i;
}
template<typename E>
void insertion_sort(E* tab, int size)
{
	for (int i = 1; i < size; ++i)
	{
		int j = i;

		while ((j > 0))
		{
			if (tab[j - 1] > tab[j])
			{
				tab[j - 1] ^= tab[j];
				tab[j] ^= tab[j - 1];
				tab[j - 1] ^= tab[j];

				--j;
			}
			else
			{
				break;
			}
		}
	}
}
template<typename E>
 void intro_sort(E* tab, int size)
 {
	int p = partition(tab, 0, size - 1);

	if (p < 9) //jezeli tablica mniejsza od 9 lub 16 to kopcowanie
	{
		insertion_sort(tab, size);
	}

	else
	{
		quick_sort(tab, 0, size - 1);
	}
}

 // dodac dla doubla !!!
template void merge<int>(int*, int, int, int);
template void merge_sort<int>(int*, int, int);
template void quick_sort<int>(int*, int, int);
template void intro_sort<int>(int*, int);