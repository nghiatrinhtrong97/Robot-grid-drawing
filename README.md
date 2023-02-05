# Robot-grid-drawing

Robot grid drawing
![image](https://user-images.githubusercontent.com/71679681/216773790-fa88c44e-ad26-4ece-8b90-cb945e931bd5.png)

<!-- @startuml
class Grid {
  +fillSquare(x: int, y: int)
  +isSquareFilled(x: int, y: int): bool
}

class Robot {
  +moveTo(x: int, y: int)
  +drawLineTo(x: int, y: int)
}

abstract class Command {
  +execute()
  +parse(input: string): Command
}

class DimensionCommand {
  +execute()
  +parse(input: string): DimensionCommand
}

class MoveToCommand {
  +execute()
  +parse(input: string): MoveToCommand
}

class LineToCommand {
  +execute()
  +parse(input: string): LineToCommand
}

class CommandParser {
  +parseCommands(input: string[]): vector<Command>
}

class InputError {
  +getMessage(): string
}

Grid --down-> Robot
Robot ..> Command
Command <|-- DimensionCommand
Command <|-- MoveToCommand
Command <|-- LineToCommand
CommandParser ..> Command
@enduml -->



<!-- p2: 
@startuml
class Grid {
  -int N
  -char grid[][]
  +Grid()
  +void setDimension(int n)
  +void moveTo(int x, int y)
  +void lineTo(int x, int y)
  +void fillSquare(int x, int y)
  +void print()
}

class Command {
  +virtual void execute(Grid& grid) = 0;
}

class DimensionCommand{
  -int n
  +DimensionCommand(int n)
  +void execute(Grid& grid)
}

class MoveToCommand {
  -int x
  -int y
  +MoveToCommand(int x, int y)
  +void execute(Grid& grid)
}

class LineToCommand{
  -int x
  -int y
  +LineToCommand(int x, int y)
  +void execute(Grid& grid)
}

class CommandParser {
  +Command* parseCommand(const std::string& line)
}

Grid -down-> Command
CommandParser -> Command
Command <|-- DimensionCommand
Command <|-- MoveToCommand
Command <|-- LineToCommand
@enduml -->


<!-- Grid: class that represents the grid on which the robot is moving and drawing. It contains methods for filling a square and checking if a square is filled.

Robot: class that represents the robot and its movements. It contains methods for moving and drawing lines on the grid.

Command: abstract class that represents a command the robot can execute. It contains methods for parsing the command and executing it.

DimensionCommand: class that inherits from Command and represents the DIMENSION command. It contains methods for setting the size of the grid.

MoveToCommand: class that inherits from Command and represents the MOVE_TO command. It contains methods for moving the robot to a specific square.

LineToCommand: class that inherits from Command and represents the LINE_TO command. It contains methods for drawing a line from the current position of the robot to a specific square.

CommandParser: class that parses the commands from the input file and creates the appropriate Command objects.

InputError: class that represents errors that occur during parsing of the input. -->

