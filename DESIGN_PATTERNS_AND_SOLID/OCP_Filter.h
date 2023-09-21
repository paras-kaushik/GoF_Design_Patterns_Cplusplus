//
//  OCP_Filter.h
//  DESIGN_PATTERNS_AND_SOLID
//
//  Created by Paras Kaushik on 09/08/23.
//

#ifndef OCP_Filter_h
#define OCP_Filter_h

enum class Color { red, green, blue };
enum class Size { small, medium, large };

struct Product{
  string name;
  Color color;
  Size size;
};

template <typename T>
struct Specification {
    virtual bool is_satisfied(T* item)=0;
};

template <typename T>
struct AndSpecification:Specification<T> {
    Specification<T>& first;
    Specification<T>& second;
    AndSpecification( Specification<T>& first,
                     Specification<T>& second):first(first), second(second){}
    bool is_satisfied(T* item) override {
        return first.is_satisfied(item) && second.is_satisfied(item);
    }
};

template <typename T>
struct OrSpecification:Specification<T> {
    Specification<T>& first;
    Specification<T>& second;
    OrSpecification( Specification<T>& first,
                     Specification<T>& second):first(first), second(second){}
    bool is_satisfied(T* item) override {
        return first.is_satisfied(item) || second.is_satisfied(item);
    }
};


struct ColorSpecification: Specification<Product> {
    Color color;
    ColorSpecification(Color color): color(color){};
    bool is_satisfied(Product* item) override {
        return item->color==color;
    }
};

struct SizeSpecification: Specification<Product> {
    Size size;
    SizeSpecification(Size size): size(size){};
    bool is_satisfied(Product* item) override {
        return item->size==size;
    }
};

template <typename T>
struct Filter {
    virtual vector<T*> filter(vector<T*> items,Specification<T> & spec)=0;
};

struct BetterFilter :Filter<Product> {
    vector<Product*> filter(vector<Product*> items,Specification<Product> & spec) override {
        vector<Product*> result;
        for(auto& item:items) {
            if(spec.is_satisfied(item))
                result.push_back(item);
        }
        return result;
    }
};

int main (){
    Product apple{"Apple", Color::green, Size::small};
     Product tree{"Tree", Color::green, Size::large};
     Product house{"House", Color::blue, Size::large};
     const vector<Product*> items { &apple, &tree, &house };
    
    ColorSpecification green(Color::green);
    SizeSpecification  large(Size::large);
    
    AndSpecification<Product> greenAndLarge(green,large);

     BetterFilter bf;
    
    for(auto& item:bf.filter(items, greenAndLarge))
        cout<<item->name<<endl;
    
    return 0;
}

#endif /* OCP_Filter_h */
