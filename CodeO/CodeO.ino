char t;
 
void setup() {
  pinMode(13,OUTPUT);   //headlight
  pinMode(12,OUTPUT);   //left forward
  pinMode(11,OUTPUT);   //left backward
  pinMode(10,OUTPUT);   //right forward
  pinMode(9,OUTPUT);    //right backward
  pinMode(8,OUTPUT);    //Indicator
  pinMode(7,OUTPUT);    //Back Light
  pinMode(6,OUTPUT);    //Back Light
  Serial.begin(9600);   //Rate for bluetooth module to communicate
}
 
void loop() {
  if(Serial.available()){
    t = Serial.read();
    Serial.println(t);
  }
 
  if(t == 'F'){            //move forward(all motors rotate in forward direction)
    digitalWrite(12,HIGH); //left forward
    digitalWrite(10,HIGH); //right forward
  }
 
  else if(t == 'B'){      //move reverse (all motors rotate in reverse direction)
    digitalWrite(11,HIGH); //right reverse
    digitalWrite(9,HIGH); //left reverse
    digitalWrite(6,HIGH); //back light
    digitalWrite(7,HIGH); //back light
  }
 
  else if(t == 'L'){      //turn right (left side motors rotate in backward direction, right side motors rotate in forward direction)
    digitalWrite(10,HIGH); //right forward
    digitalWrite(11,HIGH); //left reverse
  }
   
  else if(t == 'R'){      //turn left (left side motors rotate in forward direction, right side motors rotate in backward direction)
    digitalWrite(12,HIGH); //left forward
    digitalWrite(9,HIGH); //right reverse
  }
   
  else if(t == 'S'){      //STOP (all motors stop)
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
  }

  else if(t == 'a'){
    digitalWrite(10, HIGH); //right forward
  }

  else if(t == 'b'){
    digitalWrite(12, HIGH); //left forward
  }

  else if(t == 'c'){
    digitalWrite(9, HIGH); //right reverse
  }

  else if(t == 'd'){
    digitalWrite(11, HIGH); //left reverse
  }
  
  else if(t == 'W'){  //Led on
    digitalWrite(13,HIGH); //headlight on
  }
  
  else if(t == 'w'){  //Led off
    digitalWrite(13,LOW); //headlight off
  }
  
  else if(t == 'r'){  //reset
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
  }
  
}