#pragma once

void gamePage()
{
    is_game_page = GL_TRUE;

    // Set the background
    drawQuad(
        {-width * 1.0f, -height * 1.0f},
        {width * 1.0f, -height * 1.0f},
        {width * 1.0f, height * 1.0f},
        {-width * 1.0f, height * 1.0f},
        {47, 54, 64, 255});

    // Bar X 1
    glPushMatrix();

        glTranslatef(barX1.positionX, barX1.positionY, 0.0f);

        drawQuad(barX1.p1, barX1.p2, barX1.p3, barX1.p4, barX1.rgbaColor);

        drawFilledCircle({(barX1.p1.x + barX1.p4.x) / 2.0f, (barX1.p1.y + barX1.p4.y) / 2.0f}, 25.0f, barX1.rgbaColor);
        drawFilledCircle({(barX1.p2.x + barX1.p3.x) / 2.0f, (barX1.p2.y + barX1.p3.y) / 2.0f}, 25.0f, barX1.rgbaColor);

    glPopMatrix();

    // Bar X 2
    glPushMatrix();

        glTranslatef(barX2.positionX, barX2.positionY, 0.0f);

        drawQuad(barX2.p1, barX2.p2, barX2.p3, barX2.p4, barX2.rgbaColor);

        drawFilledCircle({(barX2.p1.x + barX2.p4.x) / 2.0f, (barX2.p1.y + barX2.p4.y) / 2.0f}, 25.0f, barX2.rgbaColor);
        drawFilledCircle({(barX2.p2.x + barX2.p3.x) / 2.0f, (barX2.p2.y + barX2.p3.y) / 2.0f}, 25.0f, barX2.rgbaColor);

    glPopMatrix();

    // Bar Y 1
    glPushMatrix();

        glTranslatef(barY1.positionX, barY1.positionY, 0.0f);

        drawQuad(barY1.p1, barY1.p2, barY1.p3, barY1.p4, barY1.rgbaColor);

        drawFilledCircle({(barY1.p1.x + barY1.p2.x) / 2.0f, (barY1.p1.y + barY1.p2.y) / 2.0f}, 25.0f, barY1.rgbaColor);
        drawFilledCircle({(barY1.p3.x + barY1.p4.x) / 2.0f, (barY1.p3.y + barY1.p4.y) / 2.0f}, 25.0f, barY1.rgbaColor);

    glPopMatrix();

    // Bar Y 1
    glPushMatrix();

        glTranslatef(barY2.positionX, barY2.positionY, 0.0f);

        drawQuad(barY2.p1, barY2.p2, barY2.p3, barY2.p4, barY2.rgbaColor);

        drawFilledCircle({(barY2.p1.x + barY2.p2.x) / 2.0f, (barY2.p1.y + barY2.p2.y) / 2.0f}, 25.0f, barY2.rgbaColor);
        drawFilledCircle({(barY2.p3.x + barY2.p4.x) / 2.0f, (barY2.p3.y + barY2.p4.y) / 2.0f}, 25.0f, barY2.rgbaColor);

    glPopMatrix();

    // Bouncing Ball 1
    glPushMatrix();

        glTranslatef(ball1.positionX, ball1.positionY, 0.0f);

        drawFilledCircle(ball1.p, ball1.radius, ball1.rgbaColor);

    glPopMatrix();

    // Border left
    drawQuad(
        {-(width + gutter) * 1.0f, -(height + gutter) * 1.0f},
        {-width * 1.0f, -(height + gutter) * 1.0f},
        {-width * 1.0f, (height + gutter) * 1.0f},
        {-(width + gutter) * 1.0f, (height + gutter) * 1.0f},
        {34, 47, 62, 255});
    // Border right
    drawQuad(
        {width * 1.0f, -(height + gutter) * 1.0f},
        {(width + gutter) * 1.0f, -(height + gutter) * 1.0f},
        {(width + gutter) * 1.0f, (height + gutter) * 1.0f},
        {width * 1.0f, (height + gutter) * 1.0f},
        {34, 47, 62, 255});
    // Border top
    drawQuad(
        {-(width + gutter) * 1.0f, height * 1.0f},
        {(width + gutter) * 1.0f, height * 1.0f},
        {(width + gutter) * 1.0f, (height + gutter) * 1.0f},
        {-(width + gutter) * 1.0f, (height + gutter) * 1.0f},
        {34, 47, 62, 255});
    // Border bottom
    drawQuad(
        {-(width + gutter) * 1.0f, -height * 1.0f},
        {(width + gutter) * 1.0f, -height * 1.0f},
        {(width + gutter) * 1.0f, -(height + gutter) * 1.0f},
        {-(width + gutter) * 1.0f, -(height + gutter) * 1.0f},
        {34, 47, 62, 255});

    if (easy_mode)
    {
        Text(-width, height + gutter / 3, "Easy Mode");
    }
    else if (medium_mode)
    {
        Text(-width, height + gutter / 3, "Medium Mode");
    }
    else if (hard_mode)
    {
        Text(-width, height + gutter / 3, "Hard Mode");
    }

    Text(-width + 600.0f, height + gutter / 3, "Point: ");
    Text(-width + 850.0f, height + gutter / 3, to_string(point).c_str());
    Text(width - 850.0f, height + gutter / 3, "Life: ");
    Text(width - 650.0f, height + gutter / 3, to_string(life).c_str());
    Text(width - 400.0f, height + gutter / 3, "Speed: ");
    Text(width - 100.0f, height + gutter / 3, getNumberWithFixedPrecision(ball1.speed, 1).c_str());

    // debugDrawLines(
    //     ballp1, ballp2,
    //     ballp3, ballp4,
    //     ballp5, ballp6,
    //     ballp7, ballp8,

    //     barxp1, barxp2,
    //     barxp3, barxp4,
    //     barxp5, barxp6,
    //     barxp7, barxp8,

    //     baryp1, baryp2,
    //     baryp3, baryp4,
    //     baryp5, baryp6,
    //     baryp7, baryp8);

    // drawLine(_p1, _p2);

    glFlush();
}