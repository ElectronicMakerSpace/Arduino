/*
 *LED Knight Rider
 * 
 *Demuestra el uso del ciclo for().
 *Enciende múltiples LEDs en secuencia, luego en reversa.
*/

//Se establece el tiempo en ms que cada LED permanece encendido (Se puede experimentar la velocidad de cambio variando este número)
int timer = 100;

void setup()
{
    //Se utiliza tilice un ciclo for para inicializar cada pin como salida
    for (int thisPin = 2; thisPin < 8; thisPin++)
    {
        pinMode(thisPin, OUTPUT);
    }
}

void loop()
{
    //Ciclo desde el pin menor al mayor
    for (int thisPin = 2; thisPin < 8; thisPin++)
    {
        //Se activa el Pin
        digitalWrite(thisPin, HIGH);
        //Tiempo de espera antes de apagarlo para poder observar el LED 
        delay(timer);
        //Se desactiva el Pin
        digitalWrite(thisPin, LOW);
    }

    //Ciclo desde el pin mayor al menor
    for (int thisPin = 7; thisPin > 1; thisPin--)
    {
        //Se activa el Pin
        digitalWrite(thisPin, HIGH);
        //Tiempo de espera antes de apagarlo para poder observar el LED 
        delay(timer);
        //Se desactiva el Pin
        digitalWrite(thisPin, LOW);
    }
}
