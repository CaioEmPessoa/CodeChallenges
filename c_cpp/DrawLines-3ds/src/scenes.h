
#include <stdio.h>
void clearScene(Screens screens) {
    C2D_TargetClear(screens.top, getColor("clear"));
    C2D_TargetClear(screens.bottom, getColor("clear"));

    // clear inputs etc..

}

void AlgoChoice(Screens screens, bool commandsValid) {
    clearScene(screens);

    // ----- TOP SCREEN -----
    C2D_SceneBegin(screens.top);
    selectedScreen = TOP;

    int* mainTitle = drawText(-40, 50, "Escolha o algoritimo", 0.5);

    int* algo1Title = drawText(-100, 0, "1 - y", 1);
    int* algo2Title = drawText(-0  , 0, "2 - x", 1);
    int* algo3Title = drawText(100 , 0, "3 - a", 1);

    // Commands
    if(!commandsValid) {
        store_button_command(
            setAlgo, &(parameter_t){.type = PARAM_CHAR, .value = {.int_val = 1}},
            1, (char*[]){"KEY_Y"}, 1, false
        );
        store_button_command(
            setAlgo, &(parameter_t){.type = PARAM_CHAR, .value = {.int_val = 2}},
            1, (char*[]){"KEY_X"}, 1, false
        );
        store_button_command(
            setAlgo, &(parameter_t){.type = PARAM_CHAR, .value = {.int_val = 3}},
            1, (char*[]){"KEY_A"}, 1, false
        );

     }
}

void LinesSpace(Screens screens, bool commandsValid) {
    clearScene(screens);

    // ----- TOP SCREEN -----
    C2D_SceneBegin(screens.top);
    selectedScreen = TOP;

    // Commands
    if(!commandsValid) { }

    // ----- BOTTOM SCREEN -----
    C2D_SceneBegin(screens.bottom);
    selectedScreen = BOTTOM;

    // Drawing elements
    int* background = drawSquare(-160, -120, 320, 240, getColor("pink"));

    // if (tmpLine.start_x != 0) {
    //     int* intialPos = drawSquare(deconvertPos('w', touch.px)-2, deconvertPos('h', touch.py)+5, 10, 10, getColor("purple"));
    // }

    // if (!tmpLine.end_x) {
    //     int* intialPos = drawSquare(deconvertP172.20.20.194os('w', touch.px)-2, deconvertPos('h', touch.py)+5, 10, 10, getColor("purple"));
    // }

    for (int i=0; i<=lastLineIndex; i++) {
        Line cLine = lines[i]; // c = current

        drawLine(
            deconvertPos('w', cLine.start_x),
            deconvertPos('h', cLine.start_y),
            deconvertPos('w', cLine.end_x),
            deconvertPos('h', cLine.end_y),
            getColor("black"),
            10
        );
    }

    // Commands
    if(!commandsValid) {
        store_button_command(
            removeLinesCommand, NULL,
            0, (char*[]){"KEY_B", "KEY_DUP"}, 2, false
        );
        store_button_command(
            setAlgo, &(parameter_t){.type = PARAM_CHAR, .value = {.int_val = 0}},
            1, (char*[]){"KEY_ZR"}, 1, false
        );
        store_touch_command(background, registerLineTouch, NULL, 0 );
    }
}