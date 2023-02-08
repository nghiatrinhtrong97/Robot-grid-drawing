#ifndef GRID_H
#define GRID_H

// class Grid {
// public:
//   void fillSquare(int x, int y);
//   bool isSquareFilled(int x, int y);
// };

#include <vector>

/******************************************************************************************
Grid: This class represents the square grid that robot operates on. 
It has a member variable int m_size that stores the size of the grid and a two-dimensional array m_square_grid that represents the grid. 
It implements the executeCommand method to execute a Command 
*******************************************************************************************/

class Grid
{
public:
    Grid();
    ~Grid();
    void setSize(int size);
    void moveTo(int x1, int y1);
    void drawLineTo(int x2, int y2);
    void showGrid() const;
    int getCurrentX() const;
    int getCurrentY() const;
    float findMin(float x1, float x2);
    float findMax(float x1, float x2);


private:
    
public:
    int m_size;
    int m_currentX;
    int m_currentY;
    std::vector<std::vector<int>> m_square_grid;
};
#endif // GRID_H