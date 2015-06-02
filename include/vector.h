#ifndef _VECTOR_H
#define _VECTOR_H

#include <utility>
#include <algorithm>

namespace sp
{
template<typename T>
class vector
{
  public:
    vector() = default;
    vector(const vector<T>&);
    vector(vector<T>&&);
    vector<T>& operator=(const vector<T>&);
    vector<T>& operator=(vector<T>&&);
    ~vector();

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
}
#endif
