#include "DmxMaster.h"

int channels[511];

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < 511; i++) {
    channels[i] = 0;
  }
  DmxMaster.write(channels);
}


int channel;
int data;
int value = 0;
int i = 0;  
// void loop() {
//   int c;

//   while(!Serial.available());
//   c = Serial.read();
//   if ((c>='0') && (c<='9')) {
//     value = 10*value + c - '0';
//   } else {
//     if (c=='c') channel = value;
//     else if (c=='w') {
//       channels[channel] = value;
//       int i;
//       // for (i=0; i < 5; i++){
//       //   Serial.print(channels[i]);
//       // }
//       DmxMaster.write(channels);
//       Serial.println();
//     }
//     value = 0;
//     }
// }

void loop() {
  int c;


  while(!Serial.available());//{

    c = Serial.read();

    if ((c>='0') && (c<='9')){
      value = 10*value + c - '0';
    }

    if (c ==',') {
      channels[i] = value;
      i++;
      value = 0;
    }

    if (c=='~') {
      channels[i] = value;
      DmxMaster.write(channels);
      i = 0;
      value=0; 
    }
  //}
}
