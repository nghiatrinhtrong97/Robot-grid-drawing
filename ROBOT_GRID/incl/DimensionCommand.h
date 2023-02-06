#ifndef DIMENSION_COMMAND_H
#define DIMENSION_COMMAND_H

/******************************************************************************************
This class represents the DIMENSION command. 
It has a member variable int m_size that stores the value of N passed to the DIMENSION command. 
It implements the execute method of the Command interface to change the size of the grid.
*******************************************************************************************/

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