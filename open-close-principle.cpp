#include <bits/stdc++.h>
using namespace std;
enum class Color{ Red, Green, Blue};
enum class Size{ Small, Medium, Large};

class Product{
  public:
  string name;
  Color color;
  Size size;
  
};
class Spec{
  public:
  virtual bool is_satisfied(Product item) = 0;
};
class Filter{
  public:
  static vector<Product> filter(vector<Product> items, Spec* spec){
    vector<Product> res;
    for(auto &item: items){
      if(spec->is_satisfied(item)) res.push_back(item);
    }
    return res;
  }

};

class ColorSpec: public Spec{
  public:
  Color color;
  ColorSpec(Color color): color(color){}
  bool is_satisfied(Product item) override{
    return item.color == color;
  }
};

class SizeSpec: public Spec{
  public:
  Size size;
 
  SizeSpec(Size size): size(size){}
  bool is_satisfied(Product item) override{
    return item.size == size;
  }
};

int main() {
  Product p1({"p1", Color::Red, Size::Small});
  Product p2{"p2", Color::Red, Size::Medium};
  Product p3{"p3", Color::Green, Size::Small};
  Spec *csp = new ColorSpec(Color::Red);
  Spec *sp = new SizeSpec(Size::Medium);
  //vector<Product> filtered = Filter::filter({p1, p2, p3}, csp);
  vector<Product> filtered = Filter::filter({p1, p2, p3}, sp);

  for(auto& x: filtered){
    cout<<x.name<<" ";
  }
}
