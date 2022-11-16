/*
    Составить программу поиска и печати в порядке убывания
    всех простых чисел из промежутка [2...201],
    используя метод "Решето Эратосфена".
*/
#include <iostream>
#include <set>

struct comporator
{
    bool operator() (int a, int b) const { return a > b; }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Лабораторная работа №3_2\n";
    const int size = 202;
    int arr[size];
    std::set<int, comporator> mySet;

    //Заполнил массив числами от 0 до 202
    for (int i = 0; i < size; i++) arr[i] = i; 

    for (int i = 2; i < size; i++) //Отсеиваю числа методом "Решето Эратосфена"
    {
        if (arr[i] != 0)
        {
            for (int j = i * i; j < size; j += i) arr[j] = 0;
        }
    }

    for (int i = 0; i < size; i++) //Удалил элементы = 0
    {
        if (arr[i] != 0) mySet.insert(arr[i]);
    }

    std::cout << "\nВывожу числа в порядке убывания, отсортированные методом \"Решето Эратосфена\"" << std::endl;
    for (auto elem : mySet) std::cout << elem << " ";
}
