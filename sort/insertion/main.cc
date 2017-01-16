#include <iostream>
#include "insertion.h"

int main(void)
{
  static const unsigned int MAX_N=100000;
  int n;
  int numbers[MAX_N];
  unsigned int i(0);
  while (std::cin >> n) {
    numbers[i++] = n;
  }

  insertion_sort(numbers,0,i);

  for (unsigned int j=0; j<i; j++) {
    std::cout << numbers[j] << std::endl;
  }

}
