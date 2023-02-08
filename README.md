# Robot-grid-drawing

Robot grid drawing
![image](https://user-images.githubusercontent.com/71679681/217058506-1b135a52-7239-45d6-971e-5b48bd5eeaed.png)

1. download source code
2. decompression
3. in ROBOT_GRID folder run: mingw32-make (Windown)/ make(Linux)
4. run main.exe



<!-- @startuml
class Grid {

  -int m_size
  -int m_currentX
  -int m_currentY
  -std::vector<std::vector<int>> m_square_grid
  +void setSize(int size)
  +void moveTo(int x1, int y1)
  +void drawLineTo(int x2, int y2)
  +void showGrid() const
  +int getCurrentX() const
  +int getCurrentY() const
}

abstract class Command {
  +virtual void execute() = 0;
}

class CommandParser {
  +Command* parse(Grid* grid, const std::string& input)
}

class DimensionCommand {
  -Grid* m_grid;
  -int m_size;
  +void execute() override
}

class MoveToCommand {
  -Grid* m_grid;
  -int m_x;
  -int m_y
  +void execute() override
}

class LineToCommand {
  -Grid* m_grid;
  -int m_x;
  -int m_y
  +void execute() override
}


Grid ..> Command
Command <|-- DimensionCommand
Command <|-- MoveToCommand
Command <|-- LineToCommand
CommandParser --> Command
@enduml -->