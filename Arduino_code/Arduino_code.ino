int FLEX_PIN1 = A0; 
int flexADC1 = 0; 
int sensorMin1 = 1023; 
int sensorMax1 = 0;

int FLEX_PIN2 = A1; 
int flexADC2 = 0; 
int sensorMin2 = 1023; 
int sensorMax2 = 0;

int FLEX_PIN3 = A2; 
int flexADC3 = 0; 
int sensorMin3 = 1023; 
int sensorMax3 = 0;

int FLEX_PIN4 = A3; 
int flexADC4 = 0; 
int sensorMin4 = 1023; 
int sensorMax4 = 0;

int FLEX_PIN5 = A4; 
int flexADC5 = 0; 
int sensorMin5 = 1023; 
int sensorMax5 = 0;

int xpin = A5;
int xadc = 0;
int xmax = 1023;
int xmin = 0;

int ypin = A6;
int yadc = 0;
int ymax = 1023;
int ymin = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("mapping time");
  while(millis()<15000)
  {
    float flexADC1 = analogRead(FLEX_PIN1);
    float flexADC2 = analogRead(FLEX_PIN2);
    float flexADC3 = analogRead(FLEX_PIN3);
    float flexADC4 = analogRead(FLEX_PIN4);
    float flexADC5 = analogRead(FLEX_PIN5);

    if(flexADC1<sensorMin1)
    {
      sensorMin1=flexADC1;
    }
    if(flexADC1>sensorMax1)
    {
      sensorMax1=flexADC1;
    }
    if(flexADC2<sensorMin2)
    {
      sensorMin2=flexADC2;
    }
    if(flexADC2>sensorMax2)
    {
      sensorMax2=flexADC2;
    }
    
    if(flexADC3<sensorMin3)
    {
      sensorMin3=flexADC3;
    }
    if(flexADC3>sensorMax3)
    {
      sensorMax3=flexADC3;
    }
    
    if(flexADC5<sensorMin5)
    {
      sensorMin5=flexADC5;
    }
    if(flexADC5>sensorMax5)
    {
      sensorMax5=flexADC5;
    }
    
    if(flexADC4<sensorMin4)
    {
      sensorMin4=flexADC4;
    }
    if(flexADC4>sensorMax4)
    {
      sensorMax4=flexADC4;
    }
  }
  Serial.println("predecting time");
}

void loop() {
  // put your main code here, to run repeatedly:
  float flexADC1 = analogRead(FLEX_PIN1);
  float flexADC2 = analogRead(FLEX_PIN2);
  float flexADC3 = analogRead(FLEX_PIN3);
  float flexADC4 = analogRead(FLEX_PIN4);
  float flexADC5 = analogRead(FLEX_PIN5);
  
  flexADC1 = constrain(flexADC1,sensorMin1, sensorMax1);
  flexADC2 = constrain(flexADC2,sensorMin2, sensorMax2);
  flexADC3 = constrain(flexADC3,sensorMin3, sensorMax3);
  flexADC4 = constrain(flexADC4,sensorMin4, sensorMax4);
  flexADC5 = constrain(flexADC5,sensorMin5, sensorMax5);
  
  
  float angle1= map(flexADC1, sensorMin1, sensorMax1, 0, 90);
  float angle2= map(flexADC2, sensorMin2, sensorMax2, 0, 90);
  float angle3= map(flexADC3, sensorMin3, sensorMax3, 0, 90);
  float angle4= map(flexADC4, sensorMin4, sensorMax4, 0, 90);
  float angle5= map(flexADC5, sensorMin5, sensorMax5, 0, 90); 

  xadc = analogRead(xpin);
  yadc = analogRead(ypin);
  Serial.print(angle1);
  Serial.print("\t\t");
  Serial.print(angle2);
  Serial.print("\t\t");
  Serial.print(angle3);
  Serial.print("\t\t");
  Serial.print(angle4);
  Serial.print("\t\t");
  Serial.print(angle5);
   Serial.print("\t\t");
  Serial.print(xadc);
   Serial.print("\t\t");
  Serial.println(yadc);
  
   
  if(((angle1>=45)&&(angle1<=65))&&((angle2>=48)&&(angle2<=65))&&((angle3>=40)&&(angle3<=50))&&((angle4>=50)&&(angle4<=60))&&((angle5>=0)&&(angle5<=25)))
  {
    Serial.print('A');
    delay(800);
  }
  if(((angle1>=0)&&(angle1<=10))&&((angle2>=0)&&(angle2<=10))&&((angle3>=0)&&(angle3<=10))&&((angle4>=0)&&(angle4<=10))&&((angle5>=45)&&(angle5<=55)))
  {
    Serial.print('B');
    delay(800);
  }
  if(((angle1>=20)&&(angle1<=40))&&((angle2>=20)&&(angle2<=40))&&((angle3>=20)&&(angle3<=40))&&((angle4>=20)&&(angle4<=40))&&((angle5>=18)&&(angle5<=28)))
  {
    Serial.print('C');
    delay(800);
  }
  if(((angle1>=50)&&(angle1<=72))&&((angle2>=45)&&(angle2<=90))&&((angle3>=35)&&(angle3<=75))&&((angle4>=0)&&(angle4<=10))&&((angle5>=45)&&(angle5<=80))&&(((xadc>=412)&&(xadc<=440))&&((yadc>=340)&&(yadc<=360))))
  {
    Serial.print('D');
    delay(800);
  }
  if(((angle1>=68)&&(angle1<=88))&&((angle2>=68)&&(angle2<=90))&&((angle3>=50)&&(angle3<=80))&&((angle4>=54)&&(angle4<=80))&&((angle5>=58)&&(angle5<=88)))
  {
    Serial.print('E');
    delay(800);
  }
  if(((angle1>=0)&&(angle1<=10))&&((angle2>=0)&&(angle2<=10))&&((angle3>=0)&&(angle3<=10))&&((angle4>=60)&&(angle4<=80))&&((angle5>=34)&&(angle5<=65)))
  {
    Serial.print('F');
    delay(800);
  }
  if(((angle1>=75)&&(angle1<=90))&&((angle2>=75)&&(angle2<=90))&&((angle3>=65)&&(angle3<=90))&&((angle4>=0)&&(angle4<=15))&&((angle5>=50)&&(angle5<=70))&&(((xadc>=390)&&(xadc<=410))&&((yadc>=400)&&(yadc<=420))))
  {
    Serial.print('G');
    delay(800);
  }
   if(((angle1>=75)&&(angle1<=90))&&((angle2>=75)&&(angle2<=90))&&((angle3>=0)&&(angle3<=15))&&((angle4>=0)&&(angle4<=15))&&((angle5>=50)&&(angle5<=70))&&(((xadc>=390)&&(xadc<=410))&&((yadc>=400)&&(yadc<=420))))
  {
    Serial.print('H');
    delay(800);
  }
  if(((angle1>=0)&&(angle1<=15))&&((angle2>=50)&&(angle2<=70))&&((angle3>=40)&&(angle3<=55))&&((angle4>=40)&&(angle4<=50))&&((angle5>=50)&&(angle5<=85))&&(((xadc>=412)&&(xadc<=440))&&((yadc>=340)&&(yadc<=360))))
  {
    Serial.print('I');
    delay(800);
  }

   if(((angle1>=0)&&(angle1<=15))&&((angle2>=50)&&(angle2<=70))&&((angle3>=40)&&(angle3<=55))&&((angle4>=40)&&(angle4<=50))&&((angle5>=50)&&(angle5<=85))&&(((xadc>=390)&&(xadc<=410))&&((yadc>=390)&&(yadc<=420))))
  {
    Serial.print('J');
    delay(800);
  }
  if(((angle1>=35)&&(angle1<=60))&&((angle2>=55)&&(angle2<=85))&&((angle3>=0)&&(angle3<=10))&&((angle4>=0)&&(angle4<=10))&&((angle5>=10)&&(angle5<=30))&&(((xadc>=412)&&(xadc<=440))&&((yadc>=340)&&(yadc<=360))))
  {
    Serial.print('K');
    delay(800);
  }
  if(((angle1>=75)&&(angle1<=90))&&((angle2>=75)&&(angle2<=90))&&((angle3>=70)&&(angle3<=90))&&((angle4>=0)&&(angle4<=15))&&((angle5>=0)&&(angle5<=30))&&(((xadc>=412)&&(xadc<=440))&&((yadc>=340)&&(yadc<=360))))
  {
    Serial.print('L');
    delay(800);
  }
  if(((angle1>=20)&&(angle1<=50))&&((angle2>=48)&&(angle2<=65))&&((angle3>=35)&&(angle3<=55))&&((angle4>=45)&&(angle4<=60))&&((angle5>=20)&&(angle5<=40)))
  {
    Serial.print('M');
    delay(800);
  }
  if(((angle1>=40)&&(angle1<=60))&&((angle2>=30)&&(angle2<=40))&&((angle3>=48)&&(angle3<=66))&&((angle4>=45)&&(angle4<=60))&&((angle5>=20)&&(angle5<=35)))
  {
    Serial.print('N');
    delay(800);
  }
  if(((angle1>=68)&&(angle1<=88))&&((angle2>=68)&&(angle2<=90))&&((angle3>=50)&&(angle3<=80))&&((angle4>=54)&&(angle4<=80))&&((angle5>=0)&&(angle5<=30)))
  {
    Serial.print('O');
    delay(800);
  }
  if(((angle1>=75)&&(angle1<=90))&&((angle2>=75)&&(angle2<=90))&&((angle3>=0)&&(angle3<=10))&&((angle4>=0)&&(angle4<=15))&&((angle5>=0)&&(angle5<=10))&&(((xadc>=335)&&(xadc<=350))&&((yadc>=360)&&(yadc<=380))))
  {
    Serial.print('P');
    delay(800);
  }
  if(((angle1>=75)&&(angle1<=90))&&((angle2>=75)&&(angle2<=90))&&((angle3>=75)&&(angle3<=90))&&((angle4>=0)&&(angle4<=15))&&((angle5>=0)&&(angle5<=10))&&(((xadc>=335)&&(xadc<=350))&&((yadc>=360)&&(yadc<=380))))
  {
    Serial.print('Q');
    delay(800);
  }
  if(((angle1>=40)&&(angle1<=72))&&((angle2>=45)&&(angle2<=90))&&((angle3>=20)&&(angle3<=45))&&((angle4>=0)&&(angle4<=10))&&((angle5>=45)&&(angle5<=80))&&(((xadc>=412)&&(xadc<=440))&&((yadc>=340)&&(yadc<=360))))
  {
    Serial.print('R');
    delay(800);
  }
  if(((angle1>=70)&&(angle1<=90))&&((angle2>=80)&&(angle2<=90))&&((angle3>=80)&&(angle3<=90))&&((angle4>=80)&&(angle4<=90))&&((angle5>=30)&&(angle5<=50)))
  {
    Serial.print('S');
    delay(800);
  }
  if(((angle1>=40)&&(angle1<=61))&&((angle2>=40)&&(angle2<=60))&&((angle3>=40)&&(angle3<=60))&&((angle4>=40)&&(angle4<=65))&&((angle5>=20)&&(angle5<=40)))
  {
    Serial.print('T');
    delay(800);
  }
  if(((angle1>=70)&&(angle1<=90))&&((angle2>=80)&&(angle2<=90))&&((angle3>=0)&&(angle3<=10))&&((angle4>=0)&&(angle4<=10))&&((angle5>=60)&&(angle5<=80)))
  {
    Serial.print('U');
    delay(800);
  }
  if(((angle1>=40)&&(angle1<=60))&&((angle2>=40)&&(angle2<=60))&&((angle3>=0)&&(angle3<=10))&&((angle4>=0)&&(angle4<=10))&&((angle5>=60)&&(angle5<=80)))
  {
    Serial.print('V');
    delay(800);
  }
  if(((angle1>=70)&&(angle1<=90))&&((angle2>=0)&&(angle2<=10))&&((angle3>=0)&&(angle3<=10))&&((angle4>=0)&&(angle4<=10))&&((angle5>=60)&&(angle5<=80)))
  {
    Serial.print('W');
    delay(800);
  }
  if(((angle1>=50)&&(angle1<=72))&&((angle2>=45)&&(angle2<=90))&&((angle3>=35)&&(angle3<=75))&&((angle4>=55)&&(angle4<=70))&&((angle5>=45)&&(angle5<=80)))
  {
    Serial.print('X');
    delay(800);
  }
  if(((angle1>=0)&&(angle1<=10))&&((angle2>=60)&&(angle2<=75))&&((angle3>=45)&&(angle3<=55))&&((angle4>=55)&&(angle4<=65))&&((angle5>=0)&&(angle5<=10)))
  {
    Serial.print('Y');
    delay(800);
  }
  if(((angle1>=75)&&(angle1<=90))&&((angle2>=45)&&(angle2<=90))&&((angle3>=75)&&(angle3<=90))&&((angle4>=0)&&(angle4<=10))&&((angle5>=65)&&(angle5<=90)))
  {
    Serial.print('Z');
    delay(800);
  }
  delay(200);
}
