#ifndef GRID_H
#define GRID_H

// class Grid {
// public:
//   void fillSquare(int x, int y);
//   bool isSquareFilled(int x, int y);
// };

#include <vector>

class Grid
{
public:
    Grid();
    void setSize(int size);
    void drawMoveTo(int x1, int y1);
    void drawLineTo(int x1, int y1, int x2, int y2);
    void print(int N) const;

private:
    int m_size;
    std::vector<std::vector<int>> m_grid;
};
#endif // GRID_H