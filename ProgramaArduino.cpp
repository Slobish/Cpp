#define BIAR 13 
#define BIAB 12
#define GO 11
#define TRAN 10
#define MO12 9
#define MO11 8

unsigned long tiempo=0;
char fase=0,pulsed=0,bajando=0,reset=0;
void setup() {
  
  digitalWrite(MO11,LOW);
  digitalWrite(MO12,LOW);
  digitalWrite(TRAN,LOW);
  pinMode(BIAR,INPUT);
  pinMode(BIAB,INPUT);
  pinMode(GO,INPUT);
  pinMode(MO11,OUTPUT);
  pinMode(MO12,OUTPUT);
  pinMode(TRAN,OUTPUT);
 
  
}
void loop()
{
/*.......................................................*/

  if (digitalRead(GO)==1)
  {
    
   if  ( (millis()-tiempo) < 2000)
   {
    pulsed=0;
    fase=0;
    digitalWrite(MO11,LOW);
    digitalWrite(MO12,LOW);
    digitalWrite(TRAN,LOW);
   
  
    while (BIAR==0)
    {
      digitalWrite(MO11,HIGH);
    }
      digitalWrite(MO11,LOW);
      
    while(digitalRead(GO)==0)
    {
      ;
    }
   }
   else 
   
   {
    
    pulsed=1; 
    fase=1; 
    tiempo=millis();
    
   }   
  }
  
  delay(100);
 

  /*.....................................................*/
  
  if (pulsed>=1)
  {
    switch(fase)  
    {
      case 1:
             digitalWrite(TRAN,HIGH);
             if (digitalRead(BIAB)==1) 
             {
             digitalWrite(TRAN,LOW);
             fase++;
             delay(500);
             }
             break;
             
      case 2: 
            digitalWrite(MO11,HIGH);
            if (digitalRead(BIAR)==1)
            {
              digitalWrite(MO11,LOW);
              fase++;
            }
            break;
      case 3:
            if (digitalRead(BIAR)==0)
            {
              delay(200);
              if (digitalRead(BIAR)==0)
              {
              digitalWrite(MO12,HIGH);
              fase++;
              }
             
            }
            break;
      case 4:      
            if (digitalRead(BIAB)==1) 
            {
              digitalWrite(MO12,LOW);
              fase=0;
              pulsed=0;
            }
         
            break;
       
    
    }
    
  }

}

