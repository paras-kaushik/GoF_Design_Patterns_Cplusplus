//
//  RenderorBridge.h
//  DESIGN_PATTERNS_AND_SOLID
//
//  Created by Paras Kaushik on 04/08/23.
//

#ifndef RenderorBridge_h
#define RenderorBridge_h
#include "Headers.h"
//
//struct MyShape {
//    virtual void draw()=0;
//};
//
//struct MyCircle: MyShape {
//    double radius;
//    void draw () override{
//        cout<<"drawing a circle";
//    }
//};
//
//
//// we want to add rendering functionality to our shapes
//// rendering can be a pixel rendering or a vector rendering
//// so for a circle i need two types of renderors
//
//
//struct MyNewShape {
//    virtual void draw()=0;
//    virtual void render()=0;
//};
//
//struct MyNewCircle1: MyNewShape {
//    double radius;
//    MyNewCircle1(double radius):radius(radius){}
//    void draw () override{
//        cout<<"drawing a circle";
//    }
//    void render () override{
//        cout<<"i render in pixels the circle of radius r="<<this->radius<<endl;
//    }
//};
//
//struct MyNewCircle2: MyNewShape {
//    double radius;
//    MyNewCircle2(double radius):radius(radius){}
//    void draw () override{
//        cout<<"drawing a circle";
//    }
//    void render () override{
//        cout<<"i render in vector the circle of radius r="<<this->radius<<endl;
//    }
//};
//
//// now we introduce a new shape sqaure
//
//struct MyNewSquare1: MyNewShape {
//    double side;
//    MyNewSquare1(double side):side(side){}
//    void draw () override{
//        cout<<"drawing a square";
//    }
//    void render () override{
//        cout<<"i render in pixels the sqaure of side l="<<this->side<<endl;
//    }
//};
//
//struct MyNewSquare2: MyNewShape {
//    double side;
//    MyNewSquare2(double side):side(side){}
//    void draw () override{
//        cout<<"drawing a square";
//    }
//    void render () override{
//        cout<<"i render in vector the sqaure of side l="<<this->side<<endl;
//    }
//};
//
//// now we futher introduce a new shape triangle
//
//struct MyNewTriangle1 : MyNewShape {
//    double side1, side2, side3;
//    MyNewTriangle1(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}
//    void draw() override {
//        cout << "drawing a triangle";
//    }
//    void render() override {
//        cout << "i render in pixels the triangle with sides: " << this->side1 << ", " << this->side2 << ", " << this->side3 << endl;
//    }
//};
//
//struct MyNewTriangle2 : MyNewShape {
//    double side1, side2, side3;
//    MyNewTriangle2(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}
//    void draw() override {
//        cout << "drawing a triangle";
//    }
//    void render() override {
//        cout << "i render in vector the triangle with sides: " << this->side1 << ", " << this->side2 << ", " << this->side3 << endl;
//    }
//};
//
//// now can infer from our code that type '1' of a concete shape is representing pixel and type 2 vector rendition
//// no if we introduce a thrid type of renering ie type '3' one class needs to be added for EVERY SHAPE ie circle, sqaure and triangle
////
////we need to create classes MyNewCircle3, MyNewSquare3, MyNewTriangle3
//// this is called a state space explosion - our classes are increasing as N * M
//// this is happening as we are trying to extend shape class in two independent dimensions
//// MyNewCircle3 with type '3' rendering
//
//struct MyNewCircle3 : MyNewShape {
//    double radius;
//    MyNewCircle3(double radius) : radius(radius) {}
//    void draw() override {
//        cout << "drawing a circle";
//    }
//    void render() override {
//        cout << "i render using type '3' for the circle of radius r=" << this->radius << endl;
//    }
//};
//
//// MyNewSquare3 with type '3' rendering
//struct MyNewSquare3 : MyNewShape {
//    double side;
//    MyNewSquare3(double side) : side(side) {}
//    void draw() override {
//        cout << "drawing a square";
//    }
//    void render() override {
//        cout << "i render using type '3' for the square of side l=" << this->side << endl;
//    }
//};
//
//// MyNewTriangle3 with type '3' rendering
//struct MyNewTriangle3 : MyNewShape {
//    double side1, side2, side3;
//    MyNewTriangle3(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}
//    void draw() override {
//        cout << "drawing a triangle";
//    }
//    void render() override {
//        cout << "i render using type '3' for the triangle with sides: " << this->side1 << ", " << this->side2 << ", " << this->side3 << endl;
//    }
//};

//struct Renderer {
//    virtual void render_circle(double radius) = 0;
//};
//
//struct PixelRenderer : Renderer {
//    void render_circle(double radius) override {
//        cout << "i render in pixels circle of radius r=" << radius << endl;
//    }
//};
//
//struct VectorRenderer : Renderer {
//    void render_circle(double radius) override {
//        cout << "i render in vector circle of radius r=" << radius << endl;
//    }
//};
//
//struct MyNewShape {
//protected:
//    Renderer& renderer;
//    MyNewShape(Renderer& renderer) : renderer(renderer) {}
//public:
//    virtual void draw() = 0;
//};
//
//struct MyNewCircle : MyNewShape {
//    double radius;
//    MyNewCircle(Renderer& renderer, double radius) : MyNewShape(renderer), radius(radius) {}
//    void draw() override {
//        cout << "drawing a circle" << endl;
//    }
//    void render() {
//        renderer.render_circle(radius);
//    }
//};


struct Renderer {
    virtual void render_circle(double radius) = 0;
    virtual void render_square(double side) = 0;
    virtual void render_triangle(double side1, double side2, double side3) = 0;
};

struct PixelRenderer : Renderer {
    void render_circle(double radius) override {
        cout << "i render in pixels circle of radius r=" << radius << endl;
    }
    void render_square(double side) override {
        cout << "i render in pixels square of side l=" << side << endl;
    }
    void render_triangle(double side1, double side2, double side3) override {
        cout << "i render in pixels triangle with sides: " << side1 << ", " << side2 << ", " << side3 << endl;
    }
};

struct VectorRenderer : Renderer {
    void render_circle(double radius) override {
        cout << "i render in vector circle of radius r=" << radius << endl;
    }
    void render_square(double side) override {
        cout << "i render in vector square of side l=" << side << endl;
    }
    void render_triangle(double side1, double side2, double side3) override {
        cout << "i render in vector triangle with sides: " << side1 << ", " << side2 << ", " << side3 << endl;
    }
};

struct MyNewShape {
protected:
    Renderer& renderer;
    MyNewShape(Renderer& renderer) : renderer(renderer) {}
public:
    virtual void draw() = 0;
    virtual void render() = 0;
};

struct MyNewCircle : MyNewShape {
    double radius;
    MyNewCircle(Renderer& renderer, double radius) : MyNewShape(renderer), radius(radius) {}
    void draw() override {
        cout << "drawing a circle" << endl;
    }
    void render() override {
        renderer.render_circle(radius);
    }
};

struct MyNewSquare : MyNewShape {
    double side;
    MyNewSquare(Renderer& renderer, double side) : MyNewShape(renderer), side(side) {}
    void draw() override {
        cout << "drawing a square" << endl;
    }
    void render() override {
        renderer.render_square(side);
    }
};

struct MyNewTriangle : MyNewShape {
    double side1, side2, side3;
    MyNewTriangle(Renderer& renderer, double s1, double s2, double s3) : MyNewShape(renderer), side1(s1), side2(s2), side3(s3) {}
    void draw() override {
        cout << "drawing a triangle" << endl;
    }
    void render() override {
        renderer.render_triangle(side1, side2, side3);
    }
};


#endif /* RenderorBridge_h */
