#include "listNode.h"

template class<T>
class List{
private:
	int _size;
	ListNode<T>* header;
	ListNode<T>* trailer;
protected:
	void init();	//列表初始化
	int clear();
	void copyNodes( ListNode<T>* p, int n);	//复制列表中自位置p开始的n项 
	void selectionSort(ListNode<T>* p, int n);
	void insertionSort(ListNode<T>* p, int n); 
public:
	List() { init(); }
	List(List<T> const& L);
	List(List<T> const& L, Rank r, int n);
	List(ListNode<T>* p, int n);
	~List();
	//read API
	Rank size() const { return _size; }
	bool empty() const { return _size <= 0; }
	T& operator[](Rank r) const;
	ListNode<T>* first(){ return header->succ; }
	ListNode<T>* last(){ return trailer->pred; }
	bool valid (ListNode<T>* p)
	{return p && trailer!=p && header!=p; }
	ListNode<T>* find(T const& e, int n, ListNode<T>* p) const;	//无序列表区间查找
	ListNode<T>* find(T const& e) const{ return find(e, _size, trailer); } 
	ListNode<T>* search(T const& e, int n, ListNode<T>* p) const;
	ListNode<T>* selectMax(ListNode<T>* p, int n);
	ListNode<T>* selectMax(){ return selectMax(header->succ, _size); }
	//write API
	ListNode<T>* insertBefore(ListNode<T>* p, T const& e)
	{ _size++; return p->insertAsPred(e); }
	ListNode<T>* insertAsLast(T const& e);
	T remove(ListNode<T>* p);
	int deduplicate();	//无序去重 
	int uniquify();	//有序去重 
};
