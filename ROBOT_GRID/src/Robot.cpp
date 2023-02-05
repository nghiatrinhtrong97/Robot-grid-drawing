#include "../incl/Robot.h"
#include "../incl/Grid.h"

Robot::Robot()
    : m_x(0), m_y(0)
{
}

void Robot::moveTo(Grid *grid, int x, int y)
{
    grid->drawMoveTo(x, y);
    m_x = x;
    m_y = y;
}

void Robot::drawLineTo(Grid *grid, int x, int y)
{
    grid->drawLineTo(m_x, m_y, x, y);
    m_x = x;
    m_y = y;
}

void Robot::showGrid(Grid *grid, int N)
{
    grid->print(N);
}

int Robot::x() const
{
    return m_x;
}

int Robot::y() const
{
    return m_y;
}