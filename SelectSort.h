#ifndef SELECTSORT_H
#define SELECTSORT_H

//针对input inputItertator类型的的容器;
//输入参数,first,last表示排序范围;
//[first,last) is valiad;
//升序排列;

template<class inputItertator>
void SelectSort(inputItertator& first, inputItertator& last)
{
	for (inputItertator _sortend = first;_sortend != last; _sortend++)
	{
		inputItertator _key = _sortend;
		for (inputItertator _nsort = _sortend; _nsort != last;_nsort++)
		{
			if(*_nsort < *_key)
				_key = _nsort;
		}
		iter_swap(_key,_sortend);
	}	
}

#endif // !SELECTSORT_H
