#include "../incl/MoveToCommand.h"
#include "../incl/Grid.h"

MoveToCommand::MoveToCommand(Grid* grid, int x, int y)
    : m_grid(grid), m_x(x), m_y(y)
{}

void MoveToCommand::execute()
{
    m_grid->moveTo(m_x, m_y);
}