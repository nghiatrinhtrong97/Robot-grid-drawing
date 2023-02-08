#ifndef MOVE_TO_COMMAND_H
#define MOVE_TO_COMMAND_H

/******************************************************************************************
MoveToCommand: This class represents the MOVE_TO command. 
It has two member variables int x and int y that store the x and y coordinates passed to the MOVE_TO command. 
It implements the execute method of the Command interface to move the robot to the specified coordinates without drawing.
*******************************************************************************************/

#include "Command.h"

class Robot;
class Grid;

class MoveToCommand : public Command
{
public:
    MoveToCommand(Grid* grid, int x, int y);
    ~MoveToCommand();
    void execute() override;

private:
    Grid* m_grid;
    int m_x;
    int m_y;
};

#endif // MOVE_TO_COMMAND_H