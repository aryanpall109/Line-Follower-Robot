int m1= 2;  //Right Motor MA1
int m2= 3;  //Right Motor MA2
int m3= 4;  //Left Motor MB1
int m4= 5;  //Left Motor MB2
int e1= A5;  //Right Motor Enable Pin EA
int e2= A4; //Left Motor Enable Pin EB

//**********5 Channel IR Sensor Connection**********//
int ir1= 8;
int ir2= 9;
int ir3= 10;
int ir4= 11;
int ir5= 12;
int count=0;

//*************************************************//

void setup() {
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(e1, OUTPUT);
  pinMode(e2, OUTPUT);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);
}

void loop() {
analogWrite(e1,230);
analogWrite(e2,180);
  //Reading Sensor Values
  int s1 = digitalRead(ir1);  //Left Most Sensor
  int s2 = digitalRead(ir2);  //Left Sensor
  int s3 = digitalRead(ir3);  //Middle Sensor
  int s4 = digitalRead(ir4);  //Right Sensor
  int s5 = digitalRead(ir5);  //Right Most Sensor
  

  //if only middle sensor detects white line
  if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 1) && (s5 == 1))
  {
    //going forward with full speed 
    //analogWrite(e1, 255); //you can adjust the speed of the motors from 0-255
    //analogWrite(e2, 255); //you can adjust the speed of the motors from 0-255
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  }

  //if only left sensor detects white line
  if((s1 == 1) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 1))
  {
    //going right with full speed (do not get confuse) 
    //analogWrite(e1, 255); //you can adjust the speed of the motors from 0-255
    //analogWrite(e2, 255); //you can adjust the speed of the motors from 0-255
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  }

  //if only left most sensor detects black line {Sharp turn 90 degrees}
  if((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 1))
  {
    //going right with full speed (do not get confuse)
    //analogWrite(e1, 255); //you can adjust the speed of the motors from 0-255
    //analogWrite(e2, 255); //you can adjust the speed of the motors from 0-255
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  }

  //if only right sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 1))
  {
    //going left with full speed 
    //analogWrite(e1, 255); //you can adjust the speed of the motors from 0-255
    //analogWrite(e2, 255); //you can adjust the speed of the motors from 0-255
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
  }

  //if only right most sensor detects black line (sharp turn)
  if((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 0))
  {
    //going left with full speed 
    //analogWrite(e1, 255); //you can adjust the speed of the motors from 0-255
    //analogWrite(e2, 255); //you can adjust the speed of the motors from 0-255
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, HIGH);
  }

  //if middle and right sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 1))
  {
    //going left with full speed 
    //analogWrite(e1, 255); //you can adjust the speed of the motors from 0-255
    //analogWrite(e2, 255); //you can adjust the speed of the motors from 0-255
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
  }

  //if middle and left sensor detects black line
  if((s1 == 1) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1))
  {
    //going right with full speed 
    //analogWrite(e1, 255); //you can adjust the speed of the motors from 0-255
    //analogWrite(e2, 255); //you can adjust the speed of the motors from 0-255
    digitalWrite(m1, HIGH);
    digitalWrite(m2, HIGH);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  }

  //if middle, left and left most sensor detects black line
  if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1))
  {
    //going right with full speed 
    //analogWrite(e1, 255); //you can adjust the speed of the motors from 0-255
    //analogWrite(e2, 255); //you can adjust the speed of the motors from 0-255
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
  }

  //if middle, right and right most sensor detects white line
  if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 0))
  {
    //going left with full speed 
    //analogWrite(e1, 255); //you can adjust the speed of the motors from 0-255
    //analogWrite(e2, 255); //you can adjust the speed of the motors from 0-255
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
  }
  
  //if all sensors are on a white line
  if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 0))
  {
    if (count==0)
    {
      digitalWrite(m1, LOW);
      digitalWrite(m2, LOW);
      digitalWrite(m3,LOW);
      digitalWrite(m4, LOW);
      delay(5000);
      digitalWrite(m1, HIGH);
      digitalWrite(m2, LOW);
      digitalWrite(m3,HIGH);
      digitalWrite(m4, LOW);
      count++; 
    }
    if (count==1)
    {
      digitalWrite(m1, LOW);
      digitalWrite(m2, LOW);
      digitalWrite(m3,LOW);
      digitalWrite(m4, LOW); 
    }
    
    
  }
  /*if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 0) && count==0)
  {
     digitalWrite(m1, LOW);
       digitalWrite(m2, LOW);
       digitalWrite(m3, LOW);
       digitalWrite(m4, LOW); 
  }
*/
  if((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 1))
  {
    // no stop
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    digitalWrite(m3,HIGH);
    digitalWrite(m4, LOW);
  }
 
}
