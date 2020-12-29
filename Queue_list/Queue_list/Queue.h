#pragma once
#include<iostream>


template<class T>
struct TLink 
{
	T val;
	TLink* pNext;
};


template <class T>
class TQueue
{
private:
	TLink<T>* pHead, * pTail;
public:
	TQueue();
	TQueue(const TQueue<T>& qu);
	~TQueue();
	TQueue<T>& operator = (const TQueue<T>& q);
	bool operator == (const TQueue<T>& q) const;
	bool operator != (const TQueue<T>& q) const;
	bool Empty() const;
	void Push(const T elem);
	bool Overloaf() const;
	T SeeHead() const;
	T GetHead();
};


template<class T>
TQueue<T>::TQueue()
{
	pHead = NULL;
	pTail = NULL;
}


template <class T>
TQueue<T>::TQueue(const TQueue<T>& q)
{
	if (q.pHead != NULL)
	{
		TLink<T>* tmp, * pre;
		pre = new TLink<T>;
		pre->val = q.pHead->val;
		pHead = pre;
		tmp = q.pHead->pNext;
		while (tmp != NULL)
		{
			TLink<T>* new_link = new TLink<T>;
			new_link->val = tmp->val;
			pre->pNext = new_link;
			pre = new_link;
			tmp = tmp->pNext;
		}
		pTail = pre;
		pre->pNext = NULL;
	}
	else
	{
		pHead = NULL;
		pTail = NULL;
	}
}


template <class T>
TQueue<T>::~TQueue()
{
	while (pHead != NULL)
	{
		TLink<T>* tmp = pHead->pNext;
		delete pHead;
		pHead = tmp;
	}
}


template <class T>
TQueue<T>& TQueue<T>::operator =(const TQueue<T>& q)
{
	if (this != &q)
	{
		while (pHead != NULL)
		{
			TLink<T>* tmp = pHead->pNext;
			delete pHead;
			pHead = tmp;
		}
		pTail = NULL;
		if (q.pHead != NULL)
		{
			TLink<T>* pre, * tmp;
			pre = new TLink<T>;
			pre->val = q.pHead->val;
			pHead = pre;
			tmp = q.pHead->pNext;
			while (tmp != NULL)
			{
				TLink<T>* new_link = new TLink<T>;
				new_link->val = tmp->val;
				pre->pNext = new_link;
				pre = new_link;
				tmp = tmp->pNext;
			}
			pTail = pre;
			pre->pNext = NULL;
		}
	}
	return (*this);
}


template<class T>
bool TQueue<T>::operator==(const TQueue<T>& q) const
{
	if (this != &q)
	{
		TLink<T>* tmp_th, * tmp_par;
		tmp_th = pHead;
		tmp_par = q.pHead;
		while (true)
		{
			if (tmp_par == NULL && tmp_th == NULL)
			{
				return true;
			}
			if (tmp_par == NULL || tmp_th == NULL)
			{
				return false;
			}
			if (tmp_th->val != tmp_par->val)
			{
				return false;
			}
			tmp_th = tmp_th->pNext;
			tmp_par = tmp_par->pNext;
		}
	}
	return true;
}


template<class T>
bool TQueue<T>::operator!=(const TQueue<T>& q) const
{
	return (!(*this == q));
}

template<class T>
bool TQueue<T>::Overloaf() const
{
	TLink<T>* tmp = new TLink<T>;
	if (tmp == 0x0)
	{
		delete tmp;
		return true;
	}
	delete tmp;
	return false;
}

template<class T>
bool TQueue<T>::Empty() const
{
	if (pHead == NULL)
		return true;
	return false;
}


template <class T>
void TQueue<T>::Push(const T elem)
{
	if (Overloaf())
	{
		throw 0;
	}
	TLink<T>* tmp = new TLink<T>;
	tmp->val = elem;
	tmp->pNext = NULL;
	if (Empty())
	{
		pHead = tmp;
		pTail = tmp;
	}
	else
	{
		pTail->pNext = tmp;
		pTail = tmp;
	}
}


template<class T>
T TQueue<T>::GetHead()
{
	if (Empty())
	{
		throw 0;
	}
	TLink<T>* tmp = pHead->pNext;
	T elem = pHead->val;
	delete pHead;
	pHead = tmp;
	return elem;
}

template<class T>
T TQueue<T>::SeeHead() const
{
	if (Empty())
		throw 0;
	return pHead->val;
}
