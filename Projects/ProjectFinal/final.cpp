#include <iostream>
#include <wiringPi.h>
#include <unistd.h>
using namespace std;


			      // GND pin 20, PWR pin 2 and 4(Designated for servo)
#define SERVO         18      // PWM0, pin 12
#define BUTTON1       27      // GPIO27, pin 13
#define BUTTON2       17      // GPIO17, pin 11, used to reset FlipFlop and Servo
#define SIGNAL        22      // GPIO22, pin 15 sends clock like signal to 7473
#define FLIPCLEAR     10      // GPIO10, pin 19 resets FlipFlop

int main() {                            // must be run as root
	wiringPiSetupGpio();            // use the GPIO numbering
	pinMode(SERVO, PWM_OUTPUT);     // PWM servo
   	pinMode(BUTTON1, INPUT);        // button1 input
	pinMode(BUTTON2, INPUT);	// button2 input
	pinMode(SIGNAL, OUTPUT);	// FlipClear output
   	pwmSetMode(PWM_MODE_MS);              // use a fixed frequency
   	pwmSetRange(1000);                    // 1000 steps
   	pwmSetClock(384);                     // gives 50Hz precisely

   	cout << "Running The Clock" << endl;
	int y = 0;	//holder for while loop
	int b = 1;	//counter for the servo loop
	int h = 0;	//value for time till home
	if(digitalRead(BUTTON1) == HIGH){	//enter when button1 is pressed
		while (y = 0){	//semi continuous loop
	      		cout << "In the loop" << b << endl;
	      		pwmWrite(SERVO, 74);	//start servo
			usleep(68000);
			pwmWrite(SERVO,75);	//stop servo
			usleep(932000);
			b++;	//increment b
			h = ((60-b)*68000);	//change value of h
			if (b == 60){	//every minute send signal to 7473
				digitalWrite(SIGNAL, HIGH);	//start signal
				usleep(50000);
				digitalWrite(SIGNAL, LOW);	//end signal
				b = 1;	//reset b counter
			}
			if(BUTTON2 == HIGH){ 	//if button 2 pressed reset all
				digitalWrite(FLIPCLEAR, HIGH);	//send reset to the 7473
				usleep(50000);
				digitalWrite(FLIPCLEAR, LOW);	//stop sending
				pwmWrite(SERVO, 74);	//start servo 
				delay(h);	//run for till home time
				pwmWrite(SERVO, 75);	//stop servo
				y = 1;	//breakout of while loop
			}
		}
	}



   	pwmSetClock(0);
   	cout << "Program has finished" << endl;
   	return 0;
}
