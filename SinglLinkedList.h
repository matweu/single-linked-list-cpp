#include <iostream>
#pragma once

template<typename T>
class List
{
public:
	List();
	~List();

	//Добавление элемента в конец
	void push_back(T data);
	//Получение размера коллекци
	int GetSize() { return Size; }
	//Удаляем первый элемент
	void pop_front();
	//Очищаем наш список
	void clear();
	//Перегрузка оператора []
	T& operator[](const int index);
	//Добавляем элемент в конец
	void push_front(T data);
	//Добавляем Элемент по индексу
	void insert(T data, int index);
	//Удаляем элемент по индексу
	void removeAt(int index);
	//Удаляем последний элемент
	void pop_back();

private:
	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;//sizelist
	Node <T>* head;
};

template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}
