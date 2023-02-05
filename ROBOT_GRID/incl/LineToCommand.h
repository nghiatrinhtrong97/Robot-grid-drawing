#ifndef LINE_TO_COMMAND_H
#define LINE_TO_COMMAND_H


#include "Command.h"

class Robot;
class Grid;

class LineToCommand : public Command
{
public:
    LineToCommand(Robot* robot, Grid* grid, int x, int y);
    void execute() override;

private:
    Robot* m_robot;
    Grid* m_grid;
    int m_x;
    int m_y;
};

#endif // LINE_TO_COMMAND_H