template<class T>
struct ListNode{
	T data;
	ListNode<T>* pred;
	ListNode<T>* succ;
	ListNode()	{}	//���header��trailer�Ĺ���
	ListNode(T e, ListNode<T>* p = NULL, ListNode<T>* s = NULL)
		:data(e), pred(p), succ(s) {}	//default ������
	ListNode<T>* insertAsPred(T const& e);
	ListNode<T>* insertAsSucc(T const& e); 
}; 
