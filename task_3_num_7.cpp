#include <iostream>
#include <cmath>
using namespace std;

class Point;//класс *точка* (задаём треугольник через Point)
class Triangle;//сам класс Triangle
class Vector;

class Point {
    friend class Vector;
    friend class Triangle;
private:
    int x;//координаты х и y
    int y;
public:
    Point() = default;
    Point(int x, int y) : x(x), y(y) {}
};

class Vector {//2 точки в афинном прос-ве
    friend class Triangle;
private:
    Point p1;
    Point p2;

public:
    Vector() = default;

    Vector(Point p1, Point p2) : p1(p1), p2(p2) {}

    int GetX() const {//извлекаем х-овую координату из вектора
        return p2.x - p1.x;
    }

    int GetY() const {// извлекаем y-овую координату из вектора
        return p2.y - p1.y;
    }

    double GetMod() const {//GetMod считает нам длину вектора
        return pow(GetX() * GetX() + GetY() * GetY(), 0.5);
    }

    double ScalarProduct(const Vector& other) const {//скалярное произведение с другим вектором
        return GetX() * other.GetX() + GetY() * other.GetY();
    }
};



class Triangle { //класс с полями-сторонами
protected:
    Point a;
    Point b;
    Point c;
    bool isTriangle(double mod_a, double mod_b, double mod_c) const {//проверяем треугольник ли это
        if (mod_a >= mod_b + mod_c || mod_b >= mod_a + mod_c || mod_c >= mod_a + mod_b) { //(если одна из сторон большн чем сумма 2х других, то это НЕ треугольник)
            return false;
        }
        else {
            return true;
        }
    }

    double getAngle(const Vector& first, const Vector& second) {//для работы с углами
        return acos(first.ScalarProduct(second) / (first.GetMod() * second.GetMod()));
    }

    void AddValueToText(string& text, int value) { //вспомогательная функция. (поместит число в текст)
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


public:
    Triangle() : a(0, 0), b(0, 0), c(0, 0) {}

    Triangle(Point a, Point b, Point c) {
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

    void setA(Point p) {//методы изменения сторон (точку принимаем в качестве параметра)
        if (p.x != 0 && p.y != 0) {//проверка на корректность. (для остальных сторон так же)
            this->a = p;
        }
        else {
            cout << "error" << endl;
        }
    }

    void setB(Point p) { //методы изменения сторон
        if (p.x != 0 && p.y != 0) {
            this->b = p;
        }
        else {
            cout << "error" << endl;
        }
    }

    void setC(Point p) {//методы изменения сторон
        if (p.x != 0 && p.y != 0) {
            this->c = p;
        }
        else {
            cout << "error" << endl;
        }
    }

    void GetAngles() {//вычисление углов.(принимает векторы)
    //создаём углы
        cout << "first angle: " << getAngle(Vector(a, b), Vector(a, c)) << endl;
        cout << "second angle: " << getAngle(Vector(a, b), Vector(b, c)) << endl;
        cout << "third angle: " << getAngle(Vector(a, c), Vector(b, c)) << endl;
    }

    double getPerimeter() {//вычисление периметра
        return Vector(a, b).GetMod() + Vector(b, c).GetMod() + Vector(a, c).GetMod();
    }

    string ToString() {//преобразование в строку
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
};


class Equilateral : public Triangle {//класс Equilateral (наследник класса Triangle)
private:
    double square;
public:
    Equilateral(Point a, Point b, Point c) : Triangle() {//проверяем что точки составляют треугольник
        if (Vector(a, b).GetMod() == Vector(b, c).GetMod() == Vector(a, c).GetMod()) {
            this->a = a;
            this->b = b;
            this->c = c;
        }
    }

    double getSquare() {//ищем площадь
        return pow(3, 0.5) * Vector(a, b).GetMod() * Vector(a, b).GetMod() / 4;
    }
};


int main() {

    Triangle tr(Point(0, 0), Point(1, 0), Point(0, 1));
    tr.setB(Point(4, 5));//(если хотим изменить знач полей)
    tr.GetAngles();
    cout << "Perimeter: " << tr.getPerimeter() << endl;
    cout << tr.ToString();

    Equilateral eq(Point(0, 0), Point(1, 0), Point(0, 1));
    cout << eq.ToString();
    cout << eq.getSquare();
    return 0;
}
