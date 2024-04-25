/**
 * @file ByteHashMap.hpp
 * @brief ByteHashMap header file
 */
#pragma once
#include <cstddef>
#include <cstdint>
#include <initializer_list>
#include <iostream>
#include <iomanip>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <utility>
#include <vector>
#include <climits>

using namespace std;
using Key = byte;

template <typename Tp>
using value_type = pair<const Key, Tp>;

#define DEBUG

ostream& operator<<(ostream& os, const byte& b) {
  os << "0x" << hex << setfill('0') << setw(2) << static_cast<uint16_t>(b);
  return os;
}

template <typename Tp>
ostream& operator<<(ostream& os, const value_type<Tp>& v) {
  os << "{" << v.first << "," << v.second << "}";
  return os;
}

template <typename Tp>
class ByteHashMap {
 public:
  ByteHashMap()
      : size_(0), buckets_(new Bucket[bucket_size_]), values_(0) {
  }

  ~ByteHashMap() {
    cerr << "ByteHashMap destructor" << endl;
    delete[] buckets_;
  }

  class Bucket {
   public:
    Bucket() : value_idx(-1) {}
    ~Bucket() {}

    int16_t value_idx;
  };

  bool
  empty(void) const {
    return size_ == 0;
  }

  size_t size(void) const {
    return size_;
  }

  size_t max_size(void) const {
    return bucket_size_;
  }

  typename vector<value_type<Tp>>::iterator begin(void) {
    return values_.begin();
  }

  typename vector<value_type<Tp>>::iterator begin(void) const {
    return values_.begin();
  }

  typename vector<value_type<Tp>>::iterator end(void) {
    return values_.end();
  }

  typename vector<value_type<Tp>>::iterator end(void) const {
    return values_.end();
  }

  template <typename... Args>
  pair<typename vector<value_type<Tp>>::iterator, bool> emplace(Args&&... args) {
    return insert(forward<Args>(args)...);
  }

  pair<typename vector<value_type<Tp>>::iterator, bool> insert(const value_type<Tp>& p) {
    const Key& k = p.first;
    auto bucket_idx = to_integer<uint8_t>(k);

    if (contains(k)) {
      return {values_.begin() + buckets_[bucket_idx].value_idx, false};
    }

    // insert
    buckets_[bucket_idx].value_idx = size_++;
    values_.emplace_back(p);
    return {values_.begin() + buckets_[bucket_idx].value_idx, true};
  }

  pair<typename vector<value_type<Tp>>::iterator, bool> insert(value_type<Tp>&& p) {
    const Key& k = p.first;
    auto bucket_idx = to_integer<uint8_t>(k);

    if (contains(k)) {
      return {values_.begin() + buckets_[bucket_idx].value_idx, false};
    }

    // insert
    buckets_[bucket_idx].value_idx = size_++;
    values_.emplace_back(move(p));
    return {values_.begin() + buckets_[bucket_idx].value_idx, true};
  }

  void insert(initializer_list<Tp> il) {
    for (const auto& t : il) {
      insert(t);
    }
  }

  // rarely used
  size_t erase(const Key& k) {
    return 0;
  }

  void clear(void) {
    for (auto bucket : buckets_) {
      bucket.value_idx = -1;
    }
    values_.clear();
  }

  size_t count(const Key& k) const {
    return contains(k) ? 1 : 0;
  }

  size_t count(const uint8_t& u) const {
    return contains(u) ? 1 : 0;
  }

  void find() {}

  bool contains(const Key& k) const {
    return (buckets_[to_integer<uint8_t>(k)].value_idx != -1);
  }

  bool contains(const uint8_t u) const {
    return (buckets_[u].value_idx != -1);
  }

  Tp& at(const Key& k) {
    if (contains(k)) {
      return values_.at(buckets_[to_integer<uint8_t>(k)].value_idx).second;
    }
    ostringstream oss;
    oss << "ByteHashMap::at: k (which is " << k << ") >= this->size() (which is " << size_ << ")";
    throw out_of_range(oss.str());
  }

  const Tp& at(const Key& k) const {
    if (contains(k)) {
      return values_.at(buckets_[to_integer<uint8_t>(k)].value_idx).second;
    }
    ostringstream oss;
    oss << "ByteHashMap::at: k (which is " << k << ") >= this->size() (which is " << size_ << ")";
    throw out_of_range(oss.str());
  }

  friend ostream& operator<<(ostream& os, const ByteHashMap& hm) {
    os << "values: [";
    for (const auto& value : hm.values_) {
      os << value << ",";
    }
    os << "]";
    return os;
  }

 private:
  static const size_t bucket_size_ = (1 << CHAR_BIT);
  size_t size_;

  Bucket* buckets_;
  vector<value_type<Tp>> values_;
};
