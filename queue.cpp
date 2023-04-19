#include <iostream>
#include <list>

template<typename T>
class MyQueue {
private:
    std::list<T> _list;
public:
    MyQueue() = default;

    //--O(1) time complexity (know where front and back are)
    void enqueue(T t) { _list.push_back(t); }
    void dequeue() { _list.pop_front(); }
    T& front() { return _list.front(); }
    const T& front() const { return _list.front(); }
    bool isEmpty() const { return _list.empty(); }
};

int main() 
{
    MyQueue<int> mqi;

    for (auto i: { 10,20,30,40,50 }) {
        mqi.enqueue(i);
    }
}



