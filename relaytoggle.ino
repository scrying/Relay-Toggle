#include <ezButton.h>

#define ARRAYSIZE(x) ((sizeof(x) / sizeof(*(x))))

#define NUM_INPUTPINS 4
int inputPins[NUM_INPUTPINS] = {A0, A1, A2, A3};

#define NUM_OUTPUTPINS 4 
int outputPins[NUM_OUTPUTPINS] = {0, 1, 2, 3};

ezButton b0(A0);
ezButton b1(A1);
ezButton b2(A2);
ezButton b3(A3);

#define NUM_BUTTONS 4
ezButton buttons[NUM_BUTTONS] = {b0, b1, b2, b3};
uint8_t buttonStates[NUM_BUTTONS] = {LOW};

#define DEBOUNCE 50

void setup() {

    for (int i=0; i < ARRAYSIZE(outputPins); i++) {

        pinMode(outputPins[i], OUTPUT);

    }

    for (int i=0; i < ARRAYSIZE(buttons); i++) {

        buttons[i].setDebounceTime(DEBOUNCE);

    }

}

void loop() {

    for (int i=0; i < ARRAYSIZE(buttons); i++) {

        buttons[i].loop();
        if (buttons[i].isPressed()) {

            buttonStates[i] = !buttonStates[i];
            digitalWrite(outputPins[i], buttonStates[i]);

        }
        
    }

}