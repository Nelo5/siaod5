

#include <iostream>
using namespace std;



struct Node {
    float val;
    Node* next;
    Node(float _val) : val(_val), next(nullptr) {}
};

struct list {
    Node* first;
    Node* last;
    list() :first(nullptr), last(nullptr) {}
    bool is_empty() {
        return first == nullptr;
    }
    void push_back(float _val) {
        Node* p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }
    void print() {
        if (is_empty()) { return; }
        Node* p = first;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
    Node* find(float _val) {
        if (is_empty()) { return nullptr; }
        Node* p = first;
        while (p && p->val != _val) {
            p = p->next;
        }
        return (p && p->val == _val) ? p : nullptr;
    }
    void remove(float _val) {
        if (is_empty()) return;
        if (first->val == _val) {
            remove_first();
            return;
        }
        else if (last->val == _val) {
            remove_last();
            return;
        }
        Node* fast = first->next;
        Node* slow = first;
        while (fast && fast->val != _val) {
            fast = fast->next;
            slow = slow->next;
        }
        if (!fast) {
            cout << "This elemet does not exist\n";
            return;
        }
        slow->next = fast->next;
        delete fast;
    }
    void remove_first() {
        if (is_empty()) { return; }
        Node* new_first = first->next;
        first = new_first;
    }
    void remove_last() {
        if (is_empty()) { return; }
        Node* fast = first->next;
        Node* slow = first;
        while (fast != last) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = nullptr;
        last = slow;
        delete fast;
    }
    void add_first(float _val) {
        Node* p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        p->next = first;
        first = p;
    }
    void remove_prelast() {
        if (is_empty()) { return; }
        Node* fast = (first->next);
        Node* slow = first;
        while (fast->next != last) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = last;
        delete fast;
    }
    void change_minmax() {
        if (is_empty()) { return; }
        Node* max = first;
        Node* min = first;
        Node* p = first;
        while (p) {
            if (p->val > max->val) { max = p; }
            if (p->val < min->val) { min = p; }
            p = p->next;
        }
        swap(max->val, min->val);
    }
    int len() {
        int counter = 0;
        Node* p = first;
        while (p) {
            counter++;
            p = p->next;
        }
        return counter;
    }
    void firstk_toend(int k) {
        if (is_empty() || k >= len()) { return; }
        last->next = first;
        Node* k_elem = first;
        int counter = 1;
        while (counter < k) {
            k_elem = k_elem->next;
            counter++;
        }
        first = k_elem->next;
        last = k_elem;
        last->next = nullptr;
    }
};



int main()
{
    setlocale(LC_ALL,"Russian");
    list list1;
    int selector;
    cout << "Enter 0 to use the prepared list, else - enter list yourself"<<endl;
    cin >> selector;
    if (selector == 0) {
        list1.push_back(3);
        list1.push_back(2);
        list1.push_back(4);
        list1.push_back(1);
        list1.push_back(5);
        list1.push_back(6);
    }
    else {
        int n;
        float value;
        cout << "Enter length of list\n";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Enter value ";
            cin >> value;
            list1.push_back(value);
        }
    }
    list1.print();
    while (true) {
        float val;
        int k;
        cout << "1 - Переставить первые k элементов в конец списка\n2 - Поменять местами минимальный и максимальный элементы\n3 - Удалить предпоследний элемент списка\n4 - Вставить узел перед первым\n5 - Удалить узел со значением val\n6 - Добавить элемент со значением val в конец\n";
        cin >> selector;
        switch (selector) {
        case 1:
            cout << "Введите k\n";
            cin >> k;
            list1.firstk_toend(k);
            list1.print();
            break;
        
        case 2:
            list1.change_minmax();
            list1.print();
            break;
        case 3:
            list1.remove_prelast();
            list1.print();
            break;
        case 4:
            cout << "Введите value\n";
            cin >> val;
            list1.add_first(val);
            list1.print();
            break;
        case 5:
            cout << "Введите value\n";
            cin >> val;
            list1.remove(val);
            list1.print();
            break;
        case 6:
            cout << "Введите value\n";
            cin >> val;
            list1.push_back(val);
            list1.print();
            break;
    }
        
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться
