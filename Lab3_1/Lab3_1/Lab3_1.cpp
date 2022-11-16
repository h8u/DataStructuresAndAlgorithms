/*
    Линейные структуры данных: очередь.
    Перенести из созданной очереди вещественных чисел в новую очередь
    все элементы, находящиеся между первым и минимальным элементами.

*/
#include <iostream>
#include <ctime>
const int qSize = 10;
class Queue
{
private: 
    int front, rear; 
public: 
    float items[qSize];
    Queue()
    {
        front = -1; //1 элемент очереди
        rear = -1; //Последний элемент очереди
    }

    bool isFull() //Заполнена ли очередь
    {
        if (front == 0 && rear == qSize - 1) return true;
        return false;
    }

    bool isEmpty() //Пуста ли очередь
    {
        if (front == -1) return true;
        else return false;
    }

    void enQueue(float element) //Добавить эл-т в конец очереди
    {
        if (isFull()) std::cout << "\nОчередь заполнена";
        else
        {
            if (front == -1) front = 0;
            rear++;
            items[rear] = element;
        }
    }

    int deQueue() //Удаление эл-та
    {
        float element;
        if (isEmpty())
        {
            std::cout << "\nОчередь пуста";
            return (-1);
        }
        else
        {
            element = items[front];
            if (front >= rear)
            {
                front = -1;
                rear = -1;
            }
            else front++;
        }
        std::cout << std::endl;
        std::cout << "\nУдален элемент: " << element;
        return (element);
    }

    void display()
    {
        if (isEmpty()) std::cout << "\nПустая очередь";
        else
        {
            std::cout << "\nЭлементы: ";
            for (int i = front; i <= rear; i++) std::cout << items[i] << " ";
        }
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Лабораторная работа №3\n";
    srand(time(NULL));
    Queue q;
    Queue q2; //[1; min]
    if (!q.isFull())
    {
        for (int i = 0; i < qSize; i++)
        {
            q.enQueue((rand()%1000) / 10.0);
        }
    }
    std::cout << "Вывожу первую очередь: " << std::endl;
    q.display();

    float qMin = q.items[0];
    int ij = 0; //Номер эл-та с мин. значением

    for (int i = 0; i < qSize; i++)
    {
        if (qMin > q.items[i])
        {
            qMin = q.items[i];
            ij = i;
        }
    }

    for (int i = 0; i <= ij; i++) q2.enQueue(q.items[i]);
    std::cout << "\n\nВывожу вторую очередь: " << std::endl;
    q2.display();
}

