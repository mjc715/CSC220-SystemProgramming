#include<stdio.h>
#include<stdlib.h>

#define FTPERATM 33
#define MAXPRESSURE 1.4
#define CONTPRESSURE 1.6

int main(void) {
	double Depth;
	double Oxygen;

	printf("Enter dive depth in ft: ");
	scanf("%lf", &Depth);
	printf("Enter percentage O2: ");
	scanf("%lf", &Oxygen);

	double AmbientPressure = Depth / FTPERATM + 1;
	double PartialPressure = Oxygen / 100 * AmbientPressure;

	printf("Ambient pressure: %.2lf \n", AmbientPressure);
	printf("O2 pressure: %.2lf \n", PartialPressure);
	
	if (PartialPressure < 0.1) {
		printf("O2 group: A\n");
	}else if (PartialPressure < 0.2) {
		printf("O2 group: B\n");
	}else if (PartialPressure < 0.3) {
		printf("O2 group: C\n");
	}else if (PartialPressure < 0.4) {
		printf("O2 group: D\n");
	}else if (PartialPressure < 0.5) {
		printf("O2 group: E\n");
	}else if (PartialPressure < 0.6) {
		printf("O2 group: F\n");
	}else if (PartialPressure < 0.7) {
		printf("O2 group: G\n");
	}else if (PartialPressure < 0.8) {
		printf("O2 group: H\n");
	}else if (PartialPressure < 0.9) {
		printf("O2 group: I\n");
	}else if (PartialPressure < 1.0) {
		printf("O2 group: J\n");
	}else if (PartialPressure < 1.1) {
		printf("O2 group: K\n");
	}else if (PartialPressure < 1.2) {
		printf("O2 group: L\n");
	}else if (PartialPressure < 1.3) {
		printf("O2 group: M\n");
	}else if (PartialPressure < 1.4) {
		printf("O2 group: N\n");
	}else {
		printf("O2 group: O\n");
	}


	if (PartialPressure > MAXPRESSURE) {
		printf("Exceeds maximal O2 pressure: true\n");

	} else {
		printf("Exceeds maximal O2 pressure: false\n");
	}
	if (PartialPressure > CONTPRESSURE) {
		printf("Exceeds contingency O2 pressure: true\n");
	} else {
		printf("Exceeds contingency O2 pressure: false\n");
	}
}

