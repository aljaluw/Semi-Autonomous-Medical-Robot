int m1_EL_Start_Stop=5;  //EL 
int m1_Signal_hall=3;   // Signal - Hall sensor
int m1_ZF_Direction=4;  // ZF 
int m1_VR_speed=2;    //VR 
int m2_EL_Start_Stop=9;  //EL 
int m2_Signal_hall=18;   // Signal - Hall sensor
int m2_ZF_Direction=8;  // ZF 
int m2_VR_speed=6;    //VR
//int diffL = constrain(diffL, 0, 20);
//int diffR = constrain(diffR, 0, 20);
//double percentL = constrain(percentL, 0, 100);
//double percentR = constrain(percentR, 0, 100);
double speed1;
double speed2;
//double coordGradient = 100/960;
//float count_pulseL = 0;
//float count_pulseR = 0;
//double spdL;
//double spdR;
//unsigned long prevTimeL = 0; 
//unsigned long prevTimeR = 0;
//#######################################
//#######################################
//int posR=0;int posL=0;int stepsL=0;int stepsR=0;
//String direction1;
//String direction2;
String x;

//void plusL() {
//  posL++; //count steps
//  count_pulseL++;
//  unsigned long currTimeL = millis();
//  diffL = posL-posR;
//  percentL = ((gradient*diffL+(percentL-gradient))*0.01);
//  if(posL>posR){
//    analogWrite(m1_VR_speed, speed1-(speed1*percentL));
//  }else if(posL<posR){
//    analogWrite(m1_VR_speed, speed1+(speed1*percentR));
//  }
//  if(currTimeL - prevTimeL >= 100){
//    spdL = (count_pulseL/90)*600;
////    Serial.print("Kecepatan Roda Kiri : ");
////    Serial.print(spdL);
////    Serial.println(" RPM");;
//    count_pulseL = 0;
//    prevTimeL = currTimeL;
//    spdL=0;
//  }
////  Serial.print("Steps Kiri : ");
////  Serial.println(posL);
//    if(posL>=stepsL || posR>=stepsR){
//    //wheelStop();
//    posL=0;
//  }
//}

//void plusR() { 
//  posR++; //count steps
//  count_pulseR++;
//  unsigned long currTimeR = millis();
//  diffR = posR-posL;
//  percentR = ((gradient*diffR+(percentR-gradient))*0.01);
//  if(posR>posL){
//     analogWrite(m2_VR_speed, speed2-(speed2*percentR));
//  }else if(posR<posL){
//    analogWrite(m2_VR_speed, speed2+(speed2*percentL));
//  }
//  if (currTimeR - prevTimeR >= 100){
//    spdR = (count_pulseR/90)*600;
////    Serial.print("Kecepatan Roda Kanan : ");
////    Serial.print(spdR);
////    Serial.println(" RPM");
//    count_pulseR = 0;
//    prevTimeR = currTimeR;
//    spdR=0;
//  }  
////  Serial.print("Steps Kanan : ");
////  Serial.println(posR);
//    if(posR>=stepsR || posL>=stepsL){
//    //wheelStop();
//    posR=0;
//  }
//}

void wheelStop(){
  digitalWrite(m1_EL_Start_Stop,LOW);
  digitalWrite(m2_EL_Start_Stop,LOW);
}

void wheelMoveForward(double speed1, double speed2){
      analogWrite(m1_VR_speed, speed1);
      analogWrite(m2_VR_speed, speed2);
//      digitalWrite(m1_EL_Start_Stop,LOW);
//      digitalWrite(m2_EL_Start_Stop,LOW);
      digitalWrite(m1_ZF_Direction,HIGH);
      digitalWrite(m2_ZF_Direction,LOW);
      digitalWrite(m1_EL_Start_Stop,HIGH);
      digitalWrite(m2_EL_Start_Stop,HIGH);
}

void wheelMoveBackward(double speed1, double speed2){
      analogWrite(m1_VR_speed, speed1);
      analogWrite(m2_VR_speed, speed2);
//      digitalWrite(m1_EL_Start_Stop,LOW);
//      digitalWrite(m2_EL_Start_Stop,LOW);
      digitalWrite(m1_ZF_Direction,LOW);
      digitalWrite(m2_ZF_Direction,HIGH);
      digitalWrite(m1_EL_Start_Stop,HIGH);
      digitalWrite(m2_EL_Start_Stop,HIGH);
}

void wheelTurnLeft(double speed1, double speed2){
      analogWrite(m1_VR_speed, speed1);
      analogWrite(m2_VR_speed, speed2);
//      digitalWrite(m1_EL_Start_Stop,LOW);
//      digitalWrite(m2_EL_Start_Stop,LOW);
      digitalWrite(m1_ZF_Direction,LOW);
      digitalWrite(m2_ZF_Direction,LOW);
      digitalWrite(m1_EL_Start_Stop,HIGH);
      digitalWrite(m2_EL_Start_Stop,HIGH);
}

void wheelTurnRight(double speed1, double speed2){
      analogWrite(m1_VR_speed, speed1);
      analogWrite(m2_VR_speed, speed2);
//      digitalWrite(m1_EL_Start_Stop,LOW);
//      digitalWrite(m2_EL_Start_Stop,LOW);
      digitalWrite(m1_ZF_Direction,HIGH);
      digitalWrite(m2_ZF_Direction,HIGH);
      digitalWrite(m1_EL_Start_Stop,HIGH);
      digitalWrite(m2_EL_Start_Stop,HIGH);
}

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
//wheel 1 - Setup pin mode
pinMode(m1_EL_Start_Stop, OUTPUT);//stop/start - EL 
pinMode(m1_Signal_hall, INPUT);   //plus       - Signal  
pinMode(m1_ZF_Direction, OUTPUT); //direction  - ZF 
//wheel 2 - Setup pin mode
pinMode(m2_EL_Start_Stop, OUTPUT);//stop/start - EL 
pinMode(m2_Signal_hall, INPUT);   //plus       - Signal  
pinMode(m2_ZF_Direction, OUTPUT); //direction  - ZF     
//Hall sensor detection - Count steps
//attachInterrupt(digitalPinToInterrupt(m1_Signal_hall), plusL, CHANGE); 
//attachInterrupt(digitalPinToInterrupt(m2_Signal_hall), plusR, CHANGE);
}

void loop() {
  if (Serial.available()>0) {
    char inChar = Serial.read();
    speed1=50;
    speed2=50;
    if (inChar == 'w'){
//      Serial.write("maju");
      speed1=50;
      speed2=50;
      wheelMoveForward(speed1, speed2);
      Serial.flush();}
    else {
      if (inChar == 'a'){
        speed1=20;
        speed2=20;
        wheelTurnLeft(speed1, speed2);
//        Serial.write("kiri");
        Serial.flush();}
      else{ 
        if (inChar == 'd'){
          speed1=20;
          speed2=20;
          wheelTurnRight(speed1, speed2);
//          Serial.write("kanan");
          Serial.flush();}
        else {
          if (inChar == 's'){
            speed1=50;
            speed2=50;
            wheelMoveBackward(speed1, speed2);
            Serial.flush();}          
  }}}
  delay(20);
//  Serial.flush();
}
  else{
    wheelStop();
    delay(20);
    Serial.flush();
  }
}
