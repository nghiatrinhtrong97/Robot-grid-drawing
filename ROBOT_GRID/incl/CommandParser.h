#ifndef COMMAND_PARSE_H
#define COMMAND_PARSE_H

#include "Command.h"
#include "DimensionCommand.h"
#include "MoveToCommand.h"
#include "LineToCommand.h"
#include "Grid.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>


class CommandParser {
 public:
  CommandParser();
  ~CommandParser();
//   Command* parse(const std::string& input);
  Command* parse(Grid* grid, const std::string& input);

 private:
  std::vector<std::string> split(const std::string& inputLine);
};

#endif // COMMAND_PARSE_H