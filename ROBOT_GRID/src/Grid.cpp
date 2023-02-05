// void Grid::fillSquare(int x, int y) {
//   // Implementation to fill a square on the grid
// }

// bool Grid::isSquareFilled(int x, int y) {
//   // Implementation to check if a square is filled
// }

#include "../incl/Grid.h"
#include <iostream>

Grid::Grid()
    : m_size(0), m_grid()
{
}

void Grid::setSize(int size)
{
    m_size = size;
    m_grid.resize(size, std::vector<int>(size, 0));
}

void Grid::drawMoveTo(int x1, int y1)
{
    m_grid[x1][y1] = 1;
}

void Grid::drawLineTo(int x1, int y1, int x2, int y2)
{
    int xMin = std::min(x1, x2);
    int xMax = std::max(x1, x2);
    int yMin = std::min(y1, y2);
    int yMax = std::max(y1, y2);

    for (int x = xMin; x <= xMax; ++x) {
        for (int y = yMin; y <= yMax; ++y) {
            m_grid[x][y] = 1;
        }
    }
}

void Grid::print(int N) const
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << "|--";
        }
        std::cout << "|" << std::endl;
        for (int j = 0; j < N; j++) {
            if(m_grid[i][j] == 1)
            {
                std::cout << "|+ ";
            }
            else
            {
                std::cout << "|  ";
            }
        }
        std::cout << "|" << std::endl;
    }
    for (int j = 0; j < N; j++) {
        std::cout << "|--";
    }
    std::cout << "|" << std::endl;
}