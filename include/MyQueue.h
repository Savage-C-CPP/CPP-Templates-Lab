#ifndef __MY_QUEUE_H__
#define __MY_QUEUE_H__

#include <list> // Linked list
#include <iterator>
/*
    class MyQueue - адаптер для класса std::list.

    При инициализации экземпляра класса MyQueue,
    class Container можно заменять на другой класс,
    реализующий методы, используемые в коде класса MyQueue.

    Пример:
    MyQueue<double, MyList<double>> q; // Очередь double, в качестве контейнера выступает MyList<double>
    MyQueue<double, std::deque<double>> q; // В качестве контейнера выступает std::deque<double>
*/
template <typename T, class Container = std::list<T>>
class MyQueue
{
protected:
    Container c;

public:
    explicit MyQueue(const Container &_ = Container()) // explicit запрещает неявный вызов конструктора, его можно вызвать только явно
    {
        c = _;
    };

    bool Empty() const { return c.empty(); };
    size_t Size() const { return c.size(); };

    T &Front() { return c.front(); };
    const T &Front() const { return c.front(); };

    T &Back() { return c.back(); };
    const T &Back() const { return c.back(); };

    void Push(const T &_) { c.push_back(_); };
    void Pop() { c.pop_front(); };

    void Print()
    {
        std::cout << "queue -> { ";
        typename Container::iterator it, penult = std::prev(c.end());
        for (it = c.begin(); it != c.end(); ++it)
        {
            std::cout << *it;
            if (it != penult)
                std::cout << ", ";
        }
        std::cout << " }\n";
    }

    static void TestMyQueue(MyQueue<T, Container> q)
    {
        while (q.Size() >= 0)
        {
            std::cout << "-----\n";
            std::cout << "Size = " << q.Size() << '\n';
            std::cout << "Front = " << q.Front() << "\nBack = " << q.Back() << '\n';
            q.Print();
            if (q.Size() == 0)
                break;
            std::cout << "Calling Pop()\n";
            q.Pop();
        }
    };
};

#endif // __MY_QUEUE_H__
