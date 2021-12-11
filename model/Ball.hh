#pragma once

#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

class Ball : public Component
{
public:
    Point p;
    GLfloat radius;

    GLboolean moveX;
    GLboolean moveY;

    Ball() : Component()
    {
        this->p = {0.0f, 0.0f};
        this->radius = 0.0f;

        this->moveX = GL_FALSE;
        this->moveY = GL_FALSE;
    }

    Ball(GLfloat _radius, RGBA rgba = {255, 255, 255, 255}) : Component(_radius, rgba)
    {
        this->p = {0.0f, 0.0f};
        this->radius = _radius;

        this->moveX = GL_FALSE;
        this->moveY = GL_FALSE;
    }

    Ball(Point p, GLfloat _radius, RGBA rgba = {255, 255, 255, 255}) : Component(p, _radius, rgba)
    {
        this->p = p;
        this->radius = _radius;

        this->moveX = GL_FALSE;
        this->moveY = GL_FALSE;
    }

    GLfloat getSizeX()
    {
        return this->radius;
    }

    GLfloat getSizeY()
    {
        return this->radius;
    }
};

Ball
    ball1(
        25.0f,
        {255, 121, 63, 255});
