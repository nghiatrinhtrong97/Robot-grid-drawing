#include "../incl/MoveToCommand.h"
#include "../incl/Robot.h"

MoveToCommand::MoveToCommand(Robot* robot, Grid* grid, int x, int y)
    : m_robot(robot), m_grid(grid), m_x(x), m_y(y)
{}

void MoveToCommand::execute()
{
    m_robot->moveTo(m_grid, m_x, m_y);
}