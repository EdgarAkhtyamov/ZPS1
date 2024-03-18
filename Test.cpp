#include <iostream>
#include <algorithm>


//Структура точки на плоскости
struct Point {
    double x;
    double y;
};

//Функция для проверки, находится ли точка C левее/правее AB 
bool onSegment(Point a, Point b, Point c) {
    if (c.x <= std::max(a.x, b.x) && c.x >= std::min(a.x, b.x) && c.y <= std::max(a.y, b.y) && c.y >= std::min(a.y, b.y)) {
        return true;
    }
    return false;
}
//Направление вектора (отрезка)
int direction(Point a, Point b, Point c) {
    double val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    if (val == 0) 
        return 0; 
    
    else if (val > 0) return 1;

    else return 2;
}

//Функция для вычисления пересечения двух треугольников 
double CommonPartArea(Point p1_tr1, Point p2_tr1, Point p3_tr1, Point p1_tr2, Point p2_tr2, Point p3_tr2) {
    Point p1 = { std::max(p1_tr1.x, p1_tr2.x), std::max(p1_tr1.y, p1_tr2.y) };
    Point p2 = { std::min(p2_tr1.x, p2_tr2.x), std::min(p2_tr1.y, p2_tr2.y) };

    if (p1.x >= p2.x || p1.y >= p2.y) {
        return 0.0; 
        // нет пересечения
    }

    return (p2.x - p1.x) * (p2.y - p1.y);
}

int main() {
    Point p1_tr1, p2_tr1, p3_tr1, p1_tr2, p2_tr2, p3_tr2;
    std::cin >> p1_tr1.x >> p1_tr1.y >> p2_tr1.x >> p2_tr1.y >> p3_tr1.x >> p3_tr1.y >> p1_tr2.x >> p1_tr2.y >> p2_tr2.x >> p2_tr2.y >> p3_tr2.x >> p3_tr2.y;

    double square= CommonPartArea(p1_tr1, p2_tr1, p3_tr1, p1_tr2, p2_tr2, p3_tr2);

    std::cout << "Result for the Task: " << square << std::endl;

    return 0;
}

