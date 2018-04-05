/*
 *Stepper Motore Control/Control de motor paso a paso
 * 
 *El motor paso a paso sigue las vueltas de del potenciómetro.
*/

#include <Stepper.h>

//Establecer los pines que se conectan al controlador del motor paso a paso
int stepIN1Pin = 8;
int stepIN2Pin = 9;
int stepIN3Pin = 10;
int stepIN4Pin = 11;
//Pin analógico utilizado para conectar el potenciómetro
int potPin = A0; 

//Se establece una variable para una revolución completa
int stepsPerRevolution = 2048;

//Se crea que el objeto "stepper"
Stepper myStepper(stepsPerRevolution, stepIN1Pin, stepIN3Pin, stepIN2Pin, stepIN4Pin);

//Lectura anterior de la entrada analógica
int previous = 0;

void setup()
{
    //Se establece la velocidad del motor a 10 RPM
    myStepper.setSpeed(10);
}

void loop()
{
    int analogValue;
    int position;

    //Se lee el valor del potenciómetro (valor entre 0 y 1023)
    analogValue = analogRead(potPin);

    //Se establece la escala para usarlo con el motor paso a paso
    position = map(analogValue, 0, 1023, 0, stepsPerRevolution * 0.6);

    //A diferencia del servomotor, el motor paso a paso no está controlado con una posición absoluta, se necesita una relativa.
    //Se mueve a cierta cantidad igual al cambio en la lectura del sensor
    myStepper.step(position - previous);

    //Recuerda el valor anterior del sensor
    previous = position;
}
