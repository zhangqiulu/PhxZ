#ifndef QUIKSORT_H
#define QUIKSORT_H

//针对Bidirectional Iterator类型的的容器;
//输入参数,first,last表示排序范围;
//[first,last) is valiad;
//升序排列;

template<class BidirectionalIterator >
void QuikSort(BidirectionalIterator & first, BidirectionalIterator & last)
{
	if (first != last && first != --last)
	{
		BidirectionalIterator _leftitr = first;
		BidirectionalIterator _rightitr = last;
		BidirectionalIterator _base = _leftitr++;

		while (_leftitr != _rightitr)
		{
			if(*_leftitr <= *_base)
				_leftitr++;
			else if(*_base <= *_rightitr)
				_rightitr--;
			else
				iter_swap(_leftitr,_rightitr);
		}

		if(*_base <= *_leftitr)
			_leftitr--;
		iter_swap(_base,_leftitr);

		++last;
		QuikSort(first,_leftitr);
		QuikSort(++_leftitr,last);
	}
}


#endif // !QUIKSORT_H
