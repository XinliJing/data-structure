typedef int Rank;
const int DEFAULT_CAPACITY = 3;

template <class T>
class Vector{
private:
	Rank _size;	//��ģ 
	int _capacity;	//���� 
	T* _element;	//������ 
protected:
	void copyFrom(T * const A, Rank lo, Rank hi);	//������������A[lo, hi) 
	void expand();	//����
	void shrink();	//���� 
	Rank bubble(Rank lo, Rank hi);
	void bubbleSort(Rank lo, Rank hi);
	void selectionSort(Rank lo, Rank hi);
	void mergeSort(Rank lo, Rank hi);	//�鲢����	
	void merge(Rank lo, Rank mi, Rank hi);	//�鲢�㷨 
	void quickSort(Rank lo, Rank hi);
	void heapSort(Rank lo, Rank hi);
	//int binSearch(T const& e, Rank lo, Rank hi) const;	//���ֲ��� 
	//int fibSearch(T const& e, Rank lo, Rank hi) const;	//fibonacci���� 
public:
	//���캯�� 
	Vector(int c = DEFAULT_CAPACITY){	//Ĭ�Ϲ��캯�� 
		_element = new T[_capacity = c];
		_size = 0;
	}
	Vector(T * const A, Rank lo, Rank hi){	//�������临�� 
		copyFrom(A, lo, hi);
	}
	Vector(Vector<T> const& V, Rank lo, Rank hi){	//vector���临�� 
		copyFrom(V, lo, hi);
	}
	//��������
	~Vector(){
		delete [] _element;	//�ͷ��ڲ��ռ� 
	}
	//read API
	Rank size() const{ return _size; }	//����Ԫ������ 
	bool empty() const{ return !_size; }	//�п� 
	int disordered() const;	//�����������Ŀ 
	Rank find(T const& e, Rank lo, Rank hi) const; //���� �������Ԫ��e
	Rank find(T const& e) const{ return find(e, 0, _size);}	//���� ȫ�ֲ���Ԫ��e
	Rank search(T const& e, Rank lo, Rank hi) const;	//���� �������Ԫ��e 
	Rank search(T const& e) const{ return search(e, 0, _size); } //���� ȫ�ֲ���e 
	//write API
	Vector<T>& operator=(Vector<T> const& V);	//����= 
	T& operator[](Rank r) const;	//����[] 0<=r<size 
	Rank insert(Rank r, T const& e);	//����Ԫ�� ,����ֵΪr 
	int remove(Rank lo, Rank hi);	//ɾ������[lo, hi)Ԫ�أ�����ֵΪ��ɾԪ����Ŀ 
	T remove(Rank r);	//��Ԫ��ɾ�������ر�ɾԪ�� 
	void sort(Rank lo, Rank hi);	//����
	void sort(){ sort(0, _size); }	//�������� 
	int deduplicate();	//����Ԫ��ȥ�� 
	int uniquify();	//����Ԫ��ȥ�� 
	//traverse
	void traverse(void (*visit)(T&)){	//����ָ�� 
		for(int i = 0;i < _size; i++)
			visit(_element[i]); 
	} 
	template <class VST>
	void traverse(VST& visit){	//��������(ͨ���Ը�ǿ) 
		for(int i = 0; i < _size; i++)
			visit(_element[i]);
	}
};
