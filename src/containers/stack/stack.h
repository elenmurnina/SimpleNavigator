#pragma once

#ifndef STACK_H
#define STACK_H

#include <memory>
#include <utility>
#include <vector>

namespace ft {
template <class T, class Container = std::vector<T>> class stack {
public:
  typedef Container container_type;
  typedef typename Container::value_type value_type;
  typedef typename Container::size_type size_type;
  typedef typename Container::reference reference;
  typedef typename Container::const_reference const_reference;

protected:
  container_type _cont;

public:
  stack() : stack(Container()) {}

  explicit stack(const Container &cont) : _cont(cont) {}

  stack(const stack &other) : _cont(other._cont) {}

  stack &operator=(const stack &other) {
    _cont = other._cont;
    return *this;
  }

  ~stack() {}

  reference top() { return _cont.back(); }

  const_reference top() const { return _cont.back(); }

  bool empty() const { return _cont.empty(); }

  size_type size() const { return _cont.size(); }

  void push(const value_type &value) { return _cont.push_back(value); }

  reference peek() { return _cont.back(); }

  const_reference peek() const { return _cont.back(); }

  void pop() { _cont.pop_back(); }

  static const stack init() { return stack<T, Container>(); }
};

template <class T, class Container>
bool operator==(const ft::stack<T> &lhs, const ft::stack<T> &rhs) {
  return lhs._cont == rhs._cont;
}

template <class T, class Container>
bool operator!=(const ft::stack<T> &lhs, const ft::stack<T> &rhs) {
  return lhs._cont != rhs._cont;
}

template <class T, class Container>
bool operator<(const ft::stack<T> &lhs, const ft::stack<T> &rhs) {
  return lhs._cont < rhs._cont;
}

template <class T, class Container>
bool operator<=(const ft::stack<T> &lhs, const ft::stack<T> &rhs) {
  return lhs._cont <= rhs._cont;
}

template <class T, class Container>
bool operator>(const ft::stack<T> &lhs, const ft::stack<T> &rhs) {
  return lhs._cont > rhs._cont;
}

template <class T, class Container>
bool operator>=(const ft::stack<T> &lhs, const ft::stack<T> &rhs) {
  return lhs._cont >= rhs._cont;
}

} // namespace ft

#endif
