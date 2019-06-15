#pragma once

#include <assert.h>
#include <iostream>
using namespace std;


// vector �ײ�ʵ����һ����̬��˳���
// ��һ����ЧԪ����start��ǣ����һ��Ԫ�ص���һ��λ����finish��ǣ��ռ�����һ��λ����enofstorage��ǣ���finish==endofstorageʱ���ռ�����
namespace bite {
	template<class T>
	class Vector {
	public:
		typedef T* iterator;
		typedef T* Reserve_iterator;
		// ���󴴽�������غ���
		Vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _enOfStorage(nullptr)
		{}

		// ����һ����ʼ��n��val��
		// T()  ��ʾ���valû�и���ʼֵ����������һ���ն���Ĭ��Ϊ0
		Vector(size_t n, const T &val = T())
			: _start(nullptr)
			, _finish(nullptr)
			, _enOfStorage(nullptr)

		{
			// ����
			reserve();
			while (n--) {
				push_back(val);
				
			}
			
		}
		//���乹��
		template<class Iterator>
		Vector(Iterator first, Iterator last) {
			reserve(last - first);

			while (first != last) {
				push_back(*first);
				++first;
			}

		}

		// ��������
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
		// �������
		size_t Size() {
			return _finish - _start;
		}
		size_t Capacity() {
			return _enOfStorage - _start;
		}

		void resize(size_t newSize, const T& val = T()) {
			// ���newSize С�ڵ��ڵ�ǰsize����Ԫ����Ч������С��newSize
			if (newSize <= Size()) {
				_finish = _start + newSize;
				return;
			}
			// ���newSize ���ڵ�ǰ����������Ҫ��������
			if (newSize > Capacity) {
				reserver(newSize);
			}
			// ��Size()����newSize,����λ����val���
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

		// Ԫ�ط������
		T& operator[](size_t pos) {
			return _start[pos];
		}
		// ���������
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
		// Ԫ���޸����
		void push_back(const T& val) {
			insert(end(), val);
		}
		void pop_back() {
			erase(--end());
		}
		iterator insert(iterator pos, const T& val) {
			assert(pos <= _finish);

			// �ж��Ƿ���Ҫ����
			if (_finish == _enOfStorage) {
				size_t oldsize = Size();
				size_t newcapacity = Capacity * 2;
				reserver(newcapacity);

				pos = _start + oldsize;
			}
			// ����Ԫ��
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