/* Automotive vehicle v.3
 * -------------------------
 *
 * Automotive vehicle with two photodiode sensors 
 * on which is based the movement of two dc motors 
 * 
 *
 * Created by Anastasis
 * Copyleft 2013
 * Greece
 *
 */
float sensorA0,sensorA0e;
float sensorA1,sensorA1e;
float voltA0,voltA0e,volt0;
float voltA1,voltA1e,volt1;
int irled0=11;
int irled1=12;
int pwmPin0=9;
int pwmPin1=10;
float k0,k1;

void setup() {
  pinMode(pwmPin0,OUTPUT); 
  pinMode(pwmPin1,OUTPUT);
  pinMode(irled0,OUTPUT);
  pinMode(irled1,OUTPUT); 
  k0=0;
  k1=0;
}

void loop(){
   voltA0e=0;
   voltA0=0;
   voltA1e=0;
   voltA1=0;
   digitalWrite(irled0,LOW);
   digitalWrite(irled1,LOW);
  
   for (int i=0; i<10; i++){
          sensorA0e=analogRead(A0);
          voltA0e+=sensorA0e*(4.5/1023.0);
   }
   
   for (int i=0; i<10; i++){
          sensorA1e=analogRead(A1);
          voltA1e+=sensorA1e*(4.5/1023.0);
   }
   
   digitalWrite(irled0,HIGH);
   digitalWrite(irled1,HIGH);
   
   for (int i=0; i<10; i++){  
          sensorA0=analogRead(A0);
          voltA0+=sensorA0*(4.5/1023.0);
   }
   
   for (int i=0; i<10; i++){  
          sensorA1=analogRead(A1);
          voltA1+=sensorA1*(4.5/1023.0);
   }
   
   volt0=voltA0e-voltA0;
   volt1=voltA1e-voltA1;
   
   if (volt0-k0>0.03)
     k0=volt0;
  
   if (volt1-k1>0.03)
     k1=volt1;
  
   if (k0>=0.50)
    analogWrite(pwmPin0,0);
   else if (k0>=0.30)
    analogWrite(pwmPin0,120);
   else
    analogWrite(pwmPin0,160);
    
   if (k1>=0.50)
    analogWrite(pwmPin1,0);
  else if (k1>=0.30)
    analogWrite(pwmPin1,120);
  else
    analogWrite(pwmPin1,160);
    }

