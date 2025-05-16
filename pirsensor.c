#include <reg51.h>
sbit PIR = P3^0;     // PIR sensor connected to P3.0
sbit LED = P3^1;   // Relay control pin connected to P3.1

void delay(unsigned int ms) {
    unsigned int i, j;
    for(i=0; i<ms; i++)
        for(j=0; j<1275; j++);
}

void main() {
    P3 = 0x00;       // Initialize port P3 as input/output

    while(1) {
        if(PIR == 1) {
            LED = 1;  // Turn ON relay (light ON)
        } else {
            LED = 0;  // Turn OFF relay (light OFF)
        }
        delay(100);  // Small delay for debounce
    }
}




