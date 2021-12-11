// #pragma once

#include <bits/stdc++.h>
#include <windows.h>
#include <mmsystem.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include "core/Component.hh"

#include "model/Ball.hh"
#include "model/Bar.hh"

using namespace std;

GLint width = 1280;
GLint height = 720;
GLint gutter = 100;

GLint point = 0;
GLint _collision = 0;
GLint life = 3;

GLint ball_opacity_hard_mode = 255;
GLboolean ball_opacity_hard_mode_go_up = GL_FALSE;
GLboolean ball_opacity_hard_mode_go_down = GL_TRUE;

GLint frame_rate_15 = 66; // 1000 / 15    = 66.67   -> 66ms
GLint frame_rate_30 = 32; // 1000 / 30    = 33.33   -> 32ms
GLint frame_rate_60 = 16; // 1000 / 60    = 16.67   -> 16ms
GLint frame_rate_120 = 8; // 1000 / 120   = 8.33    -> 8ms
GLint frame_rate_144 = 7; // 1000 / 144   = 6.94    -> 6ms
// GLint frame_rate_244 = 4;   // 1000 / 144   = 6.94    -> 6ms

GLint cfr = frame_rate_60; // Current frame rate

GLboolean is_started = GL_FALSE;
GLboolean is_collision = GL_FALSE;
GLboolean is_new_game = GL_FALSE;
GLboolean is_sound = GL_TRUE;

GLboolean is_menu_page = GL_TRUE;
GLboolean is_game_page = GL_FALSE;
GLboolean is_cover_page = GL_FALSE;
GLboolean is_settings_page = GL_FALSE;
GLboolean is_game_over = GL_FALSE;
GLboolean is_keyBoard_shortcut_page = GL_FALSE;

GLboolean easy_mode = GL_FALSE;
GLboolean medium_mode = GL_FALSE;
GLboolean hard_mode = GL_FALSE;

GLboolean current_mode = 0;

Point _p1, _p2,
    ballp1, ballp2,
    ballp3, ballp4,
    ballp5, ballp6,
    ballp7, ballp8,

    barxp1, barxp2,
    barxp3, barxp4,
    barxp5, barxp6,
    barxp7, barxp8,

    baryp1, baryp2,
    baryp3, baryp4,
    baryp5, baryp6,
    baryp7, baryp8;

// Display line
void drawLine(Point p1, Point p2, RGBA rgba = {255, 255, 255, 255}, GLfloat lineSize = 1.0f)
{
    glColor4ub(rgba.r, rgba.g, rgba.b, rgba.a);

    glLineWidth(lineSize);
    glBegin(GL_LINES);
        glVertex2f(p1.x, p1.y);
        glVertex2f(p2.x, p2.y);
    glEnd();
}

// Display filled quadrant
void drawQuad(Point p1, Point p2, Point p3, Point p4, RGBA rgba = {255, 255, 255, 255})
{
    glColor4ub(rgba.r, rgba.g, rgba.b, rgba.a);

    glBegin(GL_QUADS);
        glVertex2f(p1.x, p1.y);
        glVertex2f(p2.x, p2.y);
        glVertex2f(p3.x, p3.y);
        glVertex2f(p4.x, p4.y);
    glEnd();
}

// Display empty quadrant
void drawLineQuad(Point p1, Point p2, Point p3, Point p4, RGBA rgba = {255, 255, 255, 255}, GLfloat lineSize = 1.0f)
{
    drawLine(p1, p2, rgba, lineSize);
    drawLine(p2, p3, rgba, lineSize);
    drawLine(p3, p4, rgba, lineSize);
    drawLine(p4, p1, rgba, lineSize);
}

// Display triangle
void drawTriangle(Point p1, Point p2, Point p3, RGBA rgba = {255, 255, 255, 255})
{
    glColor4ub(rgba.r, rgba.g, rgba.b, rgba.a);

    glBegin(GL_TRIANGLES);
        glVertex2f(p1.x, p1.y);
        glVertex2f(p2.x, p2.y);
        glVertex2f(p3.x, p3.y);
    glEnd();
}

// Display empty Circle
void drawEmptyCircle(Point p, GLfloat r, RGBA rgba = {255, 255, 255, 255})
{
    GLint lineAmount = pow(r, 4);

    glColor4ub(rgba.r, rgba.g, rgba.b, rgba.a);

    glBegin(GL_LINE_LOOP);
        for (GLint i = 0; i <= 4 * lineAmount; i++)
        {
            glVertex2f(
                p.x + (r * cos((i * 2.0f * M_PI) / lineAmount)),
                p.y + (r * sin((i * 2.0f * M_PI) / lineAmount)));
        }
    glEnd();
}

// Display filled Circle
void drawFilledCircle(Point p, GLfloat r, RGBA rgba = {255, 255, 255, 255})
{
    GLint triangleAmount = pow(r, 2);

    glColor4ub(rgba.r, rgba.g, rgba.b, rgba.a);

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(p.x, p.y); // center of circle

        for (GLint i = 0; i <= triangleAmount; i++)
        {
            glVertex2f(
                p.x + (r * cos((i * 2.0f * M_PI) / triangleAmount)),
                p.y + (r * sin((i * 2.0f * M_PI) / triangleAmount)));
        }
    glEnd();
}

// Debug collision
void debugDrawLines(
    Point ballp1, Point ballp2, // top
    Point ballp3, Point ballp4, // botom
    Point ballp5, Point ballp6, // right
    Point ballp7, Point ballp8, // left

    Point barxp1, Point barxp2, // top
    Point barxp3, Point barxp4, // botom
    Point barxp5, Point barxp6, // right
    Point barxp7, Point barxp8, // left

    Point baryp1, Point baryp2, // top
    Point baryp3, Point baryp4, // botom
    Point baryp5, Point baryp6, // right
    Point baryp7, Point baryp8  // left

)
{
    drawLine(ballp1, ballp2);
    drawLine(ballp3, ballp4);
    drawLine(ballp5, ballp6);
    drawLine(ballp7, ballp8);

    drawLine(barxp1, barxp2);
    drawLine(barxp3, barxp4);
    drawLine(barxp5, barxp6);
    drawLine(barxp7, barxp8);

    drawLine({barxp1.x, -barxp1.y}, {barxp2.x, -barxp2.y});
    drawLine({barxp3.x, -barxp3.y}, {barxp4.x, -barxp4.y});
    drawLine({barxp5.x, -barxp5.y}, {barxp6.x, -barxp6.y});
    drawLine({barxp7.x, -barxp7.y}, {barxp8.x, -barxp8.y});

    drawLine(baryp1, baryp2);
    drawLine(baryp3, baryp4);
    drawLine(baryp5, baryp6);
    drawLine(baryp7, baryp8);

    drawLine({-baryp1.x, baryp1.y}, {-baryp2.x, baryp2.y});
    drawLine({-baryp3.x, baryp3.y}, {-baryp4.x, baryp4.y});
    drawLine({-baryp5.x, baryp5.y}, {-baryp6.x, baryp6.y});
    drawLine({-baryp7.x, baryp7.y}, {-baryp8.x, baryp8.y});
}

// Displaying text
void Text(GLfloat x, GLfloat y, const char *string, GLfloat fontsize = 0.3f, RGBA rgba = {255, 255, 255, 255}, void *font = GLUT_STROKE_MONO_ROMAN)
{
    glPushMatrix();

        glTranslatef(x, y, 0.0f);
        glScalef(fontsize, fontsize, 1.0f);
        glColor4ub(rgba.r, rgba.g, rgba.b, rgba.a);
        glutStrokeString(font, (const unsigned char *)string);

    glPopMatrix();
}

// Get fixed precision floting point number
string getNumberWithFixedPrecision(GLfloat number, int precision = 1)
{
    string number_str = to_string(number);
    int pos = number_str.find('.');
    return number_str.substr(0, pos + precision + 1);
}

// Move object right to left
void rightToLeft(GLfloat &p, GLfloat &s, GLfloat size)
{
    GLfloat move = (width - gutter) + 2 * size + 25.0f;

    if (p < -move)
    {
        p = move;
    }

    p -= s;
}

// Move object left to right
void downToUp(GLfloat &p, GLfloat &s, GLfloat size)
{
    GLfloat move = (height + gutter) + size;

    if (p > move)
    {
        p = -move;
    }

    p += s;
}

// Move object left to right
void leftToRight(GLfloat &p, GLfloat &s, GLfloat size)
{
    GLfloat move = (width - gutter) + 2 * size + 25.0f;

    if (p > move)
    {
        p = -move;
    }

    p += s;
}

void upToDown(GLfloat &p, GLfloat &s, GLfloat size)
{
    GLfloat move = (height + gutter) + size;

    if (p < -move)
    {
        p = move;
    }

    p -= s;
}

void collision()
{
    // Geting all the side axis
    GLfloat ballT = ball1.positionY + ball1.getSizeY();
    GLfloat ballB = ball1.positionY - ball1.getSizeY();
    GLfloat ballR = ball1.positionX + ball1.getSizeX();
    GLfloat ballL = ball1.positionX - ball1.getSizeX();

    GLfloat barXT = barX1.positionY + barX1.getSizeY();
    GLfloat barXB = barX1.positionY - barX1.getSizeY();
    GLfloat barXR = barX1.positionX + barX1.getSizeX();
    GLfloat barXL = barX1.positionX - barX1.getSizeX();

    GLfloat barYT = barY1.positionY - barY1.getSizeY();
    GLfloat barYB = barY1.positionY + barY1.getSizeY();
    GLfloat barYR = barY1.positionX - barY1.getSizeX();
    GLfloat barYL = barY1.positionX + barY1.getSizeX();

    // _p1 = {barR, height * 1.0f};
    // _p2 = {barR, -height * 1.0f};

    // Properly set all the position to quad point
    ballp1 = {ballL, ballT};
    ballp2 = {ballR, ballT};
    ballp3 = {ballL, ballB};
    ballp4 = {ballR, ballB};
    ballp5 = {ballR, ballB};
    ballp6 = {ballR, ballT};
    ballp7 = {ballL, ballB};
    ballp8 = {ballL, ballT};

    barxp1 = {barXL, barXT}; // top-left
    barxp2 = {barXR, barXT}; // top-right
    barxp3 = {barXL, barXB}; // left-bottom
    barxp4 = {barXR, barXB}; // right-bottom
    barxp5 = {barXR, barXB};
    barxp6 = {barXR, barXT};
    barxp7 = {barXL, barXB};
    barxp8 = {barXL, barXT};

    baryp1 = {barYR, barYB}; // top-left
    baryp2 = {barYL, barYB}; // top-right
    baryp3 = {barYR, barYT}; // left-bottom
    baryp4 = {barYL, barYT}; // right-bottom
    baryp5 = {barYL, barYT};
    baryp6 = {barYL, barYB};
    baryp7 = {barYR, barYT};
    baryp8 = {barYR, barYB};

    // Check the collision
    if (_collision != 1 && (barxp1.x <= ballp2.x && barxp2.x >= ballp1.x && barxp3.y <= ballp1.y && barxp1.y >= ballp3.y))
    {
        _collision = 1;
        point++;

        if (medium_mode || hard_mode)
        {
            ball1.speed += 0.1f;
        }

        if (is_sound)
        {
            PlaySound(TEXT("audio/bar-collision.wav"), NULL, SND_ASYNC);
        }
    }
    else if (_collision != 3 && (barxp1.x <= ballp2.x && barxp2.x >= ballp1.x && -barxp3.y >= ballp3.y && -barxp1.y <= ballp1.y))
    {
        _collision = 3;
        point++;

        if (medium_mode || hard_mode)
        {
            ball1.speed += 0.1f;
        }

        if (is_sound)
        {
            PlaySound(TEXT("audio/bar-collision.wav"), NULL, SND_ASYNC);
        }
    }
    else if (_collision != 2 && (baryp1.y >= ballp3.y && baryp3.y <= ballp1.y && baryp1.x <= ballp2.x && baryp2.x >= ballp1.x))
    {
        _collision = 2;
        point++;

        if (medium_mode || hard_mode)
        {
            ball1.speed += 0.1f;
        }

        if (is_sound)
        {
            PlaySound(TEXT("audio/bar-collision.wav"), NULL, SND_ASYNC);
        }
    }
    else if (_collision != 4 && (baryp1.y >= ballp3.y && baryp3.y <= ballp1.y && -baryp1.x >= ballp1.x && -baryp2.x <= ballp2.x))
    {
        _collision = 4;
        point++;

        if (medium_mode || hard_mode)
        {
            ball1.speed += 0.1f;
        }

        if (is_sound)
        {
            PlaySound(TEXT("audio/bar-collision.wav"), NULL, SND_ASYNC);
        }
    }
}

// Ball movement on game page
void ballMovement()
{
    // Get the game window axis
    GLfloat movey = width - ball1.getSizeX();
    GLfloat movex = height - ball1.getSizeY();

    // Check the collision
    collision();

    // If hard mode than change ball opacity
    if (hard_mode)
    {
        if (ball_opacity_hard_mode == 0)
        {
            ball_opacity_hard_mode_go_up = GL_TRUE;
            ball_opacity_hard_mode_go_down = GL_FALSE;
        }

        if (ball_opacity_hard_mode == 255)
        {
            ball_opacity_hard_mode_go_down = GL_TRUE;
            ball_opacity_hard_mode_go_up = GL_FALSE;
        }

        if (ball_opacity_hard_mode_go_down)
        {
            ball_opacity_hard_mode--;
        }

        if (ball_opacity_hard_mode_go_up)
        {
            ball_opacity_hard_mode++;
        }

        ball1.rgbaColor = {255, 121, 63, ball_opacity_hard_mode};
    }

    // If life have then collision
    if (life == 1 || life == 2 || life == 3)
    {
        // Reduce life if collision in game boundary
        if (
            (ball1.positionX >= movey) ||
            (ball1.positionX <= -movey) ||
            (ball1.positionY >= movex) ||
            (ball1.positionY <= -movex))
        {
            life--;

            if (is_sound)
            {
                PlaySound(TEXT("audio/life-reduce.wav"), NULL, SND_ASYNC);
            }
        }

        if (ball1.positionX >= movey)
        {
            ball1.moveX = GL_TRUE;
            _collision = 2;
        }

        if (ball1.positionX <= -movey)
        {
            ball1.moveX = GL_FALSE;
            _collision = 4;
        }

        if (ball1.positionY >= movex)
        {
            ball1.moveY = GL_TRUE;
            _collision = 1;
        }

        if (ball1.positionY <= -movex)
        {
            ball1.moveY = GL_FALSE;
            _collision = 3;
        }
    }

    // If life doesn't have show the game page
    if (0 >= life)
    {
        if (
            (ball1.positionX >= movey) ||
            (ball1.positionX <= -movey) ||
            (ball1.positionY >= movex) ||
            (ball1.positionY <= -movex))
        {
            is_game_over = GL_TRUE;
            is_started = GL_FALSE;

            if (is_sound)
            {
                PlaySound(TEXT("audio/game-over.wav"), NULL, SND_ASYNC);
            }
        }
    }

    // Move Vertical (Y axis)
    if (_collision == 2)
    {
        ball1.moveX = GL_TRUE;
    }

    if (_collision == 4)
    {
        ball1.moveX = GL_FALSE;
    }

    if (ball1.moveX)
    {
        ball1.positionX -= ball1.speed;
    }
    else
    {
        ball1.positionX += ball1.speed;
    }

    // Move Vertical (X axis)
    if (_collision == 1)
    {
        ball1.moveY = GL_TRUE;
    }
    if (_collision == 3)
    {
        ball1.moveY = GL_FALSE;
    }

    if (ball1.moveY)
    {
        ball1.positionY -= ball1.speed;
    }
    else
    {
        ball1.positionY += ball1.speed;
    }
}

// All 4 bar movement on game page
void barMovement()
{
    if (barX1.move_left == GL_TRUE || barX2.move_left == GL_TRUE)
    {
        rightToLeft(barX1.positionX, barX1.speed, barX1.getSizeX());
        rightToLeft(barX2.positionX, barX2.speed, barX2.getSizeX());
    }

    if (barX1.move_right == GL_TRUE || barX2.move_right == GL_TRUE)
    {
        leftToRight(barX1.positionX, barX1.speed, barX1.getSizeX());
        leftToRight(barX2.positionX, barX2.speed, barX2.getSizeX());
    }

    if (barY1.move_up == GL_TRUE || barY2.move_up == GL_TRUE)
    {
        downToUp(barY1.positionY, barY1.speed, barY1.getSizeX());
        downToUp(barY2.positionY, barY2.speed, barY2.getSizeX());
    }

    if (barY1.move_down == GL_TRUE || barY2.move_down == GL_TRUE)
    {
        upToDown(barY1.positionY, barY1.speed, barY1.getSizeX());
        upToDown(barY2.positionY, barY2.speed, barY2.getSizeX());
    }
}