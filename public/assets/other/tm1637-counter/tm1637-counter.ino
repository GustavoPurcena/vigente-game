// TM1637 SevenSegment Counter Wokwi Example
//
// https://wokwi.com/projects/339227323398095442

#include <TM1637.h>

const int CLK = 4;
const int DIO = 3;

TM1637 tm(CLK, DIO);
int count = 0;
int n = 0;

void setup() {
  Serial.begin(9600);
  tm.init();
  tm.set(BRIGHT_TYPICAL);
  pinMode(2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), add, RISING);
}

unsigned int counter = 0;
  
void loop() {
  //tm.display(0, (n / 1000) % 10);
  //tm.display(1, ( n / 100) % 10);
  tm.display(2, (n / 10));
  tm.display(3, n % 10);

}

void add(){
  count ++;
  Serial.println("aqui");

  if(count == 10){
    count = 0;
    n++;
    if ( n == 100){
      n = 0;
    }
  }
}
