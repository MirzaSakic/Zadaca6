#ifndef _VECTOR_H
#define _VECTOR_H

#include <utility>
#include <algorithm>
#include <initializer_list>

namespace sp
{
template<typename T>
class vector
{
  public:
    vector() = default;
    vector(const std::initializer_list<T>&);
    vector(const vector<T>&);
    vector(vector<T>&&);
    vector<T>& operator=(const vector<T>&);
    vector<T>& operator=(vector<T>&&);
    ~vector();
    class iterator;
    iterator begin () const {return iterator(_array);}
    iterator end() const {return iterator(_array + _size);}

    template<typename U>
      vector<T>& push(U&&);
    T& operator[](int);
    const T& operator[](int) const;
    int size() const { return _size; }

  private:
    int _cap{8};
    int _size{0};
    T *_array = new T[_cap];
    void reallocate();
};

template<typename T>
vector<T>::vector(const std::initializer_list<T>& in_list)
{
  _size=in_list.size();
  _cap=_size+10;
  delete [] _array;
  _array = new T [_cap];
  std::copy(in_list.begin(),in_list.end(),_array);
}

template<typename T>
vector<T>::vector(const vector<T>& otherVector) : _cap(otherVector._cap), _size(otherVector._size)
{
  std::copy(otherVector._array, otherVector._array + _size, _array);
}

template<typename T>
vector<T>::vector(vector<T>&& tempVector) : _cap(tempVector._cap), _size(tempVector._size), _array(tempVector._array)
{
  tempVector._array = nullptr;
}

template<typename T>
vector<T>& vector<T>::operator=(const vector<T>& otherVector)
{
  if(this!=&otherVector)
  {
    delete [] _array;
    _cap = otherVector._cap;
    _size = otherVector._size;
    _array = new T[_cap];
    std::copy(otherVector._array, otherVector._array + _size, _array);
  }
  return *this;
}

template<typename T>
vector<T>& vector<T>::operator=(vector<T>&& tempVector)
{
  delete [] _array;
  _cap = tempVector._cap;
  _size = tempVector._size;
  _array = tempVector._array;
  tempVector._array = nullptr;
  tempVector._size = 0;
  return *this;
}

template<typename T>
vector<T>::~vector()
{
  delete [] _array;
}

template<typename T>
template<typename U>
vector<T>& vector<T>::push(U&& element)
{
  if((_size+1) == _cap)
    reallocate();
  _array[_size++] = std::forward<U>(element);
  return *this;
}

template<typename T>
T& vector<T>::operator[](int index)
{
  return _array[index];
}

template<typename T>
const T& vector<T>::operator[](int index) const
{
  return _array[index];
}

template<typename T>
void vector<T>::reallocate()
{
  _cap *= 2;
  T * newarray = new T[_cap];
  std::copy(_array, _array + _size, newarray);
  delete [] _array;
  _array = newarray;
}

template<typename T>
class vector<T>::iterator : public std::iterator<std::random_access_iterator_tag,T>{
  
  public:
    T* pointer_el;

    //-----------------------------------------------------------
    typedef std::random_access_iterator_tag iterator_categroy;
    typedef T value_type;
    typedef size_t difference_type;
    typedef T* pointer;
    typedef T& refernece;
    //-----------------------------------------------------------

    iterator(T* p) : pointer_el(p) {}

    T& operator * () {return *pointer_el;}
    
    iterator& operator ++ ()
    {
      ++pointer_el;
      return *this;
    }

    iterator&& operator ++ (int)
    {
      iterator temp=*this;
      pointer_el++;
      return std::move(temp);
    }

    iterator& operator -- ()
    {
      --pointer_el;
      return *this;
    }

    iterator&& operator -- (int)
    {
      iterator temp = *this;
      --pointer_el;
      return std::move(temp);
    }

    iterator&& operator + (int a) const 
    {
      T* temp = this->pointer_el + a;
      iterator it (temp);
      return std::move(it);
    }

    iterator&& operator - (int a) const 
    {
      T* temp = this->pointer_el - a;
      iterator it (temp);
      return std::move(it);
    }

    iterator& operator += (int a)
    {
      this->pointer_el=this->pointer_el + a;
      return *this;
    }

    iterator& operator -= (int a)
    {
      this->pointer_el=this->pointer_el - a;
      return *this;
    }

    iterator&& operator + (const iterator& other) const 
    {
      return iterator(this->pointer_el + other.pointer_el);
    }

    iterator&& operator - (const iterator& other) const 
    {
      return iterator(this->pointer_el - other.pointer_el);
    }

/*
    iterator&& operator + (const iterator& other) const 
    {
      iterator temp = iterator (this->pointer_el + (other.pointer_el - other._array));
      return std::move(temp);
    }

    iterator&& operator - (const iterator& other) const 
    {
      iterator temp = iterator (this->pointer_el - (other.pointer_el - other._array));
      return std::move(temp);
    }
*/

    bool operator == (const iterator& other) const {return (pointer_el == other.pointer_el);}
    bool operator != (const iterator& other) const {return (pointer_el != other.pointer_el);}
    bool operator >  (const iterator& other) const {return (pointer_el >  other.pointer_el);}
    bool operator <  (const iterator& other) const {return (pointer_el <  other.pointer_el);}
    bool operator <= (const iterator& other) const {return (pointer_el <= other.pointer_el);}
    bool operator >= (const iterator& other) const {return (pointer_el >= other.pointer_el);}

};

}
#endif
