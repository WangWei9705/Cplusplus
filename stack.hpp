#pragma once

#include <deque>
using namespace std;

namespace bite {
template <class T, class Container = deque<int>> 
    class stack{
    public:
        void push(const T& data) {
            _c.push_back(data);
        }
        void pop() {
            _c.pop_back();
        }
        T& top() {
            return _c.front();
        }
        const T& top() const {
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
