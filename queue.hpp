#pragma once

#include <deque>
using namespace std;

namespace bite {
template <class T, class Container = deque<int>>
    class queue {
    public:
        void push(const T& data) {
            _c.push_back(data);

        }
        void pop() {
            _c.pop_back();

        }

        T& back() {
            return _c.back();

        }

        const T& back() const {
            return _c.back();
        }

        T& front() {
            return _c.front();
        }

        const T& front() const {
            return _c.front();
        }

        size_t size() {
            return _c.size();
        }

        bool empty() {
            _c.empty();
        }
    private:
        Container _c;
    };
}
