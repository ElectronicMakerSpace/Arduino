/*
 * Melodía
 * Reproduce una melodía a través de un speaker(altavoz).
*/

//incluye lista de lanzamientos de notas
#include "pitches.h"

//Se establece el pin al que está conectado el altavoz
int speakerPin = 8;

//Variable para especificar las notas de la melodía y su duración en fracciones de segundo
// por ejemplo negra = 4, octava nota = 8, etc.
const int melody[][2] = 
{
    {NOTE_C4, 4},
    {NOTE_G3, 8},
    {NOTE_G3, 8},
    {NOTE_A3, 4},
    {NOTE_G3, 4},
    {NOTE_BLANK, 4},
    {NOTE_B3, 4},
    {NOTE_C4, 4}
};

void setup()
{
    //Identificar el número de notas en nuestra melodía
    int numberOfNotes = sizeof(melody) / sizeof(melody[0]);

    //Iteración sobre las notas de la melodía
    for (int thisNote = 0; thisNote < numberOfNotes; thisNote++)
    {
        //Se toma la nota y la duración de la nota de la matriz
        int thisNoteTone = melody[thisNote][0];
        int thisNoteDuration = melody[thisNote][1];
  
        //Variable para calcular la duración de la nota en ms
        int noteDurationMS = 1000 / thisNoteDuration;

        //Se toca la nota
        tone(speakerPin, thisNoteTone, noteDurationMS);

       //Para distinguir las notas, se establece un tiempo mínimo entre ellas
        delay(noteDurationMS * 1.30);
    }
}

void loop()
{ 
//Si no es necesario repetir la melodía, en esta parte no se hace nada 
}
