/*Deteccion de luz 
 * Medir el brillo de la luz utilizando una fotocelda
 */

//A continuacion se cran las constantes de las lecturas mas altas 
// y mas bajas que recibe el sensor
//
//Sensor Minimo
const int sensorMin = 0; 
//Sensor Maximo
const int sensorMax = 800;

//Pin correspondiente al divisor de voltaje de la fotocelda
int photocellPin = A0;

void setup()
{
    //Configuracion serial   
    Serial.begin(9600);
}

void loop()
{
    int analogValue;
    int range;

    //Lectura de la fotocelda 
    analogValue = analogRead(photocellPin);
    //Reasignar el rango del sensor a un rango de cuatro opciones en la fotocelda
    range = map(analogValue, sensorMin, sensorMax, 0, 3);

    //Posibles acciones dependiendo del valor del rango
    switch (range) 
    {
        //Cuando se coloca la mano sobre el sensor 
        case 0:
            Serial.println("dark");
            break;
        //Cuando se coloca la mano cerca del sensor 
        case 1:
            Serial.println("dim");
            break;
        //Cuando se coloca la mano a cierta distancia del sensor
        case 2: 
            Serial.println("medium");
            break;
        //Cuando la mano se encuentra lejos del sensor 
        case 3:
            Serial.println("bright");
            break;
    }

    //Tiempo de espera antes de leer la fotocelda nuevamente 
    delay(250);
}
