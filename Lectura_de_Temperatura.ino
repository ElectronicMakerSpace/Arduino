/*
 * Reading Temperature/Lectura de Temperatura
 * 
 * Lee la temperatura en centígrado sobre el serial.
*/

//Se establece el pin de salida del sensor de temperatura LM35
int lm35Pin = A0;

void setup()
{
    //Configurar el puerto serial
    Serial.begin(9600);
}

void loop()
{ 
    int analogValue;
    float temperature;

    //Se lee el sensor de temperatura
    analogValue = analogRead(lm35Pin);

    //Se convierte el valor analógico de 10 bit a celsius
    temperature = float(analogValue) / 1023;
    temperature = temperature * 500;

    //Se imprime la temperatura en el monitor serial
    Serial.print("Temp: ");
    Serial.print(temperature);
    Serial.println("C");
    
    //Espera de 1 segundo antes de leer la temperatura nuevamente
    delay(1000);
}

