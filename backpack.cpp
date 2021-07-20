#include <iostream>
#include <vector>
using namespace std;
#define QUANTITY 7
#define CAPACITY 32

class Item(){};

// Item STRUCT Items{
//     STONE = "stone", 20, 2;
//     WOOD = "wood", 10, 5;
//     COAL = "coal", 15, 20;
// }
// Хотелось бы так сделать, чтоб потом готовые шаблоны вытягивать (::Backpack.addItem(STONE)), но я не знаю как, реализовал векторным массивом ниже
    vector <Item> store;
//  Класс предмета
class Item{
    private:
    string name;
    double weight;
    double price;
    public:
    Item() = default;
    explicit Item(string n, double w, double p) : name(n), weight(w), price(p) {};

    //  Getter'ы
    const string getName(){
        return name;
    }
    const double getWeight(){
        return weight;
    }
    const double getPrice(){
        return price;
    }

    ~Item() = default;
};

class Backpack : public Item{
    private:
    int capacity;
    double maxPrice;
    vector <Item> storage;
    public:
    Backpack() = default;
    explicit Backpack(int c) : capacity(c){ maxPrice = 0;};

    const int getCapacity(){
        return capacity;
    }

    void setCapacity(int capacity){
        this->capacity = capacity;
    }

    bool isBackpackFull(){
        return capacity == 0 ? true : false; 
    }

    void addItem(Item it){
        storage.push_back(it);
        if(capacity - it.getWeight() >= 0) capacity-=it.getWeight();
    }
    void showItems(){
        for(auto el : storage){
            cout << el.getName() << "\tWeight [" << el.getWeight() << "]\tPrice [" << el.getPrice() << "]" << endl;
        }
    }

    ~Backpack() = default;

    void func(){
        // получить упорядоченный массив соотношений элементов стоимость-вес
        // кладем лучший итем до кратного заполнения, остаток следующим итемом и тд.

        //проверка на достаточность, итемом с max ценой
    }

    // Рекурсивный перебор (лучше чем обычный, но все еще перебор)
    void recursionItemPutter(int i, int p){
        if(i == CAPACITY){
            if(p > maxPrice){
                maxPrice = p;
                // TODO: Сохранить комбинацию итемов в переменную
                //       проверка на достаточность
            }
        }
        else {
            for(int j = 0; j < capacity/store[i].getWeight(); j++){
                // TODO: Переход на следующий итем
                recursionItemPutter(i+1, p + j*store[i].getPrice());
            }
        }
    }

};

int main(){

    store.push_back(Item("Stone", 7, 11));
    store.push_back(Item("Wood", 6, 10));
    store.push_back(Item("Coal", 2, 17));
    store.push_back(Item("Gold", 10, 50));
    store.push_back(Item("Bronze", 8, 35));
    store.push_back(Item("Meat", 3, 25));
    store.push_back(Item("Glass", 5, 31));

    Backpack b1(CAPACITY);

    return 0;
}