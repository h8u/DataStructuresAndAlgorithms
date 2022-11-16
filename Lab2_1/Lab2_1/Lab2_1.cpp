/*
	15.	Запись в журнале зимней экзаменационной сессии 
	представляет собой структуру с полями: 
	курс, код группы, фамилия студента, дата поступления, 
	номер зачетной книжки, дисциплина, оценка за экзамен по дисциплине. 
	Поиск и сортировка — по номеру курса, номеру зачетной книжки, дате поступления.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>

class Node
{
public:
	int recordBookNumber; //Номер зачетной книжки
	int course; //Номер курса
	std::string lastName; //Фамилия
	std::string groupCode; //Код группы

	std::string discipline; // Название дисциплины
	int disciplineGrade; //Оценка по дисциплине

	int receiptDate; //Дата поступления 

	Node* Next;
};

class List
{
public:
	int size = 0;
	//Добавление элемента в начало списка
	void push(Node** head)
	{
		Node* newNode = new Node();

		newNode->Next = *head;
		*head = newNode;
		size++;
	}

	//Удаление головного элемента
	int pop(Node** head)
	{
		Node* temp = *head;
		int data = temp->recordBookNumber;
		*head = temp->Next;
		free(temp);
		size--;
		return data;
	}

	//Удаление элемента из списка по индексу
	int popIndex(Node** head, int index)
	{
		int i;
		int data = (*head)->recordBookNumber;
		if (index == 0)
		{
			pop(head);
		}
		else
		{
			Node* current = *head;
			for (int i = 0; i < index - 1; i++)
			{
				current = current->Next;
				pop(&(current->Next));
			}
		}
		size--;
		return data;
	}

	void print(Node* n)
	{
		std::cout << "\nСПИСОК СТУДЕНТОВ: ";
		while (n != nullptr)
		{
			std::cout << "\nНомер зачетной книжки: " << n->recordBookNumber;
			std::cout << "\nФамилия студента: " << n->lastName;
			std::cout << "\nКурс: " << n->course;
			std::cout << "\nКод группы: " << n->groupCode;
			std::cout << "\nДата поступления: " << n->receiptDate;
			std::cout << "\nДисциплина: " << n->discipline;
			std::cout << "\nОценка по дисциплине: " << n->disciplineGrade << std::endl;
			
			n = n->Next;
		}
	}

	int length(Node* head) //Длина списка
	{
		Node* current = head;
		int count = 0;
		while (current != NULL)
		{
			count++;
			current = current->Next;
		}
		return count;
	}

};
Node* SortedMerge(Node* a, Node* b, int index);
void FrontBackSplit(Node* source, Node** frontRef, Node** backRef)
{
	Node* fast;
	Node* slow;
	slow = source;
	fast = source->Next;

	while (fast != NULL) 
	{
		fast = fast->Next;
		if (fast != NULL) 
		{
			slow = slow->Next;
			fast = fast->Next;
		}
	}

	*frontRef = source;
	*backRef = slow->Next;
	slow->Next = NULL;
}

void MergeSort(Node** headRef, int index)
{
	Node* head = *headRef;
	Node* a;
	Node* b;
	if ((head == NULL) || (head->Next == NULL)) 
	{
		return;
	}
	FrontBackSplit(head, &a, &b);
	MergeSort(&a, index);
	MergeSort(&b, index);
	*headRef = SortedMerge(a, b, index);
}

Node* SortedMerge(Node* a, Node* b, int index)
{
	Node* result = NULL;

	if (a == NULL) return (b);
	else if (b == NULL) return (a);

	if (index == 1)
	{
		if (a->course <= b->course)
		{
			result = a;
			result->Next = SortedMerge(a->Next, b, index);
		}
		else
		{
			result = b;
			result->Next = SortedMerge(a, b->Next, index);
		}
	}
	if (index == 2)
	{
		if (a->recordBookNumber <= b->recordBookNumber)
		{
			result = a;
			result->Next = SortedMerge(a->Next, b, index);
		}
		else
		{
			result = b;
			result->Next = SortedMerge(a, b->Next, index);
		}
	}
	if (index == 3)
	{
		if (a->receiptDate <= b->receiptDate)
		{
			result = a;
			result->Next = SortedMerge(a->Next, b, index);
		}
		else
		{
			result = b;
			result->Next = SortedMerge(a, b->Next, index);
		}
	}
	return (result);
}

void menu()
{
	std::cout << "1) Добавить студента. \n";
	std::cout << "2) Удалить студента. \n";
	std::cout << "3) Вывести список студентов. \n";
	std::cout << "4) Найти студента. \n";
	std::cout << "5) Выход. \n";
}

int main()
{
	setlocale(LC_ALL, "Russian");
	std::system("chcp 1251"); 
	std::cout << "ЛАБОРАТОРНАЯ РАБОТА 2_1 \n";
	char menuSelection;
	char findSel;

	Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();

	List* list = new List();

	do
	{
		menu();
		std::cin >> menuSelection;

		switch (menuSelection)
		{
		case '1':
			list->push(&head);
			
			std::cout << "Введите номер зачетной книжки: ";
			std::cin >> head->recordBookNumber;
			std::cout << "Введите фамилию студента: ";
			std::cin >> head->lastName;
			std::cout << "Введите год поступления: ";
			std::cin >> head->receiptDate;

			do
			{
				std::cout << "Введите курс: ";
				std::cin >> head->course;
			} while (head->course < 0 || head->course > 6);
			std::cout << "Введите код группы: ";
			std::cin >> head->groupCode;

			std::cout << "Введите название дисциплины: ";
			std::cin >> head->discipline;

			do {
				std::cout << "Введите оценку по дисциплине: ";
				std::cin >> head->disciplineGrade;
			} while (head->disciplineGrade < 0 || head->disciplineGrade > 5);


			system("cls");
			break; 

		case '2':
			list->pop(&head);
		case '3':
			list->print(head);
			list->length(head);
			break;

		case '4':
			std::cout << "По какому параметру вы хотите найти студента? \n";
			std::cout << "1. По номеру курса\n 2. По номеру зач. книжки\n 3. По дате поступления\n";
			
			std::cin >> findSel;
			switch (findSel)
			{
			case '1':
				std::cout << "Вывожу отсортированный список студентов по номеру курса: \n";
				MergeSort(&head, 1);
				list->print(head);
				break;
			case '2':
				std::cout << "Вывожу отсортированный список студентов по номеру зачетной книжки: \n";
				MergeSort(&head, 2);
				list->print(head);
				break;
			case '3':
				std::cout << "Вывожу отсортированный список студентов по дате поступления: \n";
				MergeSort(&head, 3);
				list->print(head);
				break;
			}

			break;
		case '5':
			std::cout << "Выход из программы.";
			break;
		}

	} while (menuSelection != '5');

}