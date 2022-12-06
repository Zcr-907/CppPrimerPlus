#include "queue.h"

// 类构造方法
// 初始化成员列表
// q_size: 为常量,可以初始化但不能赋值,由于在调用构造函数之前已经被分配内存了,所以无法在构造函数内再为它赋值,所以必须采取此种方式
//         与其相似的还有引用类型 TypeName & val;
// front和rear: 只是表明,初始化成员列表可以对多个参数进行该操作,用逗号分割即可
// Queue(int qs) : q_size(qs), front(nullptr), rear(nullptr);
Queue::Queue(int qs) : q_size(qs) {
    front = rear = nullptr;
    items = 0;
}

// 释放队列中的每个元素
Queue::~Queue() {
    Node *temp;
    while (front != nullptr) {
        temp = front;
        front = temp->next;
        delete temp;
    }
}

bool Queue::isEmpty() const {
    return items == 0;
}

bool Queue::isFull() const {
    return items == q_size;
}

int Queue::queueCont() const {
    return items;
}

bool Queue::poll(const Item &item) {
    if (isFull()) {
        return false;
    }
    Node *add = new Node;
    add->item = item;
    add->next = nullptr;
    items++;
    if (front == nullptr) {
        front = add;
    } else {
        rear->next = add;
    }
    rear = add;
    return true;
}

bool Queue::peek(Item &item) {
    if (front == nullptr) {
        return false;
    }
    item = front->item;
    items--;
    Node *temp = front;
    front = front->next;
    delete temp;
    if (items == 0) {
        rear = nullptr;
    }
    return true;
}

Queue &Queue::operator=(const Queue &q) { return *this; }

