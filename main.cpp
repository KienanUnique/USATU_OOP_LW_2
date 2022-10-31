#include <iostream>
#include <cmath>

using namespace std;


class Point2D {
protected:
    double x, y;

public:
    Point2D() {
        cout << "Point2D: Constructor" << endl;
        x = 0;
        y = 0;
    }

    Point2D(double set_x, double set_y) {
        cout << "Point2D: Constructor" << endl;
        x = set_x;
        y = set_y;
    }

    Point2D(Point2D const &point2D) {
        cout << "Point2D: Constructor" << endl;
        x = point2D.x;
        y = point2D.y;
    }

    ~Point2D() {
        cout << "Point2D: Destructor" << endl;
    }

    double GetX() {
        cout << "Point2D: GetX" << endl;
        return x;
    }

    double GetY() {
        cout << "Point2D: GetY" << endl;
        return y;
    }

    void SetX(double set_x) {
        cout << "Point2D: SetX" << endl;
        x = set_x;
    }

    void SetY(double set_y) {
        cout << "Point2D: SetY" << endl;
        y = set_y;
    }
};

class Point3D : public Point2D {
private:
    double z;

public:
    Point3D() : Point2D() {
        cout << "Point3D: Constructor" << endl;
        z = 0;
    }

    Point3D(Point3D const &point3D) {
        cout << "Point3D: Constructor" << endl;
        x = point3D.x;
        y = point3D.y;
    }

    Point3D(double set_x, double set_y, double set_z) : Point2D(set_x, set_y) {
        cout << "Point3D: Constructor" << endl;
        z = set_z;
    }

    Point3D(Point2D set_point2D, double setY, double setZ) : Point2D(set_point2D.GetX(), set_point2D.GetY()) {
        cout << "Point3D: Constructor" << endl;
        z = setZ;
    }

    ~Point3D() {
        cout << "Point3D: Destructor" << endl;
    }

    double GetZ() {
        cout << "Point3D: GetZ" << endl;
        return z;
    }

    void SetZ(double set_z) {
        cout << "Point3D: SetZ" << endl;
        z = set_z;
    }
};

class Figure2D {
public:
    virtual double GetSquare() = 0;

    virtual double GetPerimeter() = 0;
};

class Rectangle : Figure2D {
protected:
    Point2D first_point, second_point;

private:
    double CalculateSideA() {
        cout << "Rectangle: CalculateSideA" << endl;
        return abs(first_point.GetX() - second_point.GetX());
    }

    double CalculateSideB() {
        cout << "Rectangle: CalculateSideB" << endl;
        return abs(first_point.GetY() - second_point.GetY());
    }

public:
    Rectangle(Rectangle const &rectangle) {
        cout << "Rectangle: Constructor" << endl;
        first_point = rectangle.first_point;
        second_point = rectangle.second_point;
    }

    Rectangle(Point2D set_first_point, Point2D set_second_point) {
        cout << "Rectangle: Constructor" << endl;
        first_point = set_first_point;
        second_point = set_second_point;
    }

    Rectangle(double first_point_x, double first_point_y, double second_point_x, double second_point_y) {
        cout << "Rectangle: Constructor" << endl;
        first_point.SetX(first_point_x);
        first_point.SetY(first_point_y);
        second_point.SetX(second_point_x);
        second_point.SetY(second_point_y);
    }

    ~Rectangle() {
        cout << "Rectangle: Destructor" << endl;
    }

    Point2D GetFirstPoint() {
        cout << "Rectangle: GetFirstPoint" << endl;
        return first_point;
    }

    Point2D GetSecondPoint() {
        cout << "Rectangle: GetSecondPoint" << endl;
        return second_point;
    }

    void SetFirstPoint(Point2D set_point2D) {
        cout << "Rectangle: SetFirstPoint" << endl;
        first_point = set_point2D;
    }

    void SetSecondPoint(Point2D set_point2D) {
        cout << "Rectangle: SetSecondPoint" << endl;
        second_point = set_point2D;
    }

    double GetPerimeter() override {
        cout << "Rectangle: GetPerimeter" << endl;
        return (CalculateSideA() + CalculateSideB()) * 2;
    }

    double GetSquare() override {
        cout << "Rectangle: GetSquare" << endl;
        return CalculateSideA() * CalculateSideB();
    }
};

class Square : public Rectangle {
private:
    double CalculateSide() {
        cout << "Square: CalculateSide" << endl;
        return abs(first_point.GetY() - second_point.GetY());
    }

public:
    Square(Square const &square) {
        first_point = square.first_point;
        second_point = square.second_point;
    }

    Square(Point2D set_first_point, Point2D set_second_point) : Rectangle(set_first_point, set_second_point) {

    };

    Square(double first_point_x, double first_point_y, double second_point_x, double second_point_y) : Rectangle(
            first_point_x, first_point_y, second_point_x, second_point_y) {

    };

    Point2D GetFirstPoint() {
        return first_point;
    }

    Point2D GetSecondPoint() {
        return second_point;
    }

    void SetFirstPoint(Point2D set_point2D) {
        first_point = set_point2D;
    }

    void SetSecondPoint(Point2D set_point2D) {
        second_point = set_point2D;
    }

    double GetPerimeter() override {
        return CalculateSide() * 4;
    }

    double GetSquare() override {
        return CalculateSide() * CalculateSide();
    }
};

class Triangle : public Figure2D {
private:
    Point2D first_point, second_point, third_point;

    static double CalculateSide(Point2D first_side_point, Point2D second_side_point) {
        return sqrt(
                (second_side_point.GetX() - first_side_point.GetX()) *
                (second_side_point.GetX() - first_side_point.GetX()) +
                (second_side_point.GetY() - first_side_point.GetY()) *
                (second_side_point.GetY() - first_side_point.GetY()));
    }

    double CalculateSideA() {
        return CalculateSide(first_point, second_point);
    }

    double CalculateSideB() {
        return CalculateSide(first_point, third_point);
    }

    double CalculateSideC() {
        return CalculateSide(third_point, second_point);
    }

public:
    Point2D GetFirstPoint() {
        return first_point;
    }

    Point2D GetSecondPoint() {
        return second_point;
    }

    Point2D GetThirdPoint() {
        return second_point;
    }

    void SetFirstPoint(Point2D setPoint2D) {
        first_point = setPoint2D;
    }

    void SetSecondPoint(Point2D setPoint2D) {
        second_point = setPoint2D;
    }

    void SetThirdPoint(Point2D setPoint2D) {
        first_point = setPoint2D;
    }

    double GetPerimeter() override {
        return CalculateSideA() + CalculateSideB() + CalculateSideC();
    }

    double GetSquare() override {
        double halfPerimeter = GetPerimeter() / 2;
        return sqrt(halfPerimeter * (halfPerimeter - CalculateSideA()) * (halfPerimeter - CalculateSideB()) *
                    (halfPerimeter - CalculateSideC()));
    }
};

class Figure3D {
public:
    virtual double GetVolume() = 0;
};


int main() {
    return 0;
}
