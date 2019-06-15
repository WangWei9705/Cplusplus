#pragma once

#include <assert.h>
#include <iostream>
using namespace std;


// vector 底层实际是一个动态的顺序表
// 第一个有效元素用start标记，最后一个元素的下一个位置用finish标记，空间的最后一个位置用enofstorage标记，当finish==endofstorage时，空间满了
namespace bite {
	template<class T>
	class Vector {
	public:
		typedef T* iterator;
		typedef T* Reserve_iterator;
		// 对象创建销毁相关函数
		Vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _enOfStorage(nullptr)
		{}

		// 构造一个初始放n个val的
		// T()  表示如果val没有给初始值就让他等于一个空对象，默认为0
		Vector(size_t n, const T &val = T())
			: _start(nullptr)
			, _finish(nullptr)
			, _enOfStorage(nullptr)

		{
			// 扩容
			reserve();
			while (n--) {
				push_back(val);
				
			}
			
		}
		//区间构造
		template<class Iterator>
		Vector(Iterator first, Iterator last) {
			reserve(last - first);

			while (first != last) {
				push_back(*first);
				++first;
			}

		}

		// 拷贝构造
		Vector(const  Vector<T>& v) 
			: _start(nullptr)
			, _finish(nullptr)
			, _enOfStorage(nullptr)

		{
			reserve(v.Capacity);
			
			for (size_t i = 0; i < v.Size(); i++) {
				_finish[i++] = v[i];
			}
			_finish = _start + v.Size();
			_enOfStorage = _start + v.Capacity();
			
		}

		Vector<T>& operator = (Vector<T> v) {
			Swap(v);
			return *this;

		}

		void Swap(Vector<T>& v) {
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_enOfStorage, v._enOfStorage);
		}
		~Vector() {
			delete[] _start;
			_start = _finish = _enOfStorage = nullptr;
		}
		// 容量相关
		size_t Size() {
			return _finish - _start;
		}
		size_t Capacity() {
			return _enOfStorage - _start;
		}

		void resize(size_t newSize, const T& val = T()) {
			// 如果newSize 小于等于当前size，则元素有效个数缩小到newSize
			if (newSize <= Size()) {
				_finish = _start + newSize;
				return;
			}
			// 如果newSize 大于当前容量，则需要考虑扩容
			if (newSize > Capacity) {
				reserver(newSize);
			}
			// 将Size()扩大到newSize,多余位置用val填充
			for (size_t i = Size(); i < newSize; i++) {
				_finish[i] = val;

			}	

		}

		void reserver(size_t newcapacity) {
			if (newcapacity > Capacity) {
				size_t oldsize = Size();
				T* temp = new T[newcapacity];

				if (_start) {
					for (size_t i = 0; i < oldsize; i++) {
						temp[i] = _start[i];

					}
				}
				_start = temp;
				_finish = _start + oldsize;
				_enOfStorage = _start + newcapacity;
			}
		}
		bool Isempty() {
			return _finish == _start;
		}

		// 元素访问相关
		T& operator[](size_t pos) {
			return _start[pos];
		}
		// 迭代器相关
		iterator begin() {
			return _start;
		}
		iterator end() {
			return _finish;
		}

		Reserve_iterator rbegin() {
			return _begin();
		}
		Reserve_iterator rend() {
			return _end;
		}
		// 元素修改相关
		void push_back(const T& val) {
			insert(end(), val);
		}
		void pop_back() {
			erase(--end());
		}
		iterator insert(iterator pos, const T& val) {
			assert(pos <= _finish);

			// 判断是否需要扩容
			if (_finish == _enOfStorage) {
				size_t oldsize = Size();
				size_t newcapacity = Capacity * 2;
				reserver(newcapacity);

				pos = _start + oldsize;
			}
			// 搬移元素
			iterator it = _finish;
			while (it > _finish) {
				*it = *(it - 1);
				--it;
			}
			*pos = val;
			++_finish;
			return pos;	
			
		}

		iterator erase(iterator pos) {
			iterator it = pos + 1;
			while (it != _finish) {
				*(it - 1) = *it;
				++it;
			}
			--_finish;
			return pos;
		}
	
	
	
	private:
		T* _start;
		T* _finish;
		T* _enOfStorage;
	};


}

void Test() {
	bite::Vector<int> v1;

	bite::Vector<int> v2(6, 6);
	cout << v2.Size() << endl;
	cout << v2.Capacity() << endl;
	cout << v2.begin() << endl;

	v2.push_back(8);
	cout << v2.Size() << endl;
	cout << v2.Capacity() << endl;

	


}