#include <iostream>
#include <utility>

#ifndef STACK_PRJ_STACK2_HPP
#define STACK_PRJ_STACK2_HPP

template <typename T>
class StackNotCopyTypes {
  node<T>* first_n;

 public:
  template <typename... Args>
  void push_emplace(Args&&... value) {
    (push(value), ...);
  }
  StackNotCopyTypes() {
    first_n = nullptr;
  }
  const T& head() const {
    if (first_n == nullptr) {
      throw std::runtime_error("Stack was empty");
    } else {
      return first_n->value;
    }
  }

  void push(T&& value) {
    auto pushing_node = new node<T>(std::move(value), first_n);
    first_n = pushing_node;
  }
  void push(T& value) {
    auto pushing_node = new node<T>(value, first_n);
    first_n = pushing_node;
  }
  T pop() {
    if (first_n) {
      node<T>* tmp = first_n->next_n;
      first_n->next_n = nullptr;
      delete first_n;
      first_n = tmp;
      return this->head();
    } else {
      throw std::runtime_error("Stack was empty");
    }
  }
  StackNotCopyTypes(const StackNotCopyTypes&) = delete;
  StackNotCopyTypes& operator=(const StackNotCopyTypes&) = delete;
  StackNotCopyTypes& operator=(StackNotCopyTypes&& rStack) noexcept {
    delete first_n;
    first_n = std::move(rStack.first_n);
  }
  ~StackNotCopyTypes() {
    if (first_n != nullptr) {
      delete first_n;
      first_n = nullptr;
    }
  }
};

#endif  // STACK_PRJ_STACK2_HPP
