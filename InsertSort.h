#ifndef INSERTSORT_H
#define INSERTSORT_H

//针对input itertaor类型的的容器;
//输入参数,first,last表示排序范围;
//[first,last) is valiad;
//升序排列;


template<class BidirectionalIterator>
void InsertSort(BidirectionalIterator& first ,BidirectionalIterator& last)
{
	BidirectionalIterator _sortend = first;
	_sortend++;

	for (;_sortend != last; _sortend++)
	{
		BidirectionalIterator _sortbegin = first;
		while (_sortbegin != _sortend && *_sortbegin < *_sortend)
		{	_sortbegin++;}
		if(_sortbegin != _sortend)
		{
			typename std::iterator_traits<BidirectionalIterator>::value_type _tosort(*_sortend);
			BidirectionalIterator _movrbegin = _sortend;
			BidirectionalIterator _movrprev = _movrbegin;
			for (;_movrbegin != _sortbegin;_movrbegin--)
			{
				--_movrprev;
				*_movrbegin = *_movrprev;
			}
			*_sortbegin = _tosort;
		}
	}
}

#endif