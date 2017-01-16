#include <string.h>

template <class Item>
void exchange(Item &a, Item &b)
{
  Item temp=a;
  a=b;
  b=temp;
}


template <class Item>
void counting_sort(Item a[], unsigned int k, unsigned int l, unsigned int r)
{
  if (l==r) return;

  // first count elements
  unsigned int count[k];
  memset(count,'\0', sizeof(count));

  for (unsigned int i=l; i<=r;i++) {
    count[ a[i] ] ++;
  }

  // acumulate counts
  for (unsigned int i=1; i<k; i++) {
    count[i] += count[i-1];
  }
  Item tmp[r-l+1];

  // start copying values in order
  for (unsigned int i=l; i<=r; i++) {
    Item val = a[i];
    count [ val ]--;
    tmp[ count[ val ] ] = val;
  }

  // copy elements into a
  for (unsigned int i=l; i<=r; i++) {
    a[i] = tmp [i];
  }
    
  

}
