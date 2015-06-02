#ifndef _STACK_H
#define _STACK_H

#include<iostream>
#include <initializer_list>

template<typename T>
class stack
{
  private:
    struct Node;
    Node* _head=nullptr;
    int _size=0;
    void deallocate();

  public:

    /***Constructors***/

    stack() = default;
    stack(std::initializer_list<T>&&);
    stack(const std::initializer_list<T>&);
    stack(const stack<T>&);
    stack(stack<T>&&);
    ~stack();

    
    /******Methods*****/

    bool inStack(const T&) const;
    T pop();
    T& top();
    const T& top() const;
    template<typename U>
    stack<T>& push(U&&);
    int size() const { return _size; }


    /*****Operators****/
    stack<T>& operator=(const stack<T>&);
    stack<T>& operator=(stack<T>&&);

};

/*****Constructors*****/

template<typename T>
stack<T>::stack(std::initializer_list<T>&& lst)
{
  typename std::initializer_list<T>::iterator it;
  for(it=lst.begin();it!=lst.end();++it)
  {
    push(std::move(*it));
  }
}

template<typename T>
stack<T>::stack(const std::initializer_list<T>& lst)
{
  typename std::initializer_list<T>::const_iterator it;
  for(it=lst.begin();it!=lst.end();++it)
  {
    push(*it);
  }
}

template<typename T>
stack<T>::stack(const stack<T>& stk)
{
  if(stk._size!=0)
  {
    _size=stk._size;
    Node *flow=stk._head;
    Node *novi=new Node(flow->_value);
    _head=novi;
    flow=flow->_next;
    while(flow!=nullptr)
    {
      novi->_next=new Node(flow->_value);
      novi=novi->_next;
      flow=flow->_next;
    }
  }
}

template<typename T>
stack<T>::stack(stack<T>&& stk)
{
  _head=stk._head;
  stk._head=nullptr;
  _size=stk._size;
  stk._size=0;
}

/****Destructor****/

template<typename T>
stack<T>::~stack()
{
  deallocate();
}

template<typename T>
void stack<T>::deallocate()
{
  if(_head!=nullptr)
  {
    Node* p = _head;
    _head=_head->_next;
    while(_head!=nullptr)
    {
      delete p;
      p=_head;
      _head=_head->_next;
    }
    delete p;
  }
}

/*****Methods******/

template<typename T>
bool stack<T>::inStack(const T& param) const
{
  Node *pom=_head;
  while(pom!=nullptr)
  {
    if(pom->_value==param)
      return true;
    pom=pom->_next;
  }
  return false;
}

template<typename T>
T stack<T>::pop()
{
  T rtrn = std::move(_head->_value);
  Node *dlt = _head;
  _head=_head->_next;
  --_size;
  delete dlt;
  return std::move(rtrn);
}

template<typename T>
T& stack<T>::top()
{
  return _head->_value;
}

template<typename T>
const T& stack<T>::top() const
{
  return _head->_value;
}

template<typename T>
template<typename U>
stack<T>& stack<T>::push(U&& el)
{
  Node *nw = new Node(std::forward<U>(el));
  nw->_next=_head;
  _head=nw;
  ++_size;
  return *this;
}

/****Operators*****/
template<typename T>
stack<T>& stack<T>::operator=(const stack<T>& s)
{
  if(&s!=this)
  {
    if(_size!=0)
      deallocate();
    if(s._size!=0)
    {
      _size=s._size;
      Node *flow=s._head;
      Node *novi=new Node(flow->_value);
      _head=novi;
      flow=flow->_next;
      while(flow!=nullptr)
      {
        novi->_next=new Node(flow->_value);
        novi=novi->_next;
        flow=flow->_next;
      }
    }
  }
  return *this;
}

template<typename T>
stack<T>& stack<T>::operator=(stack<T>&& s)
{
  deallocate();
  _head=s._head;
  s._head=nullptr;
  _size=s._size;
  return *this;
}

template<typename T>
struct stack<T>::Node
{
  T _value;
  Node* _next=nullptr;
  template<typename U>
  Node(U&& value) : _value(std::forward<U>(value)) {}
};

#endif
