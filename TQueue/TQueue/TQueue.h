#pragma once
#include <iostream>
template <class T>
class TQueue {
	T* pMem;
	int size, head, tail, cnt;
public:
	TQueue(int sz = 10) : size(sz), pMem(new T[sz]), tail(-1), head(0), cnt(0) {}
	TQueue(const TQueue& q);
	~TQueue() {
		delete[] pMem;
	}

	TQueue& operator =(const TQueue& q);
	bool operator ==(const TQueue& q);
	bool operator !=(const TQueue& q) { return !(*this == q); }

	bool isEmpty() { return cnt == 0; }
	bool isFull() { return cnt == size; }
	void push(T item);
	void clear();
	T pop();

	T Head() { return head; }
	T Tail() { return tail; }
};
//*********************************************************
//                          ŒÕ—“–” “Œ–€
//*********************************************************
template <class T>
TQueue<T>::TQueue(const TQueue& q) {
	size = q.size;
	cnt = q.cnt;
	head = q.head;
	tail = q.tail;
	pMem = new T[size];
	if (tail >= head) {
		for (int i = 0; head+i <= tail; i++) {
			pMem[head + i] = q.pMem[head + i];
		}
	}
	else {
		for (int i = 0; i <= tail; i++) {
			pMem[i] = q.pMem[i];
		}
		for (int i = head; i < size; i++) {
			pMem[i] = q.pMem[i];
		}
	}
}
//*********************************************************
//                         ‘”Õ ÷»ŒÕ¿À
//*********************************************************
template <class T>
void TQueue<T>::push(T item) {
	if (isFull()) throw - 1;
	tail = (tail + 1) % size;
	pMem[tail] = item;
	cnt++;
}
template <class T>
T TQueue<T>::pop() {
	if (isEmpty()) throw - 1;
	T res = pMem[head];
	head = (head + 1) % size;
	cnt--;
	return res;
}
template <class T>
void TQueue<T>::clear() {
	tail = -1;
	head = 0;
}
//*********************************************************
//                         Œœ≈–¿“Œ–€
//*********************************************************
template <class T>
bool TQueue<T>:: operator==(const TQueue& q) {
	if (size != q.size || cnt != q.cnt) return false;
	if (cnt == 0) return true;
	for (int i = 0; i < cnt; i++) {
		if (pMem[(head + i) % size] != q.pMem[(q.head + i) % size]) return false;
	}
	return true;
}
template <class T>
TQueue<T>& TQueue<T>::operator=(const TQueue& q) {
	if (this == &q) return *this;
	if (size != q.size) {
		size = q.size;
		delete[] pMem;
		pMem = new T[size];
	}
	cnt = q.cnt;
	head = q.head;
	tail = q.tail;
	if (q.tail >= q.head) {
		for (int i = 0; head+i <= tail; i++) {
			pMem[head + i] = q.pMem[head + i];
		}
	}
	else {
		for (int i = 0; i <= tail; i++) {
			pMem[i] = q.pMem[i];
		}
		for (int i = head; i < size; i++) {
			pMem[i] = q.pMem[i];
		}
	}
	return *this;
}