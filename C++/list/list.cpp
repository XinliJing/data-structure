#include "List.h"
ListNode<T>* ListNode<T>::insertAsPred(T const& e){
	ListNode<T>* x = new ListNode(e, pred, this);
	pred->succ = x; pred = x; return x;
}
//初始化 
template<class T>
void List<T>::init(){
	header = new ListNode<T>;
	trailer = new ListNode<T>;
	header->succ = trailer;	header->pred = NULL;
	trailer->pred = header;	trailer->succ = NULL;
	_size = 0;
}
template<class T>
void List<T>::copyNodes(ListNode<T>* p, int n){
	init();
	while(n--){
		insertAsLast(p->data);
		p = p->succ;
	}
}
template<class T>
List<T>::~List(){
	clear(); delete header; delete trailer;
}
template<class T>
int List<T>::clear(){
	int oldSize = _size;
	while(_size)	remove(trailer->pred);
	return _size;
}
template<class T>
ListNode<T>* insertAsLast(T const& e){
	return insertBefore(trailer, e);
}
template<class T>
T List<T>::remove(ListNode<T>* p){
	T e = p->data;
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete p;
	_size--;
	return e;
} 
//重载[]
template<class T>
T& List<T>::operator[](Rank r) const{
	ListNode<T>* p = first();
	while(0 < r--)	p = p->succ;
	return p->data; 
}
//无序列表区间查找
template<class T>
ListNode<T>* List<T>::find(T const& e, int n, ListNode<T>* p) const{
	while(n--)
		if(e == (p = p->pred)->data) return p;
	return NULL;
} 
template<class T>
int List<T>::deduplicate(){
	if(_size < 2) return 0;
	int oldSize = _size;
	ListNode<T>* p = header->succ; int r = 1;
	while(trailer != (p = p->succ)){
		ListNode<T>* q = find(p->data, r, p);
		if(q)
			remove(q);
		else
			r++;
	}
	return oldSize - _size;
}
template<class T>
int List<T>::uniquify(){
	if(_size < 2) return 0;
	int oldSize = _size;
	ListNode<T>* p = header->succ;
	ListNode<T>* q;
	while(trailer != (q = p->succ)){
		if(p->data == q->data){
			remove(q);
		}
		else{
			p = p->succ;	//p = q;
		}
	}
	return oldSize-_size;
}
template<class T>
ListNode<T>* List<T>::search(T const& e, int n, ListNode<T>* p){
	while(n--){
		if(((p = p -> pred) -> data) <= e); break;
	}
	return p;
} 
