/*
 * Grafico de barras LED
 * 
 * Enciende una serie de LED en función del valor de un sensor analógico.
 * Esta es una manera simple de hacer una visualización de gráfico de barras. Aunque este gráfico usa 6 LEDs, puede usar cualquier número cambiando el conteo de LEDs
 */

// Establecer el pin al que está conectado el potenciómetro
int potPin = A0;
// Se crea una matriz con los números de pin a los que están conectados los LEDs
// Si se desea agregar más LEDs, solo se anexan en la matriz
int ledPins[] = {2, 3, 4, 5, 6, 7};
//Variable correspondiente a la cantidad de LEDs en el gráfico de barras
int ledCount = sizeof(ledPins) / sizeof(ledPins[0]);

void setup()
{
  //En un ciclo for se inicializa cada pin como salida
    for (int thisLed = 0; thisLed < ledCount; thisLed++)
    {
        pinMode(ledPins[thisLed], OUTPUT);
    }
}

void loop()
{
    //Variable correspondiente a la lectura del potenciómetro
    int potReading = analogRead(potPin);
    //Se asigna el resultado a un rango de 0 a la cantidad de LEDs que se encuentran conectados
    int ledLevel = map(potReading, 0, 1023, 0, ledCount);

    //Ciclo sobre el conjunto de LED:
    for (int thisLed = 0; thisLed < ledCount; thisLed++)
    {
      //Si el índice de los elementos de la matriz es menor que "ledLevel" cambia el pin para este elemento
        if (thisLed < ledLevel)
        {
            digitalWrite(ledPins[thisLed], HIGH);
        }
        //Se apagan todos los pines más altos que "ledLevel"
        else
        {
            digitalWrite(ledPins[thisLed], LOW);
        }
    }
}
