
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

    C2D_TextBuf textBuffer = C2D_TextBufNew(128);

    int* mainTitle = drawText(-60, 50, "Escolha o algoritimo:", textBuffer, 0.5);

    int* algo1Title = drawText(-120,  25, "Y - Desenhar Linha", textBuffer, 1);
    int* algo2Title = drawText(-120, -25, "X - Desenhar Cubos", textBuffer, 1);

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
     }
}

void LinesSpace(Screens screens, bool commandsValid) {
    clearScene(screens);

    // ----- TOP SCREEN -----
    C2D_SceneBegin(screens.top);
    selectedScreen = TOP;

    // Commands
    if(!commandsValid) {}

    // ----- BOTTOM SCREEN -----
    C2D_SceneBegin(screens.bottom);
    selectedScreen = BOTTOM;

    // Drawing elements
    int* background = drawSquare(-160, 120, 320, 240, getColor("pink"));

    C2D_TextBuf textBuffer = C2D_TextBufNew(128);

    drawText(90, -95,  "B - Sair", textBuffer, 0.5);
    drawText(90, -105, "X - Limpar", textBuffer, 0.5);

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
            setAlgo, &(parameter_t){.type = PARAM_CHAR, .value = {.int_val = 0}},
            1, (char*[]){"KEY_B"}, 1, false
        );
        store_button_command(
            removeLinesCommand, NULL,
            0, (char*[]){ "KEY_X"}, 1, false
        );
        store_touch_command(background, registerLineTouch, NULL, 0 );
    }
}

void CubesSpace(Screens screens, bool commandsValid) {
    clearScene(screens);

    // ----- TOP SCREEN -----
    C2D_SceneBegin(screens.top);
    selectedScreen = TOP;

    C2D_TextBuf textBuffer = C2D_TextBufNew(2048);

    drawText(-180, 80, "Coordenadas do Cubo:", textBuffer, 1);

    char buf[128];
    snprintf(buf, sizeof buf,
        "%s top_left : x=%d y=%d",
        tmpCubeCurrentStep == 1 ? ">" : " ",
        tmpCube.top_left.x,
        tmpCube.top_left.y
    );
    drawText(-180, 60, buf, textBuffer, 0.8);

    snprintf(buf, sizeof buf, "%s top_right: x=%d y=%d", tmpCubeCurrentStep == 2 ? ">" : " ", tmpCube.top_right.x, tmpCube.top_right.y);
    drawText(-180, 40, buf, textBuffer, 0.8);

    snprintf(buf, sizeof buf, "%s bot_right: x=%d y=%d", tmpCubeCurrentStep == 3 ? ">" : " ", tmpCube.bot_right.x, tmpCube.bot_right.y);
    drawText(-180, 20, buf, textBuffer, 0.8);

    snprintf(buf, sizeof buf, "%s bot_left : x=%d y=%d", tmpCubeCurrentStep == 4 ? ">" : " ", tmpCube.bot_left.x,  'h', tmpCube.bot_left.y);
    drawText(-180, 0, buf, textBuffer, 0.8);


    if (tmpCubeCurrentStep >= 5) {
        drawText(-180, -30, "Acoes do Cubo", textBuffer, 1);

        snprintf(buf, sizeof buf, "↑ ou ↓ escala = %f", tmpCube.scale);
        drawText(-180, -50, buf, textBuffer, 0.8);
        snprintf(buf, sizeof buf, "L ou R angulo = %d°", tmpCube.angle);
        drawText(-175, -70, buf, textBuffer, 0.8);
    }

    // Commands
    if(!commandsValid) {
        store_button_command(
            scaleCube, &(parameter_t){.type = PARAM_CHAR, .value = {.int_val = 1}},
            1, (char*[]){"KEY_DDOWN"}, 1, false
        );
        store_button_command(
            scaleCube, &(parameter_t){.type = PARAM_CHAR, .value = {.int_val = 2}},
            1, (char*[]){"KEY_DUP"}, 1, false
        );
        store_button_command(
            scaleCube, &(parameter_t){.type = PARAM_CHAR, .value = {.int_val = 1}},
            1, (char*[]){"KEY_CSTICK_DOWN"}, 1, true
        );
        store_button_command(
            scaleCube, &(parameter_t){.type = PARAM_CHAR, .value = {.int_val = 2}},
            1, (char*[]){"KEY_CSTICK_UP"}, 1, true
        );
        store_button_command(
            rotateCube, &(parameter_t){.type = PARAM_CHAR, .value = {.int_val = 1}},
            1, (char*[]){"KEY_L"}, 1, false
        );
        store_button_command(
            rotateCube, &(parameter_t){.type = PARAM_CHAR, .value = {.int_val = 2}},
            1, (char*[]){"KEY_R"}, 1, false
        );
        store_button_command(
            rotateCube, &(parameter_t){.type = PARAM_CHAR, .value = {.int_val = 1}},
            1, (char*[]){"KEY_CSTICK_LEFT"}, 1, true
        );
        store_button_command(
            rotateCube, &(parameter_t){.type = PARAM_CHAR, .value = {.int_val = 2}},
            1, (char*[]){"KEY_CSTICK_RIGHT"}, 1, true
        );
    }

    // ----- BOTTOM SCREEN -----
    C2D_SceneBegin(screens.bottom);
    selectedScreen = BOTTOM;

    // Drawing elements
    int* background = drawSquare(-160, 120, 320, 240, getColor("purple"));

    int* commandsHud1 = drawTextQuick(90, -95,  "B - Sair", 0.5);
    int* commandsHud2 = drawTextQuick(90, -105, "X - Limpar", 0.5);

    // if (tmpLine.start_x != 0) {
    //     int* intialPos = drawSquare(deconvertPos('w', touch.px)-2, deconvertPos('h', touch.py)+5, 10, 10, getColor("purple"));
    // }

    // if (!tmpLine.end_x) {
    //     int* intialPos = drawSquare(deconvertP172.20.20.194os('w', touch.px)-2, deconvertPos('h', touch.py)+5, 10, 10, getColor("purple"));
    // }

    // cubePreview
    drawCube(tmpCube, tmpCubeCurrentStep);

    for (int i=0; i<=lastCubeIndex; i++) {
        Cube cCube = cubes[i]; // c = current
        drawCube(cCube, 5);
    }

    // Commands
    if(!commandsValid) {
        store_button_command(
            setAlgo, &(parameter_t){.type = PARAM_CHAR, .value = {.int_val = 0}},
            1, (char*[]){"KEY_B"}, 1, false
        );
        store_button_command(
            setNextStep, NULL,
            0, (char*[]){"KEY_A"}, 1, false
        );
        store_button_command(
            removeCubesCommand, NULL,
            0, (char*[]){ "KEY_X"}, 1, false
        );
        store_touch_command(background, registerCubeVerticesTouch, NULL, 0 );
    }
}