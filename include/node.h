#ifndef _NODE_H_
#define _NODE_H_

#include<iostream>

template<typename T>
struct Node
{
	T info;
	Node *rlink = nullptr;
	Node *llink = nullptr;
	Node() = default;
	Node(const T&);
	Node(const Node&);
	Node(Node&&);
	Node& operator=(const Node&);
	Node& operator=(Node&&);
	~Node();
	void print() const;
	private:
	void copyNode(Node<T>&, const Node<T>&);
};

template<typename T>
Node<T>::Node(const T& value) : info(value) {}

template<typename T>
Node<T>::Node(const Node<T>& n2) : info(n2.info)
{
	copyNode(*this, n2);
}

template<typename T>
Node<T>::Node(Node<T>&& n2) : info(std::move(n2.info))
{
	rlink = n2.rlink;
	llink = n2.llink;
	n2.rlink=nullptr;
	n2.llink=nullptr;
}

template<typename T>
Node<T>& Node<T>::operator=(const Node<T>& n2)
{
	info = n2.info;
	copyNode(*this, n2);
  return *this;
}

template<typename T>
Node<T>& Node<T>::operator=(Node<T>&& n2)
{
	info = std::move(n2.info);
	rlink = n2.rlink;
	llink = n2.llink;
	n2.rlink=nullptr;
	n2.llink=nullptr;
  return *this;
}

template<typename T>
Node<T>::~Node()
{
	delete llink;
	delete rlink;
}

template<typename T>
void Node<T>::copyNode(Node<T>& n1, const Node<T>& n2)
{
	if(n2.llink!=nullptr)
	{
		n1.llink = new Node<T>(n2.llink->info);
		copyNode(*(n1.llink), *(n2.llink));
	}
	if(n2.rlink!=nullptr)
	{
		n1.rlink = new Node<T>(n2.rlink->info);
		copyNode(*(n1.rlink), *(n2.rlink));
	}
}

template<typename T>
void Node<T>::print() const
{
	std::cout<<info<<std::endl;
	if(llink!=nullptr) llink->print();
	if(rlink!=nullptr) rlink->print();
}

#endif
