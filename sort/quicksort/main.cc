#include <iostream>
#include "quicksort.h"

///////////////////////////////////////////////////////////////////////////////
int main(void)
{
  unsigned int numbers[10000];
  int i(0);
  unsigned int r=0;
  while (std::cin >> i) {
    numbers[r++]=i;;
  }

  quicksort(numbers, 0, r-1);

  for (unsigned int n = 0; n<r; n++) {
    std::cout << numbers[n] << "\n";
  }

}
