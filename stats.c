#include "stats.h"

struct Stats compute_statistics( float* numberset, int setlength) {
    struct Stats s;
    
    if(setlength!=0){
    int i,j,k;
    double total=0;
    float maximum =numberset[0];
    float minimum =numberset[0];
    
    
    //average calculation
    for(i=0;i<setlength;i++){
        total=total+ numberset[i];
    }
    s.average = total/setlength;
    
    //max calculation
    for(j=1;j<setlength;j++){
        if(numberset[j]> maximum)
            maximum =numberset[j];
    }     
    s.max = maximum;
    
    //
    for(k=1;k<setlength;k++){
        if(numberset[k]< minimum)
            minimum =numberset[k];
    }
    s.min = minimum;
    }
    else{
         s.average=0;
      s.min = 0;
        s.max =0;
    }
   
    return s;
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats){
    
    //alerters[0] = emailAlerter;
    //alerters[1] = ledAlerter ;
    
    if (computedStats.max > maxThreshold)
    {
        (*alerters[0])();
        (*alerters[1])();
    }
}
int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
void emailAlerter (void){
 emailAlertCallCount ++;
}

void ledAlerter (void){
ledAlertCallCount ++;
}
