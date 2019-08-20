template<class T>
struct ListNode{
	T data;
	ListNode<T>* pred;
	ListNode<T>* succ;
	ListNode()	{}	//针对header和trailer的构造
	ListNode(T e, ListNode<T>* p = NULL, ListNode<T>* s = NULL)
		:data(e), pred(p), succ(s) {}	//default 构造器
	ListNode<T>* insertAsPred(T const& e);
	ListNode<T>* insertAsSucc(T const& e); 
}; 
