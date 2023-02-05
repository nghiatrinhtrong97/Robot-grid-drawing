#ifndef DIMENSION_COMMAND_H
#define DIMENSION_COMMAND_H

#include "Command.h"

class Grid;

class DimensionCommand : public Command
{
public:
    DimensionCommand(Grid* grid, int size);
    void execute() override;

private:
    Grid* m_grid;
    int m_size;
};

#endif // DIMENSION_COMMAND_H