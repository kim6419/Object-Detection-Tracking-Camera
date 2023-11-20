String inputstring ="";

String pan = "";
String tilt = "";


void setup() 
{
  inputstring.reserve(10);
  Serial.begin(9600);
}

void loop() 
{
  if(Serial.available() > 0)
  {
  char ch = Serial.read();
  if(ch != '\n')
  {
    rx_str[i] = ch;
    i++;
  }
  
  if(ch !='\n')
    {
      inputstring += ch;
    }
  else
    {
      if(inputstring.substring(0, 3) == "pan")
      {
        pan = inputstring.substring(3);
        Serial.print(pan);
      }
      else if(inputstring.substring(0, 4) == "tilt")
      {
        tilt = inputstring.substring(4);
        Serial.print(tilt);
      }
      inputstring ="";
    }
  }
}

