#pragma once

void gameCoverPage()
{
    is_cover_page = GL_TRUE;

    // Set the background
    glBegin(GL_QUADS);
        glColor4ub(39, 60, 117, 255);
        glVertex2f(width * 1.0f, height * 1.0f);
        glVertex2f(-width * 1.0f, height * 1.0f);

        glColor4ub(25, 42, 86, 255);
        glVertex2f(-width * 1.0f, -height * 1.0f);
        glVertex2f(width * 1.0f, -height * 1.0f);
    glEnd();

    Text(-215.0f, height * 1.0f - 150, "Computer Graphics[M]", 0.3f, {241, 196, 15, 255});
    Text(-120.0f, height * 1.0f - 210, "Bouncing Ball", 0.3f, {241, 196, 15, 255});
    Text(-110.0f, height * 1.0f - 270, "Submitted by", 0.3f, {241, 196, 15, 255});
    Text(-160.0f, height * 1.0f - 330, "Team Glacier [G7]", 0.3f, {241, 196, 15, 255});

    Text(-720.0f, height * 1.0f - 510, "ID", 0.3f, {241, 196, 15, 255});
    Text(-300.0f, height * 1.0f - 510, "Name", 0.3f, {241, 196, 15, 255});
    Text(550.0f, height * 1.0f - 510, "Contribution", 0.3f, {241, 196, 15, 255});

    Text(-720.0f, height * 1.0f - 610, "19-41135-2", 0.3f, {241, 196, 15, 255});
    Text(-300.0f, height * 1.0f - 610, "Samuel, Nobir Hossain", 0.3f, {241, 196, 15, 255});
    Text(550.0f, height * 1.0f - 610, "30%", 0.3f, {241, 196, 15, 255});

    Text(-720.0f, height * 1.0f - 670, "19-39517-1", 0.3f, {241, 196, 15, 255});
    Text(-300.0f, height * 1.0f - 670, "Rahat, MD. Mohibor Rahman", 0.3f, {241, 196, 15, 255});
    Text(550.0f, height * 1.0f - 670, "28%", 0.3f, {241, 196, 15, 255});

    Text(-720.0f, height * 1.0f - 730, "19-41154-2", 0.3f, {241, 196, 15, 255});
    Text(-300.0f, height * 1.0f - 730, "Sajjad, Nahian", 0.3f, {241, 196, 15, 255});
    Text(550.0f, height * 1.0f - 730, "21%", 0.3f, {241, 196, 15, 255});

    Text(-720.0f, height * 1.0f - 790, "19-39501-1", 0.3f, {241, 196, 15, 255});
    Text(-300.0f, height * 1.0f - 790, "Moni, Khuko", 0.3f, {241, 196, 15, 255});
    Text(550.0f, height * 1.0f - 790, "21%", 0.3f, {241, 196, 15, 255});

    Text(-110.0f, height * 1.0f - 1090, "Submitted to", 0.3f, {241, 196, 15, 255});
    Text(-160.0f, height * 1.0f - 1150, "Mahfujur Rahman", 0.3f, {241, 196, 15, 255});
    Text(-260.0f, height * 1.0f - 1210, "Faculty of Science and Technology", 0.2f, {241, 196, 15, 255});
    Text(-310.0f, height * 1.0f - 1270, "American International University-Bangladesh", 0.175f, {241, 196, 15, 255});

    if (is_keyBoard_shortcut_page)
    {
        gameKeyboarShortcut();
        return;
    }

    glFlush();
}