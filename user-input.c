#include <stdio.h>

int main() {
    int tab[4]; // Tablica na 4 cyfry podane przez gracza
    printf("Podaj 4 cyfry, aby zgadnac haslo (0-5):\n");

    for (int i = 0; i < 4; i++) {
        scanf("%d", &tab[i]);

        while (tab[i] < 0 || tab[i] > 5) {
            printf("Liczba spoza zakresu! Podaj cyfre (0-5) jeszcze raz:\n");
            scanf("%d", &tab[i]);
        }
    }

    return tab[4];
}

