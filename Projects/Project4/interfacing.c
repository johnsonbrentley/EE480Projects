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
	printf("2.Sweeping Light Movement From Left to Right\n");
	printf("3.Sweeping Light Movement From Right to Left\n");
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
								delay(1000);
								digitalWrite(LED5, HIGH);
								delay(1000);
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
			printf("Sweeping Light Movement From Left to Right Activated\n");
		}
		else if (input == 3){
			printf("Sweeping Light Movement From Right to Left Activated\n");
		}
		else if (input == 4){
			printf("Continuous Sweeping Light Movement Activated\n");
		}
		else if (input == 5){
			printf("User Input Decimal to Binary Translation Activated\n");
		}
		else {
			printf("Not vaild. Enter a  different integer Activated\n");
			scanf("%d", &input);
			i = 0;
		}
	}
}
