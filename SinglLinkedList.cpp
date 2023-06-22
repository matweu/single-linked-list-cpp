#include <iostream>
#include "SinglLinkedList.h"

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		while (current->pNext !=nullptr)
		{
			current = current-> pNext;
		}
		current->pNext = new Node<T>(data);
	}
	++Size;
}

template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = head;
	
	head = head->pNext;
	delete temp;
	--Size;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		++counter;
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	++Size;
}

template<typename T>
void List<T>::insert(T data, int index)
{
	if (index==0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; ++i)
		{
			previous = previous->pNext;
		}
		//Node<T>* NewNode = new Node<T>(data, previous->pNext);
		//previous->pNext = NewNode;
		previous->pNext = new Node<T>(data, previous->pNext); //То же самое, но короче код
		++Size;
	}
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previos = this->head;
		for (int i = 0; i < index-1; i++)
		{
			previos = previos->pNext;
		}

		Node<T> *DeletePtr = previos->pNext;
		previos->pNext = DeletePtr->pNext;
		delete DeletePtr;
		--Size;
	}
}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}


int main()
{
	setlocale(LC_CTYPE, "Rus");
	List<int> lst;
	lst.push_back(5);
	lst.push_back(51);
	lst.push_front(13);
	std::cout << "///////////////////" << std::endl;
	for (int i = 0; i < lst.GetSize(); ++i)
	{
		std::cout << lst[i] << std::endl;
	}
	lst.pop_back();
	lst.pop_back();
	lst.insert(1, 1);
	lst.insert(2, 2);
	std::cout << "///////////////////" << std::endl;
	for (int i = 0; i < lst.GetSize(); ++i)
	{
		std::cout << lst[i] << std::endl;
	}
	lst.clear();
	std::cout << "Number of Elemets:" << lst.GetSize() << std::endl;

}