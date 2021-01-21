#pragma once
#include <string>
#include <fstream>


template <typename _T1>
class DifferentSizeArrays
{


public:


	DifferentSizeArrays(const std::string fileName);
	~DifferentSizeArrays();

	DifferentSizeArrays(const DifferentSizeArrays& arr) = delete;



	_T1& operator() (const int line, const int col);

	int numItemsInLine(const int line) const;
	int numLines() const;



private:
	int size;
	_T1** arr = nullptr;
	int* arraySize = nullptr;


};




template <typename _T1>
DifferentSizeArrays< _T1 >::DifferentSizeArrays(const std::string fileName)
{
	std::ifstream iFile;
	iFile.open(fileName, std::ios_base::in);
	if (!iFile.is_open())
	{
		throw("Can't open file");
	}

	iFile >> size;

	arr = new _T1 * [size];
	arraySize = new int[size];
	for (int i = 0; i < size; ++i)
	{
		iFile >> arraySize[i];
		arr[i] = new _T1[arraySize[i]];
		for (int j = 0; j < arraySize[i]; ++j)
		{
			iFile >> arr[i][j];
		}
	}
	iFile.close();
}





template <typename _T1>
DifferentSizeArrays< _T1 >::~DifferentSizeArrays()
{
	if (arr != nullptr)
	{
		for (int i = 0; i < size; ++i)
		{
			delete[] arr[i];
		}
		delete[] arr;
	}
	if (arraySize != nullptr)
	{
		delete[] arraySize;
	}
}





template <typename _T1>
_T1& DifferentSizeArrays< _T1 >::operator() (const int line, const int col)
{
	if (line >= size)
	{
		throw("(line >= size)");
	}
	if (col >= arraySize[line])
	{
		throw ((col >= arraySize[line]));
	}
	return arr[line][col];
}




template <typename _T1>
int DifferentSizeArrays< _T1 >::numItemsInLine(const int line) const
{
	if (line >= size)
	{
		throw("(line >= size)");
	}
	return arraySize[line];
}




template <typename _T1>
int DifferentSizeArrays< _T1 >::numLines() const
{
	return size;
}



































































