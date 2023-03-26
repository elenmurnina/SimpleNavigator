#pragma once

#ifndef QUEUE_H
#define QUEUE_H

#include <memory>
#include <utility>
#include <vector>

namespace ft {
template <class T, class Container = std::vector<T>> class queue {
public:
  typedef Container container_type;
  typedef typename Container::value_type value_type;
  typedef typename Container::size_type size_type;
  typedef typename Container::reference reference;
  typedef typename Container::const_reference const_reference;

protected:
  container_type _cont;

public:
  /*Constructors etc*/
  queue() : queue(Container()) {}

  explicit queue(const Container &cont) : _cont(cont) {}

  queue(const queue &other) : _cont(other._cont) {}

  queue &operator=(const queue &other) {
    _cont = other._cont;
    return *this;
  }

  ~queue() {}

  reference back() { return _cont.back(); }

  const_reference back() const { return _cont.back(); }

  reference front() { return _cont.front(); }

  const_reference front() const { return _cont.front(); }

  bool empty() const { return _cont.empty(); }

  size_type size() const { return _cont.size(); }

  void push(const value_type &value) { return _cont.push_back(value); }

  reference peek() { return _cont.front(); }

  const_reference peek() const { return _cont.front(); }

  void pop() { _cont.erase(_cont.begin()); }

  static const queue<T, Container> init() { return queue<T, Container>(); }
};

template <class T, class Container>
bool operator==(const ft::queue<T> &lhs, const ft::queue<T> &rhs) {
  return lhs._cont == rhs._cont;
}

template <class T, class Container>
bool operator!=(const ft::queue<T> &lhs, const ft::queue<T> &rhs) {
  return lhs._cont != rhs._cont;
}

template <class T, class Container>
bool operator<(const ft::queue<T> &lhs, const ft::queue<T> &rhs) {
  return lhs._cont < rhs._cont;
}

template <class T, class Container>
bool operator<=(const ft::queue<T> &lhs, const ft::queue<T> &rhs) {
  return lhs._cont <= rhs._cont;
}

template <class T, class Container>
bool operator>(const ft::queue<T> &lhs, const ft::queue<T> &rhs) {
  return lhs._cont > rhs._cont;
}

template <class T, class Container>
bool operator>=(const ft::queue<T> &lhs, const ft::queue<T> &rhs) {
  return lhs._cont >= rhs._cont;
}

}

#endif
