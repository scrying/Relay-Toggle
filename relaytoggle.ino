#include <ezButton.h>

#define ARRAYSIZE(x) ((sizeof(x) / sizeof(*(x))))

/*  Declare Input Pins
`*
 *  NUM_INPUTPINS must match the number of pins in
 *  the array
 * 
 */
#define NUM_INPUTPINS 4
int inputPins[NUM_INPUTPINS] = {A0, A1, A2, A3};

/*  Declare Output Pins
 *
 *  NUM_OUTPUTPINS must match the number of pins in
 *  the array
 * 
 */
#define NUM_OUTPUTPINS 4 
int outputPins[NUM_OUTPUTPINS] = {0, 1, 2, 3};

/*  Assign Input Pins to Buttons
 *
 *  Assign input pins to buttons here in the form of:
 *      ezButton buttonName(inputPin)
 * 
 */
ezButton b0(A0);
ezButton b1(A1);
ezButton b2(A2);
ezButton b3(A3);

/*  Add Buttons 
 *
 *  Add button names to be used
 *  NUM_BUTTONS must match the number of buttons in 
 *  the array
 * 
 */
#define NUM_BUTTONS 4
ezButton buttons[NUM_BUTTONS] = {b0, b1, b2, b3};

/*  Initialize Button State  */
uint8_t buttonStates[NUM_BUTTONS] = {LOW};

/*  Set ezButton Debounce Time in Milliseconds  */
#define DEBOUNCE 50

/*  Initialize Arduino Pins  */
void setup() {

    /*  Initialize Output Pins  */
    for (int i=0; i < ARRAYSIZE(outputPins); i++) {

        pinMode(outputPins[i], OUTPUT);

    }

    /*  Initialize ezButton Debounce Time in Milliseconds  */
    for (int i=0; i < ARRAYSIZE(buttons); i++) {

        buttons[i].setDebounceTime(DEBOUNCE);

    }

}

/*  Main Program  */
void loop() {

    for (int i=0; i < ARRAYSIZE(buttons); i++) {

        buttons[i].loop();
        
        /*  ** Add And Remove Functionality Here **
         *
         *  Code can be modified between start and end 
         * 
         */
        //  Code Start
        if (buttons[i].isPressed()) {

            buttonStates[i] = !buttonStates[i];
            digitalWrite(outputPins[i], buttonStates[i]);

        }
        //  Code End 
    }

}