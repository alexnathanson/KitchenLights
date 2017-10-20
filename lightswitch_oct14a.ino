const int transistorPin1 = 3;    // connected to the base of the transistor
const int transistorPin2 = 5;    // connected to the base of the transistor
const int transistorPin3 = 6;    // connected to the base of the transistor
const int transistorPin4 = 9;    // connected to the base of the transistor

int inPot = 0; // store value of potentiameter input
int potPin = 2; //potentiameter pin

int sinkButt = 0; // store value of sink and stove light switch
int sinkPin = 4; // switch pin

int outputValue1 = 0; //variable to store the transistor output
int outputValue2 = 0; //variable to store the transistor output
int outputValue3 = 0;//variable to store the transistor output
int outputValue4 = 0;//variable to store the transistor output

void setup() {
    Serial.begin(9600);
   // set  the transistor pin as output:
   pinMode(transistorPin1, OUTPUT);
   pinMode(transistorPin2, OUTPUT);
   pinMode(transistorPin3, OUTPUT);
   pinMode(transistorPin4, OUTPUT);

}

void loop() {

// read the value from the potentiameter
    inPot = analogRead(potPin); 

/*
// print the potentiameter input
    Serial.print("Pot: ");
    Serial.println(inPot);
  */  
  
//control main kitchen lights
      if (inPot >= 750){
         outputValue1 = 255;
         outputValue2 = 255;
         outputValue3 = 255;
      }else if (inPot >= 500){
         outputValue1 = 255;
         outputValue2 = 255;
         outputValue3 = 0;
      }else if (inPot >= 250){
         outputValue1 = 255;
         outputValue2 = 0;
         outputValue3 = 0;
      }else {
         outputValue1 = 0;
         outputValue2 = 0;
         outputValue3 = 0;
      }

//control sink and stove lights
      if (sinkButt == HIGH){
        outputValue4 = 255;
      } else{
        outputValue4 = 0;
      }

//output to transistors
      analogWrite(transistorPin1, outputValue1);
      analogWrite(transistorPin2, outputValue2);
      analogWrite(transistorPin3, outputValue3);
      analogWrite(transistorPin4, outputValue4);


// print feedback
      Serial.print("Transistor 1: ");
      Serial.println(outputValue1);
      Serial.print("Transistor 2: ");
      Serial.println(outputValue2);
      Serial.print("Transistor 3: ");
      Serial.println(outputValue3);
     // Serial.print("Transistor 4: ");
     // Serial.println(outputValue4);
      
}
