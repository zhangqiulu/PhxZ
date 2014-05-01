#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include <iterator>

//针对input itertaor类型的的容器;
//输入参数,first,last表示排序范围;
//[first,last) is valiad;
//排序是有标记的，直到没有任意两个需要比较为止;
//升序排列;
template<class _inputIterator>
void _BubbleSort(_inputIterator &first,_inputIterator& last)
{
	bool _needsort = true;	
	while (_needsort)
	{
		_inputIterator _currentitr = first;
		_inputIterator _previtr = first;
		_needsort = false;

		for(_previtr = _currentitr++;_currentitr != last;_previtr=_currentitr++)
		{			
			if(*_currentitr < *_previtr)
			{
				iter_swap(_currentitr,_previtr);
				_needsort = true;
			}
		}
	}
}

#endif