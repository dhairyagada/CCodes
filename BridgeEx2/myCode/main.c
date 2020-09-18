#include <stdio.h>

typedef struct{
	float a;
	float b;
	float c;
	int N;
	double* length; //Dynamic memory
} bridge_t;

void bridge_getDimensions(bridge_t * const me);
void bridge_calcLength(bridge_t * const me);
void bridge_print(bridge_t const * const me);

void main()
{
	bridge_t bridge = {0,0,0,0,0};

	bridge_getDimensions(&bridge);
	bridge_calcLength(&bridge);
	bridge_print(&bridge);

}

struct bowProperties{
	float a;	//Width
	float b;	//Height

};

struct bridgeInfo {
	struct bowProperties bowInfo;
	int N;
	float c;	// Street Height
};

struct elementInfo{
	int elementNo ;
	float elementXPos;
	float elementYPos;
	float length;
};

struct bridgeInfo getBridgeInfo(){
	struct bowProperties bow = {
			a:0,
			b:0
	};
	struct bridgeInfo bridge ={
			bowInfo :bow,
			c :0,
			N:0
	};

	printf("Please Enter Value for a");
	scanf("%f", &(bridge.bowInfo.a));

	printf("Please Enter Value for b");
	scanf("%f", &(bridge.bowInfo.b));

	printf("Please Enter Value for c");
	scanf("%f", &(bridge.c));

	printf("Please Enter Value for N");
	scanf("%d", &(bridge.N));

	return bridge;

}


float getBowYPosition(struct bowProperties bow, float  xPos){
	float yPos = 0.0;

	float p1 = -(4*bow.b)/(bow.a*bow.a);

	float p2 = (4*bow.b)/bow.a;

	float p3 = 0.0;

	//Formula

	yPos = (p1* xPos*xPos) + (p2*xPos) + p3;

	return yPos;
}

void calcElementLength(struct bridgeInfo bridge,struct elementInfo *element){

	//Bow Position
	element->elementYPos = getBowYPosition(bridge.bowInfo,element->elementXPos);
	//Bow Length
	element->length = -element->elementYPos + bridge.bowInfo.b + bridge.c;

}


int main()
{

	setvbuf(stdout, NULL, _IONBF, 0);

	printf("Bridge\n");
	struct bridgeInfo bridge;

	//Get Bridge Input
	bridge = getBridgeInfo();

	for(int i = 0;i<bridge.N;i++){

		// Process Every Element
		struct elementInfo element = {
					elementNo : i,
					elementXPos: (bridge.bowInfo.a/(bridge.N-1)) *i ,
					elementYPos:0,
					length:0
		};
		calcElementLength(bridge,&element);

		printf("Element No %d at position x %f has a lenght of %f\n",element.elementNo,element.elementXPos,element.length);
	}

	return 0;

}
