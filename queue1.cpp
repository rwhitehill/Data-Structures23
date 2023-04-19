#include <iostream>
#include <list>

template<typename T>
class myQueue {
private:
    std::list<T> _list;
public:
    myQueue() = default;

    void enqueue(T t) { _list.push_back(t); }
    void dequeue() { _list.pop_front(); }
    T& front() { return _list.front(); }
    const T& front() const { return _list.front(); }
    bool empty() { return _list.empty(); }
};

int main()
{
    myQueue<int> mqi;

    for (auto i : { 1,2,3,4,5 }) {
        mqi.enqueue(i);
    }

    while (!mqi.empty()) {
        std::cout << mqi.front() << " ";
        mqi.dequeue();
    }

    return 0;
}
