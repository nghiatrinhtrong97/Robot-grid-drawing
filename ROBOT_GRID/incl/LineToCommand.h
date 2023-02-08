#ifndef LINE_TO_COMMAND_H
#define LINE_TO_COMMAND_H

/******************************************************************************************
LineToCommand: This class represents the LINE_TO command. 
It has two member variables int x and int y that store the x and y coordinates passed to the LINE_TO command. 
It implements the execute method of the Command interface to move the robot from its current position to the specified coordinates while drawing a line on the grid.
*******************************************************************************************/

#include "Command.h"

class Robot;
class Grid;

class LineToCommand : public Command
{
public:
    LineToCommand(Grid* grid, int x, int y);
    ~LineToCommand();
    void execute() override;

private:
    Grid* m_grid;
    int m_x;
    int m_y;
};

#endif // LINE_TO_COMMAND_H