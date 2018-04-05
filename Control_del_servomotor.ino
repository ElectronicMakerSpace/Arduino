/*
 * Servo Control/ Control del servomotor
 * 
 *Controla la posición del servomotor usando un potenciómetro.
 */

#include <Servo.h>
 
//El pin naranja se conecta al pin digital 9
int servoPin = 9;
//Se declara el pin analógico utilizado para conectar el potenciómetro
int potPin = A0; 

//Se crea un objeto "servo" para controlar el servomotor, se pueden crear un máximo de ocho objetos "servo"
Servo myServo;

void setup()
{
    //Se conecta el servomotor en el pin 9 al objeto "servo"
    myServo.attach(servoPin);
}
 
void loop()
{
    int analogValue;
    int position;

    //Se lee el valor del potenciómetro (valor entre 0 y 1023)
    analogValue = analogRead(potPin);

    //Se establece la escala para usarlo con el servomotor (valor entre 0 y 180)
    position = map(analogValue, 0, 1023, 0, 179);
    
    //Se establece la posición del servomotor según el valor de la escala
    myServo.write(position);

    //Tiempo de espera para que el servomotor llegue
    delay(15);
}
