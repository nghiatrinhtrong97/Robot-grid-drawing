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
    int x() const;
    int y() const;

private:
    int m_x;
    int m_y;
};

#endif // ROBOT_H