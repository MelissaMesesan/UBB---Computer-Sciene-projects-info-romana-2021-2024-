#include "functii.h"


int cmp_int(int* elem, int* elem1)
{
	return !(*elem - *elem1);
}

void del_int(int* elem) {
}

void del_int2(int* elem) {
	free(elem);
}

int* copy_int(int* elem) {
	int* copie = (int*)malloc(sizeof(int));
	*copie = *elem;
	return copie;
}