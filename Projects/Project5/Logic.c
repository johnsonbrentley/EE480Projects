#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>


			//Pin 2 PWR; Pin 20 GND

#define MAJX	14	//PIN 8  MAJORITY OUTPUT X
#define MAJY	15	//PIN 10 MAJORITY OUTPUT Y
#define MAJZ	18	//PIN 12 MAJORITY OUTPUT Z

#define MINX	23	//PIN 16 MINORITY OUTPUT X
#define MINY	24	//PIN 18 MINORITY OUTPUT Y
#define MINZ	25	//PIN 22 MINORITY OUTPUT Z

#define COMX1	17	//PIN 11 COMPARITOR OUTPUT X1
#define COMX2	27	//PIN 13 COMPARITOR OUTPUT X2
#define COMY1	22	//PIN 15 COMPARITOR OUTPUT Y1
#define COMY2	10	//PIN 19 COMPARITOR OUTPUT Y2
#define COMZ1	9	//PIN 21 COMPARITOR OUTPUT Z1
#define COMZ2	11	//PIN 23 COMPARITOR OUTPUT Z2
#define NOTPWR	19	//PIN 35 Supply Power to NOT gate



int main(){
	int input;
	wiringPiSetupGpio();
	pinMode(MAJX ,OUTPUT);	//declaring all the different GPIOs as Input or Output
	pinMode(MAJY ,OUTPUT);
	pinMode(MAJZ ,OUTPUT);
	pinMode(MINX ,OUTPUT);
	pinMode(MINY ,OUTPUT);
	pinMode(MINZ ,OUTPUT);
	pinMode(COMX1 ,OUTPUT);
	pinMode(COMX2 ,OUTPUT);
	pinMode(COMY1 ,OUTPUT);
	pinMode(COMY2 ,OUTPUT);
	pinMode(COMZ1 ,OUTPUT);
	pinMode(COMZ2 ,OUTPUT);

	pinMode(NOTPWR ,OUTPUT);//

	digitalWrite(MAJX ,LOW);// setting all values as low
	digitalWrite(MAJY ,LOW);
	digitalWrite(MAJZ ,LOW);
	digitalWrite(MINX ,LOW);
	digitalWrite(MINY ,LOW);
	digitalWrite(MINZ ,LOW);
	digitalWrite(COMX1 ,LOW);
	digitalWrite(COMX2 ,LOW);
	digitalWrite(COMY1 ,LOW);
	digitalWrite(COMY2 ,LOW);
	digitalWrite(COMZ1 ,LOW);
	digitalWrite(COMZ2 ,LOW);//

	printf("Menu Driven Interface:\n1.Majority Function\n2.Minority Function\n3.Comparitor Function\nEnter Your Choice (1-3):\n");//print interfeace menu
	scanf("%d", &input);	//read user input
	printf("Input is %d\n", input);
	int input1;	//inputs given by user
	int input2;
	int input3;	//
	int i = 0;	//loop counter for checking interface output
	int a = 0;	//loop counter for checking majority output1
	int b = 0;	//loop counter for checking majority output2
	int c = 0;	//loop counter for checking majority output3
	int d = 0;	//loop counter for checking minority output1
	int e = 0;	//loop counter for checking minority output2
	int f = 0;	//loop counter for cehcking minority output3
	int g = 0;	//loop counter for checking compar1 output 1
	int h = 0;	//loop counter for checking compar1 output 2
	int j = 0;	//loop counter for checking compar1 output 3
	int k = 0;	//loop counter for checking compar2 output 1
	int l = 0;	//loop counter for checking compar2 output 2
	int m = 0;	//loop counter for checking compar2 output 3

	for(int i = 1; i < 2; i++){	//loop for checking correct input values

		if (input == 1){	//first branch- Majority circuit
			printf("Enter The Input/Output Values(1/0) For Input1:\n");
			scanf("%d", &input1); 	//reading user value 1
			for(a = 1; a < 2; a++){ //loop for checking correct values

				if (input1 > 1 || input1 < 0){ 	//if incorrect try again
					printf("Enter a Value of 1 or 0:\n");
					scanf("%d", &input1);	//read new value
					a = 0;//reset check loop
				}
				else if (input1 ==  1){//if one then send output
					digitalWrite(MAJX, HIGH);
				}
				else if(input1 == 0) {	//if zero send no output
					digitalWrite(MAJX, LOW);
				}
			}
			printf("Enter The Input/Output Values(1/0) For Input2:\n");
			scanf("%d", &input2);	//reads second value
			for(b = 1; b < 2; b++){	//checks for correct integer

				if (input2 > 1 || input2 < 0){	//if incorrect try again
					printf("Enter a Value of 1 or 0:\n");
					scanf("%d", &input2);	//read new value
					b = 0; //reset check loop
				}
				else if (input2 == 1){	//if one send output
					digitalWrite(MAJY, HIGH);
				}
				else if(input2 == 0) {	//if zero send no output
					digitalWrite(MAJY, LOW);
				}
			}

			printf("Enter The Input/Output Values(1/0) For Input3:\n");
			scanf("%d", &input3);	//reads value 3
			for(c = 1; c < 2; c++){ //loop checking values

				if (input3 > 3 || input3 < 0){	//if incorrect try again
					printf("Enter a Value of 1 or 0:\n");
					scanf("%d", &input1); //reads new value
					c = 0;// resets check loop
				}
				else if (input3 == 1){	//if one then send output
					digitalWrite(MAJZ, HIGH);
				}
				else if(input3 == 0) {	//if zero then send no output
					digitalWrite(MAJZ, LOW);
				}
			}
		}
//////////////////////////////////////////////////////////////////////////////////////////////////////
			else if (input == 2){	//second branch- minority circuit
				printf("In path 2\n");
				printf("Enter The Input/Output Values(1/0) For Input1:\n");
				scanf("%d", &input1);	//read first value
				for(d = 1; d < 2; d++){	//input checking loop

					if (input1 > 1 || input1 < 0){	//if incorrect try again
						printf("Enter a Value of 1 or 0:\n");
						scanf("%d", &input1);	//read input
						d = 0;	//resets check loop
					}
					else if (input1 == 1){	//if one send output
						digitalWrite(MINX, HIGH);
					}
					else if(input1 == 0) { //if zero send no output
						digitalWrite(MINX, LOW);
					}
				}
				printf("Enter The Input/Output Values(1/0) For Input2:\n");
				scanf("%d", &input2);	//reads input
				for(e = 1; e < 2; e++){	//input checking loop

					if (input2 > 1 || input2 < 0){	//if incorrect try again
						printf("Enter a Value of 1 or 0:\n");
						scanf("%d", &input2);	//reads value
						e = 0;//resets check loop
					}
					else if (input2 == 1){	//if one send output
						digitalWrite(MINY, HIGH);
					}
					else if(input2 == 0) {	//if zero send no output
						digitalWrite(MINY, LOW);
					}
				}

				printf("Enter The Input/Output Values(1/0) For Input3:\n");
				scanf("%d", &input3); //reads input
				for(f = 1; f < 2; f++){	//input checking loop

					if (input3 > 3 || input3 < 0){ //if incorrect try again
						printf("Enter a Value of 1 or 0:\n");
						scanf("%d", &input1); //reads value
						f = 0; //resets check loop
					}
					else if (input3 == 1){	//if one send output
						digitalWrite(MINZ, HIGH);
					}
					else if(input3 == 0) {	//if zero send no output
						digitalWrite(MINZ, LOW);
					}
				}
				digitalWrite(NOTPWR, HIGH);	//power NOT gate
			}
//////////////////////////////////////////////////////////////////////////////////////////////////////
			else if (input == 3){ //third branch comparitor circuit
				printf("In path 3\n");
				printf("Enter The Input/Output Values(1/0) For Input1:\n");
				scanf("%d", &input1);	//reads input
				for(g = 1; g < 2; g++){ //checking loop

					if (input1 > 1 || input1 < 0){ //if incorrect input try again
						printf("Enter a Value of 1 or 0:\n");
						scanf("%d", &input1); //read value
						g = 0;//reset check loop
					}
					else if (input1 == 1){	//if one  send output
						digitalWrite(COMX1, HIGH);
					}
					else if(input1 == 0) {	//send no output
						digitalWrite(COMX1, LOW);
					}
				}
				printf("Enter The Input/Output Values(1/0) For Input2:\n");
				scanf("%d", &input2); //read input
				for(h = 1; h < 2; h++){ //checking loop

					if (input2 > 1 || input2 < 0){ //if incorrect try agin
						printf("Enter a Value of 1 or 0:\n");
						scanf("%d", &input2); //read value
						h = 0; //sets check loop
					}
					else if (input2 == 1){ //send output
						digitalWrite(COMY1, HIGH);
					}
					else if(input2 == 0) {// send no output
						digitalWrite(COMY1, LOW);
					}
				}

				printf("Enter The Input/Output Values(1/0) For Input3:\n");
				scanf("%d", &input3);	//reads value
				for(j = 1; j < 2; j++){ //checking loop

					if (input3 > 3 && input3 < 0){ //if incorret try again
						printf("Enter a Value of 1 or 0:\n");
						scanf("%d", &input1); //read value
						j = 0; //resets check loop
					}
					else if (input3 == 1){ //send output
						digitalWrite(COMZ1, HIGH);
					}
					else if(input3 == 0) {	//send no output
						digitalWrite(COMZ1, LOW);
					}
				}
				printf("Enter The Input/Output Values(1/0) For Input1:\n");
				scanf("%d", &input1); //read value
				for(k = 1; k < 2; k++){ //check loop

					if (input1 > 1 || input1 < 0){//if incorrect try again
						printf("Enter a Value of 1 or 0:\n"); 
						scanf("%d", &input1);//read value
						k = 0;//reset loop
					}
					else if (input1 == 1){ //send output
						digitalWrite(COMX2, HIGH);
					}
					else if(input1 == 0) {	//send no output
						digitalWrite(COMX2, LOW);
					}
				}
				printf("Enter The Input/Output Values(1/0) For Input2:\n");
				scanf("%d", &input2); //read value
				for(l = 1; l < 2; l++){ //checking loop

					if (input2 > 1 && input2 < 0){ //if incorrect try again
						printf("Enter a Value of 1 or 0:\n");
						scanf("%d", &input2); //read value
						l = 0; //resets loop
					}
					else if (input2 == 1){ //send output
						digitalWrite(COMY2, HIGH);
					}
					else if(input2 == 0) { //send no output
						digitalWrite(COMY2, LOW);
					}
				}

				printf("Enter The Input/Output Values(1/0) For Input3:\n");
				scanf("%d", &input3); //read value
				for(m = 1; m < 2; m++){ //checking loop

					if (input3 > 3 || input3 < 0){ //if incorrect try again
						printf("Enter a Value of 1 or 0:\n");
						scanf("%d", &input1); //read value
						m = 0; //resets check loop
					}
					else if (input3 == 1){ //send output
						digitalWrite(COMZ2, HIGH);
					}
					else if(input3 == 0) { //send no output
						digitalWrite(COMZ2, LOW);
					}
				}
			}
//////////////////////////////////////////////////////////////////////////////////////////////////////
			else{ //fourth branch -checking branch
			printf("Invaild Integer. Enter a Different Integer:\n");
			scanf("%d", &input); //read value
			i = 0; //resets loop
			}

		}
	delay(5000);	//wait the turn everything off
	digitalWrite(MAJX ,LOW);
	digitalWrite(MAJY ,LOW);
	digitalWrite(MAJZ ,LOW);
	digitalWrite(MINX ,LOW);
	digitalWrite(MINY ,LOW);
	digitalWrite(MINZ ,LOW);
	digitalWrite(COMX1 ,LOW);
	digitalWrite(COMX2 ,LOW);
	digitalWrite(COMY1 ,LOW);
	digitalWrite(COMY2 ,LOW);
	digitalWrite(COMZ1 ,LOW);
	digitalWrite(COMZ2 ,LOW);
	digitalWrite(NOTPWR ,LOW);
}
