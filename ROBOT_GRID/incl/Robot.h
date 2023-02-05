#ifndef ROBOT_H
#define ROBOT_H

class Grid;

class Robot
{
public:
    Robot();
    void moveTo(Grid *grid, int x, int y);
    void drawLineTo(Grid *grid, int x, int y);
    void showGrid(Grid *grid, int N);
    int getCurrentX() const;
    int getCurrentY() const;

private:
    int m_currentX;
    int m_currentY;
};

#endif // ROBOT_H