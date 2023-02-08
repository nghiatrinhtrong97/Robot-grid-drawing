#include "incl/CommandParser.h"


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "input file name not provided " << std::endl;
        return 1;
    }

    Grid grid;

    std::string filename = argv[1];
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "unable to open file " << std::endl;
        return 1;
    }

    std::vector<Command*> commands;
    CommandParser parser;
    std::string line;
    while (std::getline(file, line)) {
        try {
            Command* cmd = parser.parse(&grid, line);
            if(cmd != nullptr){
                commands.push_back(cmd);
            }else{
                std::cout << "unable to parse commands --------> EXIT " << std::endl;
                return -1;
            }
        } catch (const std::exception& e) {
            std::cout << "unable to parse commands " << e.what() << std::endl;
        }
    }

    for (Command *command : commands)
    {
        command->execute();
    }

    grid.showGrid();

    // clean up
    for (Command* cmd : commands) {
        delete cmd;
    }

    return 0;
}