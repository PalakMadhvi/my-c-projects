#include<stdio.h>
#include<time.h>
#include<windows.h>  //for sleep()
int main(){
	while(1){
		time_t now;
		struct tm*currentTime;
		
		//get current system time
		time(&now);
		currentTime =localtime(&now);
		
		//Extract date and time
		int hour = currentTime->tm_hour;
		int minut=currentTime->tm_min;
		int second=currentTime->tm_sec;
		int day=currentTime->tm_mday;
		int month=currentTime->tm_mon+1; //months start from 0
		int year=currentTime->tm_year+1900;
		
		//Conver to 12 hour format with AM/PM
		char*meridian="AM";
		if(hour>=12){
			meridian="PM";
			if(hour>12)hour-=12;
		}
		
		if(hour==0)hour=12; //midnight case
		
		//Clear screen before printing (Window command)
		system("cls");
		//print date and time
		printf("===============================\n");
		printf("    DIGITAL CLOCK\n");
		printf("===============================\n\n");
		printf("Date: %02d-%02d-%d\n",day,month,year);
		printf("Time: %02d:%02d:%02d%s\n",hour,minut,second,meridian);
		printf("================================\n");
		//Wait 1 second
		sleep(1000);
	}
	
	return 0;
}