#include <iostream>
class Figure
{
protected:
    std::string f_name = "Фигура";
    int a, b, c, d, A, B, C, D;
    int sides = 0;
    bool f_sides = false;
    virtual bool check() {
        if (sides == 0)
            return true;
        else
            return false;
    };
public:

    virtual void print_info() {
        std::cout << "\n" << f_name << ":" << std::endl;
        if (check()) {
            std::cout << "Правильная" << std::endl;
        }
        else {
            std::cout << "Неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << sides << std::endl;
    }
    std::string getName() { return f_name; }
    int geta() { return a; }
    int getb() { return b; }
    int getc() { return c; }
    int getd() { return d; }
    int getA() { return A; }
    int getB() { return B; }
    int getC() { return C; }
    int getD() { return D; }
};

class Triangle : public Figure
{
protected:
    bool check() override {
        if ((A + B + C) == 180){
            return true;
        }
        else {
            return false;
        }
    }
public:
    Triangle() {};
    Triangle(int a_, int b_, int c_, int A_, int B_, int C_) {
        f_name = "Треугольник";
        sides = 3;
        a = a_;
        b = b_;
        c = c_;
        A = A_;
        B = B_;
        C = C_;
        f_sides = check();
    }
    void print_info() override {
        Figure::print_info();
        std::cout << "Стороны: ";
        std::cout << " a = " << geta() << ", b = " << getb() << ", с = " << getc() << std::endl;;
        std::cout << "Углы:";
        std::cout << " А = " << getA() << ", В = " << getB() << ", С = " << getC()<<std::endl;
    }
       
};
class R_Triangle : public Triangle {
protected:
    bool check() override {
        if (Triangle::check() && (C == 90)) {
            return true;
        }
        else {
            return false;
        }
    }

public:
    
    R_Triangle(int a_, int b_, int c_, int A_, int B_): Triangle(a,b,c,A,B,C ){
        f_name = "Прямоугольный треугольник";
        a = a_;
        b = b_;
        c = c_;
        A = A_;
        B = B_;
        C = 90;
    }
};

class Isosceles_Triangle : public Triangle {
protected:
    bool check() override {
        if (Triangle::check() && (a==c && A==C)) {
            return true;
        }
        else {
            return false;
        }
    }
public:

    Isosceles_Triangle(int a_, int b_, int A_, int B_): Triangle(a,b,c,A,B,C) {
        f_name = "Равнобедренный треугольник";
        a = c = a_;
        b = b_;
        A = C = A_;
        B = B_;
    }
};

class Equilateral_Triangle : public Triangle{

    protected:
    bool check() override {
    if ((a==b==c && A==B==C) && (A=B=C=60)) {
        return true;
    }
    else {
        return false;
    }
}

public:
    Equilateral_Triangle(int a_):Triangle(a, b, c, A, B, C) {
        f_name = "Равносторонний треугольник";
        a = b = c = a_;
        A = B = C = 60;
    }
};


class Quadrilateral : public Figure
{
protected:
    bool check() override {
        if ((A + B + C) == 360) {
            return true;
        }
        else {
            return false;
        }
    }
public:
    void print_info() override {
        Figure::print_info();
        std::cout << "Стороны: ";
        std::cout << " a = " << geta() << ", b = " << getb() << ", с = " << getc() << ", d= "<< getd() << std::endl;;
        std::cout << "Углы:";
        std::cout << " А = " << getA() << ", В = " << getB() << ", С = " << getC()<< ", D= "<< getD() << std::endl;
    }

    Quadrilateral() {};

    Quadrilateral(int a_, int b_, int c_, int d_, int A_, int B_, int C_, int D_) {
        f_name = "Четырехугольник";
        sides = 4;
        a = a_;
        b = b_;
        c = c_;
        d = d_;
        A = A_;
        B = B_;
        C = C_;
        D = D_;
    }
};
class Parallelogram : public Quadrilateral{
protected:
    bool check() override {
        if ((A==C && B==D) && (a==c && b==c)) {
            return true;
        }
        else {
            return false;
        }
    }
public:
    Parallelogram() {};
    Parallelogram(int a_, int b_, int A_, int B_):Quadrilateral(a, b, c, d, A, B, C, D) {
        f_name = "Параллелограмм";
        a = c = a_;
        b = d = b_;
        A = C = A_;
        B = D = B_;
    }
};

class Rectangle : public Parallelogram {
protected:
    bool check() override {
        if ((A=B=C=D=90) && (a == c && b == c)) {
            return true;
        }
        else {
            return false;
        }
    }
public:
    Rectangle(int a_, int b_): Parallelogram (a,b,A,B) {
        f_name = "Прямоугольник";
        a = c = a_;
        b = d = b_;
        A = B = C = D = 90;
    }
};

class Rhomb : public Parallelogram {
protected:
    bool check() override {
        if ((A == C && B == D ) && (a = b = c =d)) {
            return true;
        }
        else {
            return false;
        }
    }
public:
    Rhomb() {};
    Rhomb(int a_, int A_, int B_) : Parallelogram(a, b, A, B) {
        f_name = "Ромб";
        a = b = c = d = a_;
        A = C = A_;
        B = D = B_;
    }
};

class Square : public Rhomb {
protected:
    bool check() override {
        if ((A =B=C=D=90) && (a = b = c = d)) {
            return true;
        }
        else {
            return false;
        }
    }
public:
    Square(int a_) : Rhomb (a,A,B){
        f_name = "Квадрат";
        a = b = c = d = a_;
        A = B = C = D = 90;
    }
};



int  main()
{
    setlocale(LC_ALL, "RUS");
    Figure figure;
    figure.print_info();
    Triangle triangle(20, 30, 40, 30, 20, 50);
    triangle.print_info();
    R_Triangle r_triangle(20, 30, 40, 30, 60);
    r_triangle.print_info();
    Isosceles_Triangle isosceles_triangle(20, 60, 30, 40);
    isosceles_triangle.print_info();
    Equilateral_Triangle equilateral_triangle(20);
    equilateral_triangle.print_info();
    Quadrilateral quadrilateral(20, 30, 40, 50, 60, 30, 30, 60);
    quadrilateral.print_info();
    Parallelogram parallelogram(45, 60, 30, 20);
    parallelogram.print_info();
    Rectangle rectangle(40, 50);
    rectangle.print_info();
    Rhomb rhomb(40, 30, 40);
    rhomb.print_info();
    Square square(30);
    square.print_info();



}