/*
    Стек. 
    Заполнить стек N случайными числами
    из интервала [10; 100]
    Найти количество чисел, которые
    при делении на 7 дают в остатке 2.
*/
#include <iostream>
#include <vector>
#include <ctime>

void printVector(const std::vector<int>& stack)
{
    for (auto element : stack) std::cout << element << " ";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    std::cout << "Лабораторная работа №2_2\n";
    int count = 0;
    int size = 0; 
    std::vector<int> stack{};
    printVector(stack);
    std::cout << "Введите размер стека: " << std::endl;
    std::cin >> size;

    for (int i = 0; i < size; i++)
    {
        stack.push_back(rand() % 100 + 10);
    }

    std::cout << "Сгенерированный стек: " << std::endl;
    printVector(stack);

    for (int i = 0; i < size; i++)
    {
        if ((stack[i] % 7) == 2) count++;
    }

    std::cout << "\nКоличество чисел, которые при делении "
        "на 7 дают в остатке 2: " << count;

}
