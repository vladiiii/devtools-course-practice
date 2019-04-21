// Copyright 2019 Alexander Batashev

#ifndef MODULES_SET_INCLUDE_SET_H_
#define MODULES_SET_INCLUDE_SET_H_

#include <algorithm>
#include <iterator>
#include <vector>

template <typename T>
class Set {
 private:
  std::vector<T> items_;

 public:
  typedef typename std::vector<T>::const_iterator const_iterator;

  Set() = default;
  Set(const Set& src) = default;
  Set(Set&& src) = default;
  Set& operator=(const Set& src) = default;
  Set& operator=(Set&& src) = default;
  ~Set() = default;

  void Insert(T item) {
    if (std::find(items_.begin(), items_.end(), item) == items_.end()) {
      items_.push_back(item);
      std::sort(items_.begin(), items_.end());
    }
  }

  void Remove(T item) {
    const auto& pos = std::find(items_.begin(), items_.end(), item);
    if (pos != items_.end()) {
      items_.erase(pos);
    }
  }

  const_iterator begin() const { return items_.begin(); }

  const_iterator end() const { return items_.end(); }

  size_t Size() { return items_.size(); }

  void Expand(Set &other) {
      for (auto& item : other) {
          Insert(item);
      }
  }

  void Subtract(Set &other) {
      for (auto& item : other) {
          Remove(item);
      }
  }

  bool Contains(const T &item) const {
      for (const auto &other : items_) {
          if (item == other) {
              return true;
          }
      }
      return false;
  }

  static Set Intersect(Set &set1, Set &set2) {
      Set<T> resSet(set1);
      for (auto item : set1.items_) {
          if (!set2.Contains(item)) {
              resSet.Remove(item);
          }
      }
      return resSet;
  }

  static Set SymmetricDifference(Set &set1, Set &set2) {
      Set<T> resSet(set1);
      for (auto item : set2.items_) {
          if (!set1.Contains(item)) {
              resSet.Insert(item);
          } else {
              resSet.Remove(item);
          }
      }
      return resSet;
  }
};

#endif  // MODULES_SET_INCLUDE_SET_H_
