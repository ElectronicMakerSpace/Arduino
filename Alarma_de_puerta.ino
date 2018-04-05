/*
 * Door Alarm/Alarma de puerta
 * 
 * Reproduce una alarma cuando la distancia al telémetro ultrasónico cambia más que una tolerancia preestablecida. 
 * Colóquese enfrente de una puerta y presione el botón para establecer la distancia de la alarma. Abrir la puerta ahora sonará la alarma, 
 * la alarma no se detendrá hasta que la puerta esté cerrada.
 */

//Incluye nuestra lista de notas
#include "pitches.h"

//Se declaran los pines conectados al sensor ultrasónico
int echoPin = 4;
int trigPin = 5;

//Se declara el pin conectado al botón
int buttonPin = 2;

//Se declara el pin al que está conectado el speaker (altavoz)
int speakerPin = 8;

//La lectura de distancia tiene que cambiar más o menos que la distancia registrada y la tolerancia
float distance_to_door_tolerance = 10;

//La distancia a la puerta en cm
//-1 significa que aún no se ha establecido
float distance_to_door = -1;

//Las notas en la melodía y su duración en fracciones de segundo
//Por ejemplo negra = 4, octava nota = 8, etc.
const int melody[][2] = 
{
    {NOTE_D7, 4},
    {NOTE_A6, 4},
    {NOTE_BLANK, 4}
};

void play_alarm()
{
    //Se identifica el número de notas en la melodía
    int numberOfNotes = sizeof(melody) / sizeof(melody[0]);

    //Iteración de las notas de la melodía
    for (int thisNote = 0; thisNote < numberOfNotes; thisNote++)
    {
        //Se selecciona la nota y la duración de la nota de la matriz
        int thisNoteTone = melody[thisNote][0];
        int thisNoteDuration = melody[thisNote][1];

        //Se calcula la duración de la nota en ms
        int noteDurationMS = 1000 / thisNoteDuration;

        //Se toca la nota
        tone(speakerPin, thisNoteTone, noteDurationMS);

        //Para distinguir las notas, se establece un tiempo mínimo entre ellas.
        delay(noteDurationMS * 1.30);
    }
}

float get_distance_cm()
{
    float distanceCentimeters;
    int pulseLenMicroseconds;

   
    //Bit-bang una pequeña onda cuadrada en el "tring pin"  para iniciar el buscador de rango
    digitalWrite(trigPin, LOW);
    delayMicroseconds(20);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(100);
    digitalWrite(trigPin, LOW);

    //Se mide la longitud del pulso desde el pin de eco
    pulseLenMicroseconds = pulseIn(echoPin, HIGH);

    //Se calcula la distancia usando la velocidad del sonido
    distanceCentimeters = pulseLenMicroseconds / 29.387 / 2;

    return distanceCentimeters;
}

void setup()
{
    //Se establece el modo de pin en el eco ultrasónico y "tring pins"
    pinMode(echoPin, INPUT);
    pinMode(trigPin, OUTPUT);
    //Se configura el modo del botón para INPUT con pullup
    pinMode(buttonPin, INPUT_PULLUP);
}

void loop()
{
    int button;
    float distance;

    //Se lee el sensor ultrasónico
    distance = get_distance_cm();

    //Si la distancia es mayor o menor que la distancia de alarma preestablecida, y se ha establecido una distancia, suena la alarma.
    if (distance > distance_to_door + distance_to_door_tolerance
        || distance < distance_to_door - distance_to_door_tolerance)
    {
        if (distance_to_door != -1)
            play_alarm();
    }

    //Se lee el estado del botón
    button = digitalRead(buttonPin);

    //Si se presiona el botón, se configura la distancia hasta la última distancia leída
    if (button == LOW)
    {
        distance_to_door = distance;
    }
}
