#include <iostream>
#include <cmath>
using namespace std;

class Figure {
public:
    virtual void display() const = 0;
    virtual void get() = 0;                
    virtual double area() const = 0;       
    virtual double perimeter() const = 0;  
    virtual ~Figure() {}                   
};

class Circle : public Figure {
private:
    double radius;
public:
    void get() override {
        cout << "Enter radius of circle: ";
        cin >> radius;
    }
    
    void display() const override {
        cout << "Circle: Radius=" << radius 
             << ", Area=" << area() 
             << ", Perimeter=" << perimeter() << endl;
    }
    
    double area() const override {
        return 3.14159 * radius * radius;
    }
    
    double perimeter() const override {
        return 2 * 3.14159 * radius;
    }
};

class Rectangle : public Figure {
private:
    double length;
    double breadth;
public:
    void get() override {
        cout << "Enter length of rectangle: ";
        cin >> length;
        cout << "Enter breadth of rectangle: ";
        cin >> breadth;
    }
    
    void display() const override {
        cout << "Rectangle: Length=" << length 
             << ", Breadth=" << breadth 
             << ", Area=" << area() 
             << ", Perimeter=" << perimeter() << endl;
    }
    
    double area() const override {
        return length * breadth;
    }
    
    double perimeter() const override {
        return 2 * (length + breadth);
    }
};

class Triangle : public Figure {
private:
    double side1, side2, side3;
public:
    void get() override {
        cout << "Enter three sides of triangle: ";
        cin >> side1 >> side2 >> side3;
    }
    
    void display() const override {
        cout << "Triangle: Sides=" << side1 << "," << side2 << "," << side3 
             << ", Area=" << area() 
             << ", Perimeter=" << perimeter() << endl;
    }
    
    double area() const override {
        double s = perimeter() / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
    
    double perimeter() const override {
        return side1 + side2 + side3;
    }
};

int main() {
    Figure* figures[3];
    
    cout << "=== CREATING FIGURES ===" << endl;
    
    cout << "\n--- Circle ---" << endl;
    figures[0] = new Circle();
    figures[0]->get();
      
    cout << "\n--- Rectangle ---" << endl;
    figures[1] = new Rectangle();
    figures[1]->get();
    
    cout << "\n--- Triangle ---" << endl;
    figures[2] = new Triangle();
    figures[2]->get();

    cout << "\n=== DISPLAYING ALL FIGURES ===" << endl;
    for(int i = 0; i < 3; i++) {
        figures[i]->display();
    }
    
    cout << "\n=== CALCULATING TOTALS ===" << endl;
    double totalArea = 0;
    double totalPerimeter = 0;
    
    for(int i = 0; i < 3; i++) {
        totalArea += figures[i]->area();
        totalPerimeter += figures[i]->perimeter();
    }
    
    cout << "Total Area of all figures: " << totalArea << endl;
    cout << "Total Perimeter of all figures: " << totalPerimeter << endl;

    cout << "\n=== INDIVIDUAL FUNCTION CALLS ===" << endl;
    for(int i = 0; i < 3; i++) {
        cout << "Figure " << (i+1) << ":" << endl;
        cout << "Area: " << figures[i]->area() << endl;
        cout << "Perimeter: " << figures[i]->perimeter() << endl;
        cout << "---" << endl;
    }

    for(int i = 0; i < 3; i++) {
        delete figures[i];
    }
    
    return 0;
}
