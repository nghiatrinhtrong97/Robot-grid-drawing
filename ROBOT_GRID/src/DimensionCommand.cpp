#include "../incl/DimensionCommand.h"
#include "../incl/Grid.h"

DimensionCommand::DimensionCommand(Grid* grid, int size)
    : m_grid(grid), m_size(size)
{}

void DimensionCommand::execute()
{
    m_grid->setSize(m_size);
    m_grid = nullptr;
}