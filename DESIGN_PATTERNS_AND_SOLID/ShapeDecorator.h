//
//  ShapeDecorator.h
//  DESIGN_PATTERNS_AND_SOLID
//
//  Created by Paras Kaushik on 01/08/23.
//
// extending functionality of a class
// even a decorator function can be made
#ifndef ShapeDecorator_h
#define ShapeDecorator_h

struct Shape{
  virtual string str() const = 0;
};

struct Circle : Shape {
  float radius;
  Circle(){}

  explicit Circle(const float radius)
    : radius{radius} {}

  void resize(float factor){
    radius *= factor;
  }

  string str() const override{
    ostringstream oss;
    oss << "A circle of radius " << radius;
    return oss.str();
  }
};

struct Square : Shape{
  float side;
  Square(){}

  explicit Square(const float side)
    : side{side}{}

  string str() const override{
    ostringstream oss;
    oss << "A square of with side " << side;
    return oss.str();
  }
};

// we are not changing the base class of existing
// objects
// cannot make, e.g., ColoredSquare, ColoredCircle, etc.
struct ColoredShape : Shape{// A DYNAMIC DECORATOR
  Shape& shape;
  string color;

  ColoredShape(Shape& shape, const string& color)
    : shape{shape},
      color{color}{}

  string str() const override{
    ostringstream oss;
    oss << shape.str() << " has the color " << color;
    return oss.str();
  }
};

struct TransparentShape : Shape{
  Shape& shape;
  uint8_t transparency;
    //ANOTHER DYNAMIC DECORATOR- a red and transparent shape can be made
  TransparentShape(Shape& shape, const uint8_t transparency)
    : shape{shape},
      transparency{transparency}{}

  string str() const override{
    ostringstream oss;
    oss << shape.str() << " has "
      << static_cast<float>(transparency) / 255.f*100.f
      << "% transparency";
    return oss.str();
  }
};
// a disadvantage is that this restricts our access to the underlying api functions

#endif /* ShapeDecorator_h */
