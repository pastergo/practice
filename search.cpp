#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
#define ARR_SIZE 7
// Поиск в связном списке
template< typename T >
int searchListElement(const list<T>& l, const T el){        //  Поиск просиходит перебором через итераторы: от begin до end, 
    auto it = find(l.begin(), l.end(), el);                 //  если находится искомый элемент, итератор it принимает его индекс
    return it != l.end() ? distance(l.begin(), it) : -1;    //  Возвращает int индекса итератора или -1 (в случае отсутствия элемента)
}

// Линейный поиск в массиве
template< typename T>
int linarSearchArray(T *arr, const T key){                  //  Линейный поиск - перебор от первого до последнего элемента массива, 
    for(auto i = 0; i < ARR_SIZE; i++){                     //  при котором итерационно сравнивается элемент с ключом.
        if (arr[i] == key) return i;                        //  При нахождении возвращает индекс или -1 (в случае отсутствия элемента)
    }
    return -1;
}
// Оба поиска находят индекс первого соответствующего элемента, но не последующих

// Вывод сортировок
template< typename T1, typename T2>
void out(const list<T1>& l, T2 *arr){
    T1 n1;
    cout << "1.\tEnter the key..." << endl;
    cin >> n1;
    int response = searchListElement(l, n1);
    cout << response << endl;
    cout << "2.\tEnter the key..." << endl;
    T2 n2;
    cin >> n2;
    response = linarSearchArray(arr, n2);
    cout << response << endl;
}

int main(){
    list<int> l1 = {1, 3, 44, 232, 1, 12, 23 };
    double arr[ARR_SIZE] = {0.0, 0.01, 0.02, 0.1, 2.1, 4.3, 9.9};
    out(l1,arr);
    return 0;
}