#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include "node.h"
#include <utility>
#include <stdexcept>
#include <iostream>
#include "vector.h"
#include <functional>

template<typename T>
class BinaryTree
{
  using func = std::function<bool(const T&, const T&)>;
  public:
    BinaryTree() = default;
    BinaryTree(func gT, func lT, func eq) : greaterThan(gT), lessThan(lT), equal(eq) {}
    BinaryTree(const Node<T>&);
    BinaryTree(const BinaryTree&);
    BinaryTree(BinaryTree&&);
    ~BinaryTree();

    BinaryTree& operator=(const BinaryTree&);
    BinaryTree& operator=(BinaryTree&&);
    
    template<typename U>
      BinaryTree& push(U&&);
    bool find(const T&) const;
    bool remove(const T&);
    const T& get(const T&) const;
    T& get(const T&);

    void inOrder(std::ostream&) const;
    //void postOrder() const;
    //void preOrder() const;
    void printBST() const;
    void BalanceTree();
    void BalanceTree(sp::vector<T>&);
    void setGreaterThan(func gT) { greaterThan = gT; }
    void setLessThan(func lT) { lessThan = lT; }
    void setEqual(func eq) { equal = eq; }
    template<typename U>
    void TreeToVectorPointers(sp::vector<U>&) const;

  private:
    Node<T>* root=nullptr;
    void createTree(Node<T>*, Node<T>*);
    void print_inOrder(Node<T>*, std::ostream&) const;
    bool findWrapper(const T&, Node<T>*) const;
    bool removeWrapper(const T&, Node<T>*);
    void elementFound(Node<T>*, Node<T>*, bool);
    void printBSTWrapper(Node<T>*) const;
    void FillVectorWithElements(sp::vector<T>&, Node<T>*) const;
    template<typename U>
    void FillVectorWithPointers(sp::vector<U>&, Node<T>*) const;
    void CreateTreeFromVector(sp::vector<T>&, int, int);
    func greaterThan = [](const T& first, const T& second) { return first>second; };
    func lessThan = [](const T& first, const T& second) { return first<second; };
    func equal = [](const T& first, const T& second) { return first == second; };
};

template<typename T>
BinaryTree<T>::BinaryTree(const Node<T>& node) 
{ 
  root = new Node<T>(node.info);
  if(node.llink!=nullptr)
  {
    root->llink=new Node<T>(node.llink->info);
    createTree(root->llink, node.llink);
  }
  if(node.rlink!=nullptr)
  {
    root->rlink = new Node<T>(node.rlink->info);
    createTree(root->rlink, node.rlink);
  }
}

template<typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& otherTree)
{
  if(otherTree.root != nullptr)
  {
    root = new Node<T>(otherTree.root->info);
    if(otherTree.root->llink != nullptr)
    {
      root->llink = new Node<T>(otherTree.root->llink->info);
      createTree(root->llink, otherTree.root->llink);
    }
    if(otherTree.root->rlink != nullptr)
    {
      root->rlink = new Node<T>(otherTree.root->rlink->info);
      createTree(root->rlink, otherTree.root->rlink);
    }
  }
}

template<typename T>
BinaryTree<T>::BinaryTree(BinaryTree<T>&& otherTree)
{
  root = otherTree.root;
  otherTree.root = nullptr;
}

template<typename T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& otherTree)
{
  if(this != &otherTree)
  {
    delete root;
    root = nullptr;
    if(otherTree.root != nullptr)
    {
      root = new Node<T>(otherTree.root->info);
      if(otherTree.root->llink != nullptr)
      {
        root->llink = new Node<T>(otherTree.root->llink->info);
        createTree(root->llink, otherTree.root->llink);
      }
      if(otherTree.root->rlink != nullptr)
      {
        root->rlink = new Node<T>(otherTree.root->rlink->info);
        createTree(root->rlink, otherTree.root->rlink);
      }
    }
  }
  return *this;
}

template<typename T>
BinaryTree<T>& BinaryTree<T>::operator=(BinaryTree<T>&& otherTree)
{
  delete root;
  root = otherTree.root;
  otherTree.root = nullptr;
  return *this;
}

template<typename T>
void BinaryTree<T>::createTree(Node<T>* dest, Node<T>* source)
{
  if(source->llink != nullptr)
  {
    dest->llink = new Node<T>(source->llink->info);
    createTree(dest->llink, source->llink);
  }
  if(source->rlink != nullptr)
  {
    dest->rlink = new Node<T>(source->rlink->info);
    createTree(dest->rlink, source->rlink);
  }
}

template<typename T>
template<typename U>
BinaryTree<T>& BinaryTree<T>::push(U&& info)
{
  if(root == nullptr)
    root  = new Node<T>(std::forward<U>(info));
  else
  {
    Node<T> *temp = root;
    while(1)
    {
      if(greaterThan(temp->info,info))
      {
        if(temp->llink != nullptr)
          temp = temp->llink;
        else
        {
          temp->llink = new Node<T>(std::forward<U>(info));
          break;
        }
      }
      else if(lessThan(temp->info,info))
      {
        if(temp->rlink != nullptr)
          temp = temp->rlink;
        else
        {
          temp->rlink = new Node<T>(std::forward<U>(info));
          break;
        }
      }
      else
        throw std::invalid_argument("Element already exists.");
    }
  }
  return *this;
}

template<typename T>
bool BinaryTree<T>::find(const T& elem) const
{
  return findWrapper(elem, root);
}

template<typename T>
bool BinaryTree<T>::findWrapper(const T& elem, Node<T>* node) const
{
  if(node==nullptr)
    return false;
  if(equal(node->info, elem))
    return true;
  if(greaterThan(node->info, elem))
    return findWrapper(elem, node->llink);
  else
    return findWrapper(elem, node->rlink);
}

template<typename T>
const T& BinaryTree<T>::get(const T& element) const
{
  Node<T>* temp = root;
  while(temp!=nullptr)
  {
    if(equal(temp->info, element))
      return temp->info;
    else if(greaterThan(temp->info, element))
      temp = temp -> llink;
    else
      temp = temp -> rlink;
  }
  throw std::invalid_argument("Element does not exist!");
}

template<typename T>
T& BinaryTree<T>::get(const T& element)
{
  Node<T>* temp = root;
  while(temp!=nullptr)
  {
    if(equal(temp->info, element))
      return temp->info;
    else if(greaterThan(temp->info, element))
      temp = temp -> llink;
    else
      temp = temp -> rlink;
  }
  throw std::invalid_argument("Element does not exist!");
}

template<typename T>
bool BinaryTree<T>::remove(const T& elem)
{
  if(root == nullptr)
    return false;
  if(equal(root->info, elem))
  {
    if(root->llink == nullptr && root->rlink == nullptr)
    {
      delete root;
      root = nullptr;
    }
    if(root->llink == nullptr && root->rlink != nullptr)
    {
      std::swap(root->info, root->rlink->info);
      delete root->rlink;
      root->rlink = nullptr;
    }
    else if(root->rlink == nullptr && root->llink != nullptr)
    {
      std::swap(root->info, root->llink->info);
      delete root->llink;
      root->llink = nullptr;
    }
    else
      elementFound(root, root, true);
    return true;
  }
  else if(greaterThan(root->info, elem))
    return removeWrapper(elem, root->llink);
  else return removeWrapper(elem, root->rlink);
}

template<typename T>
bool BinaryTree<T>::removeWrapper(const T& elem, Node<T>* node)
{
  if(greaterThan(node->info, elem))
  {
    if(node->llink == nullptr) return false;
    if(equal(node->llink->info, elem))
    {
      elementFound(node, node->llink, true);
      return true;
    }
    else return removeWrapper(elem, node->llink);
  }
  else if(lessThan(node->info, elem))
  {
    if(node->rlink == nullptr) return false;
    if(equal(node->rlink->info, elem))
    {
      elementFound(node, node->rlink, false);
      return true;
    }
    else return removeWrapper(elem, node->rlink);
  }
  else return true;
} 

template<typename T>
void BinaryTree<T>::elementFound(Node<T>* parent, Node<T>* element, bool left)
{
  if(element->llink == nullptr && element->rlink == nullptr)
  {
    delete element;
    if(left) parent->llink = nullptr;
    else parent->rlink=nullptr;
  }
  else if(element->llink==nullptr && element->rlink != nullptr)
  {
    if(left) parent->llink = element->rlink;
    else parent->rlink = element->rlink;
    element->rlink = nullptr;
    delete element;
  }
  else if(element->rlink==nullptr && element->llink != nullptr)
  {
    if(left) parent->llink = element->llink;
    else parent->rlink = element->llink;
    element->llink=nullptr;
    delete element;
  }
  else
  {
    Node<T> *exchange = element->llink;
    Node<T> *exchangeParent = element;
    while( exchange->rlink != nullptr )
    {
      exchangeParent = exchange;
      exchange = exchange -> rlink;
    }
    std::swap(element->info, exchange->info);
    exchangeParent->rlink = nullptr;
    delete exchange;
  }
}

template<typename T>
void BinaryTree<T>::inOrder(std::ostream& out) const
{
  print_inOrder(root, out);
}

template<typename T>
void BinaryTree<T>::print_inOrder(Node<T>* node, std::ostream& out) const
{
  if(node == nullptr)
    return;
  print_inOrder(node->llink, out);
  out<<node->info<<std::endl;
  print_inOrder(node->rlink, out);
}

template<typename T>
void BinaryTree<T>::printBST() const
{
  printBSTWrapper(root);
}

template<typename T>
void BinaryTree<T>::printBSTWrapper(Node<T>* node) const
{
  if(node == nullptr)
  {
    std::cout<<"Nullptr\n";
    return;
  }
  std::cout<<"Elem: "<<node->info<<std::endl;
  std::cout<<"Left child of "<<node->info<<" is: ";
  printBSTWrapper(node->llink);
  std::cout<<"Right child of "<<node->info<<" is: ";
  printBSTWrapper(node->rlink);
}

template<typename T>
void BinaryTree<T>::BalanceTree()
{
  sp::vector<T> sortedElements;
  FillVectorWithElements(sortedElements, root);
  delete root;
  root=nullptr;
  CreateTreeFromVector(sortedElements, 0, sortedElements.size());
}

template<typename T>
void BinaryTree<T>::CreateTreeFromVector(sp::vector<T>& vec, int bottom, int top)
{
  if((top-bottom)<2 && top != 1) return;
  if(top==1)
  {
    push(std::move(vec[0]));
    return;
  }
  int middle = (top+bottom) / 2;
  push(std::move(vec[middle]));
  CreateTreeFromVector(vec, middle, top);
  CreateTreeFromVector(vec, bottom, middle);
}

template<typename T>
void BinaryTree<T>::BalanceTree(sp::vector<T>& vec)
{
  delete root;
  root = nullptr;
  CreateTreeFromVector(vec, 0, vec.size());
}

template<typename T>
void BinaryTree<T>::FillVectorWithElements(sp::vector<T>& vec, Node<T>* node) const
{
  if(node == nullptr)
    return;
  FillVectorWithElements(vec, node->llink);
  vec.push(node->info);
  FillVectorWithElements(vec, node->rlink);
}

template<typename T>
template<typename U>
void BinaryTree<T>::TreeToVectorPointers(sp::vector<U>& vec) const
{
  FillVectorWithPointers(vec, root);
}

template<typename T>
template<typename U>
void BinaryTree<T>::FillVectorWithPointers(sp::vector<U>& vec, Node<T>* node) const
{
  if(node == nullptr)
    return;
  FillVectorWithPointers(vec, node->llink);
  vec.push(&(node->info));
  FillVectorWithPointers(vec, node->rlink);
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
  delete root;
}

#endif
