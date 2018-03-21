#include "types.h"
#include "stat.h"
#include "user.h"
#include "date.h"

int main(int argc, char **argv){
	struct rtcdate r;
	printf(1, "Current time: \n");
	gettime(&r);

	printf(1, "%d:%d:%d GMT\n",
         r.hour, r.minute, r.second);


	//Convert to IST
	if(argc > 1){
		if(*argv[1] == 'i'){
			int h  0 , minute = 0; 
		  	hour = r.hour + 5;
		  	minute = r.minute + 30;
		  	if(hour > 24){
		    hour = hour - 24;
		    r.day = r.day + 1;      
		  	}
			if(minute > 60){
			    minute = minute - 60;
			    if(hour == 23){
			      hour = 0;
			      r.day = r.day + 1;
			    }      
			    else 
			        hour = hour+1;
			}
			printf(1, "%d:%d:%d IST\n", hour, minute, r.second);
		}
	}

	exit();

}

