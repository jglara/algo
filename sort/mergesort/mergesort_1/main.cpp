#include <iostream>
#include <vector>

////////////////////////////////////////////////////////////////////////////////
// pre: a[l..m] is ordered and a[m+1..r] is ordered
// post: a[l..r] is ordered
// This method is not stable
template <class Item>
void merge(Item a[], unsigned int l, unsigned int m, unsigned int r)
{
  Item b[r-l+1];

  // copy first half into b (ascending)
  unsigned int j=0;
  for (unsigned int i=l; i<=m; i++) {
    b[j++] = a[i];
  }

  // copy second half into b (descending)
  for (unsigned int i=r; i>m; i--) {
    b[j++] = a[i];
  }

  unsigned int i=0;
  j=r-l;
  while(i<j) {
    if (b[i] < b[j]) {
      a[l++] = b[i++];
    } else {
      a[l++] = b[j--];
    }
  }

  // copy the last element
  a[l] = b[i];
  
}


////////////////////////////////////////////////////////////////////////////////
template <class Item>
void mergesort(Item a[], unsigned int l, unsigned int r)
{

  if (l == r) {
    return;
  }
  
  unsigned int m = l+((r-l)/2);

  mergesort(a,l,m);
  mergesort(a,m+1,r);

  merge(a,l,m,r);

}

////////////////////////////////////////////////////////////////////////////////
int main(void)
{
  //std::vector<int> numbers;
  unsigned int numbers[10000];
  int i(0);
  unsigned int r=0;
  while (std::cin >> i) {
    numbers[r++]=i;;
  }

  mergesort(numbers, 0, r-1);

  for (unsigned int n = 0; n<r; n++) {
    std::cout << numbers[n] << "\n";
  }

}
