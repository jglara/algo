#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_

template <class Item>
void exchange(Item &a, Item &b)
{
  Item temp=a;
  a=b;
  b=temp;
}

// choose pivot
template <class Item>
Item choose_pivot(Item a[], unsigned int l, unsigned int r)
{

  if (l==r) return a[r];
  if (a[l] > a[r]) {
    exchange(a[l], a[r]);
  }

  if ((r-l)>1) {

    if (a[l] > a[r-1]) {
      exchange(a[l], a[r-1]);
    }

    if (a[r] > a[r-1]) {
      exchange(a[r], a[r-1]);
    }
  }

  return a[r];

}

// partition of a[l..r] around a[r], returns a[r] position
template <class Item>
unsigned int select(Item a[], unsigned int l, unsigned int r)
{

  
  Item pivot = choose_pivot(a,l,r);

  unsigned int i=l;
  unsigned int j=r;
  for (;;) {

    do {
      i++;
    } while (a[i] < pivot);

    do {
      j-- ;
    } while (a[j] > pivot);
    if (i >= j) break;

    // exchange a[i] & a[j]
    exchange(a[i], a[j]);
  }

  exchange(a[i], a[r]);

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

