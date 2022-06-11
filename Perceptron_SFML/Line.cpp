/*
 * This class simply creates a line to visualise the function that
 * used in the perceptron.
 * 
 */

#include "Line.h"

Line::Line(sf::RenderWindow* hwnd) : window(hwnd)
{
    createLine();
}

Line::~Line()
{

}

void Line::createLine()
{
    int numOfPoints = 1000;
    linePoints = sf::VertexArray(sf::Points, numOfPoints);

    // Line function:   y = ax + b
    //                  y = 2 * x + 1
    // Remember +y is up

    for (int i = 0; i < numOfPoints; ++i)
    {
        int randXVal = getRandValue();

        // 50/50 chance to negate the xVal
        if (rand() % 2 == 0)
        {
            randXVal = -randXVal;
        }

        // Not sure why, but to get the line as it should be according to Desmos graphing calculator
        // the negative value of the xVal must be passed for a linear function, for a quadratic it can be passed as normal???
        float yVal = f(-randXVal);

        linePoints[i].color = sf::Color::Red;
        linePoints[i].position = sf::Vector2f(randXVal, yVal);
    }
}

int Line::getRandValue()
{
    int randVal = rand() % 145;

    // 50/50 chance to negate the value
    if (rand() % 2 == 0)
    {
        randVal = -randVal;
    }

    return randVal;
}

// Function of a line
float Line::f(float xPos)
{
    return 2 * xPos + 1;
    //return -std::pow(0.2 * xPos, 2) - ((size_t)2.0f * xPos) + 200;
}

void Line::render()
{
    window->draw(linePoints);
}