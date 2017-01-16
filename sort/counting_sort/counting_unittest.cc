
#include <gtest/gtest.h>
#include "counting.h"

TEST(is, sort_1) {
unsigned int test[] = { 1,2,1 };

counting_sort(test, 3, 0, 2);

EXPECT_EQ(test[0], 1);
EXPECT_EQ(test[1], 1);
EXPECT_EQ(test[2], 2);
}

TEST(is, sort_2) {

  static const int N=10;
  unsigned int test[][N] = {
    {1,1,1,3,3,3,4,4,4,1},
    {2,1,2,1,2,1,2,1,2,1},
    {0,0,0,0,0,0,0,0,0,0}
  };

  for (unsigned int t=0; test[t][0] != 0; t++) {
  
    counting_sort(test[t],5,0,N-1);
    // check order
    for(unsigned int i=0; i<N-1; i++) {
      EXPECT_TRUE(test[t][i] <= test[t][i+1] );
    }
    
  }

}
