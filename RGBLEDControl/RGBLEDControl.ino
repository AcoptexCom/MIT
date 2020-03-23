const int redPin = 9;     //Red pin of RGB LED attached to Arduino digital pin 9
const int greenPin = 10;  //Green pin of RGB LED attached to Arduino digital pin 10
const int bluePin = 11;   //Blue pin of RGB LED attached to Arduino digital pin 11

String redValue;       //we define the redValue 
String greenValue;     //we define the greenValue
String blueValue;      //we define the blueValue  

char message[12];          //we store color symbols in message array. color message from Android app consists of 12 characters
byte index = 0;            //we define the position in array

//variables:
char read_char;            //we define read character variable
char currentColor;         //we define currentColor variable
int star = 0;              //we define star variable

void setup() {
  Serial.begin(9600);       //we initialize serial communication at 9600 bps
  pinMode(redPin,OUTPUT);   //we set the redPin as OUTPUT
  pinMode(greenPin, OUTPUT);//we set the greenPin as OUTPUT
  pinMode(bluePin,OUTPUT);  //we set the bluePin as OUTPUT  
}

void loop() {
  while(Serial.available() > 0){  //while we are reading the message 
    star = 0;
    if(index < (11)){             //the color message can have up to 12 characters 
      read_char = Serial.read();  //we read a character and store it in message array
      message[index] = read_char;     
      if(read_char=='R'){
         currentColor = 'R';
         redValue = "";
      }
      else if(read_char=='G'){
         currentColor = 'G';
         greenValue = "";
      }
      else if(read_char=='B'){
         currentColor = 'B';
         blueValue = "";
      }
      if(currentColor == 'R' && read_char!='R'){//if currentColor equal to 'R' and read_char is not equal to 'R'
         redValue += read_char;                 //equivalent to the expression redValue = redValue + read_char
      }
      else if(currentColor == 'G' && read_char!='G'){//if currentColor equal to 'G' and read_char is not equal to 'G'
         greenValue += read_char;                    //equivalent to the expression greenValue = greenValue + read_char
      }
      else if(currentColor == 'B' && read_char!='B'){//if currentColor equal to 'B' and read_char is not equal to 'B'
         blueValue += read_char;                     //equivalent to the expression blueValue = blueValue + read_char
      }
      index++;                     //we increment position
      message[index] = '\0';       //we delete the last position
   }
   
 }

 if(star == 0){
   analogWrite(redPin, 255-redValue.toInt());
   analogWrite(greenPin, 255-greenValue.toInt());
   analogWrite(bluePin, 255-blueValue.toInt());
   
    star=1;
       for(int i=0; i<12; i++){
      message[i] = '\0';
    } 
    index=0;  //we reset the index
 }

}
