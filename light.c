#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <lcd.h>


const char PCF8591 = 0x48; // adresa
int fd, adcVal;

int main() {
	FILE *file = fopen("data.txt", "w");
	if(file == NULL){
		printf("Error, file could now open!\n");
		exit(-1);
	}

	if (wiringPiSetup () == -1) exit (1);
		fd = wiringPiI2CSetup(PCF8591);

	pinMode(25, OUTPUT);
	pinMode(26, OUTPUT);
	pinMode(27, OUTPUT);

	digitalWrite(25, 0);
	digitalWrite(26, 1);
	digitalWrite(27, 0);
	
	for(int i = 0; i < 5; i++)	
	{	 	
		adcVal = wiringPiI2CReadReg8(fd, PCF8591 + 0);
	 	printf("vrijednost: %d\n", adcVal);
		
		if(adcVal>200)
			{
			//printf("low ");
			digitalWrite(25, 1);
			digitalWrite(26, 1);
			digitalWrite(27, 1);
			}
		else if(adcVal > 140 && adcVal < 200) 
			{
			//printf("medium");
			digitalWrite(25, 1);
			digitalWrite(26, 1);
			digitalWrite(27, 0);
			}
		else
			{
			//printf("high");
			digitalWrite(25, 1);
			digitalWrite(26, 0);
			digitalWrite(27, 0);
			}	
		fprintf(file, " %d \n", adcVal);
		delay(1000);
	}
	digitalWrite(25, 0);
	digitalWrite(26, 0);
	digitalWrite(27, 0);	
 return 0;
}
