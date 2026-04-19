// Copyright 2025 NNTU-CS
#include "tstack.h"
#include <cctype>
#include <string>

int priority(char op) {
  if (op == '+' || op == '-') return 1;
  if (op == '*' || op == '/') return 2;
  return 0;
}

std::string infx2pstfx(const std::string& inf) {
  TStack<char, 100> ops;
  std::string result;

  for (size_t i = 0; i < inf.size(); ++i) {
    char c = inf[i];

    if (isdigit(c)) {
      while (i < inf.size() && isdigit(inf[i])) {
        result += inf[i];
        i++;
      }
      result += ' ';
      i--;
    } else if (c == '(') {
      ops.push(c);
    } else if (c == ')') {
      while (!ops.isEmpty() && ops.top() != '(') {
        result += ops.top();
        result += ' ';
        ops.pop();
      }
      ops.pop();
    } else if (c == '+' || c == '-' || c == '*' || c == '/') {
      while (!ops.isEmpty() && priority(ops.top()) >= priority(c)) {
        result += ops.top();
        result += ' ';
        ops.pop();
      }
      ops.push(c);
    }
  }

  while (!ops.isEmpty()) {
    result += ops.top();
    result += ' ';
    ops.pop();
  }

  if (!result.empty() && result.back() == ' ') {
    result.pop_back();
  }

  return result;
}

int eval(const std::string& pref) {
  TStack<int, 100> st;

  for (size_t i = 0; i < pref.size(); ++i) {
    char c = pref[i];

    if (c == ' ') continue;

    if (isdigit(c)) {
      int num = 0;
      while (i < pref.size() && isdigit(pref[i])) {
        num = num * 10 + (pref[i] - '0');
        i++;
      }
      st.push(num);
      i--;
    } else {
      int b = st.top();
      st.pop();
      int a = st.top();
      st.pop();

      int res = 0;
      if (c == '+') {
        res = a + b;
      } else if (c == '-') {
        res = a - b;
      } else if (c == '*') {
        res = a * b;
      } else if (c == '/') {
        res = a / b;
      }

      st.push(res);
    }
  }

  return st.top();
}
