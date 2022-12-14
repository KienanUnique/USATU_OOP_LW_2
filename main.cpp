#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


class Point2D {
private:
    double x, y;

public:
    Point2D() : x(0), y(0) {
        cout << "Point2D:\t Point2D()" << endl;
    }

    Point2D(double set_x, double set_y) : x(set_x), y(set_y) {
        cout << "Point2D:\t Point2D(double set_x, double set_y)" << endl;
    }

    Point2D(Point2D const &point2D) : x(point2D.x), y(point2D.y) {
        cout << "Point2D:\t Point2D(Point2D const &point2D)" << endl;
    }

    ~Point2D() {
        cout << "Point2D:\t ~Point2D()" << endl;
    }

    double GetX() const {
        cout << "Point2D:\t double GetX()" << endl;
        return x;
    }

    double GetY() const {
        cout << "Point2D:\t double GetY()" << endl;
        return y;
    }

    void SetX(double set_x) {
        cout << "Point2D:\t void SetX(double set_x)" << endl;
    }

    void SetY(double set_y) {
        cout << "Point2D:\t void SetY(double set_y)" << endl;
        y = set_y;
    }

    void SetCoordinates(double set_x, double set_y) {
        cout << "Point2D:\t void SetCoordinates(double set_x, double set_y)" << endl;
        x = set_x;
        y = set_y;
    }
};

class Figure2D {
public:
    Figure2D() {
        cout << "Figure2D:\t Figure2D()" << endl;
    }

    virtual ~Figure2D() {
        cout << "Figure2D:\t ~Figure2D()" << endl;
    }

    virtual double GetSquare() {
        cout << "Figure2D:\t double GetSquare()" << endl;
        return -1;
    }

    virtual double GetPerimeter() {
        cout << "Figure2D:\t double GetPerimeter()" << endl;
        return -1;
    }
};

class Rectangle : public Figure2D {
protected:
    Point2D first_point, second_point;

    double CalculateSideA() {
        cout << "Rectangle:\t double CalculateSideA()" << endl;
        return abs(first_point.GetX() - second_point.GetX());
    }

    double CalculateSideB() {
        cout << "Rectangle:\t double CalculateSideB()" << endl;
        return abs(first_point.GetY() - second_point.GetY());
    }

public:
    Rectangle(Rectangle const &rectangle) : first_point(rectangle.first_point), second_point(rectangle.second_point) {
        cout << "Rectangle:\t Rectangle(Rectangle const &rectangle)" << endl;
    }

    Rectangle(const Point2D &set_first_point, const Point2D &set_second_point) : first_point(set_first_point),
                                                                                 second_point(set_second_point) {
        cout << "Rectangle:\t Rectangle(const Point2D &set_first_point, const Point2D &set_second_point)" << endl;
    }

    Rectangle(const Point2D &set_left_down_point, double side_a, double side_b) : first_point(set_left_down_point),
                                                                                  second_point(
                                                                                          set_left_down_point.GetX() +
                                                                                          side_a,
                                                                                          set_left_down_point.GetY() +
                                                                                          side_b) {
        cout << "Rectangle:\t Rectangle(const Point2D &set_left_down_point, double side_a, double side_b)" << endl;
    }

    Rectangle(double first_point_x, double first_point_y, double second_point_x, double second_point_y) : first_point(
            first_point_x, first_point_y), second_point(second_point_x, second_point_y) {
        cout
                << "Rectangle:\t Rectangle(double first_point_x, double first_point_y, double second_point_x, double second_point_y)"
                << endl;
    }

    Rectangle() : first_point(0, 0), second_point(0, 0) {
        cout << "Rectangle:\t Rectangle()" << endl;
    }

    ~Rectangle() override {
        cout << "Rectangle:\t ~Rectangle()" << endl;
    }

    Point2D GetFirstPoint() {
        cout << "Rectangle:\t Point2D GetFirstPoint()" << endl;
        return first_point;
    }

    Point2D GetSecondPoint() {
        cout << "Rectangle:\t Point2D GetSecondPoint()" << endl;
        return second_point;
    }

    void SetFirstPoint(const Point2D &set_point2D) {
        cout << "Rectangle:\t void SetFirstPoint(const Point2D &set_point2D)" << endl;
        first_point = set_point2D;
    }

    void SetSecondPoint(const Point2D &set_point2D) {
        cout << "Rectangle:\t void SetSecondPoint(const Point2D &set_point2D)" << endl;
        second_point = set_point2D;
    }

    double GetPerimeter() override {
        cout << "Rectangle:\t double GetPerimeter()" << endl;
        return (CalculateSideA() + CalculateSideB()) * 2;
    }

    double GetSquare() override {
        cout << "Rectangle:\t double GetSquare()" << endl;
        return CalculateSideA() * CalculateSideB();
    }
};

class RectangleAlternative : public Figure2D {
protected:
    Point2D *first_point, *second_point;

    double CalculateSideA() {
        cout << "RectangleAlternative:\t double CalculateSideA()" << endl;
        return abs(first_point->GetX() - second_point->GetX());
    }

    double CalculateSideB() {
        cout << "RectangleAlternative:\t double CalculateSideB()" << endl;
        return abs(first_point->GetY() - second_point->GetY());
    }

public:
    RectangleAlternative(RectangleAlternative const &rectangle) : first_point(new Point2D(*rectangle.first_point)),
                                                                  second_point(new Point2D(*rectangle.second_point)) {
        cout << "RectangleAlternative:\t RectangleAlternative(RectangleAlternative const &rectangle)" << endl;
    }

    RectangleAlternative(const Point2D &set_first_point, const Point2D &set_second_point) : first_point(
            new Point2D(set_first_point)), second_point(new Point2D(set_second_point)) {
        cout << "RectangleAlternative:\t RectangleAlternative(Point2D *set_first_point, Point2D *set_second_point)"
             << endl;
    }

    RectangleAlternative() : first_point(new Point2D(0, 0)), second_point(new Point2D(0, 0)) {
        cout << "RectangleAlternative:\t RectangleAlternative()" << endl;
    }

    ~RectangleAlternative() override {
        cout << "~RectangleAlternative():\t ~Rectangle()" << endl;
        delete first_point;
        delete second_point;
    }

    Point2D GetFirstPoint() {
        cout << "RectangleAlternative:\t Point2D GetFirstPoint()" << endl;
        return *first_point;
    }

    Point2D GetSecondPoint() {
        cout << "RectangleAlternative:\t Point2D GetSecondPoint()" << endl;
        return *second_point;
    }

    Point2D *GetFirstPointPointer() {
        cout << "RectangleAlternative:\t Point2D* GetFirstPointPointer()" << endl;
        return first_point;
    }

    Point2D &GetSecondPointPointer() {
        cout << "RectangleAlternative:\t Point2D& GetSecondPointPointer()" << endl;
        return *second_point;
    }

    void SetFirstPointPointer(Point2D *set_point2D) {
        cout << "RectangleAlternative:\t void SetFirstPointPointer(Point2D *set_point2D)" << endl;
        first_point = set_point2D;
    }

    void SetSecondPointPointer(Point2D *set_point2D) {
        cout << "RectangleAlternative:\t void SetSecondPointPointer(Point2D *set_point2D)" << endl;
        second_point = set_point2D;
    }

    void SetFirstPoint(const Point2D &set_point2D) {
        cout << "RectangleAlternative:\t void SetFirstPoint(const Point2D& set_point2D)" << endl;
        *first_point = set_point2D;
    }

    void SetSecondPoint(const Point2D &set_point2D) {
        cout << "RectangleAlternative:\t void SetSecondPoint(const Point2D& set_point2D)" << endl;
        *second_point = set_point2D;
    }

    double GetPerimeter() override {
        cout << "RectangleAlternative:\t double GetPerimeter()" << endl;
        return (CalculateSideA() + CalculateSideB()) * 2;
    }

    double GetSquare() override {
        cout << "RectangleAlternative:\t double GetSquare()" << endl;
        return CalculateSideA() * CalculateSideB();
    }
};

class Square : public Rectangle {
private:
    using Rectangle::SetSecondPoint;

public:
    Square(Square const &square) : Rectangle(square) {
        cout << "Square:\t Square(Square const &square) : Rectangle(square)" << endl;
    }

    Square(const Point2D &set_first_point, double side_length) : Rectangle(set_first_point.GetX(),
                                                                           set_first_point.GetY(),
                                                                           set_first_point.GetX() + side_length,
                                                                           set_first_point.GetY() + side_length) {
        cout
                << "Square:\t Square(const Point2D &set_first_point, double side_length) : Rectangle(set_first_point.GetX(), set_first_point.GetY(), set_first_point.GetX() + side_length, set_first_point.GetY() + side_length)"
                << endl;
    };

    Square(double first_point_x, double first_point_y, double side_length) : Rectangle(
            first_point_x, first_point_y, first_point_x + side_length, first_point_y + side_length) {
        cout
                << "Square:\t Square(double first_point_x, double first_point_y, double side_length) : Rectangle(first_point_x, first_point_y, first_point_x + side_length, first_point_y + side_length)"
                << endl;
    };

    Square() : Rectangle() {
        cout << "Square:\t Square() : Rectangle()" << endl;
    }


    ~Square() override {
        cout << "Square:\t ~Square()" << endl;
    }

    void SetSideLength(double side_length) {
        cout << "Square:\t void SetSideLength(double side_length)" << endl;
        second_point.SetCoordinates(first_point.GetX() + side_length, first_point.GetY() + side_length);
    }

    double GetPerimeter() override {
        cout << "Square:\t double GetPerimeter()" << endl;
        return CalculateSideA() * 4;
    }
};

class Triangle : public Figure2D {
private:
    Point2D first_point, second_point, third_point;

    static double CalculateSide(const Point2D &first_side_point, const Point2D &second_side_point) {
        cout
                << "Triangle:\t static double CalculateSide(const Point2D &first_side_point, const Point2D &second_side_point)"
                << endl;
        return sqrt(
                (second_side_point.GetX() - first_side_point.GetX()) *
                (second_side_point.GetX() - first_side_point.GetX()) +
                (second_side_point.GetY() - first_side_point.GetY()) *
                (second_side_point.GetY() - first_side_point.GetY()));
    }

    double CalculateSideA() {
        cout << "Triangle:\t double CalculateSideA()" << endl;
        return CalculateSide(first_point, second_point);
    }

    double CalculateSideB() {
        cout << "Triangle:\t double CalculateSideB()" << endl;
        return CalculateSide(first_point, third_point);
    }

    double CalculateSideC() {
        cout << "Triangle:\t double CalculateSideC()" << endl;
        return CalculateSide(third_point, second_point);
    }


public:
    Triangle(const Point2D &set_first_point, const Point2D &set_second_point, const Point2D &set_third_point)
            : first_point(set_first_point), second_point(set_second_point), third_point(set_third_point) {
        cout
                << "Triangle:\t Triangle(const Point2D &set_first_point, const Point2D &set_second_point, const Point2D &set_third_point)"
                << endl;
    }

    Triangle(const double &set_first_point_x, const double &set_first_point_y, const double &set_second_point_x,
             const double &set_second_point_y, const double &set_third_point_x, const double &set_third_point_y)
            : first_point(set_first_point_x, set_first_point_y), second_point(set_second_point_x, set_second_point_y),
              third_point(set_third_point_x, set_third_point_y) {
        cout
                << "Triangle:\t Triangle(const double &set_first_point_x, const double &set_first_point_y, const double &set_second_point_x, const double &set_second_point_y, const double &set_third_point_x, const double &set_third_point_y) "
                << endl;
    }

    Triangle(const Triangle &triangle) : first_point(triangle.first_point), second_point(triangle.second_point),
                                         third_point(triangle.third_point) {
        cout << "Triangle:\t Triangle(const Triangle &triangle)" << endl;
    }

    Triangle() : first_point(0, 0), second_point(0, 0), third_point(0, 0) {
        cout << "Triangle:\t Triangle()" << endl;
    }

    ~Triangle() override {
        cout << "Triangle:\t ~Triangle()" << endl;
    }

    Point2D GetFirstPoint() {
        cout << "Triangle:\t Point2D GetFirstPoint()" << endl;
        return first_point;
    }

    Point2D GetSecondPoint() {
        cout << "Triangle:\t Point2D GetSecondPoint()" << endl;
        return second_point;
    }

    Point2D GetThirdPoint() {
        cout << "Triangle:\t Point2D GetThirdPoint()" << endl;
        return second_point;
    }

    void SetFirstPoint(const Point2D &setPoint2D) {
        cout << "Triangle:\t void SetFirstPoint(const Point2D &setPoint2D)" << endl;
        first_point = setPoint2D;
    }

    void SetSecondPoint(const Point2D &setPoint2D) {
        cout << "Triangle:\t void SetSecondPoint(const Point2D &setPoint2D)" << endl;
        second_point = setPoint2D;
    }

    void SetThirdPoint(const Point2D &setPoint2D) {
        cout << "Triangle:\t void SetThirdPoint(const Point2D &setPoint2D)" << endl;
        first_point = setPoint2D;
    }

    double GetPerimeter() override {
        cout << "Triangle:\t double GetPerimeter()" << endl;
        return CalculateSideA() + CalculateSideB() + CalculateSideC();
    }

    double GetSquare() override {
        cout << "Triangle:\t double GetSquare()" << endl;
        double halfPerimeter = GetPerimeter() / 2;
        return sqrt(halfPerimeter * (halfPerimeter - CalculateSideA()) * (halfPerimeter - CalculateSideB()) *
                    (halfPerimeter - CalculateSideC()));
    }
};

class CompositionFigure2D {
private:
    vector<Figure2D *> figures;

public:
    CompositionFigure2D() {
        cout << "CompositionFigure2D:\t CompositionFigure2D()" << endl;
    }

    ~CompositionFigure2D() {
        cout << "CompositionFigure2D:\t ~CompositionFigure2D()" << endl;
        while (!figures.empty()) {
            Figure2D *backFigure = figures.back();
            figures.pop_back();
            delete backFigure;
        }
    }

    void AddFigure(Figure2D *figure) {
        cout << "CompositionFigure2D:\t void AddFigure(Figure2D *figure)" << endl;
        figures.push_back(figure);
    }

    double GetCompositionSquare() {
        cout << "CompositionFigure2D:\t double GetCompositionSquare()" << endl;
        double compositionSquare = 0;
        for (auto i: figures) {
            compositionSquare += i->GetSquare();
        }
        return compositionSquare;
    }

    double GetCompositionPerimeter() {
        cout << "CompositionFigure2D:\t double GetCompositionPerimeter()" << endl;
        double compositionPerimeter = 0;
        for (auto i: figures) {
            compositionPerimeter += i->GetPerimeter();
        }
        return compositionPerimeter;
    }
};

int main() {
    double tmp_val;
    Point2D pointA = Point2D(0, 0);
    Point2D pointB = Point2D(5, 5);
    Point2D pointC = Point2D(10, 0);
    cout << "==============================" << endl << endl;

    Figure2D **figures = new Figure2D *[3];
    cout << "----------" << endl;
    figures[0] = new Rectangle(pointA, pointB);
    cout << "----------" << endl;
    figures[1] = new Square(pointA, 25);
    cout << "----------" << endl;
    figures[2] = new Triangle(pointA, pointB, pointC);
    cout << "----------" << endl;

    for (int i = 0; i < 3; i++) {
        tmp_val = figures[i]->GetPerimeter();
        cout << "Calculated perimeter: " << tmp_val << endl << endl;
        cout << "----------" << endl;
    }

    cout << "==============================" << endl << endl;

    CompositionFigure2D compositionFigure2D;
    for (int i = 0; i < 3; i++) {
        cout << "----------" << endl;
        compositionFigure2D.AddFigure(figures[i]);
    }
    cout << "----------" << endl;
    tmp_val = compositionFigure2D.GetCompositionSquare();
    cout << "Calculated square: " << tmp_val << endl;
    cout << "----------" << endl;
    tmp_val = compositionFigure2D.GetCompositionPerimeter();
    cout << "Calculated perimeter: " << tmp_val << endl;
    cout << "==============================" << endl << endl;

    Rectangle rectangle = Rectangle(pointA, pointB);
    cout << "----------" << endl;
    tmp_val = rectangle.GetSquare();
    cout << "Calculated square: " << tmp_val << endl;
    cout << "==============================" << endl << endl;

    RectangleAlternative rectangleAlternative = RectangleAlternative(pointA, pointB);
    cout << "----------" << endl;
    tmp_val = rectangleAlternative.GetSquare();
    cout << "Calculated square: " << tmp_val << endl;
    cout << "==============================" << endl << endl;

    Square square = Square(pointA, 25);
    cout << "----------" << endl;
    tmp_val = square.GetSquare();
    cout << "Calculated square: " << tmp_val << endl;
    cout << "----------" << endl;
    tmp_val = square.GetFirstPoint().GetX();
    cout << "Get x: " << tmp_val << endl;
    cout << "----------" << endl;
    square.SetSideLength(1);
    cout << "----------" << endl;
    tmp_val = square.GetSquare();
    cout << "Calculated square: " << tmp_val << endl;
    cout << "==============================" << endl << endl;

    Rectangle square_rectangle = Square(pointA, 25);
    cout << "----------" << endl;
    tmp_val = square_rectangle.GetSquare();
    cout << "Calculated square: " << tmp_val << endl;
    cout << "==============================" << endl << endl;

    Square square_empty;
    cout << "----------" << endl;
    tmp_val = square_empty.GetSquare();
    cout << "Calculated square: " << tmp_val << endl;
    cout << "----------" << endl;
    square_empty.SetSideLength(8);
    cout << "----------" << endl;
    tmp_val = square_empty.GetSquare();
    cout << "Calculated square: " << tmp_val << endl;
    cout << "----------" << endl;
    square_empty = Square(0, 0, 3);
    cout << "----------" << endl;
    tmp_val = square_empty.GetSquare();
    cout << "Calculated square: " << tmp_val << endl;
    cout << "==============================" << endl << endl;

    return 0;
}
