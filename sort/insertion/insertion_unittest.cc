
#include <gtest/gtest.h>
#include "insertion.h"

TEST(is, sort_1) {
unsigned int test[] = { 3,2,1 };

insertion_sort(test, 0, 2);

EXPECT_EQ(test[0], 1);
EXPECT_EQ(test[1], 2);
EXPECT_EQ(test[2], 3);
}

TEST(is, sort_2) {

  static const int N=10;
  unsigned int test[][N] = {
    {3,0,6,8,4,9,1,5,2,7},
    {4,1,2,8,5,6,7,0,3,9},
    {1,4,9,2,0,3,7,5,6,8},
    {0,0,0,0,0,0,0,0,0,0}
  };

  for (unsigned int t=0; test[t][0] != 0; t++) {
  
    insertion_sort(test[t],0,N-1);
    // check order
    for(unsigned int i=0; i<N-1; i++) {
      EXPECT_TRUE(test[t][i] < test[t][i+1] );
    }
    
  }

}
