/*
    Автозамена цифр.
    В строке заменить цифры на их словестные описания.
*/

#include <iostream>
#include <list>
#include <string>

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Лабораторная работа №1. Строки\n";
    
    std::string numbers;
    std::string words[] = { "Ноль ", "Один ", "Два ", "Три ", "Четыре ", "Пять ",
        "Шесть ", "Семь ", "Восемь ", "Девять ", "Минус "};

    std::cout << "Введите цифры: ";
    std::cin >> numbers;
    std::cout << "Введенные цифры в строке: ";
    std::cout << numbers << std::endl;

    for (int i = 0; i < numbers.size(); i++)
    {
        switch (numbers[i])
        {
            //Сравниваю значения каждой ячейки строки. Удаляю цифру, вставляю текст.
            case '0': numbers.erase(i, 1); numbers.insert(i, words[0]); break;
            case '1': numbers.erase(i, 1); numbers.insert(i, words[1]); break;
            case '2': numbers.erase(i, 1); numbers.insert(i, words[2]); break;
            case '3': numbers.erase(i, 1); numbers.insert(i, words[3]); break;
            case '4': numbers.erase(i, 1); numbers.insert(i, words[4]); break;
            case '5': numbers.erase(i, 1); numbers.insert(i, words[5]); break;
            case '6': numbers.erase(i, 1); numbers.insert(i, words[6]); break;
            case '7': numbers.erase(i, 1); numbers.insert(i, words[7]); break;
            case '8': numbers.erase(i, 1); numbers.insert(i, words[8]); break;
            case '9': numbers.erase(i, 1); numbers.insert(i, words[9]); break;
            case '-': numbers.erase(i, 1); numbers.insert(i, words[10]); break;
        }
    }
    std::cout << "Результат: " << numbers;

}
