#pragma once

void gameOverPage()
{
    is_game_over = GL_TRUE;

    // Set the background
    glBegin(GL_QUADS);
        glColor4ub(39, 60, 117, 180);
        glVertex2f(width * 1.0f, height * 1.0f);
        glVertex2f(-width * 1.0f, height * 1.0f);

        glColor4ub(25, 42, 86, 180);
        glVertex2f(-width * 1.0f, -height * 1.0f);
        glVertex2f(width * 1.0f, -height * 1.0f);
    glEnd();

    RGBA text_color1 = {241, 196, 15};

    Text(-width + 600.0f, 300.0f, "Point: ");
    Text(-width + 850.0f, 300.0f, to_string(point).c_str());
    Text(width - 850.0f, 300.0f, "Speed: ");
    Text(width - 650.0f, 300.0f, getNumberWithFixedPrecision(ball1.speed, 1).c_str());

    Text(-500.0f, 0.0f, "Game Over", 1.0f, {214, 48, 49, 255});
    Text(-220.0f, -150.0f, "Play Again", 0.4f, text_color1);
    Text(-100.0f, -220, "Quit", 0.4f, text_color1);

    if (is_keyBoard_shortcut_page)
    {
        gameKeyboarShortcut();
        return;
    }

    glFlush();
}