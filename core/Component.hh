#pragma once

#include <bits/stdc++.h>
#include <GL/glut.h>

#include "Point.hh"
#include "Color.hh"

using namespace std;

#define SPEED 1.0f

class Component
{
public:
    GLfloat positionX;
    GLfloat positionY;

    GLfloat width;
    GLfloat height;

    GLfloat speed;

    RGBA rgbaColor;

    Component()
    {
        this->positionX = 0.0f;
        this->positionY = 0.0f;

        this->width = 0.0f;
        this->height = 0.0f;

        this->speed = SPEED;

        this->rgbaColor = {255, 255, 255, 255};
    }

    Component(Point p1, Point p2, Point p3, Point p4, RGBA rgba = {255, 255, 255, 255})
    {
        // Center point
        this->positionX = (p1.x + p2.x + p3.x + p4.x) / 4.0f;
        this->positionY = (p1.y + p2.y + p3.y + p4.y) / 4.0f;

        this->speed = SPEED;

        // RGB color
        this->rgbaColor = rgba;

        // X and Y length
        this->width = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
        this->height = sqrt(pow(p3.x - p2.x, 2) + pow(p3.y - p2.y, 2));
    }

    Component(GLfloat radius, RGBA rgba = {255, 255, 255, 255})
    {
        this->positionX = 0.0f;
        this->positionY = 0.0f;

        this->speed = SPEED;

        this->rgbaColor = rgba;

        this->width = 2.0f * radius;
        this->height = 2.0f * radius;
    }

    Component(Point p, GLfloat radius, RGBA rgba = {255, 255, 255, 255})
    {
        this->positionX = p.x;
        this->positionY = p.y;

        this->speed = SPEED;

        this->rgbaColor = rgba;

        this->width = 2.0f * radius;
        this->height = 2.0f * radius;
    }

    GLfloat getSizeX();
    GLfloat getSizeY();
};