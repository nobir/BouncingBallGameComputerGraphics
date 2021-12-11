#pragma once

void gameSettingsPage()
{
    is_settings_page = GL_TRUE;

    // Set the background
    glBegin(GL_QUADS);
        glColor4ub(39, 60, 117, 255);
        glVertex2f(width * 1.0f, height * 1.0f);
        glVertex2f(-width * 1.0f, height * 1.0f);

        glColor4ub(25, 42, 86, 255);
        glVertex2f(-width * 1.0f, -height * 1.0f);
        glVertex2f(width * 1.0f, -height * 1.0f);
    glEnd();

    Text(-250.0f, height * 1.0f - 510, "Settings", 0.4f);

    if (is_sound)
    {
        Text(-250.0f, height * 1.0f - 710, "Sound On", 0.4f);
    }
    else
    {
        Text(-250.0f, height * 1.0f - 710, "Sound Off", 0.4f);
    }

    if (is_keyBoard_shortcut_page)
    {
        gameKeyboarShortcut();
        return;
    }

    glFlush();
}