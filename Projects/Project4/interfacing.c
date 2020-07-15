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
	pinMode(LED1, OUTPUT);		//delcraing LED1 as an output
	pinMode(LED2, OUTPUT);		//declaring LED2 as an output
	pinMode(LED3, OUTPUT);		//declaring LED3 as an output
	pinMode(LED4, OUTPUT);		//delcaring LED4 as an output
	pinMode(LED5, OUTPUT);		//declaring LED5 as an output
	digitalWrite(LED1, LOW);	//Turning LED off
	digitalWrite(LED2, LOW);	//turning LED off
	digitalWrite(LED3, LOW);	//turning LED off
	digitalWrite(LED4, LOW);	//turning LED off
	digitalWrite(LED5, LOW);	//turning LED off

	printf("Menu Driven Interface:\n");			//Print the interface menu for user selecting
	printf("1.Sequential Count in Binary\n");
	printf("2.Sweeping Light Movement From Right to Left\n");
	printf("3.Sweeping Light Movement From Left to Right\n");
	printf("4.Continuous Sweeping Light Movement\n");
	printf("5.User Input Decimal to Binary Translation\n");
	printf("Enter Your Choice\n");
	scanf("%d", &input);			//scan the keyboard input
	printf("The input is %d\n", input);	//displaying the user input

	for(int i = 1; i < 2; i++){		//loop for repeating a wrong input value

		if (input == 1){		//first branch if statement
			printf("Sequential Count in Binary Activated\n");
			for (int e = 0; e < 2; e++){	//loop for the 5th bit counter
				for (int d = 0; d < 2; d++){	//loop for the 4th bit counter
					for (int c = 0; c < 2; c++){	//loop for the 3rd bit counter
						for (int b = 0; b < 2; b++){	//loop for the 2nd bit counter
							for (int a = 0; a < 1; a++){	//loop for the 1st bit counter
								digitalWrite(LED5, LOW);	//Turn the LED off, displaying a 0
								delay(500);
								digitalWrite(LED5, HIGH);	//after second LED on, displaying 1
								delay(500);
							}
							digitalWrite(LED5, LOW);	//Turn LED in bit 2 spot on
							digitalWrite(LED4, HIGH);	//Turn LED in bit 1 spot off
						}
						digitalWrite(LED4, LOW);	//turn led in bit 2 spot off
						digitalWrite(LED3, HIGH);	//turn led in bit 3 spot on
					}
					digitalWrite(LED3, LOW);	//turn led in bit 3 spot off
					digitalWrite(LED2, HIGH);	//turn led in bit 4 spot on
				}
				digitalWrite(LED2, LOW);	//turn led in bit 4 spot off
				digitalWrite(LED1, HIGH);	//turn led in bit 5 spot on
			}
		digitalWrite(LED1, LOW);	//turn led in bit 5 spot off
		}
		else if (input == 2){		//second branch if statement
			printf("Sweeping Light Movement From Right to Left Activated\n");
			digitalWrite(LED5, HIGH);	//
			delay(1000);			//
			digitalWrite(LED5, LOW);	//
			delay(1000);			//
			digitalWrite(LED4, HIGH);	//
			delay(1000);			//
			digitalWrite(LED4, LOW);	//
			delay(1000);			//
			digitalWrite(LED3, HIGH);	//For all turn on the
			delay(1000);			//led on the right and
			digitalWrite(LED3, LOW);	//turn off led to the left
			delay(1000);			//with 1 second delay
			digitalWrite(LED2, HIGH);	//0.5 hertz = 2second period
			delay(1000);			//
			digitalWrite(LED2, LOW);	//
			delay(1000);			//
			digitalWrite(LED1, HIGH);	//
			delay(1000);			//
			digitalWrite(LED1, LOW);
		}
		else if (input == 3){
			printf("Sweeping Light Movement From Left to Right Activated\n");
			digitalWrite(LED1, HIGH);	//
			delay(1000);			//
			digitalWrite(LED1, LOW);	//
			delay(1000);			//
			digitalWrite(LED2, HIGH);	//
			delay(1000);			//For all turn on the
			digitalWrite(LED2, LOW);	//led on the left and 
			delay(1000);			//turn off led to the left
			digitalWrite(LED3, HIGH);	//with 1 second delay
			delay(1000);			//0.5 hertz = 2second period
			digitalWrite(LED3, LOW);	//
			delay(1000);			//
			digitalWrite(LED4, HIGH);	//
			delay(1000);			//
			digitalWrite(LED4, LOW);	//
			delay(1000);			//
			digitalWrite(LED5, HIGH);	//
			delay(1000);			//
			digitalWrite(LED5, LOW);	//
		}
		else if (input == 4){
			printf("Continuous Sweeping Light Movement Activated\n");
			while (1==1){	//loop to continuosly run the pattern

			digitalWrite(LED5, HIGH);	//Sweep to the right to left
			delay(1000);			//Until LED 1
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
			delay(1000);			//starting to sweep to the left
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
			digitalWrite(LED4, LOW);	//ending at one before right
			delay(1000);			//0.5hertz = 2second periods
			}
		}
		else if (input == 5){		//fifth branch loop
			int input;		//declare user input value
			int remain = 0;		//declare modifying user value varible
			printf("User Input Decimal to Binary Translation Activated\n");
			printf("Enter a Decimal Number (0-31):\n");
			scanf("%d", &input);		//reads user input value
			for (int k = 1; k < 2; k++){	//looop for repeating if wrong value is entered
				if (input >= 0 && input <= 31){	//if statement to check for input of 0-31
					printf("Beginning to Determine\n");
					if ((input/16) == 1){	//if input can be divided by 16 turn led 1 on and subtract input by 16
						digitalWrite(LED1, HIGH);
						remain = (input - 16);
//						printf("Remaining vaue: %d\n", remain);
					}
					else {		//if not then make input equal remain
						remain = input;
					}
					if ((remain/8) == 1){	//if the remaining value is divided by 8-led on & reamin -8
						digitalWrite(LED2, HIGH);
						remain = (remain - 8);
//						printf("Remaining vaue: %d\n", remain);
					}
					if ((remain/4) == 1){	//if remaining value is divided by 4-led on & reamin -4
						digitalWrite(LED3, HIGH);
						remain = (remain - 4);
//						printf("Remaining vaue: %d\n", remain);
					}
					if ((remain/2) == 1){	//if remaining value is divided by 2-led on & remain -2
						digitalWrite(LED4, HIGH);
						remain = (remain - 2);
//						printf("Remaining vaue: %d\n", remain);
					}
					if ((remain/1) == 1){	//if remaining value is divided by 1-led on & remain -1
						digitalWrite(LED5, HIGH);
						remain = (remain - 1);
//						printf("Remaining vaue: %d\n", remain);
					}
					delay(5000);	//leave lights at max on for 5 seconds
				}
				else {	//if the value does not equal 0-31
					for (int j = 0; j < 5; j++){	//loop for flashing led 5 times at 0.5hertz
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
					scanf("%d", &input);	//reads the new integer and sets to input
					k = 0;
				}
			}
			digitalWrite(LED1, LOW);	//at the end turn off leds
			digitalWrite(LED2, LOW);
			digitalWrite(LED3, LOW);
			digitalWrite(LED4, LOW);
			digitalWrite(LED5, LOW);

		}
		else {	//if the value does not equal 1-5
			printf("Not vaild. Enter a  different integer Activated\n");
			scanf("%d", &input);	//reads the new integer and sets to input
			i = 0; //resets the while loop
		}
	}
}
