/*
 * Seguidor de Tono
 *  Reproduce un tono variable a través del altavoz. El tono sigue la luz presente en la fotocelda. Cubra la luz y el tono bajará, si hay más luz y aumentará.
*/

//Se establece el pin al que está conectado el altavoz
int speakerPin = 8;
//Se establece el pin divisor de voltaje de la fotocelda
int photocellPin = A0;


//Valor del sensor mínimo
const int sensorMin = 0;
//Valor del sensor máximo
const int sensorMax = 600;
//El tono más bajo posible
const int lowestPitch = 150;
//El tono mayor posible
const int highestPitch = 1000;

void setup()
{
    //No es necesario hacer nada en esta parte
}

void loop()
{
    int analogValue;
    int pitch;

    //Lectura de la fotocelda
    analogValue = analogRead(photocellPin);

    //Mapear el rango de entrada analógica al rango de tono de salida
    pitch = map(analogValue, sensorMin, sensorMax, lowestPitch, highestPitch);

    //Se toca el tono
    tone(speakerPin, pitch);
}
