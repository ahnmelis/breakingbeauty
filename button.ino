//butoon
int input= D0;
int output= D2;
int value;


bool first_flag = false;
//bool second_flag = false;
bool ending_flag= false;
Timer s(10000, first_txt);

void first_txt() {
  Particle.publish("email");
//  ending_flag= true;
  s.changePeriod(60000);
}

/*void second_txt(){
  Particle.publish("email");
}*/


//Timer m(10000, second_txt);
//int count_s = 0;
//LED
//int led_output = D6;
String message;
//int led_value;

void setup() {
    pinMode(input, INPUT);
    pinMode(output, OUTPUT);
    digitalWrite(output, HIGH);
    digitalWrite(input,HIGH);
  //  pinMode(input, INPUT_PULLUP);
    //lED
  /*  pinMode(led_output, OUTPUT);
    digitalWrite(led_output,HIGH);*/
    Particle.variable("message", message);

}
void loop() {
  value=digitalRead(input);
  if(value==LOW){
    //while(digitalRead(input)!=LOW){
      //delay(1000);
    //}
    if (first_flag == false) {
      s.start();
      first_flag=true;
    }


  /*  if (ending_flag == true) {
      m.start();
    }*/

    //delay(1000);
    //count++;

  //if (count == 10) {
    //  Particle.publish("email");
      //count = 0;

  //  }
  //  digitalWrite(led_output, LOW);
    message="bracelet is off";
    //Particle.publish("email");
  }
  else{
  //  Particle.publish("off");
    //digitalWrite(led_output,HIGH);
    message="bracelet is on";
    //count = 0;
    if (first_flag==true){
    s.stop();
  }
/*    if (ending_flag==true){
    m.stop();
  }
    ending_flag= false;*/
    first_flag=false;
  }

}
