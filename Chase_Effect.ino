                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                /*
---ASININE FATUITY PROGRAMMING NOTES---
the leds are supposed to light one after the other as if they are chasing each other
I realized that using sizeof() doubled the size of the arrays thus introducing unnecessary delays
To solve the above problem, getting an accurate size of array has the formula sizeof(myArray)/sizeof(int)
Again I realized that using different counter variables does not make a difference hence I made one counter for everything called myCounter
Tinkering with the delay gives rise to nice disco lights, the smaller the better the chase
*/
int myLed[]={2,3,4,5,6,7,8,9,10,11};//these are the LED pins to use 
int myCounter=0;// to access it globally
int myArraySize=sizeof(myLed)/sizeof(int);
//to be able to see the transitions otherwise they all light dimly, with none up so brightly
int myDelay =200; 
void setup() {
//set all my pins to output

while(myCounter<myArraySize){
     pinMode(myLed[myCounter],OUTPUT);
     myCounter++;
  }
}

void loop() {
 
  myCounter=0;
 do{
  digitalWrite(myLed[myCounter],HIGH);
  delay(myDelay);
  digitalWrite(myLed[myCounter],LOW);
  myCounter++;
 }while(myCounter<myArraySize);
 myCounter=myArraySize;
 do{
  digitalWrite(myLed[myCounter],HIGH);
  delay(myDelay);
  digitalWrite(myLed[myCounter],LOW);
  myCounter--;
 }while(myCounter>0);//if you put the >= then it will dilly dally at the last LED which is my first anyway!
  
  }
