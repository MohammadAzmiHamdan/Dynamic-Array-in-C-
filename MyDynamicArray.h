#pragma once

#include <iostream>
using namespace std;

template <class T>
class clsDynamicArray
{

protected:
    int _Size = 0;
    T* _TempArray;

public:
    T* OriginalArray;

    clsDynamicArray(int Size = 0)
    {
        if (Size < 0)
            Size = 0;

        _Size = Size;

        OriginalArray = new T[_Size];

    }

    ~clsDynamicArray()
    {

        delete[]  OriginalArray;

    }

    bool SetItem(int index, T Value)
    {

        if (index >= _Size || index < 0)
        {
            return false;
        }

        OriginalArray[index] = Value;
        return true;

    }


    int Size()
    {
        return _Size;
    }

    bool IsEmpty()
    {
        return (_Size == 0 ? true : false);

    }

    void PrintList()

    {
        
        for (int i = 0; i <= _Size - 1; i++)
        {
            cout << OriginalArray[i] << " ";
        }

        cout << "\n";

    }

    void Resize(int NewSize) {


        if (NewSize < 0) {
            NewSize = 0;
        }

        _TempArray = new T[NewSize];

        if (_Size > NewSize) {
            _Size = NewSize;
        }

        for (int i = 0;i < _Size;i++)
        {
            _TempArray[i] = OriginalArray[i];

        }

        _Size = NewSize;


        delete[] OriginalArray;
        OriginalArray = _TempArray;


    }
    T GetItem(int Index)
    {
        if (Index < 0 || Index >= _Size)
            return T{};

        return OriginalArray[Index];
    }
    void Clear() {
        delete[]OriginalArray;
        _Size = 0;
        OriginalArray = new T[0];
    }
    void Reverse() {
        _TempArray = new T[_Size];
        for (int i = 0;i < _Size  ;i++) {
            _TempArray[i] = OriginalArray[_Size - i -1];

        }
        delete[] OriginalArray;
        OriginalArray = _TempArray;
    }
    bool DeleteItemAt(int Index)
    {
        if (Index < 0 || Index >= _Size)
            return false;

        for (int i = Index; i < _Size - 1; i++)
        {
            OriginalArray[i] = OriginalArray[i + 1];
        }

        Resize(_Size - 1);

        return true;
    }
    bool DeleteFirstItem() {
        return DeleteItemAt(0);
    }
    bool DeleteLastItem() {
        return DeleteItemAt(_Size-1);
    }
    int Find(T Value) {
        for (int i = 0;i < _Size;i++) {
            if (OriginalArray[i] == Value)
                return i;
        }
        return -1;
    }
    bool DeleteItem(T Value) {
        return DeleteItemAt(Find(Value));
    }
    bool InsertItemAt(int index, T Value) {
       if (index <0 || index>_Size)
            return false;
       Resize(_Size + 1);
       for(int i = _Size - 1;i > index;i--) {
           OriginalArray[i ] = OriginalArray[i-1];
       }
       OriginalArray[index] = Value;
       return true;
      }

    void InsertAtBeginning(T value)
    {
        InsertItemAt(0, value);
    }


    bool InsertBefore(int index, T value)
    {
        if (index < 0 || index >= _Size)
            return false;

        return InsertItemAt(index, value);
    }


    bool InsertAfter(int index, T value)
    {
        if (index < 0 || index >= _Size)
            return false;

        return InsertItemAt(index + 1, value);
    }


    bool InsertAtEnd(T value)
    {
        return InsertItemAt(_Size, value);
    }
};

