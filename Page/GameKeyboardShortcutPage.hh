#pragma once

void gameKeyboarShortcut()
{
    is_keyBoard_shortcut_page = GL_TRUE;

    // Set the background
    glBegin(GL_QUADS);
        glColor4ub(39, 60, 117, 255);
        glVertex2f(width * 1.0f, height * 1.0f);
        glVertex2f(-width * 1.0f, height * 1.0f);

        glColor4ub(25, 42, 86, 255);
        glVertex2f(-width * 1.0f, -height * 1.0f);
        glVertex2f(width * 1.0f, -height * 1.0f);
    glEnd();

    Text(-560.0f, height * 1.0f - 100, "*Press L for Go back to Game Menu*", 0.4f);

    Text(-950.0f, height * 1.0f - 310, "Key", 0.3f);
    Text(-445.0f, height * 1.0f - 310, "Description", 0.3f);

    Text(-950.0f, height * 1.0f - 410, "arrow up / down", 0.25f);
    Text(-445.0f, height * 1.0f - 410, "Control left and right Bar", 0.25f);

    Text(-950.0f, height * 1.0f - 450, "arrow left / right", 0.25f);
    Text(-445.0f, height * 1.0f - 450, "Control top and bottom Bar", 0.25f);

    Text(-950.0f, height * 1.0f - 490, "0", 0.25f);
    Text(-445.0f, height * 1.0f - 490, "Change Frame rate to 15 FPS", 0.25f);

    Text(-950.0f, height * 1.0f - 530, "1", 0.25f);
    Text(-445.0f, height * 1.0f - 530, "Change Frame rate to 30 FPS", 0.25f);

    Text(-950.0f, height * 1.0f - 570, "2", 0.25f);
    Text(-445.0f, height * 1.0f - 570, "Change Frame rate to 60 FPS", 0.25f);

    Text(-950.0f, height * 1.0f - 610, "3", 0.25f);
    Text(-445.0f, height * 1.0f - 610, "Change Frame rate to 120 FPS", 0.25f);

    Text(-950.0f, height * 1.0f - 650, "4", 0.25f);
    Text(-445.0f, height * 1.0f - 650, "Change Frame rate to 144 FPS", 0.25f);

    Text(-950.0f, height * 1.0f - 690, "8", 0.25f);
    Text(-445.0f, height * 1.0f - 690, "Game Sound on", 0.25f);

    Text(-950.0f, height * 1.0f - 730, "9", 0.25f);
    Text(-445.0f, height * 1.0f - 730, "Game Sound off", 0.25f);

    Text(-950.0f, height * 1.0f - 770, "s", 0.25f);
    Text(-445.0f, height * 1.0f - 770, "Start the game", 0.25f);

    Text(-950.0f, height * 1.0f - 810, "p", 0.25f);
    Text(-445.0f, height * 1.0f - 810, "Pause the game", 0.25f);

    Text(-950.0f, height * 1.0f - 850, "r", 0.25f);
    Text(-445.0f, height * 1.0f - 850, "Resume the game", 0.25f);

    Text(-950.0f, height * 1.0f - 890, "n", 0.25f);
    Text(-445.0f, height * 1.0f - 890, "Play again / New game", 0.25f);

    Text(-950.0f, height * 1.0f - 930, "e", 0.25f);
    Text(-445.0f, height * 1.0f - 930, "Play Easy mode", 0.25f);

    Text(-950.0f, height * 1.0f - 970, "m", 0.25f);
    Text(-445.0f, height * 1.0f - 970, "Play Medium mode", 0.25f);

    Text(-950.0f, height * 1.0f - 1010, "h", 0.25f);
    Text(-445.0f, height * 1.0f - 1010, "Play Hard mode", 0.25f);

    Text(-950.0f, height * 1.0f - 1050, "Esc", 0.25f);
    Text(-445.0f, height * 1.0f - 1050, "Show menu page", 0.25f);

    Text(-950.0f, height * 1.0f - 1090, "k", 0.25f);
    Text(-445.0f, height * 1.0f - 1090, "Show keyboard page", 0.25f);

    Text(-950.0f, height * 1.0f - 1130, "l", 0.25f);
    Text(-445.0f, height * 1.0f - 1130, "Show menu page from keyboard page", 0.25f);

    Text(-950.0f, height * 1.0f - 1170, "c", 0.25f);
    Text(-445.0f, height * 1.0f - 1170, "Show cover page", 0.25f);

    Text(-950.0f, height * 1.0f - 1210, "x", 0.25f);
    Text(-445.0f, height * 1.0f - 1210, "Show settings page", 0.25f);

    Text(-950.0f, height * 1.0f - 1250, "q", 0.25f);
    Text(-445.0f, height * 1.0f - 1250, "Quite the game", 0.25f);

    glFlush();
}

/*


    Text(-560.0f, height * 1.0f - 100, "*Press L for Go back to Game Menu*", 0.4f);

    Text(-950.0f, height * 1.0f - 310, "Key", 0.3f);
    Text(-445.0f, height * 1.0f - 310, "Description", 0.3f);

    Text(-950.0f, height * 1.0f - 410, "0", 0.25f);
    Text(-445.0f, height * 1.0f - 410, "Change Frame rate to 15 FPS", 0.25f);

    Text(-950.0f, height * 1.0f - 470, "1", 0.25f);
    Text(-445.0f, height * 1.0f - 470, "Change Frame rate to 30 FPS", 0.25f);

    Text(-950.0f, height * 1.0f - 530, "2", 0.25f);
    Text(-445.0f, height * 1.0f - 530, "Change Frame rate to 60 FPS", 0.25f);

    Text(-950.0f, height * 1.0f - 590, "3", 0.25f);
    Text(-445.0f, height * 1.0f - 590, "Change Frame rate to 120 FPS", 0.25f);

    Text(-950.0f, height * 1.0f - 650, "4", 0.25f);
    Text(-445.0f, height * 1.0f - 650, "Change Frame rate to 144 FPS", 0.25f);

    Text(-950.0f, height * 1.0f - 710, "e", 0.25f);
    Text(-445.0f, height * 1.0f - 710, "Easy mode", 0.25f);

    Text(-950.0f, height * 1.0f - 770, "m", 0.25f);
    Text(-445.0f, height * 1.0f - 770, "Medium mode", 0.25f);

    Text(-950.0f, height * 1.0f - 830, "h", 0.25f);
    Text(-445.0f, height * 1.0f - 830, "Hard mode", 0.25f);

    Text(-950.0f, height * 1.0f - 890, "n", 0.25f);
    Text(-445.0f, height * 1.0f - 890, "New Game", 0.25f);

    Text(-950.0f, height * 1.0f - 950, "s", 0.25f);
    Text(-445.0f, height * 1.0f - 950, "Start The Game", 0.25f);

    Text(-950.0f, height * 1.0f - 1010, "p", 0.25f);
    Text(-445.0f, height * 1.0f - 1010, "Pause The Gmae", 0.25f);

    Text(-950.0f, height * 1.0f - 1070, "arrow up/down", 0.25f);
    Text(-445.0f, height * 1.0f - 1070, "Control left and right Bar", 0.25f);

    Text(-950.0f, height * 1.0f - 1130, "arrow left/right", 0.25f);
    Text(-445.0f, height * 1.0f - 1130, "Control top and bottom Bar", 0.25f);

    Text(-950.0f, height * 1.0f - 1190, "Esc", 0.25f);
    Text(-445.0f, height * 1.0f - 1190, "Game Settings", 0.25f);

    Text(-950.0f, height * 1.0f - 1250, "a", 0.25f);
    Text(-445.0f, height * 1.0f - 1250, "About page show all the information about the Group", 0.25f);

*/