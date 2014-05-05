#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

template<class T,class Iterator>
Iterator BinarySearch(T key,Iterator &first,Iterator &last)
{
	return _BinarySearch(key,first,last,_Iter_cat(first));
}


//针对RandomAccess Itertator类型的的容器;
//输入参数,first,last表示排序范围;
//[first,last) is valiad;
//二分查找，如果有重复数据，随机返回其中任意的一个迭代器,如果没找到，那就返回last迭代器;
template<class T,class RandomAccessIterator>
RandomAccessIterator _BinarySearch(T key,RandomAccessIterator &first,RandomAccessIterator &last, std::random_access_iterator_tag)
{
	int _cursize = last - first;
	if(_cursize < 1 )	return last;
	else if(_cursize < 3)
	{		
		for(RandomAccessIterator _itr = first; _itr != last; _itr++)
		{
			if(*_itr == key)    return _itr;
		}
		return last;
	}
	else
	{
		RandomAccessIterator _left = first;
		RandomAccessIterator _right = last;
		_right--;
		if(key < *_left || key > *_right)	return last;
		else
		{
			int _middle =  static_cast<int>((last - first) / 2);
			RandomAccessIterator _mid = first + _middle;
			if(*_mid == key)	return _mid;
			
			*_mid > key ? _right = _mid : _left = _mid;
			RandomAccessIterator _tempitr =  BinarySearch(key,_left,++_right);
			if (_tempitr == _right )	return last;
			else return _tempitr;
		}	
	}
}

//针对input Itertator类型的的容器;
//输入参数,first,last表示排序范围;
//[first,last) is valiad;
//二分查找，如果有重复数据，随机返回其中任意的一个迭代器,如果没找到，那就返回last迭代器;
template<class T,class inputItertator>
inputItertator _BinarySearch(T key,inputItertator &first,inputItertator &last, std::input_iterator_tag)
{
	int _cursize = distance(first,last);
	if(_cursize < 1 )	return last;
	else if(_cursize < 3)
	{		
		for(inputItertator _itr = first; _itr != last; _itr++)
		{
			if(*_itr == key)    return _itr;
		}
		return last;
	}
	else
	{
		inputItertator _left = first;
		inputItertator _right = last;
		_right--;
		if(key < *_left || key > *_right)	return last;
		else
		{
			int _middle =  static_cast<int>(distance(first,last) / 2);
			inputItertator _mid = first;
			advance(_mid,_middle);
			if(*_mid == key)	return _mid;

			*_mid > key ? _right = _mid : _left = _mid;
			inputItertator _tempitr =  BinarySearch(key,_left,++_right);
			if (_tempitr == _right )	return last;
			else return _tempitr;
		}	
	}
}
#endif