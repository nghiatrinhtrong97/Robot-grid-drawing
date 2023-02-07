#include "../incl/Grid.h"
#include <iostream>

Grid::Grid()
    : m_size(0), m_currentX(0), m_currentY(0), m_square_grid()
{
}

void Grid::setSize(int size)
{
    m_size = size;
    m_square_grid.resize(size, std::vector<int>(size, 0));
}

int Grid::getCurrentX() const
{
    return m_currentX;
}

int Grid::getCurrentY() const
{
    return m_currentY;
}

float Grid::findMin(float x1, float x2){
    return ((x1 < x2) ? x1 : x2);
}

float Grid::findMax(float x1, float x2){
    return ((x1 > x2) ? x1 : x2);
}

void Grid::moveTo(int x1, int y1)
{
    if (x1 < 0 || x1 >= m_square_grid.size() || y1 < 0 || y1 >= m_square_grid.size())
    {
        std::cout << "Invalid input: line coordinates are out of grid boundaries." << std::endl;
        return;
    }
    m_square_grid[x1][y1] = 1;
    m_currentX = x1;
    m_currentY = y1;
}

void Grid::drawLineTo(int x, int y)
{
    if (x < 0 || x >= m_square_grid.size() || y < 0 || y >= m_square_grid.size())
    {
        std::cout << "Invalid input: line coordinates are out of grid boundaries." << std::endl;
        return;
    }

    int currentX = m_currentX;
    int currentY = m_currentY;

    float startX = (float)currentX + 0.5;
    float startY = (float)currentY + 0.5;
    float endX = (float)x + 0.5;
    float endY = (float)y + 0.5;

    int deltaX = x - currentX;
    int deltaY = y - currentY;

    if (deltaX == 0)
    {
        int yMin = std::min(currentY, y);
        int yMax = std::max(currentY, y);
        for (int yFill = yMin; yFill <= yMax; yFill++)
        {
            m_square_grid[currentX][yFill] = 1;
            // std::cout << "deltaX == 0, x: " << currentX << ", y: " << yFill << std::endl;
        }
        return;
    }

    if (deltaY == 0)
    {
        int xMin = std::min(currentX, x);
        int xMax = std::max(currentX, x);
        for (int xFill = xMin; xFill <= xMax; xFill++)
        {
            m_square_grid[xFill][currentY] = 1;
            // std::cout << "deltaY == 0, x: " << xFill << ", y: " << currentY << std::endl;
        }
        return;
    }

    float m = (float)deltaY / (float)deltaX;
    // std::cout << "m: "<< m << std::endl;
    float c = startY - m * startX;
    // std::cout << "c: "<< c << std::endl;

    int xMin = std::min(currentX, x);
    int xMax = std::max(currentX, x);
    int yMin = std::min(currentY, y);
    int yMax = std::max(currentY, y);

    float yMinFloat = std::min(startY, endY);
    float yMaxFloat = std::max(startY, endY);

    for (int xFill = xMin; xFill <= xMax; xFill++)
    {
        float yFillUpperCorner = 0;
        float yFillBottomCorner = 0;

        if((xFill == xMin)){
            yFillUpperCorner = m * (xFill+0.5) + c;
        }else{
            yFillUpperCorner = m * xFill + c;
        }

        if((xFill == xMax)){
            yFillBottomCorner = m * (xFill+0.5) + c;
        }else{
            yFillBottomCorner = m * (xFill+1) + c;
        }

        // Fix for case the line goes through one of the 4 corners of a square
        int yFillBottomCornerInt = (int)yFillBottomCorner;
        if(yFillBottomCorner == (float)yFillBottomCornerInt){
            yFillBottomCorner -= 1;
        }

        // std::cout << "yFillUpperCorner: "<< yFillUpperCorner << std::endl;
        // std::cout << "yFillBottomCorner: "<< yFillBottomCorner << std::endl;
        if (yFillUpperCorner >= yMinFloat && yFillUpperCorner <= yMaxFloat)
        {
            float yMinCorner = std::min(yFillUpperCorner, yFillBottomCorner);
            float yMaxCorner = std::max(yFillUpperCorner, yFillBottomCorner);
            // std::cout << "yMinCorner: "<< yMinCorner << std::endl;
            // std::cout << "yMaxCorner: "<< yMaxCorner << std::endl;
            for(int yFill = int(yMinCorner); yFill <= int(yMaxCorner); yFill++)
            {
                m_square_grid[xFill][yFill] = 1;
                // std::cout << "different, x: " << xFill << ", y: " << int(yFillUpperCorner) << std::endl;
            }
            // std::cout << "different, x: " << xFill << ", y: " << int(yFillUpperCorner) << std::endl;
        }
    }

    m_currentX = x;
    m_currentY = y;

    // std::cout << "end" << std::endl;
}

void Grid::showGrid() const
{
    for (int i = 0; i < m_size; i++)
    {
        for (int j = 0; j < m_size; j++)
        {
            std::cout << "|--";
        }
        std::cout << "|" << std::endl;
        for (int j = 0; j < m_size; j++)
        {
            if (m_square_grid[i][j] == 1)
            {
                std::cout << "|x ";
            }
            else
            {
                std::cout << "|  ";
            }
        }
        std::cout << "|" << std::endl;
    }
    for (int j = 0; j < m_size; j++)
    {
        std::cout << "|--";
    }
    std::cout << "|" << std::endl;
}