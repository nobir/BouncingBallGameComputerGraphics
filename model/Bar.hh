#pragma once

#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

class Bar : public Component
{
public:
    Point p1;
    Point p2;
    Point p3;
    Point p4;

    GLboolean move_left;
    GLboolean move_right;
    GLboolean move_up;
    GLboolean move_down;

    Bar() : Component()
    {
        this->p1 = {0.0f, 0.0f};
        this->p2 = {0.0f, 0.0f};
        this->p3 = {0.0f, 0.0f};
        this->p4 = {0.0f, 0.0f};

        this->speed = 10.0f;

        this->move_right = GL_FALSE;
        this->move_right = GL_FALSE;
        this->move_up = GL_FALSE;
        this->move_down = GL_FALSE;
    }

    Bar(Point p1, Point p2, Point p3, Point p4, RGBA rgba = {255, 255, 255, 255}) : Component(p1, p2, p3, p4, rgba)
    {
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
        this->p4 = p4;

        this->speed = 10.0f;

        this->move_right = GL_FALSE;
        this->move_right = GL_FALSE;
        this->move_up = GL_FALSE;
        this->move_down = GL_FALSE;
    }

    GLfloat getSizeX()
    {
        return this->width / 2;
    }

    GLfloat getSizeY()
    {
        return this->height / 2;
    }
};

Bar
    // Top bar
    barX1(
        {-100.0f, -25.0f},
        {100.0f, -25.0f},
        {100.0f, 25.0f},
        {-100.0f, 25.0f},
        {163, 203, 56,255}),
    // Bottom bar
    barX2(
        {-100.0f, -25.0f},
        {100.0f, -25.0f},
        {100.0f, 25.0f},
        {-100.0f, 25.0f},
        {163, 203, 56,255}),
    // Right bar
    barY1(
        {-25.0f, -100.0f},
        {25.0f, -100.0f},
        {25.0f, 100.0f},
        {-25.0f, 100.0f},
        {163, 203, 56,255}),
    // Left bar
    barY2(
        {-25.0f, -100.0f},
        {25.0f, -100.0f},
        {25.0f, 100.0f},
        {-25.0f, 100.0f},
        {163, 203, 56,255});
