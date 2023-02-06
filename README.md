# Robot-grid-drawing

Robot grid drawing
![image](https://user-images.githubusercontent.com/71679681/217058506-1b135a52-7239-45d6-971e-5b48bd5eeaed.png)

@startuml
class Grid {
  -int m_size
  -int m_currentX
  -int m_currentY
  -std::vector<std::vector<int>> m_square_grid
  +void setSize(int size)
  +void moveTo(int x1, int y1)
  +void drawLineTo(int x2, int y2)
  +void lineTo(int x, int y)
  +void showGrid() const
  +int getCurrentX() const
  +int getCurrentY() const
}

class Command {
  +virtual void execute(Grid& grid) = 0;
}

class DimensionCommand{
  -int n
  -Grid* m_grid
  +DimensionCommand(Grid* grid, int size)
  +void execute() override
}

class MoveToCommand {
  -int m_x
  -int m-y
  -Grid* m_grid
  +MoveToCommand(Grid* grid, int x, int y)
  +void execute() override
}

class LineToCommand{
  -int m_x
  -int m_y
  -Grid* m_grid
  +LineToCommand(Grid* grid, int x, int y)
  +void execute() override
}

Grid -down-> Command
Command <|-- DimensionCommand
Command <|-- MoveToCommand
Command <|-- LineToCommand
@enduml


