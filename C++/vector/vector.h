typedef int Rank;
const int DEFAULT_CAPACITY = 3;

template <class T>
class Vector{
private:
	Rank _size;	//规模 
	int _capacity;	//容量 
	T* _element;	//数据区 
protected:
	void copyFrom(T * const A, Rank lo, Rank hi);	//复制数组区间A[lo, hi) 
	void expand();	//扩容
	void shrink();	//缩容 
	Rank bubble(Rank lo, Rank hi);
	void bubbleSort(Rank lo, Rank hi);
	void selectionSort(Rank lo, Rank hi);
	void mergeSort(Rank lo, Rank hi);	//归并排序	
	void merge(Rank lo, Rank mi, Rank hi);	//归并算法 
	void quickSort(Rank lo, Rank hi);
	void heapSort(Rank lo, Rank hi);
	//int binSearch(T const& e, Rank lo, Rank hi) const;	//二分查找 
	//int fibSearch(T const& e, Rank lo, Rank hi) const;	//fibonacci查找 
public:
	//构造函数 
	Vector(int c = DEFAULT_CAPACITY){	//默认构造函数 
		_element = new T[_capacity = c];
		_size = 0;
	}
	Vector(T * const A, Rank lo, Rank hi){	//数组区间复制 
		copyFrom(A, lo, hi);
	}
	Vector(Vector<T> const& V, Rank lo, Rank hi){	//vector区间复制 
		copyFrom(V, lo, hi);
	}
	//析构函数
	~Vector(){
		delete [] _element;	//释放内部空间 
	}
	//read API
	Rank size() const{ return _size; }	//返回元素数量 
	bool empty() const{ return !_size; }	//判空 
	int disordered() const;	//返回逆序对数目 
	Rank find(T const& e, Rank lo, Rank hi) const; //无序 区间查找元素e
	Rank find(T const& e) const{ return find(e, 0, _size);}	//无序 全局查找元素e
	Rank search(T const& e, Rank lo, Rank hi) const;	//有序 区间查找元素e 
	Rank search(T const& e) const{ return search(e, 0, _size); } //有序 全局查找e 
	//write API
	Vector<T>& operator=(Vector<T> const& V);	//重载= 
	T& operator[](Rank r) const;	//重载[] 0<=r<size 
	Rank insert(Rank r, T const& e);	//插入元素 ,返回值为r 
	int remove(Rank lo, Rank hi);	//删除区间[lo, hi)元素，返回值为被删元素数目 
	T remove(Rank r);	//单元素删除，返回被删元素 
	void sort(Rank lo, Rank hi);	//排序
	void sort(){ sort(0, _size); }	//整体排序 
	int deduplicate();	//无序元素去重 
	int uniquify();	//有序元素去重 
	//traverse
	void traverse(void (*visit)(T&)){	//函数指针 
		for(int i = 0;i < _size; i++)
			visit(_element[i]); 
	} 
	template <class VST>
	void traverse(VST& visit){	//函数对象(通用性更强) 
		for(int i = 0; i < _size; i++)
			visit(_element[i]);
	}
};
