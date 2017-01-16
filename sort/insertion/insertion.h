#ifndef _SELECTION_H_
#define _SELECTION_H_

template <class Item>
void exchange(Item &a, Item &b)
{
  Item temp=a;
  a=b;
  b=temp;
}


template <class Item>
void insertion_sort(Item a[], unsigned int l, unsigned int r)
{
  if (l==r) return;
  

  // find the smallest element
  unsigned int i_min(l);
  for (unsigned int i=l; i<=r; i++) {
    if (a[i] < a[i_min]) {
      i_min = i;
    }
  }
  if (i_min != l) {
    exchange(a[l], a[i_min]);
  }

  for (unsigned int i=l+2; i<=r; i++) {

    Item n=a[i];

    unsigned int j=i;
    while (a[j-1] > n) {
        exchange(a[j-1], a[j]);
        j--;
    }
    a[j] = n;
  }


}

#endif
