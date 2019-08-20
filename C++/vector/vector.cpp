#include "vector.h"
#include "../fibonacci/Fib.h"

template <class T>
//������������ 
void Vector<T>::copyFrom(T * const A, Rank lo, Rank hi){
	_element = new T[_capacity = 2*(hi-lo)];	//����ռ� 
	_size = 0;	//��ģ���� 
	while(lo < hi)	//���� 
		_element[_size++] = A[lo++];	//��һ���� 
}
//����
template <class T>
void Vector<T>::expand(){
	if(_size < _capacity)
		return;
	//_capacity = max(_capacity, DEFAULT_CAPACITY);
	T * _oldElement = _element;
	_element = new T[_capacity *= 2];
	for(int i = 0; i < _size; i++){
		_element[i] = _oldElement[i];
	} 
	delete [] _oldElement;
} 
//����
template <class T>
void Vector<T>::shrink(){
	if(_capacity < DEFAULT_CAPACITY) return;
	if(_size/4 > _capacity) return;	//>25%������ 
	T * _oldElement = _element; 
	_element = new T[_capacity/2];
	for(int i = 0; i < _size; i++){
		_element[i] = _oldElement[i];
	}
	delete [] _oldElement;
}
//����Ԫ��
template <class T>
Rank Vector<T>::insert(Rank r, T const& e){
	expand();	//����Ҫ������ 
	for(int i = _size; i > r; i--)
		_element[i] = _element[i-1];
	_element[r] = e;
	_size++;
	return r;
} 
//ɾ������[lo, hi)Ԫ��
template <class T>
int Vector<T>::remove(Rank lo, Rank hi){
	if(lo == hi) return 0;
	while(hi < _size) _element[lo++] = _element[hi++];
	_size = lo;
	shrink();
	return hi-lo; 
} 
//��Ԫ��ɾ�� 
template <class T>
T Vector<T>::remove(Rank r){
	T e = _element[r];
	remove(r, r+1);
	return e;
} 
//���� �������Ԫ��T 
template<class T>
Rank Vector<T>::find(T const& e, Rank lo, Rank hi) const{
	while((lo < hi--) && (e != _element[hi]));
	return hi;	//hi<lo�����ʧ�ܣ����򷵻�hi������Ԫ�ص��� 
} 
//���� �������Ԫ��T
template<class T>
Rank Vector<T>::search(T const& e, Rank lo, Rank hi) const{
	return (rand() % 2) ?
		binSearch(_element, e, lo, hi)
	  : fibSearch(_element, e, lo, hi);
} 
template<class T>
void Vector<T>::sort(Rank lo, Rank hi){
	switch(rand() % 5){
		case 1: bubbleSort(lo, hi);	break;
		case 2: selectionSort(lo, hi);	break;
		case 3: mergeSort(lo, hi);	break;
		case 4: heapSort(lo, hi);	break;
		default: quickSort(lo, hi);	break;
	}
}
template<class T>
void Vector<T>::bubbleSort(Rank lo, Rank hi){
	while(lo < (hi = bubble(lo, hi--)));
} 
template<class T>
Rank Vector<T>::bubble(Rank lo, Rank hi){
	Rank last = lo;
	while(++lo < hi){
		if(element[lo-1] > element[lo]){
			last = lo;
			swap(element[lo-1], element[lo]);
		}
	}
	return last;
}
template<class T>
void Vector<T>::mergeSort(Rank lo, Rank hi){
	if(hi - lo < 2)	return;
	Rank mi = (lo+hi)/2;
	mergeSort(lo, mi);
	mergeSort(mi, hi);
	merge(lo, mi, hi); 
}
template<class T>
void Vector<T>::merge(Rank lo, Rank mi, Rank hi){
	T* A = &element[lo];	//�� T* A = element + lo; 
	int lb = mi-lo;
	T* B = new T[lb];
	int lc = hi-mi;
	T* C = &element[mi];
	for(Rank i = 0; i < lb; B[i] = A[i++]);
	for(int i = 0, j = 0, k = 0;j < lb){
		if(k < lc && C[k] < B[j])	A[i++] = C[k++];
		if(lc <= k || B[j] <= C[k])	A[i++] = B[j++];
	}
	delete [] B;
}
template<class T>
static Rank binSearch(T* A, T const& e, Rank lo, Rank hi){
	while(lo < hi){
		Rank mi = (lo+hi)/2;
		if(e < A[mi])		hi = mi;
		else				lo = mi+1;
	}
	return --lo;
}
//Fibonacci����
template<class T>
static Rank fibSearch(T* A, T const& e, Rank lo, Rank hi){
	Fib fib(hi - lo);
	while(lo < hi){
		while(hi - lo < fib.get()) fib.prev();
		Rank mi = lo + fib.get() - 1;
		if(e < A[mi])		hi = mi;
		else if(A[mi] < e)	lo = mi+1;
		else 				return mi;
	}
	return -1;
}
//����Ԫ��ȥ��
template<class T>
int Vector<T>::deduplicate(){
	int oldSize = _size;
	Rank i = 1;
	while(i < _size){
		if(find(_element[i], 0, i) < 0)
			i++;
		else
			remove(i);
	}
	return oldSize - _size;
}  
//����Ԫ��ȥ��
template<class T>
int Vector<T>::uniquify(){
	Rank i = 0, j = 0;
	while(++j < _size){
		if(_element[i] != _element[j])
			_element[++i] = _element[j];
	}
	_size = ++i;
	shrink();
	return j - i;
	
} 
//�����������Ŀ 
template<class T>
int disordered() const{
	int n = 0;
	for(int i = 1; i < _size; i++)
		n += (_element[i-1] > _element[i])
	return n;
}
//����= 
template <class T>
Vector<T>& Vector<T>::operator=(Vector<T> const& V){
	if(_element)
		delete [] _element;
	copyFrom(V._element, 0, V.size());
	return *this;
}
//����[]
template <class T>	//0 <= r < _size
T& Vector<T>::operator[](Rank r) const{
	return _element[r];
}
