#pragma once

void gameMenuPage()
{
    is_menu_page = GL_TRUE;

    // Set the background
    glBegin(GL_QUADS);
        glColor4ub(39, 60, 117, 255);
        glVertex2f(width * 1.0f, height * 1.0f);
        glVertex2f(-width * 1.0f, height * 1.0f);

        glColor4ub(25, 42, 86, 255);
        glVertex2f(-width * 1.0f, -height * 1.0f);
        glVertex2f(width * 1.0f, -height * 1.0f);
    glEnd();

    RGBA text_color1 = {241, 196, 15};

    // Text(0, 0, "*Press K for Keyboard shortcut*");
    Text(-560.0f, height * 1.0f - 100, "*Press K for Keyboard shortcut*", 0.4f);

    Text(-250.0f, height * 1.0f - 510, "Game Menu", 0.4f);
    if (easy_mode || medium_mode || hard_mode)
    {
        Text(-160.0f, height * 1.0f - 610, "Resume", 0.4f, text_color1);
        Text(-220.0f, height * 1.0f - 680, "New Game", 0.4f, text_color1);
    }
    else
    {
        Text(-140.0f, height * 1.0f - 610, "Easy", 0.4f, text_color1);
        Text(-180.0f, height * 1.0f - 680, "Medium", 0.4f, text_color1);
        Text(-140.0f, height * 1.0f - 740, "Hard", 0.4f, text_color1);
    }
    Text(-220.0f, height * 1.0f - 800, "Settings", 0.4f, text_color1);
    Text(-155.0f, height * 1.0f - 860, "Quit", 0.4f, text_color1);
    Text(-420.0f, height * 1.0f - 980, "About Team Glacier", 0.4f, text_color1);

    // if (is_keyBoard_shortcut_page)
    // {
    //     gameKeyboarShortcut();
    //     return;
    // }

    glFlush();
}