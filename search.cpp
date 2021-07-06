#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
#define LIST_SIZE 3

template< typename T >
int searchListElement(const list<T>& l, const T el){
    auto it = find(l.begin(), l.end(), el);
    return it != l.end() ? distance(l.begin(), it) : -1;
}

int main(){
    list<int> l1 = {1, 3, 44, 232, 1, 12, 23 };
    int n;
    cin >> n;
    int response = searchListElement(l1, n);
    cout << response;
    return 0;
}