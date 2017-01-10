#include <iostream>
#include <vector>

////////////////////////////////////////////////////////////////////////////////
// pre: first..med is ordered and med+1..last is ordered
// post: first..last is ordered
// This method is stable
template <class RandomIt>
void merge(RandomIt first, RandomIt med, RandomIt last)
{
  std::vector< typename std::iterator_traits<RandomIt>::value_type > a(first,med);
  std::vector< typename std::iterator_traits<RandomIt>::value_type > b(med,last);

  RandomIt it_a = a.begin();
  RandomIt it_b = b.begin();
  while (first != last) {
    // a finished, take from b
    if (it_a == a.end()) {
      *first++ = *it_b++;
    } else if (it_b == b.end()) {
      // b finished, take from a
      *first++ = *it_a++;
    } else {
      if (*it_a < *it_b) {
        *first++ = *it_a++;
      } else {
        *first++ = *it_b++;
      }
    }
  }
}


////////////////////////////////////////////////////////////////////////////////
template <class RandomIt>
void mergesort(RandomIt first, RandomIt last)
{

  if ( (last - first) == 1 ) {
    return;
  }

  RandomIt med=first + (last - first) / 2 ;
  mergesort(first, med);
  mergesort(med, last);

  merge(first, med, last);

}

////////////////////////////////////////////////////////////////////////////////
int main(void)
{
  std::vector<int> numbers;
  int i(0);
  while (std::cin >> i) {
    numbers.push_back(i);
  }

  mergesort(numbers.begin(), numbers.end());

  for(auto it=numbers.begin(); it!=numbers.end(); it++) {
    std::cout << *it << "\n";
  }

}
