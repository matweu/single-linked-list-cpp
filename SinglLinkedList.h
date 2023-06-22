#include <iostream>
#pragma once

template<typename T>
class List
{
public:
	List();
	~List();

	//���������� �������� � �����
	void push_back(T data);
	//��������� ������� ��������
	int GetSize() { return Size; }
	//������� ������ �������
	void pop_front();
	//������� ��� ������
	void clear();
	//���������� ��������� []
	T& operator[](const int index);
	//��������� ������� � �����
	void push_front(T data);
	//��������� ������� �� �������
	void insert(T data, int index);
	//������� ������� �� �������
	void removeAt(int index);
	//������� ��������� �������
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
