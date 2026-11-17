#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 0 - czerwony
// 1 - zielony
// 2 - niebieski
// 3 - zolty
// 4 - fioletowy

int losuj(){
	srand(time(NULL));

	int min = 0;
	int max = 4;

	int losy[5] = {};

	for(int i = 0; i < 4; i++){
		losy[i] = (rand() % (max - min + 1)) + min;
		printf("%d ", losy[i]);
	}
}
