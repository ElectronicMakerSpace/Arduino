/*
 * Introduction to Servo Motors/Introducción a los Servomotores
 * 
 * Giro del servomotor de 0 a 180 grados y viceversa.
 */

#include <Servo.h> 

//Se conecta el pin naranja a el pin 9
int servoPin = 9;

//Se crea un objeto "servo" para controlar el servomotor, se puede crear un máximo de ocho objetos servo
Servo myServo;
 
void setup() 
{
    //Se conecta el servomotor en el pin 9 al objeto "servo"
    myServo.attach(servoPin);
}

void loop()
{
    //Se mueve el servomotor a 0 grados
    myServo.write(0);

    //Tiempo de espera del movimiento del servomotor
    delay(1000);

    //Se mueve el servomotor a 180 grados
    myServo.write(180);

    // Tiempo de espera del movimiento del servomotor
    delay(1000);
}
