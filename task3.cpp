#include "Triangle.h"

Point::Point(int x, int y) : x(x), y(y) {}
/**
 * @brief конструктор с параметрами
 *
 */

Vector::Vector(Point p1, Point p2) : p1(p1), p2(p2) {}
/**
 * @brief конструктор с параметрами
 *
 */

int Vector::GetX() const {
    /**
 * @brief гетер поля "x"
 *
 */
    return p2.x - p1.x;
}

int Vector::GetY() const {
    /**
 * @brief гетер поля "y"
 *
 */
    return p2.y - p1.y;
}

double Vector::GetMod() const {
    /**
 * @brief взятие модуля вектора
 *
 */
    return pow(GetX() * GetX() + GetY() * GetY(), 0.5);
}

double Vector::ScalarProduct(const Vector& other) const {
    /**
 * @brief результат скалярного произведения
 *
 */
    return GetX() * other.GetX() + GetY() * other.GetY();
}

bool Triangle::isTriangle(double mod_a, double mod_b, double mod_c) const {
    /**
 * @brief метод, определяющий, может ли существовать треугольник с такими сторонами
 *
 */
    return (mod_a >= mod_b + mod_c || mod_b >= mod_a + mod_c || mod_c >= mod_a + mod_b) {
        return false;
    }
    else {
        return true;
    }
}

double Triangle::getAngle(const Vector& first, const Vector& second) {
    /**
 * @brief взятие угла между двумя векторами
 *
 */
    return acos(first.ScalarProduct(second) / (first.GetMod() * second.GetMod()));
}

void Triangle::AddValueToText(string& text, int value) {
    /**
 * @brief добавление числа "value" к строке "text"
 *
 */
    string temp;
    int ost;
    if (value == 0) {
        temp += '0';
    }
    else {
        while (value != 0) {
            ost = value % 10;
            temp += char('0' + ost);

            value -= ost;
            value /= 10;
        }
    }

    for (int i = temp.size() - 1; i >= 0; --i) {
        text += temp[i];
    }
}

Triangle::Triangle() : a(0, 0), b(0, 0), c(0, 0) {}
/**
 * @brief дефолтный конструктор
 *
 */

Triangle::Triangle(Point a, Point b, Point c) {
    /**
 * @brief конструктор с параметрами
 *
 */
    if (isTriangle(Vector(a, b).GetMod(), Vector(a, c).GetMod(), Vector(b, c).GetMod())) {//конструктор принимает точки
        //если *треугольник*, то соотв. поля - это точки из параметров
        this->a = a;
        this->b = b;
        this->c = c;
    }
    else {
        *this = Triangle();
        cout << "error" << endl;
    }
}

void Triangle::setA(Point p) {//методы изменения сторон (точку принимаем в качестве параметра)
    /**
 * @brief сетер поля "a"
 *
 */
    if (p.x != 0 && p.y != 0) {//проверка на корректность. (для остальных сторон так же)
        this->a = p;
    }
    else {
        cout << "error" << endl;
    }
}

void Triangle::setB(Point p) { //методы изменения сторон
    /**
 * @brief сетер поля "b"
 *
 */
    if (p.x != 0 && p.y != 0) {
        this->b = p;
    }
    else {
        cout << "error" << endl;
    }
}

void Triangle::setC(Point p) {
    /**
 * @brief сетер поля "c"
 *
 */
    if (p.x != 0 && p.y != 0) {
        this->c = p;
    }
    else {
        cout << "error" << endl;
    }
}

void Triangle::GetAngles() {
    /**
 * @brief взятие углов у треугольника
 *
 */
    //создаём углы
    cout << "first angle: " << getAngle(Vector(a, b), Vector(a, c)) << endl;
    cout << "second angle: " << getAngle(Vector(a, b), Vector(b, c)) << endl;
    cout << "third angle: " << getAngle(Vector(a, c), Vector(b, c)) << endl;
}

double Triangle::getPerimeter() {
    /**
 * @brief взятие периметра у треугольника
 *
 */
    return Vector(a, b).GetMod() + Vector(b, c).GetMod() + Vector(a, c).GetMod();
}

string Triangle::ToString() {
    /**
 * @brief приведение треугольника к string
 *
 */
    string text;
    text += "first side: x - ";
    AddValueToText(text, a.x);
    text += ", y - ";
    AddValueToText(text, a.y);
    text += ';';

    text += "second side: x - ";
    AddValueToText(text, b.x);
    text += ", y - ";
    AddValueToText(text, b.y);
    text += ';';

    text += "third side: x - ";
    AddValueToText(text, c.x);
    text += ", y - ";
    AddValueToText(text, c.y);
    text += ';';
    text += '\n';


    return text;
}

Equilateral::Equilateral(Point a, Point b, Point c) : Triangle() {
    /**
 * @brief конструктор с параметрами
 *
 */
    if (Vector(a, b).GetMod() == Vector(b, c).GetMod() == Vector(a, c).GetMod()) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
}

double Equilateral::getSquare() {
    /**
 * @brief взятие площади
 *
 */
    return pow(3, 0.5) * Vector(a, b).GetMod() * Vector(a, b).GetMod() / 4;
}
 
