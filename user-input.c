#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum
{
    BRAK = 0,
    ISTNIEJE_NIE_TUTAJ = 1,
    TRAFIONE = 2
} Ocena;

void losuj(int *tab);                                                            /* silnik.c */
void ocenCiag(int *ciag_wylosowany, int *ciag_wejsciowy, Ocena *ciag_wyjsciowy); /* oceny.c */

#define ROZMIAR 4
#define MAX_PROB 10
#define ZAKRES_KOLOR 6 /* kolory 0-5 */

static void wczytaj_probe(int *proba)
{
    printf("Podaj 4 cyfry (0-5):\n");
    for (int i = 0; i < ROZMIAR; i++)
    {
        while (1)
        {
            printf("Cyfra %d: ", i + 1);
            if (scanf("%d", &proba[i]) != 1)
            {
                while (getchar() != '\n')
                {
                }
                printf("Bledne dane. Podaj cyfre 0-5.\n");
                continue;
            }
            if (proba[i] >= 0 && proba[i] < ZAKRES_KOLOR)
                break;
            printf("Liczba spoza zakresu! Podaj cyfre 0-5.\n");
        }
    }
}

static void pokaz_oceny(const Ocena *o)
{
    for (int i = 0; i < ROZMIAR; i++)
    {
        if (o[i] == TRAFIONE)
            printf("T ");
        else if (o[i] == ISTNIEJE_NIE_TUTAJ)
            printf("I ");
        else
            printf(". ");
    }
    printf("\n");
}

int main(void)
{
    srand((unsigned)time(NULL));

    int kod[ROZMIAR];
    int proba[ROZMIAR];
    Ocena oceny[ROZMIAR];

    losuj(kod); /* silnik.c */

    for (int proby = 1; proby <= MAX_PROB; proby++)
    {
        wczytaj_probe(proba);
        ocenCiag(kod, proba, oceny); /* oceny.c */

        printf("Ocena: ");
        pokaz_oceny(oceny);

        int trafione = 0;
        for (int i = 0; i < ROZMIAR; i++)
            if (oceny[i] == TRAFIONE)
                trafione++;

        if (trafione == ROZMIAR)
        {
            printf("Wygrales w %d probach!\n", proby);
            return 0;
        }
        printf("Proby: %d/%d\n", proby, MAX_PROB);
    }

    printf("Przegrales. Kod: ");
    for (int i = 0; i < ROZMIAR; i++)
        printf("%d ", kod[i]);
    printf("\n");
    return 0;
}