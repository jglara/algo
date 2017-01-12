#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_


// partition of a[l..r] around a[r], returns a[r] position
template <class Item>
unsigned int select(Item a[], unsigned int l, unsigned int r)
{
  Item val = a[r];

  unsigned int i=l;
  unsigned int j=r-1;
  for (;;) {

    while ((i<r) && (a[i] < val)) i++;
    while ((j>l) && (a[j] > val)) j--;
    if (i >= j) break;

    // exchange a[i] & a[j]
    Item temp = a[i];
    a[i++] = a[j];
    a[j--] = temp;

  }

  // exchange a[i] & a[r]
  a[r] = a[i];
  a[i] = val;

  return i;

}


// sorts a[l..r]
template <class Item>
void quicksort(Item a[], unsigned int l, unsigned int r)
{

  if (l==r) return;
  
  unsigned int m = select(a,l,r);

  if (l<m) quicksort(a,l,m-1);
  if (m<r) quicksort(a,m+1,r);
}

#endif

