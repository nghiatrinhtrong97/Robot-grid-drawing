#include "incl/Command.h"
#include "incl/DimensionCommand.h"
#include "incl/MoveToCommand.h"
#include "incl/LineToCommand.h"
#include "incl/Grid.h"
#include "incl/Robot.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char *argv[])
{
    // if (argc < 2)
    // {
    //     std::cerr << "Usage: " << argv[0] << " <input_file>\n";
    //     return 1;
    // }

    Grid grid;
    Robot robot;

    std::vector<Command *> commands;
    int a, b, c, d, e;
    char repeat = 'y';

    while (repeat == 'y' || repeat == 'Y')
    {
        std::cout << "Enter value for DIMENSION: ";
        std::cin >> a;
        commands.push_back(new DimensionCommand(&grid, a));

        std::cout << "Enter value for MOVE_TO (x, y): ";
        std::cin >> b >> c;
        commands.push_back(new MoveToCommand(&robot, &grid, b, c));

        std::cout << "Enter value for LINE_TO (x, y): ";
        std::cin >> d >> e;
        commands.push_back(new LineToCommand(&robot, &grid, d, e));

        std::cout << std::endl;

        std::cout << "DIMENSION: " << a << std::endl;
        std::cout << "MOVE_TO: (" << b << ", " << c << ")" << std::endl;
        std::cout << "LINE_TO: (" << d << ", " << e << ")" << std::endl;

        for (Command *command : commands)
        {
            command->execute();
        }

        robot.showGrid(&grid, a);

        std::cout << "Repeat? (y/n): ";
        std::cin >> repeat;
    }

    return 0;
}