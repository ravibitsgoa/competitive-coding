#include <iostream>
#include <cmath>
void foo(double x, double y)
{
  if (std::cos(x) != std::cos(y)) {
    std::cout << "Huh?!?\n";  // You might end up here when x == y!!
  }
}
int main()
{
  foo(1.0, 1.01);
  return 0;
}
