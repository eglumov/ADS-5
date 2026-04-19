// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template <typename T, int size>
class TStack {
 public:
  TStack() : topIndex(-1) {}

  bool isEmpty() const {
    return topIndex == -1;
  }

  bool isFull() const {
    return topIndex == size - 1;
  }

  void push(const T& value) {
    data[++topIndex] = value;
  }

  void pop() {
    --topIndex;
  }

  T& top() {
    return data[topIndex];
  }

  const T& top() const {
    return data[topIndex];
  }

 private:
  static const int kSize = size;
  T data[kSize];
  int topIndex;
};

#endif // INCLUDE_TSTACK_H_
