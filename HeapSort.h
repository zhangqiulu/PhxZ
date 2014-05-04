#ifndef HEAPSORT_H
#define HEAPSORT_H
#include <iterator>

template<class Iterator>
void HeapSort(Iterator &first,Iterator &last)
{
	HeapSort(first,last,_Iter_cat(first));
}

//针对inputItertator类型的的容器;
//输入参数,first,last表示排序范围;
//[first,last) is valiad;
//升序排列;

template<class inputItertator>
void HeapSort(inputItertator &first,inputItertator &last,std::input_iterator_tag)
{
	inputItertator _sortbegin = last;
	_sortbegin--;

	for (;_sortbegin != first; _sortbegin--)
	{
		int _cur = distance(first,_sortbegin);
		int _father = floor((_cur-1)/2);
		inputItertator _curitr = first;
		advance(_curitr,_father);

		for (; ;_curitr--)
		{
			int _cur_l = distance(first,_curitr);

			inputItertator _leftchild = _curitr;
			advance(_leftchild,_cur_l+1);
			inputItertator _rightchild = _curitr;
			advance(_rightchild,_cur_l+2);

			inputItertator _end = _sortbegin;
			if(_rightchild != ++_end) 
			{
				if(*_curitr < *_leftchild || *_curitr < *_rightchild)
					*_leftchild > *_rightchild ? iter_swap(_curitr,_leftchild) : iter_swap(_curitr,_rightchild);
			}
			else
			{
				if(*_curitr < *_leftchild)
					iter_swap(_curitr,_leftchild);
			}
			if(_curitr == first) break;
		}
		iter_swap(_sortbegin,first);
	}
}

//针对RandomAccess Itertator类型的的容器;
//输入参数,first,last表示排序范围;
//[first,last) is valiad;
//升序排列;
template<class RandomAccessIterator>
void HeapSort(RandomAccessIterator &first,RandomAccessIterator &last,std::random_access_iterator_tag)
{
	RandomAccessIterator _sortbegin = last;
	_sortbegin--;

	for (;_sortbegin != first; _sortbegin--)
	{
		int _cur = _sortbegin - first;
		int _father = floor((_cur-1)/2);
		RandomAccessIterator _curitr = first;
		while (_father)
		{
			_curitr++;_father--;
		}
		for (; ;_curitr--)
		{

			RandomAccessIterator _leftchild = _curitr;
			RandomAccessIterator _rightchild = _curitr;
			RandomAccessIterator _end = _sortbegin;
			int _cur_l = _curitr -first;
			while (_cur_l+1)
			{
				_leftchild++;_cur_l--;
			}
			_cur_l = _curitr -first;
			while (_cur_l+2)
			{
				_rightchild++;_cur_l--;
			}

			if(_rightchild != ++_end) 
			{
				if(*_curitr < *_leftchild || *_curitr < *_rightchild)
					*_leftchild > *_rightchild ? iter_swap(_curitr,_leftchild) : iter_swap(_curitr,_rightchild);
			}
			else
			{
				if(*_curitr < *_leftchild)
					iter_swap(_curitr,_leftchild);
			}
			if(_curitr == first) break;
		}
		iter_swap(_sortbegin,first);
	}
}
#endif