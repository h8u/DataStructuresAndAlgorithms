/*
	Лабораторная работа №4.
	Заданный одномерный массив отсортировать по возрастанию
	цифры десятков каждого элемента. (!!!)
	Сортировки: включением, быстрая.
	Тестирование выполнить на:
	1) Неотсорт. 2) Частично отсорт. 3) Отсорт. в обратном порядке.
	Сравнить эффективность методов сортировки для различных типов последоват.
*/

#include <iostream>
#include <string>
#include <ctime> //Для rand
#include <algorithm> //Для std::sort

void insertionSort(int array[], int size); //Сортировка вставками (включением)
int partition(int* array, int left, int pivot); //Быстрая сортировка, работа с Пивотом
void quickSort(int* array, int left, int pivot); //Быстрая сортировка
int comporator(int const& i, int const& j) { return i > j; } //Компоратор для обратной сортировки массивов

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Лабораторная работа №4" << std::endl;
	const int size = 10;
	int arr[size];
	int arrForInsertionSort[size];
	int arrForQuickSort[size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 1000 + 10;
		arrForQuickSort[i] = arr[i]; //Копирую массивы для каждой сортировки
		arrForInsertionSort[i] = arr[i];
	}
	std::cout << "Массив на " << size << " элементов, заполненный случайными числами: " << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	clock_t timeForSort[12]; //Массив точек времени, для подсчета эффективности
	int timeCount = 0;

	//
	std::cout << "\n\nПровожу тестирование, на неотсортированном массиве: " << std::endl;
	std::cout << "Выполняю сортировку вставками: " << std::endl;
	timeForSort[timeCount] = clock(); timeCount++;
	insertionSort(arrForInsertionSort, size);
	for (int i = 0; i < size; i++)
	{
		std::cout << arrForInsertionSort[i] << " ";
	}
	timeForSort[timeCount] = clock();
	std::cout << "\nВремени потребовалось для алгоритма: " 
		<< (double)(timeForSort[timeCount] - timeForSort[timeCount - 1]) / CLOCKS_PER_SEC << std::endl;

	std::cout << "\nВыполняю быструю сортировку: " << std::endl;
	timeForSort[timeCount] = clock(); timeCount++;
	quickSort(arrForQuickSort, 0, size - 1);
	for (int i = 0; i < size; i++)
	{
		std::cout << arrForQuickSort[i] << " ";
	}
	timeForSort[timeCount] = clock();
	std::cout << "\nВремени потребовалось для алгоритма: "
		<< (double)(timeForSort[timeCount] - timeForSort[timeCount - 1]) / CLOCKS_PER_SEC << std::endl;

	//
	std::cout << "\n\nПровожу тестирование на частично отсортированном массиве: " << std::endl;
	for (int i = 0; i < size; i++)
	{
		arrForQuickSort[i] = arr[i]; //Копирую рандомные значения элементов и их расположение в массивы
		arrForInsertionSort[i] = arr[i]; //для каждой сортировки
	}
	std::sort(arrForInsertionSort, arrForInsertionSort + size / 2); //Сортирую по возрастанию частично (наполовину)
	std::sort(arrForQuickSort, arrForQuickSort + size / 2);

	std::cout << "Выполняю сортировку вставками: " << std::endl;
	timeForSort[timeCount] = clock(); timeCount++;
	insertionSort(arrForInsertionSort, size);
	for (int i = 0; i < size; i++)
	{
		std::cout << arrForInsertionSort[i] << " ";
	}
	timeForSort[timeCount] = clock();
	std::cout << "\nВремени потребовалось для алгоритма: "
		<< (double)(timeForSort[timeCount] - timeForSort[timeCount - 1]) / CLOCKS_PER_SEC << std::endl;

	std::cout << "\nВыполняю быструю сортировку: " << std::endl;
	timeForSort[timeCount] = clock(); timeCount++;
	quickSort(arrForQuickSort, 0, size - 1);
	for (int i = 0; i < size; i++)
	{
		std::cout << arrForQuickSort[i] << " ";
	}
	timeForSort[timeCount] = clock();
	std::cout << "\nВремени потребовалось для алгоритма: "
		<< (double)(timeForSort[timeCount] - timeForSort[timeCount - 1]) / CLOCKS_PER_SEC << std::endl;
	
	//
	std::cout << "\n\nПровожу тестирование на отсортированном в обратном порядке массиве: " << std::endl;
	for (int i = 0; i < size; i++)
	{
		arrForQuickSort[i] = arr[i];
		arrForInsertionSort[i] = arr[i];
	}
	//Сортирую в обратном порядке при помощи ф. std::sort и настроенного компоратора
	std::sort(std::begin(arrForInsertionSort), std::end(arrForInsertionSort), comporator); 
	std::sort(std::begin(arrForQuickSort), std::end(arrForQuickSort), comporator); 

	std::cout << "Выполняю сортировку вставками: " << std::endl;
	timeForSort[timeCount] = clock(); timeCount++;
	insertionSort(arrForInsertionSort, size);
	for (int i = 0; i < size; i++)
	{
		std::cout << arrForInsertionSort[i] << " ";
	}
	timeForSort[timeCount] = clock();
	std::cout << "\nВремени потребовалось для алгоритма: "
		<< (double)(timeForSort[timeCount] - timeForSort[timeCount - 1]) / CLOCKS_PER_SEC << std::endl;

	std::cout << "\nВыполняю быструю сортировку: " << std::endl;
	timeForSort[timeCount] = clock(); timeCount++;
	quickSort(arrForQuickSort, 0, size - 1);
	for (int i = 0; i < size; i++)
	{
		std::cout << arrForQuickSort[i] << " ";
	}
	timeForSort[timeCount] = clock();
	std::cout << "\nВремени потребовалось для алгоритма: "
		<< (double)(timeForSort[timeCount] - timeForSort[timeCount - 1]) / CLOCKS_PER_SEC << std::endl;
}

void insertionSort(int array[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int j = i - 1;
		while (j >= 0 && (array[j] /10 % 10) > (array[j + 1] / 10 % 10))
		{
			std::swap(array[j], array[j + 1]);
			j--;
		}
	}
}

int partition(int* array, int left, int pivot)
{
	int low = left - 1;
	int high = pivot - 1;

	for (int j = left; j <= high; j++)
	{
		if ((array[j] / 10 % 10) <= (array[pivot] / 10 % 10))
		{
			low++;
			std::swap(array[low], array[j]);
		}
	}
	std::swap(array[low + 1], array[pivot]);
	return low + 1;
}

void quickSort(int* array, int left, int pivot)
{
	if (left < pivot)
	{
		int new_pivot = partition(array, left, pivot);
		quickSort(array, left, new_pivot - 1);
		quickSort(array, new_pivot + 1, pivot);
	}
}