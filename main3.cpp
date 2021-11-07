#include "Triangle.h"

int main() {

    Triangle tr(Point(0, 0), Point(1, 0), Point(0, 1));
    tr.setB(Point(4, 5));
    tr.GetAngles();
    cout << "Perimeter: " << tr.getPerimeter() << endl;
    cout << tr.ToString();

    Equilateral eq(Point(0, 0), Point(1, 0), Point(0, 1));
    cout << eq.ToString();
    cout << eq.getSquare();
    return 0;
}
 
