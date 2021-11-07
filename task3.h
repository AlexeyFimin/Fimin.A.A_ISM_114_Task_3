#include <iostream>
#include <cmath>

using namespace std;


class Triangle;
class Vector;

class Point {
    friend class Vector;
    friend class Triangle;
private:
    int x;
    int y;
public:
    Point() = default;
    /**
 * @brief дефолтный конструктор
 *
 */
    Point(int x, int y);
    /**
 * @brief конструктор с параметрами
 *
 */
};

class Vector {
    friend class Triangle;
private:
    Point p1;
    Point p2;

public:
    Vector() = default;
    /**
 * @brief дефолтный конструктор
 *
 */

    Vector(Point p1, Point p2);
    /**
 * @brief конструктор с параметрами
 *
 */

    int GetX() const;
    /**
 * @brief гетер поля "x"
 *
 */

    int GetY() const;
    /**
 * @brief гетер поля "y"
 *
 */

    double GetMod() const;
    /**
 * @brief взятие модуля вектора
 *
 */

    double ScalarProduct(const Vector& other) const;
    /**
 * @brief результат скалярного произведения
 *
 */
};



class Triangle {
protected:
    Point a;
    Point b;
    Point c;
    bool isTriangle(double mod_a, double mod_b, double mod_c) const;
    /**
 * @brief метод, определяющий, может ли существовать треугольник с такими сторонами
 *
 */

    double getAngle(const Vector& first, const Vector& second);
    /**
 * @brief взятие угла между двумя векторами
 *
 */

    void AddValueToText(string& text, int value);
    /**
 * @brief добавление числа "value" к строке "text"
 *
 */


public:
    Triangle();
    /**
 * @brief дефолтный конструктор
 *
 */

    Triangle(Point a, Point b, Point c);
    /**
 * @brief конструктор с параметрами
 *
 */

    void setA(Point p);
    /**
 * @brief сетер поля "a"
 *
 */

    void setB(Point p);
    /**
 * @brief сетер поля "b"
 *
 */

    void setC(Point p);
    /**
 * @brief сетер поля "c"
 *
 */

    void GetAngles();
    /**
 * @brief взятие углов у треугольника
 *
 */

    double getPerimeter();
    /**
 * @brief взятие периметра у треугольника
 *
 */

    string ToString();
    /**
 * @brief приведение треугольника к string
 *
 */
};


class Equilateral : public Triangle {
private:
    double square;
public:
    Equilateral(Point a, Point b, Point c);
    /**
 * @brief конструктор с параметрами
 *
 */

    double getSquare();
    /**
 * @brief взятие площади
 *
 */
};
