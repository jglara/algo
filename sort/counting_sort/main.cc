#include <iostream>
#include "counting.h"

int main(void)
{
  static const unsigned int MAX_N=100000;
  static const unsigned int MAX_K=10;
  unsigned int n;
  int numbers[MAX_N];
  unsigned int i(0);
  while (std::cin >> n) {
    numbers[i++] = n;
    if (n >= MAX_K) {
      std::cerr << "Max number allowed: " << MAX_K << std::endl;
      return -1;
    }
  }

  counting_sort(numbers,MAX_K,0,i);

  for (unsigned int j=0; j<i; j++) {
    std::cout << numbers[j] << std::endl;
  }

}
