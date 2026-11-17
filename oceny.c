#ifndef _MMIND_OCENY
#define _MMIND_OCENY
#include <stdlib.h>

typedef enum 
{
  BRAK = 0,
  ISTNIEJE_NIE_TUTAJ = 1,
  TRAFIONE = 2,
} Ocena;

// "Kolory": cyfry 0-5 włącznie
#define OC_MIN 0;
#define OC_MAX 5;
#define OC_ROZMIAR_CIAGU 4;

void ilosc_w_ciagu(int* ciag, int* ilosc_kolorow)
{
	for (int j = OC_MIN; j <= OC_MAX; j++) 
	{
		for (int i = 0; i < OC_ROZMIAR_CIAGU; i++)
	       	{
			if (ciag[i] == j) ilosc_kolorow[j] += 1;
		}
	}
}


// Ocena oceny[4];
// ocenCiag(..., ..., oceny);
// printf(oceny)


// Ocenia ciąg wejściowy, i
void ocenCiag(int* ciag_wylosowany, int* ciag_wejsciowy, Ocena* ciag_wyjsciowy) 
{
	int ilosc_kolor_wylosow[6] = {0};
	int ilosc_kolor_wejsciowy[6] = {0};
	ilosc_w_ciagu(ciag_wylosowany, ilosc_kolor_wylosow);
	ilosc_w_ciagu(ciag_wejsciowy, ilosc_kolor_wejsciowy);

	for (int i = 0; i < OC_ROZMIAR_CIAGU; i++)
	{
		int kolor_gracz = ciag_wejsciowy[i];
		if (kolor_gracz == ciag_wylosowany[i]) 
		{
			ciag_wyjsciowy[i] = TRAFIONE;
			ilosc_kolor_wejsciowy[kolor_gracz] -= 1;
			ilosc_kolor_wylosow[kolor_gracz] -= 1;
		}
		else 
		{
			if (ilosc_kolor_wejsciowy[kolor_gracz] <= 0 || ilosc_kolor_wylosow[kolor_gracz] <= 0) 
			{
			    ciag_wyjsciowy[i] = BRAK;
		            continue;	    
			}
			for (int j = 0; j < OC_ROZMIAR_CIAGU; j++) 
			{
				if (kolor_gracz == ciag_wylosowany[j]) 
				{
					ciag_wyjsciowy[i] = ISTNIEJE_NIE_TUTAJ;
					ilosc_kolor_wejsciowy[kolor_gracz] -= 1;
					ilosc_kolor_wylosow[kolor_gracz] -= 1;
					continue;
				}
			}

		}
	}
}





















#endif
