#ifndef MOVE_TO_COMMAND_H
#define MOVE_TO_COMMAND_H

#include "Command.h"

class Robot;
class Grid;

class MoveToCommand : public Command
{
public:
    MoveToCommand(Robot* robot, Grid* grid, int x, int y);
    void execute() override;

private:
    Robot* m_robot;
    Grid* m_grid;
    int m_x;
    int m_y;
};

#endif // MOVE_TO_COMMAND_H