/*
 * Interruptor de luz automático
 * Enciende automáticamente un LED cuando oscurece.
*/

//Se define una constante que describe cuándo está lo suficientemente oscuro para encender el LED
const int sensorDark = 500;

//Pin correspondiente al divisor de votalje de la fotocelda
int photocellPin = A0;
//Pin correspondiente al LED
int LEDPin = 2;

void setup()
{
    //Se inicializa el pin corespondiente al LED como salida
    pinMode(LEDPin, OUTPUT);
}

void loop()
{
    int analogValue;

    //Lectura de la fotocelda
    analogValue = analogRead(photocellPin);

    //Cuanto mayor sea la lectura del valor analógico, más oscuro será.
    //Si la lectura es al menos tan oscuro como la constante "sensorDark", se enciende el LED
    if (analogValue < sensorDark)
    {
        digitalWrite(LEDPin, HIGH);
    }
    //En caso cotrario se apaga el LED
    else
    {
        digitalWrite(LEDPin, LOW);
    }

    //Espere 1 ms para obtener mejores lecturas del sensor de calidad
    delay(1);
}
