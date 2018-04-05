/*
 * Introduction to Stepper Motors/Introduccion a a los motres paso a paso
 * 
 * Simplemente gira el stepper desde 360 ​​grados adelante y atrás.
 */

#include <Stepper.h>

int stepIN1Pin = 8;
int stepIN2Pin = 9;
int stepIN3Pin = 10;
int stepIN4Pin = 11;

int stepsPerRevolution = 2048;

Stepper myStepper(stepsPerRevolution,
                  stepIN1Pin, stepIN3Pin,
                  stepIN2Pin, stepIN4Pin);

void setup()
{
    //Establecer la velocidad RPM
    myStepper.setSpeed(6);
}

void loop()
{
    //PASO 1 Revolucion en una dirección
    myStepper.step(stepsPerRevolution);
    //Espera un segundo
    delay(1000);

    //Revolucion en otra dirección
    myStepper.step(-stepsPerRevolution);
    //Espera un segundo
    delay(1000);
}
