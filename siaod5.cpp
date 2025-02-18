// siaod5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//Это первое изменение

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
};



int main()
{
    std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
