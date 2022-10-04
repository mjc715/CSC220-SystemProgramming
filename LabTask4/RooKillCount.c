#include <stdlib.h>
#include <stdio.h>
#define ROADWIDTH 0.01
#define RKCONSTANT 1.47

int main(void) {

	float SquareSide;
	float RoadLength;
	float RooCount;

	printf("Enter length of side of square in km: ");
	scanf("%f",&SquareSide);
	printf("Enter length of road in km: ");
	scanf("%f", &RoadLength);
	printf("Enter number of kangaroos: ");
	scanf("%f", &RooCount);

	float SquareArea = SquareSide * SquareSide;
	float RoadArea = RoadLength * ROADWIDTH;
	float RooDensity = RooCount / SquareArea;
	float Kills = RooDensity * RoadArea * RKCONSTANT;

	printf("Expected number of kills: %.2f \n",Kills);
}



