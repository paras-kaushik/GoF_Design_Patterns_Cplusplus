//
//  LSP_Sqaure_Rectangle.h
//  DESIGN_PATTERNS_AND_SOLID
//
//  Created by Paras Kaushik on 09/08/23.
//

#ifndef LSP_Sqaure_Rectangle_h
#define LSP_Sqaure_Rectangle_h


class Rectangle{// has no pure virtual function so its neither an abstract class nor an interface
protected:
  int width, height;
public:
  Rectangle(const int width, const int height)
    : width{width}, height{height} { }

  int get_width() const { return width; }
  virtual void set_width(const int width) { this->width = width; }
  int get_height() const { return height; }
  virtual void set_height(const int height) { this->height = height; }

  int area() const { return width * height; }
};

class Square : public Rectangle {
public:
  Square(int size): Rectangle(size,size) {}
  void set_width(const int width) override {
    this->width = height = width;
  }
  void set_height(const int height) override {
    this->height = width = height;
  }
};


void processRectanlge(Rectangle& r) {// => Function is giving faulty results as it violates LISKOV SUBSTITUTION PRINCIPLE
  int w = r.get_width();
  r.set_height(10);

  std::cout << "expected area = " << (w * 10)
    << ", got " << r.area() << std::endl;
}



// objects of a superclass should be replaceable with objects of its subclasses without affecting the correctness of the program.
int main()
{
  Rectangle r{ 5,5 };
    processRectanlge(r);

    Square s{ 5 };
    processRectanlge(s);// violation of LSP

  getchar();
  return 0;
}
// A resolution here would be removing the inheritance between Rectangle and Square and instead create separate classes for Rectangle and Square without any inheritance relationship.

#endif /* LSP_Sqaure_Rectangle_h */
