/*
  Rodrigo Cordoba
  Belloni Lucio
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

#include <LiquidCrystal.h>

//define de lcd
#define RS 13
#define E 12
#define D4 11
#define D5 10
#define D6 9
#define D7 8
//define de leds
#define LEDNARANJA 2
#define LEDROJO 3
#define LEDVERDE 4
#define LEDAMARILLO 5
#define LEDBLANCO 6
#define LEDAZUL 7
//define de puertos analogicos
#define POTENCIOMETRO A1
#define BUZZER A2
#define PULSADOR A3

void encenderLeds(int pin);
void apagarLeds(int pin);
void parpadear(void);
void sonarBuzzer(void);
void sonarBuzzerGano(void);

LiquidCrystal myLcd(RS,E,D4,D5,D6,D7);

int banderaPulsador=0;
int contadorDeBatallas=0;
int randNumber;

void setup()
{
  for(int i = 2; i <= 7 ; i++)
  {
    pinMode(i, OUTPUT);
  }
  myLcd.begin(16,2);
  pinMode(PULSADOR,INPUT_PULLUP);
  pinMode(BUZZER,OUTPUT);
  Serial.begin(9600);

  randomSeed(analogRead(0));
}

void loop()
{
  float lectura;
  float poder;
  int estadoPulsador = digitalRead(PULSADOR);

  if(estadoPulsador==HIGH)
  {
    banderaPulsador=1;
  }
  else
  {
  	if(banderaPulsador==1)
    {
      delay(50);
      randNumber = random(100,200);
      banderaPulsador=0;

      lectura=analogRead(POTENCIOMETRO);
      poder=map(lectura,0,1023,90,190);

      contadorDeBatallas++;
    }
  }
  switch(contadorDeBatallas)
  {
    case 1:
    	if(poder>randNumber)
        {
          delay(400);
          myLcd.clear();

          myLcd.setCursor(0,0);
          myLcd.print("GAMORA:");
          myLcd.print(randNumber);
          myLcd.setCursor(0,1);
          myLcd.print("THANOS:");
          myLcd.print(poder);

          encenderLeds(LEDNARANJA);
          sonarBuzzer();
        }
   	 	else
        {
          delay(400);
          myLcd.clear();

          apagarLeds();

          myLcd.setCursor(0,1);
          myLcd.print("Perdio Thanos");

          contadorDeBatallas=0;
        }
    break;
    case 2:
    	if(poder>randNumber)
        {
          delay(400);
          myLcd.clear();

          myLcd.setCursor(0,0);
          myLcd.print("LOKI:");
          myLcd.print(randNumber);
          myLcd.setCursor(0,1);
          myLcd.print("THANOS:");
          myLcd.print(poder);

          encenderLeds(LEDNARANJA);
          encenderLeds(LEDROJO);
          sonarBuzzer();
        }
    	else
        {
          delay(400);
          myLcd.clear();

          apagarLeds();

          myLcd.setCursor(0,1);
          myLcd.print("Perdio Thanos");
          contadorDeBatallas=0;
        }
    break;
    case 3:
    	if(poder>randNumber)
        {
          delay(400);
          myLcd.clear();

          myLcd.setCursor(0,0);
          myLcd.print("COLECCIONIST:");
          myLcd.print(randNumber);
          myLcd.setCursor(0,1);
          myLcd.print("THANOS:");
          myLcd.print(poder);

          encenderLeds(LEDNARANJA);
          encenderLeds(LEDROJO);
          encenderLeds(LEDVERDE);
          sonarBuzzer();
        }
    	else
        {
          delay(400);
          myLcd.clear();

          apagarLeds();

          myLcd.setCursor(0,1);
          myLcd.print("Perdio Thanos");
          contadorDeBatallas=0;
        }
    break;
    case 4:
    	if(poder>randNumber)
        {
          delay(400);
          myLcd.clear();

          myLcd.setCursor(0,0);
          myLcd.print("STAR LORD:");
          myLcd.print(randNumber);
          myLcd.setCursor(0,1);
          myLcd.print("THANOS:");
          myLcd.print(poder);

          encenderLeds(LEDNARANJA);
          encenderLeds(LEDROJO);
          encenderLeds(LEDVERDE);
          encenderLeds(LEDAMARILLO);
          sonarBuzzer();
        }
    	else
        {
          delay(400);
          myLcd.clear();

          apagarLeds();

          myLcd.setCursor(0,1);
          myLcd.print("Perdio Thanos");
          contadorDeBatallas=0;
        }
    break;
    case 5:
    	if(poder>randNumber)
        {
          delay(400);
          myLcd.clear();

          myLcd.setCursor(0,0);
          myLcd.print("DR STRANGE:");
          myLcd.print(randNumber);
          myLcd.setCursor(0,1);
          myLcd.print("THANOS:");
          myLcd.print(poder);

          encenderLeds(LEDNARANJA);
          encenderLeds(LEDROJO);
          encenderLeds(LEDVERDE);
          encenderLeds(LEDAMARILLO);
          encenderLeds(LEDBLANCO);
          sonarBuzzer();
        }
    	else
        {
          delay(400);
          myLcd.clear();

          apagarLeds();

          myLcd.setCursor(0,1);
          myLcd.print("Perdio Thanos");
          contadorDeBatallas=0;
        }
    break;
    case 6:
    	if(poder>randNumber)
        {
          delay(400);
          myLcd.clear();

          myLcd.setCursor(0,0);
          myLcd.print("VISION:");
          myLcd.print(randNumber);
          myLcd.setCursor(0,1);
          myLcd.print("THANOS:");
          myLcd.print(poder);

          encenderLeds(LEDNARANJA);
          encenderLeds(LEDROJO);
          encenderLeds(LEDVERDE);
          encenderLeds(LEDAMARILLO);
          encenderLeds(LEDBLANCO);
          encenderLeds(LEDAZUL);
          sonarBuzzer();

          if(contadorDeBatallas==6)
          {
            delay(400);
            myLcd.clear();

            myLcd.setCursor(0,0);
            myLcd.print("No me quiero ir");
            myLcd.setCursor(0,1);
            myLcd.print("SR.STARK");

            for(int i = 0; i < 3 ; i++)
            {
              parpadear();
              sonarBuzzerGano();
            }
          }
        }
    	else
        {
          delay(400);
          myLcd.clear();

          apagarLeds();

          myLcd.setCursor(0,1);
          myLcd.print("Perdio Thanos");
          contadorDeBatallas=0;
        }
    	contadorDeBatallas=0;
    break;
  }
}

void encenderLeds(int pin)
{
    digitalWrite(pin, HIGH);
}

void apagarLeds(void)
{
  for(int i = 2; i <= 7 ; i++)
  {
    digitalWrite(i, LOW);
  }
}

void parpadear(void)
{
  for(int i = 2; i <= 7 ; i++)
  {
    digitalWrite(i, HIGH);
  }
  delay(350);
  for(int i = 2; i <= 7 ; i++)
  {
    digitalWrite(i, LOW);
  }
  delay(350);
}

void sonarBuzzer(void)
{
  tone(BUZZER,150);
  delay(150);
  noTone(BUZZER);
}
void sonarBuzzerGano(void)
{
  tone(BUZZER,350);
  delay(1500);
  noTone(BUZZER);
}






	return EXIT_SUCCESS;
}
