/*
 *Using the LCD/Usando el LCD
 * 
 *Demuestra el uso de una pantalla LCD de 16x2. La libreria LiquidCrystal funciona con todas las pantallas LCD que son compatibles con el controlador Hitachi HD44780. 
 *Ajuste el contraste de las pantallas LCD con el potenciómetro hasta que pueda ver los caracteres en la pantalla LCD.
*/

//incluye la Libreria
#include <LiquidCrystal.h>

//Se declaran todos los pines del LCD
int lcdRSPin = 12;
int lcdEPin = 11;
int lcdD4Pin = 5;
int lcdD5Pin = 4;
int lcdD6Pin = 3;
int lcdD7Pin = 2;

//Se inicializa la libreria con los números de los pines de interfaz
LiquidCrystal lcd(lcdRSPin, lcdEPin, lcdD4Pin, lcdD5Pin, lcdD6Pin, lcdD7Pin);

void setup()
{
    //Se configura el número de columnas y filas de la pantalla LCD:
    lcd.begin(16, 2);

    //Se imprime un mensaje en la pantalla LCD.
    lcd.print("Hola mundo");
}

void loop()
{
    //Se coloca el cursor en la columna 0, línea 1. (NOTA: la línea 1 es la segunda fila, ya que el conteo comienza con 0)
    lcd.setCursor(0, 1);

    //Se imprime la cantidad de segundos desde el reinicio
    lcd.print(millis() / 1000);
}
