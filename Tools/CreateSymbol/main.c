#include <stdio.h>
#define ARRAY_SIZE 3
#define ARRAY_ROW 7
#define ARRAY_FIELD 5

const int symbols[ARRAY_SIZE][ARRAY_ROW][ARRAY_FIELD] = {
	{ //A
		{0, 1, 1, 1, 0},
		{1, 1, 0, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
	},
	{ //B
		{1, 1, 1, 0, 0},
		{1, 0, 0, 1, 0},
		{1, 1, 1, 0, 0},
		{1, 1, 1, 1, 0},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 0},
	},
	{ //C
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
	}
};

int main()
{
	for(int i = 0; i < ARRAY_ROW; i++) {
		for(int j = 0; j < ARRAY_FIELD; j++) {
			printf("%d", symbols[2][i][j]);
		}
		printf("\n");
	}
	/*FILE *f = fopen("data.bin", "wb");
	for(int i = 0; i < ARRAY_SIZE; i++) {
		for(int j = 0; j < ARRAY_ROW; j++) {
			for(int k = 0; k < ARRAY_FIELD; k++) {
				fwrite(&symbols[i][j][k], 1, 1, f);
			}
		}
	}
	fclose(f);*/
	return 0;
}