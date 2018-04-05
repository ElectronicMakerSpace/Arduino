/*
 * Interruptor serial LED
 * Alterna los LED a través del serial usando el comando Switch Case, enviando los siguientes caracteres:
 * - r = Red
 * - y = Yellow
 * - g = Green
 * - w = white
 *Enviar cualquier caracterer diferente a los anteriores para apagar los cuatr LEDs
 */

//Relacion del Pin correspondiente a cada LED 
int LEDRedPin = 5;
int LEDYellowPin = 4;
int LEDGreenPin = 3;
int LEDWhitePin = 2;

void setup()
{
    //Configuracion serial
    Serial.begin(9600);

    //Establecer los cuatro pines LED en modo de salida
    pinMode(LEDRedPin, OUTPUT);
    pinMode(LEDYellowPin, OUTPUT);
    pinMode(LEDGreenPin, OUTPUT);
    pinMode(LEDWhitePin, OUTPUT);
}

void toggleLED(int LEDPin)
{
    //Para alternar el LED la variable se pasa como argumento
    digitalWrite(LEDPin, !digitalRead(LEDPin));
}

void loop()
{
    if (Serial.available() > 0)
    {
        //Se establece que unicamente se leerá un solo caracter
        int inByte = Serial.read();

        // Distintos casos, correspondientes a cada caracter
        switch (inByte)
        {
            //Si se recibe r, y, g, ó w se alterna al LED correspondiente utilizando las siguientes funciones
            case 'r':
                toggleLED(LEDRedPin);
                break;
            case 'y':
                toggleLED(LEDYellowPin);
                break;
            case 'g':
                toggleLED(LEDGreenPin);
                break;
            case 'w':
                toggleLED(LEDWhitePin);
                break;
            default:
                //Si se recibe cualquier otro caracter, los LEDs se apagaran 
                digitalWrite(LEDRedPin, LOW);
                digitalWrite(LEDYellowPin, LOW);
                digitalWrite(LEDGreenPin, LOW);
                digitalWrite(LEDWhitePin, LOW);
                break;
        }
    }
}
