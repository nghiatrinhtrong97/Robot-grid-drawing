#include "../incl/CommandParser.h"

CommandParser::CommandParser() {}

Command *CommandParser::parse(Grid* grid, const std::string &input)
{
    std::vector<std::string> tokens = split(input);
    if (tokens.empty())
    {
        throw std::invalid_argument("Input is empty");
    }

    if (tokens[0] == "DIMENSION")
    {
        if (tokens.size() != 2)
        {
            std::cout <<"error DIMENSION input, please check input file again " << std::endl;
            return nullptr;
        }

        std::cout <<"DIMENSION " << tokens[1] <<std::endl;

        try
        {
            int n = stoi(tokens[1]);
            if (n <= 0)
            {
                std::cout <<"error DIMENSION input, please check input file again " << std::endl;
                return nullptr;
            }
            return (new DimensionCommand(grid, n));
        }
        catch (const std::invalid_argument &e)
        {
            // throw error or return error code indicating that the input is invalid
            return nullptr;
        }
    }
    else if (tokens[0] == "MOVE_TO")
    {
        if (tokens.size() != 3)
        {
            std::cout <<"error MOVE_TO input, please check input file again " << std::endl;
            return nullptr;
        }

        std::cout <<"MOVE_TO " << tokens[1] << tokens[2] << std::endl;
        try
        {
            int x = std::stoi(tokens[1]);
            int y = std::stoi(tokens[2]);
            return (new MoveToCommand(grid, x, y));
        }
        catch (const std::invalid_argument &e)
        {
            std::cout <<"error MOVE_TO input, please check input file again " << std::endl;
            return nullptr;
        }
    }
    else if (tokens[0] == "LINE_TO")
    {
        if (tokens.size() != 3)
        {
            std::cout <<"error LINE_TO input, please check input file again " << std::endl;
            return nullptr;
        }

        std::cout <<"LINE_TO " << tokens[1] << tokens[2] << std::endl;
        try
        {
            int x = std::stoi(tokens[1]);
            int y = std::stoi(tokens[2]);
            return (new LineToCommand(grid, x, y));
        }
        catch (const std::invalid_argument &e)
        {
            std::cout <<"error LINE_TO input, please check input file again " << std::endl;
            return nullptr;
        }return nullptr;
    }
    else
    {
        std::cout <<"Invalid command, please check input file again " << std::endl;
        return nullptr;
    }
}

std::vector<std::string> CommandParser::split(const std::string &inputLine)
{
    std::vector<std::string> tokens;
    std::istringstream stream(inputLine);
    std::string token;
    while (stream >> token)
    {
        tokens.push_back(token);
    }
    return tokens;
}