#include <iostream>
#include <stdexcept>
#include "IntVector.h"

using namespace std;

// Constructor
// Sets both the size and capacity of the IntVector to the value of the parameter passed in and
// dynamically allocates an array of that size as well. However, if the capacity is 0, then there is no
// array. Make sure you do not leave a dangling pointer. This function should initialize all elements
// (if any) of the array to the value of the 2nd parameter.
//
IntVector::IntVector(unsigned capacity, int value)
{
    _size = capacity;
    _capacity = capacity;

    if (_capacity > 0)
    {
        _data = new int[_capacity];

        for (unsigned i = 0; i < _size; ++i)
        {
            _data[i] = value;
        }
    }
    else
    {
        _data = 0;
    }
}

// The destructor is used to clean up (delete) any remaining dynamically-allocated memory. For this
//class, that will be the array pointed to by the int pointer named _data.
//
IntVector::~IntVector()
{
    delete[] _data;
    _data = 0;
}

// This function returns the current size (not the capacity) of the IntVector object, which is the
// values stored in the _size member variable.
//
unsigned IntVector::size() const
{
    return _size;
}

// This function returns the current capacity (not the size) of the IntVector object, which is the
// value stored in the _capacity member variable.
//
unsigned IntVector::capacity() const
{
    return _capacity;
}

// Returns whether the IntVector is empty (_size is 0).
//
bool IntVector::empty() const
{
    if (_size == 0)
    {
        return true;
    }

    return false;
}

// This function will return the value stored in the element at the passed in index position. Your
// function should throw an out of range exception if an invalid index is passed in. An invalid index
// is an index greater than or equal to the size.
//
// Throwing an exception: You will need to include the standard library stdexcept. Then, when the 
// index is out of range, execute the following statement:
//
// throw out_of_range("IntVector::at_range_check");
//
// To test if this worked, declare an IntVector of size 10 and then call the at function passing it an 
// index argument of 10 or larger. You should see the following output:
//
// terminate called after throwing an instance of 'std::out_of_range'
//   what():  IntVector::at_range_check
// Aborted
//
const int & IntVector::at(unsigned index) const
{
    if (index >= _size)
    {
        throw out_of_range("IntVector::at_range_check");
    }

    return _data[index];
}

// This function will return the value stored in the first element of the IntVector. This function does 
// not check the size of the IntVector or the array. If the IntVector is empty then calling this 
// function causes undefined behavior.
//
const int & IntVector::front() const
{
    return _data[0];
}

// This function will return the value stored in the last element of the IntVector. This function does 
// not check the size of the IntVector or the array. If the IntVector is empty then calling this 
// function causes undefined behavior.
//
const int & IntVector::back() const
{
    return _data[_size - 1];
}





// This function will double the capacity of the vector. This function should reallocate 
// memory for the dynamically allocated array and update the value of capacity. Make sure 
// your expand() function properly handles the case when capacity is 0. This will be a 
// special case within the expand() function. Since doubling 0 still gives you 0, you should 
// set capacity to 1 in this special case.
//
// Make sure you don't create a memory leak here.
void IntVector::expand()
{
    _capacity *= 2;

    if (_capacity > 0)
    {
        int* data = new int[_capacity];

        for (unsigned i = 0; i < _size; ++i)
        {
            data[i] = _data[i];
        }

        for (unsigned i = _size; i < _capacity; ++i)
        {
            data[i] = 0;
        }

        delete[] _data;

        _data = data;
    }
    else
    {
        _capacity = 1;
        _data = new int[1];
        _data[0] = 0;
    }
}

// This function will expand the capacity of the vector by the amount passed in. This 
// function should reallocate memory for the dynamically allocated array and update the 
// value of capacity.
//
// Make sure you don't create a memory leak here.
//
void IntVector::expand(unsigned amount)
{
    _capacity += amount;

    if (_capacity > 0)
    {
        int* data = new int[_capacity];

        for (unsigned i = 0; i < _size; ++i)
        {
            data[i] = _data[i];
        }

        for (unsigned i = _size; i < _capacity; ++i)
        {
            data[i] = 0;
        }

        delete[] _data;

        _data = data;
    }
    else
    {
        _capacity = 1;
        _data = new int[1];
        _data[0] = 0;
    }
}

// This function inserts data at position index. To do this, all values currently at position 
// index and greater are shifted to the right by 1 (to the element right after its current 
// position).
//
// Size will be increased by 1. However, If size will become larger than capacity, this 
// function needs to first double the capacity. In other words, if capacity and size are both 
// 20 when this function is called, this function must first increase the capacity to 40 and 
// then it will be able to increase the size to 21.
//
// Since other functions will also potentially need to expand (double) the capacity, call the 
// private helper function named expand (see above) to do this for you.
//
// This function should throw an out_of_range exception, passing it the string 
// "IntVector::insert_range_check" if the index is too large. See bottom of 
// specifications for more details on how to throw an exception and how to test that it 
// works properly.
//
void IntVector::insert(unsigned index, int value)
{
    if (index >= _size)
    {
        throw out_of_range("IntVector::insert_range_check");
    }

    if (_size == _capacity)
    {
        expand();
    }

    for (unsigned i = _size; i > index; i--)
    {
        _data[i] = _data[i - 1];
    }

    _data[index] = value;

    _size++;
}

// This function removes the value at position index and shifts all of the values at positions 
// greater than index to the left by one (to the element right before its current position).
//
// Size is decreased by 1.
//
// This function should throw an out_of_range exception, passing it the string 
// "IntVector::erase_range_check" if the index is too large. See bottom of 
// specifications for more details on how to throw an exception and how to test that it 
// works properly.
//
void IntVector::erase(unsigned index)
{
    if (index >= _size)
    {
        throw out_of_range("IntVector::erase_range_check");
    }

    for (unsigned i = index; i < _size - 1; i++)
    {
        _data[i] = _data[i + 1];
    }

    _size--;
}

// This function inserts a value at the back end of the array.
//
// Size will be increased by 1. However, If size will become larger than capacity, this 
// function needs to first increase the capacity. In other words, if capacity and size are both 
// 20 when this function is called, capacity must first be increased to 40 and then size can 
// be increased to 21.
//
// Since other functions will also potentially need to expand (double) the capacity, call the 
// private helper function named expand (see above) to do this for you.
//
void IntVector::push_back(int value)
{
    if (_size == _capacity)
    {
        expand();
    }

    _data[_size] = value;

    _size++;
}

// This function just needs to decrease size by 1.
//
// This function will never throw an exception. Calling pop_back on an empty vector will 
// cause undefined behavior.
//
void IntVector::pop_back()
{
    _size--;
}

// This function reduces the size of the vector to 0.
//
void IntVector::clear()
{
    _size = 0;
}

// This function resizes the vector to contain size elements.
//
// If size is smaller than the current size(_size), this function just reduces the value of _size 
// to size.
//
// If size is greater than the current size(_size), then the appropriate number of elements 
// are inserted at the end of the vector, giving all of the new elements the value passed in 
// through the 2nd parameter (value).
//
// If the new value of size will be larger than capacity, then the capacity must first be 
// expanded by either doubling (expand()) or by increasing the capacity by a specific 
// amount (expand(new size - current capacity)), whichever results in the largest capacity. 
// Then, this function can increase the size appropriately.
//
void IntVector::resize(unsigned size, int value)
{
    if (size < _size)
    {
        _size = size;
    }
    else if (size < _capacity)
    {
        for (unsigned i = _size; i < size; i++)
        {
            _data[i] = value;
        }

        _size = size;
    }
    else
    {
        if (_capacity * 2 > size)
        {
            expand();
        }
        else
        {
            unsigned expand_amount = size - _capacity;
            expand(expand_amount);
        }

        for (unsigned i = _size; i < size; i++)
        {
            _data[i] = value;
        }

        _size = size;
    }
}

// This function requests that the capacity (the size of the dynamically allocated array) be 
// set to n at minimum. This informs the vector of a planned increase in size.
//
// This function should NOT ever reduce the size of the vector. If n is larger than the current 
// capacity then the capacity should be expanded to n.
//
// A call to this function never affects the elements contained in the vector, nor the vector's 
// size.
//
void IntVector::reserve(unsigned n)
{
    if (n > _capacity)
    {
        unsigned expand_amount = n - _capacity;
        expand(expand_amount);
    }
}

// Assigns new content to the vector object, dropping all the elements contained in the 
// vector before the call and replacing them by those specified by the parameters. The new 
// value of size will be n and all values stored in the vector will have the value of the 2nd 
// parameter.
//
// If the new value of size will be larger than capacity, then this function must first expand 
// capacity by either double (expand()) or by increasing the capacity by a specific amount 
// (expand(n - capacity)), whichever results in the largest capacity.
//
void IntVector::assign(unsigned n, int value)
{
    if (n >  _capacity)
    {
        if (_capacity * 2 > n)
        {
            expand();
        }
        else
        {
            unsigned expand_amount = n - _capacity;
            expand(expand_amount);
        }
    }

    _size = n;

    for (unsigned i = 0; i < _size; i++)
    {
        _data[i] = value;
    }
}

// This function does exactly the same thing the accessor (const) version of at does.
//
// Throwing an exception
// You will need to include the standard library stdexcept. Then, when the index is out of range, 
// execute the following statement:
//
//   throw out_of_range("IntVector::at_range_check");
//
// To test if this worked, declare an IntVector of size 10 and then call the at function passing it an 
// index argument of 10 or larger. You should see the following output:
//
//    terminate called after throwing an instance of 
//    'std::out_of_range'
//
//    what():  IntVector::at_range_check
//
// Aborted
//
int & IntVector::at(unsigned index)
{
    if (index >= _size)
    {
        throw out_of_range("IntVector::at_range_check");
    }

    return _data[index];
}

// This function does exactly the same thing the accessor (const) version of front does.
//
int & IntVector::front( )
{
    return _data[0];
}

// This function does exactly the same thing the accessor (const) version of back does.
//
int & IntVector::back( )
{
    return _data[_size - 1];
}

