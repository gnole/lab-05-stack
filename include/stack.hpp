// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_STACK_HPP_
#define INCLUDE_STACK_HPP_

#include <iostream>
#include <utility>

template <typename T>
struct node {
  T value;
  node<T>* next_n;
  node() {next_n = nullptr;}
  node(const T& val, node<T>* next_node);
  node(const T&& val, node<T>* next_node);
  ~node();
};


template <typename T>
class Stack {
  node<T>* first_n;
 public:
  // task 1
  Stack();
  Stack(Stack&& r_stack) noexcept {
    first_n = std::move(r_stack.first_n);
  }
  ~Stack();
  void push(T&& value);
  void push(const T& value);
  void pop();
  const T& head() const;
  Stack(const Stack&) = delete;
  Stack& operator=(const Stack&) = delete;
  Stack& operator=(Stack&& rStack) noexcept;
 };


template <typename T>
node<T>::node(const T& val, node<T>* next_node) {
  value = val;
  next_n = next_node;
}

template <typename T>
node<T>::~node<T>() {
  if (next_n != nullptr) {
    delete next_n;
    next_n = nullptr;
  }
}
template <typename T>
node<T>::node(const T&& val, node<T>* next_node) {
  value = std::move(val);
  next_n = next_node;
}
//---------end-node-definition-zone-------

template <typename T>
Stack<T>::Stack() {
  first_n = nullptr;
}

template <typename T>
Stack<T>::~Stack<T>() {
  if (first_n != nullptr) {
    delete first_n;
    first_n = nullptr;
  }
}

template <typename T>
void Stack<T>::push(T&& value) {
  auto pushing_node = new node<T>(std::move(value), first_n);
  first_n = pushing_node;
}

template <typename T>
void Stack<T>::push(const T& value) {
  auto pushing_node = new node<T>(value, first_n);
  first_n = pushing_node;
}

template <typename T>
void Stack<T>::pop() {
  if (first_n) {
    node<T>* tmp = first_n->next_n;
    first_n->next_n = nullptr;
    delete first_n;
    first_n = tmp;
  } else {
    throw std::runtime_error("Stack was empty");
  }
}

template <typename T>
const T& Stack<T>::head() const {
  if (first_n == nullptr) {
    throw std::runtime_error("Stack was empty");
  } else {
    return first_n->value;
  }
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack&& rStack) noexcept {
  if (this == &rStack) return *this;
  delete first_n;
  first_n = std::move(rStack.first_n);
  return *this;
}

#endif // INCLUDE_STACK_HPP_
