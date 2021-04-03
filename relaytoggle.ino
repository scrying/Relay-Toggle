#include <ezButton.h>

#define NUM_INPUTPINS 4
#define NUM_OUTPUTPINS 4 
#define NUM_EZBUTTONS 4
#define DEBOUNCE 50

int inputPins[NUM_INPUTPINS] = {A0, A1, A2, A3};
int outputPins[NUM_OUTPUTPINS] = {0, 1, 2, 3};

ezButton b1(A0);
ezButton b2(A1);
ezButton b3(A2);
ezButton b4(A3);

ezButton ezbs[NUM_EZBUTTONS] = {b1, b2, b3, b4};
uint8_t ezbsState[NUM_EZBUTTONS] = {LOW};

void setup() {

    for (int i=0; i < (sizeof(outputPins) / sizeof(outputPins[0])); i++) {

        pinMode(outputPins[i], OUTPUT);

    }

    for (int i=0; i < (sizeof(ezbs) / sizeof(ezbs[0])); i++) {

        ezbs[i].setDebounceTime(DEBOUNCE);

    }

}

void loop() {

    for (int i=0; i < (sizeof(ezbs) / sizeof(ezbs[0])); i++) {

        ezbs[i].loop();

    }

    for (int i=0; i < (sizeof(ezbs) / sizeof(ezbs[0])); i++) {

        if (ezbs[i].isPressed()) {

            ezbsState[i] = !ezbsState[i];
            digitalWrite(outputPins[i], ezbsState[i]);

        }
        
    }

}