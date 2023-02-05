#include "../incl/LineToCommand.h"
#include "../incl/Robot.h"
#include "../incl/Grid.h"

LineToCommand::LineToCommand(Robot* robot, Grid* grid, int x, int y)
    : m_robot(robot), m_grid(grid), m_x(x), m_y(y)
{}

void LineToCommand::execute()
{
    m_robot->drawLineTo(m_grid, m_x, m_y);
}