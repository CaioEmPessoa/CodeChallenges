
#include <stdio.h>
void clearScene(Screens screens) {
    C2D_TargetClear(screens.top, getColor("clear"));
    C2D_TargetClear(screens.bottom, getColor("clear"));

    // clear inputs etc..

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
    //     int* intialPos = drawSquare(deconvertPos('w', touch.px)-2, deconvertPos('h', touch.py)+5, 10, 10, getColor("purple"));
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
        store_touch_command(background, registerLineTouch, NULL, 0 );
    }
}