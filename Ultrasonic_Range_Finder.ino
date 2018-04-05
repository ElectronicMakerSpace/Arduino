/*
 *Ultrasonic Range Finder/Buscador de rango ultrasónico
 * Imprime la distancia medida desde el buscador de rango a través del monitor serial. Coloque la placa en su escritorio y abra el monitor serial. 
 * Mueva un objeto en frente del sensor ultrasónico y verá la distancia al objeto impreso a través del moitor serial.
*/

//Se establecen los pines conectados al sensor ultrasónico
int echoPin = 4;
int trigPin = 5;

void setup()
{
      //Configuracion del puerto serial
      Serial.begin(9600);
      //Se configura el modo pin en el eco ultrasónico y pines tric
      pinMode(echoPin, INPUT);
      pinMode(trigPin, OUTPUT);
}

void loop()
{
    float distanceCentimeters;
    int pulseLenMicroseconds;

    //Bit-bang una pequeña onda cuadrada en el "trig pin" para iniciar el buscador de rango
    digitalWrite(trigPin, LOW);
    delayMicroseconds(20);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(100);
    digitalWrite(trigPin, LOW);

    //Se mide la longitud del pulso desde el pin de eco
    pulseLenMicroseconds = pulseIn(echoPin, HIGH);

    //Se calcula la distancia usando la velocidad del sonido
    distanceCentimeters = pulseLenMicroseconds / 29.387 / 2;

    //Se imprime la distancia calculada en el monitor serial
    Serial.println(distanceCentimeters);

    delay(100);
}
