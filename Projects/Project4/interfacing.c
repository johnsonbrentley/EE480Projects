#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>

#define LED1 9	//pin21//blue
#define LED2 10	//pin19//brown
#define LED3 17	//pin11//green
#define LED4 22	//pin15//orange
#define LED5 27	//pin13//yellow


int main(){
	int input;
	wiringPiSetupGpio();
	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);
	pinMode(LED3, OUTPUT);
	pinMode(LED4, OUTPUT);
	pinMode(LED5, OUTPUT);
	digitalWrite(LED1, LOW);
	digitalWrite(LED2, LOW);
	digitalWrite(LED3, LOW);
	digitalWrite(LED4, LOW);
	digitalWrite(LED5, LOW);

	printf("Menu Driven Interface:\n");
	printf("1.Sequential Count in Binary\n");
	printf("2.Sweeping Light Movement From Right to Left\n");
	printf("3.Sweeping Light Movement From Left to Right\n");
	printf("4.Continuous Sweeping Light Movement\n");
	printf("5.User Input Decimal to Binary Translation\n");
	printf("Enter Your Choice\n");
	scanf("%d", &input);
	printf("The input is %d\n", input);

	for(int i = 1; i < 2; i++){

		if (input == 1){
			printf("Sequential Count in Binary Activated\n");
			for (int e = 0; e < 2; e++){
				for (int d = 0; d < 2; d++){
					for (int c = 0; c < 2; c++){
						for (int b = 0; b < 2; b++){
							for (int a = 0; a < 1; a++){
								digitalWrite(LED5, LOW);
								delay(500);
								digitalWrite(LED5, HIGH);
								delay(500);
							}
							digitalWrite(LED5, LOW);
							digitalWrite(LED4, HIGH);
						}
						digitalWrite(LED4, LOW);
						digitalWrite(LED3, HIGH);
					}
					digitalWrite(LED3, LOW);
					digitalWrite(LED2, HIGH);
				}
				digitalWrite(LED2, LOW);
				digitalWrite(LED1, HIGH);
			}
		digitalWrite(LED1, LOW);
		}
		else if (input == 2){
			printf("Sweeping Light Movement From Right to Left Activated\n");
			digitalWrite(LED5, HIGH);
			delay(1000);
			digitalWrite(LED5, LOW);
			delay(1000);
			digitalWrite(LED4, HIGH);
			delay(1000);
			digitalWrite(LED4, LOW);
			delay(1000);
			digitalWrite(LED3, HIGH);
			delay(1000);
			digitalWrite(LED3, LOW);
			delay(1000);
			digitalWrite(LED2, HIGH);
			delay(1000);
			digitalWrite(LED2, LOW);
			delay(1000);
			digitalWrite(LED1, HIGH);
			delay(1000);
			digitalWrite(LED1, LOW);
		}
		else if (input == 3){
			printf("Sweeping Light Movement From Left to Right Activated\n");
			digitalWrite(LED1, HIGH);
			delay(1000);
			digitalWrite(LED1, LOW);
			delay(1000);
			digitalWrite(LED2, HIGH);
			delay(1000);
			digitalWrite(LED2, LOW);
			delay(1000);
			digitalWrite(LED3, HIGH);
			delay(1000);
			digitalWrite(LED3, LOW);
			delay(1000);
			digitalWrite(LED4, HIGH);
			delay(1000);
			digitalWrite(LED4, LOW);
			delay(1000);
			digitalWrite(LED5, HIGH);
			delay(1000);
			digitalWrite(LED5, LOW);
		}
		else if (input == 4){
			printf("Continuous Sweeping Light Movement Activated\n");
			while (1==1){

			digitalWrite(LED5, HIGH);
			delay(1000);
			digitalWrite(LED5, LOW);
			delay(1000);
			digitalWrite(LED4, HIGH);
			delay(1000);
			digitalWrite(LED4, LOW);
			delay(1000);
			digitalWrite(LED3, HIGH);
			delay(1000);
			digitalWrite(LED3, LOW);
			delay(1000);
			digitalWrite(LED2, HIGH);
			delay(1000);
			digitalWrite(LED2, LOW);
			delay(1000);
			digitalWrite(LED1, HIGH);
			delay(1000);
			digitalWrite(LED1, LOW);
			delay(1000);
			digitalWrite(LED2, HIGH);
			delay(1000);
			digitalWrite(LED2, LOW);
			delay(1000);
			digitalWrite(LED3, HIGH);
			delay(1000);
			digitalWrite(LED3, LOW);
			delay(1000);
			digitalWrite(LED4, HIGH);
			delay(1000);
			digitalWrite(LED4, LOW);
			delay(1000);
			}
		}
		else if (input == 5){
			int input;
			int remain = 0;
			printf("User Input Decimal to Binary Translation Activated\n");
			printf("Enter a Decimal Number (0-31):\n");
			scanf("%d", &input);
			for (int k = 1; k < 2; k++){
				if (input >= 0 && input <= 31){
					printf("Beginning to Determine\n");
					if ((input/16) == 1){
						digitalWrite(LED1, HIGH);
						remain = (input - 16);
//						printf("Remaining vaue: %d\n", remain);
					}
					else {
						remain = input;
					}
					if ((remain/8) == 1){
						digitalWrite(LED2, HIGH);
						remain = (remain - 8);
//						printf("Remaining vaue: %d\n", remain);
					}
					if ((remain/4) == 1){
						digitalWrite(LED3, HIGH);
						remain = (remain - 4);
//						printf("Remaining vaue: %d\n", remain);
					}
					if ((remain/2) == 1){
						digitalWrite(LED4, HIGH);
						remain = (remain - 2);
//						printf("Remaining vaue: %d\n", remain);
					}
					if ((remain/1) == 1){
						digitalWrite(LED5, HIGH);
						remain = (remain - 1);
//						printf("Remaining vaue: %d\n", remain);
					}
					delay(5000);
				}
				else {
					for (int j = 0; j < 5; j++){
						digitalWrite(LED1, HIGH);
						digitalWrite(LED2, HIGH);
						digitalWrite(LED3, HIGH);
						digitalWrite(LED4, HIGH);
						digitalWrite(LED5, HIGH);
						delay(1000);
						digitalWrite(LED1, LOW);
						digitalWrite(LED2, LOW);
						digitalWrite(LED3, LOW);
						digitalWrite(LED4, LOW);
						digitalWrite(LED5, LOW);
						delay(1000);
					}
					printf("Out of Vaild Range. Enter Number Between 0-31\n");
					scanf("%d", &input);
					k = 0;
				}
			}
			digitalWrite(LED1, LOW);
			digitalWrite(LED2, LOW);
			digitalWrite(LED3, LOW);
			digitalWrite(LED4, LOW);
			digitalWrite(LED5, LOW);

		}
		else {
			printf("Not vaild. Enter a  different integer Activated\n");
			scanf("%d", &input);
			i = 0;
		}
	}
}
