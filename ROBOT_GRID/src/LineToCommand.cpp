#include "../incl/LineToCommand.h"
#include "../incl/Grid.h"

LineToCommand::LineToCommand(Grid* grid, int x, int y)
    : m_grid(grid), m_x(x), m_y(y)
{}

void LineToCommand::execute()
{
    m_grid->drawLineTo(m_x, m_y);
    m_grid = nullptr;
}