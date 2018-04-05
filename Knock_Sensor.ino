/*
 * Knock Sensor
 * Imprime "Knock!" en el monitor serial cuando el buzzer detecta un golpe
*/

//Indica que el buzzer está conectado al pin analógico 0
int piezoPin = A0;
//Se establece el pin al que está conectado el LED
int ledPin = 2;
//Valor de umbral para decidir cuándo el sonido detectado es un knock o no lo es
const int threshold = 300; 

void setup()
{
    //Configuración del puerto serial
    Serial.begin(9600);
    
    //Configuracion del LED como salida
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    int analogValue;

    //Lectura del sensor que se almacena
    analogValue = analogRead(piezoPin);

    //Si la lectura del sensor es mayor que el umbral:
    if (analogValue > threshold)
    {
      //Envía la cadena "Knock!" volver a la computadora, seguido de una nueva línea
      Serial.println("Knock!");

      //Enciende el LED
      digitalWrite(ledPin, HIGH);

      //Tiempo de espera antes de que el LED se apague para poder observarlo iluminado
       delay(500);
       digitalWrite(ledPin, LOW);
    }

    //Lapso de tiempo para evitar sobrecargar el buffer del puerto serie
    delay(100);
}
