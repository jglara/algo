#include <gtest/gtest.h>
#include "quicksort.h"

TEST(qs, choose_pivot_1) {
  unsigned int test1[] = {3,2,1};

  EXPECT_EQ(choose_pivot(test1,0,2), 2);

}

TEST(qs, select_1) {

  unsigned int test1[] = {3,2,1};
  unsigned int val = select(test1,0,2);
  EXPECT_EQ(val, 1);

}

TEST(qs, select_2) {

  unsigned int test1[] = {3,1,2};
  unsigned int val = select(test1,0,2);
  EXPECT_EQ(val, 1);

}

TEST(qs, select_3) {

  unsigned int test1[] = {2,1,3};
  unsigned int val = select(test1,0,2);
  EXPECT_EQ(val, 1);

}

TEST(qs, select_4) {

  unsigned int test1[] = {2,2,2};
  unsigned int val = select(test1,0,2);
  EXPECT_EQ(val, 1);

}


// sort randomly disordered lists
TEST(qs, sort_1) {
  static const int N=10;
  unsigned int test1[][N] = {
    {3,0,6,8,4,9,1,5,2,7},
    {4,1,2,8,5,6,7,0,3,9},
    {1,4,9,2,0,3,7,5,6,8},
    {0,0,0,0,0,0,0,0,0,0}
  };

  for (unsigned int t=0; test1[t][0] != 0; t++) {
  
    quicksort(test1[t],0,N-1);
    // check order
    for(unsigned int i=0; i<N-1; i++) {
      EXPECT_TRUE(test1[t][i] < test1[t][i+1] );
    }
    
  }

}

// sort ordered list, and completely disorder list
TEST(qs, sort_2) {
  static const int N=10;
  unsigned int test1[][N] = {
    {10,9,8,7,6,5,4,3,2,1},
    {1,2,3,4,5,6,7,8,9,10},
    {0,0,0,0,0,0,0,0,0,0}
  };

  for (unsigned int t=0; test1[t][0] != 0; t++) {
  
    quicksort(test1[t],0,N-1);
    // check order
    for(unsigned int i=0; i<N-1; i++) {
      EXPECT_TRUE(test1[t][i] < test1[t][i+1] );
    }
    
  }

}


// sort list with repeated elements
TEST(qs, sort_3) {
  static const int N=10;
  unsigned int test1[][N] = {
    {1,1,1,3,3,3,4,4,4,1},
    {2,1,2,1,2,1,2,1,2,1},
    {0,0,0,0,0,0,0,0,0,0}
  };

  for (unsigned int t=0; test1[t][0] != 0; t++) {
  
    quicksort(test1[t],0,N-1);
    // check order
    for(unsigned int i=0; i<N-1; i++) {
      EXPECT_TRUE(test1[t][i] <= test1[t][i+1] );
    }
    
  }

}
