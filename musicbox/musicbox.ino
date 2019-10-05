#include "pitches.h"
#include "button.h"
#include "buzzer.h"

#define PIN_BUTTON_MEL_ONE 3
#define PIN_BUTTON_OFF 5
#define PIN_BUTTON_SPEED 4
#define PIN_BUZZER 6

Button buttonMelodyOne(PIN_BUTTON_MEL_ONE);
Button buttonOff(PIN_BUTTON_OFF);
Button buttonSpeed(PIN_BUTTON_SPEED);
Buzzer buzzer(PIN_BUZZER);

int notes[] = {NOTE_FS5, NOTE_CS6, NOTE_GS5, NOTE_SILENCE, NOTE_A5, NOTE_A5, NOTE_FS5, NOTE_CS6, NOTE_GS5, NOTE_A5, NOTE_B5, NOTE_A5, NOTE_FS5, NOTE_GS5, NOTE_E5, NOTE_D5, NOTE_E5, NOTE_FS5, NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_E5};
double durations[] = {6, 6, 12, 2, 4, 4, 6, 6, 9, 5, 5, 6, 6, 12, 6, 6, 6, 12, 6, 6, 6, 6};
int melodyLength = 22;

unsigned long speeds[] = {25, 50, 100, 200, 400, 800};
int currentSpeed = 2;
int speedsLength = 6;

// maybe somewhere in the future we will have one more button...
 #define PIN_BUTTON_MEL_TWO 4
 Button buttonMelodyTwo(PIN_BUTTON_MEL_TWO);

// and the second melody
 int notes2[] = {NOTE_C4, NOTE_SILENCE, NOTE_G4, NOTE_SILENCE};
 double durations2[] = {4, 1, 4, 1};
 int melodyLength2 = 4;

void setup()
{
    buzzer.setMelody(notes, durations, melodyLength);
}

void loop()
{
    buzzer.playSound();

    if (buttonOff.wasPressed())
    {
        buzzer.turnSoundOff();
    }

    if (buttonMelodyOne.wasPressed())
    {
        buzzer.setMelody(notes, durations, melodyLength);
        buzzer.turnSoundOn();
    }

    if (buttonSpeed.wasPressed())
    {
        currentSpeed = (currentSpeed + 1)%speedsLength;
        buzzer.setNoteDuration(speeds[currentSpeed]);
    }
}
