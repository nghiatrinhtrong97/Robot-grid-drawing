#include "../incl/Robot.h"
#include "../incl/Grid.h"

Robot::Robot()
    : m_currentX(0), m_currentY(0)
{
}

void Robot::moveTo(Grid *grid, int x, int y)
{
    grid->drawMoveTo(x, y);
    m_currentX = x;
    m_currentY = y;
}

void Robot::drawLineTo(Grid *grid, int x, int y)
{
    grid->drawLineTo(m_currentX, m_currentY, x, y);
    m_currentX = x;
    m_currentY = y;
}

void Robot::showGrid(Grid *grid, int N)
{
    grid->print(N);
}

int Robot::getCurrentX() const
{
    return m_currentX;
}

int Robot::getCurrentY() const
{
    return m_currentY;
}