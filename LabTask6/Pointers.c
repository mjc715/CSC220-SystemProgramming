
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 5

typedef int* IntPointer;
typedef int FiveInts[ARRAY_SIZE];
typedef IntPointer PointFiveInts[ARRAY_SIZE];
//-------------------------------------
void Initializer(FiveInts NumArray, PointFiveInts PointerArray) {
	
	srand(getpid());
	for (int i = 0; i < 5; i++) {
		NumArray[i] = rand();
		PointerArray[i] = &NumArray[i];
	}
	
}
//--------------------------------------
void PrintInts (FiveInts Array) {
	for (int i = 0; i < ARRAY_SIZE; ++i) {
		printf("%i : %i\n", i, Array[i]);
	}
}
//--------------------------------------
void PrintPointers (PointFiveInts Array) {
	for (int i = 0; i < ARRAY_SIZE; ++i) {
		printf("%i : %i\n", i, *Array[i]);
	}
}
//--------------------------------------
void SortArray (FiveInts Array) {
	int Swapped = 1;

	while (Swapped) {
		Swapped = 0;
		for (int i = 0; i < ARRAY_SIZE - 1; i++) {
			if (Array[i] > Array[i+1]) {
					Swapped = 1;
					int Temp = Array[i];
					Array[i] = Array[i + 1];
					Array[i+1] = Temp;
			}
		}
	}

}
//--------------------------------------
void SortPointers (PointFiveInts Pointers) {
	int Swapped = 1;

	while (Swapped) {
		Swapped = 0;
		for (int i = 0; i < ARRAY_SIZE - 1; i++) {
			if (*(Pointers[i]) > *(Pointers[i+1])){
				Swapped = 1;
				IntPointer Temp = Pointers[i];
				Pointers[i] = Pointers[i+1];
				Pointers[i+1] = Temp;
			}
		}
	}

}
//--------------------------------------
int main(void) {
	FiveInts NumArray;
	PointFiveInts PointerArray;

	Initializer(NumArray, PointerArray);
	printf("Initial array of random ints:\n");
	PrintInts(NumArray);
	printf("Sorted array of pointers:\n");
	SortPointers(PointerArray);
	PrintPointers(PointerArray);
	printf("Sorted array of ints:\n");
	SortArray(NumArray);
	PrintInts(NumArray);
	printf("Array of pointers:\n");
	PrintPointers(PointerArray);
}
//--------------------------------------
