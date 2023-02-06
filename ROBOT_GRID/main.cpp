#include "incl/Command.h"
#include "incl/DimensionCommand.h"
#include "incl/MoveToCommand.h"
#include "incl/LineToCommand.h"
#include "incl/Grid.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char *argv[])
{

    std::vector<Command *> commands;
    int a(-1), b(-1), c(-1), d(-1), e(-1), f(-1), g(-1);
    char repeat = 'y';

    Grid grid;

    while (repeat == 'y' || repeat == 'Y')
    {
        std::cout << "Enter value for DIMENSION: ";
        if (!(std::cin >> a)) {
            std::cout << "Error: Invalid input for dimension." << std::endl;
            return 1;
        }
        commands.push_back(new DimensionCommand(&grid, a));

        while (true)
        {
            std::cout << "Enter command: Enter 'm' for MOVE_TO and 'l' for LINE_TO"<< std::endl;
            std::cout << "press any other key to display the final result" << std::endl;
            std::cout << "your choice: ";
            std::string command;
            if (!(std::cin >> command))
            {
                std::cout << "Error: Invalid input for command type." << std::endl;
                return 1;
            }
            if (command == "m" || command == "M")
            {
                std::cout << "Enter MOVE_TO coordinates (b, c): ";
                if (!(std::cin >> b >> c))
                {
                    std::cout << "Error: Invalid input for MOVE_TO coordinates." << std::endl;
                    return 1;
                }
                commands.push_back(new MoveToCommand(&grid, b, c));
                for (Command *command : commands)
                {
                    command->execute();
                }
                grid.showGrid();
                grid.m_square_grid.clear();
            }
            else if (command == "l" || command == "L")
            {
                std::cout << "Enter LINE_TO coordinates (d, e): ";
                if (!(std::cin >> d >> e))
                {
                    std::cout << "Error: Invalid input for LINE_TO coordinates." << std::endl;
                    return 1;
                }
                commands.push_back(new LineToCommand(&grid, d, e));
                for (Command *command : commands)
                {
                    command->execute();
                }
                grid.showGrid();
                grid.m_square_grid.clear();
            }
            else
            {
                break;
            }
        }

        for (Command *command : commands)
        {
            command->execute();
        }

        grid.showGrid();

        commands.clear();
        grid.m_square_grid.clear();

        std::cout << "Repeat? (y/n): ";

        if (!(std::cin >> repeat))
        {
            std::cout << "Error: Invalid input and robot will sleep, bye and see you again." << std::endl;
            return 1;
        }
    }

    return 0;
}