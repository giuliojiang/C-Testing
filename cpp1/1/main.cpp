#include <iostream>

int readNumber(int minimum, int maximum)
{
    int out = 0;
    do
    {
        std::cin >> out;
        if (!(minimum <= out && out <= maximum))
        {
            std::cout << "number must be between " << minimum << " and " << maximum << std::endl;
        }
    }
    while (!(minimum <= out && out <= maximum));
    return out;
}

void calculateRectangleMetrics(int width, int length, int* perimeter, int& area)
{
    *perimeter = 2*width + 2*length;
    area = width * length;
}

int main(void)
{
    int width = readNumber(1, 10000);
    int length = readNumber(1, 20000);
    int perimeter = 0;
    int area = 0;
    calculateRectangleMetrics(width, length, &perimeter, area);
    std::cout << "perimeter=" << perimeter << std::endl;
    std::cout << "area=" << area << std::endl;
    return 0;
}
