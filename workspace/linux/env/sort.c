#include <stdio.h>
#include <stdlib.h>

void sort() {
	int array[] = {3,4,2,1,5};
	int count = 5;
	int temp, i;
	for (i = 0; i < count -1 ; i ++) {
		for (int j = i + 1; j < count; j ++) {
			if (array[i] > array[j] ) {
				temp = array[i] ;
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	for (i = 0; i < count - 1; i++) {
		printf("%d, ", array[i]);
	}
	printf("%d\n",array[count -1]);
}

// use pointer
void sort2() {
	//int array[] = {3,4,2,1,5};
	//int *array = {3,4,2,1,5};
	int *array = malloc(sizeof(int)*5);
	*array = 3;
	*(array + 1) = 4;
	*(array + 2) = 2;
	*(array + 3) = 1;
	*(array + 4) = 5;
	int count = 5;
	int *p = array;
	int temp, i;
	for (i = 0; i < count -1 ; i ++) {
		for (int j = i + 1; j < count; j ++) {
			if (*(p + i) > *(p + j) ) {
				temp = *(p + i) ;
				*(p + i) = *(p + j);
				*(p + j) = temp;
			}
		}
	}
	for (i = 0; i < count - 1; i++) {
		printf("%d, ", *(p + i));
	}
	printf("%d\n", *(p + count -1));
	free(p);
}
void main() {
	sort2();
	exit(0);
}
