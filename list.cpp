#include <iostream>
using namespace std;

template <typename T>
class List
{
private:
    struct Node
    {
        T data;
        Node *next;
    };
    Node *head;
    int size;

public:
    List();
    ~List();
    void push(T data);
    void print();
    int get_size() const;
    T get_element(int) const;
    List operator + (const List<T> &);
    };

template <typename T>
List<T>::List() {}

template <typename T>
List<T>::~List()
{
    // while (NULL != head)
    // {
    //     Node *p = head;
    //     head = head->next;
    //     delete p;
    // }
}

template <typename T>
void List<T>::push(T data)
{
    if (NULL == head)
    {
        head = new Node;
        head->data = data;
        head->next = NULL;
    }
    else
    {
        Node *p = head;
        while (NULL != p->next)
        {
            p = p->next;
        }
        Node *a = new Node;
        a->data = data;
        a->next = NULL; 
        p->next = a;

        // p->next = new Node;
        // head->data = data;
        // head->next = NULL;
    }
    this -> size++;
}

template <typename T>
void List<T>::print()
{
    Node *p = head;
    while (NULL != p)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

template <typename T>
int List<T>::get_size() const{
    return this -> size;


    // if (index >= size || index < 0)
    // {
    //     return -1;
    // }
    // Node * cur = head;
    // for (int i = 0; i < index; i++)
    // {
    //     cur = cur ->next;
    // }
    // return cur->data;
    //cout << get_size() << endl;
    
}

template <typename T>

T List<T>::get_element(int index) const{
    if (index > this -> size || index < 1) {
        cout << "No element for this index" << endl;
        return 0;
    }else
    {
        Node * p = head;
        for (int i = 1; i < index; i++)
        {
            p = p-> next;
        }
        return p -> data;
    }
}

template <typename T>
List<T> List<T>::operator + (const List<T> &l){
        Node *p = this->head;
        while (NULL != p->next)
        {
            p = p->next;
            cout << "2" << endl;
        }
        p->next = l.head;
        cout << "10" << endl;
        List *temp = new List;
        temp->head = this -> head;
        temp->size = this -> size + l.size;

        return *temp;
}
int main()
{
    List<int> l;

    List<float> l1;
        l1.push(1.34);
        l1.push(2.34);
        l1.push(3.34);
        l1.push(4.34);
        l1.push(5.34);
    List<float> l2;
        l2.push(6.34);
        l2.push(7.34);
        l2.push(8.34);
        l2.push(9.34);
        l2.push(10.34);

        // cout << l1.get_element(1) << endl;
        // cout << l1.get_element(4) << endl;
        // cout << l1.get_element(-5) << endl;

    List<float> la = l1 + l2;
         cout << la.get_size() << endl;
        for (int i = 1; i <= la.get_size(); i++) {
                std::cout << la.get_element(i) << std::endl;
        }
    return 0;
}