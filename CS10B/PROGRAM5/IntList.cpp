#include "IntList.h"

// Constructor, Initializes an empty list. 
IntList::IntList()
{
    head = nullptr;
    tail = nullptr;
}

// Destructor, Deallocates all remaining dynamically allocated memory (all remaining IntNodes).
IntList::~IntList()
{
    while (!empty())
    {
        pop_front();
    }
}

// Inserts a data value (within a new node) at the front end of the list.
void IntList::push_front(int value)
{
    IntNode* node = new IntNode(value);

    if (head == nullptr)
    {
        head = node;
        tail = node;
    }
    else
    {
        node->next = head;
        head = node;
    }
}

// Removes the value (actually removes the node that contains the value) at the front end of the list.
// Does nothing if the list is already empty.
void IntList::pop_front()
{
    if (head != nullptr)
    {
        IntNode* node = head;
        head = node->next;

        if (head == nullptr)
        {
            tail = nullptr;
        }

        delete node;
    }
}

// Returns true if the list does not store any data values (does not have any nodes), otherwise returns false.
bool IntList::empty() const
{
    if (head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Returns a reference to the first value in the list. Calling this on an empty list causes undefined behavior.
const int & IntList::front() const
{
    return head->value;
}

// Returns a reference to the last value in the list. Calling this on an empty list causes undefined behavior.
const int & IntList::back() const
{
    return tail->value;
}

// Overloads the insertion operator (<<) so that it sends to the output stream (ostream) a single line all of
// the int values stored in the list, each separated by a space. This function does NOT send a newline or space
// at the end of the line.
ostream & operator<<(ostream & out, const IntList & list)
{
    IntNode* cursor = list.head;

    while (cursor != nullptr)
    {
        out << cursor->value;

        cursor = cursor->next;

        if (cursor != nullptr)
        {
            out << " ";
        }
    }

    return out;
}




// the copy constructor. Make sure this performs deep copy.
IntList::IntList(const IntList &cpy)
{
    IntNode* cursor = cpy.head;

    while (cursor != nullptr)
    {
        push_front(cursor->value);

        cursor = cursor->next;
    }
}


// the overloaded assignment operator. Make sure this performs deep copy.
IntList & IntList::operator=(const IntList &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    while (!empty())
    {
        pop_front();
    }

    IntNode* cursor = rhs.head;

    while (cursor != nullptr)
    {
        push_front(cursor->value);

        cursor = cursor->next;
    }

    return *this;
}

// Inserts a data value (within a new node) at the back end of the list.
void IntList::push_back(int value)
{
    IntNode* node = new IntNode(value);

    if (head == nullptr)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
}

// Removes (deallocates) all IntNodes in the IntList. Don't forget to set both head and tail
// to appropriate values for an empty list. DO NOT leave them dangling!
void IntList::clear()
{
    while (!empty())
    {
        pop_front();
    }

    head = nullptr;
    tail = nullptr;
}

void swap(IntNode* one, IntNode* two)
{
    int temp = one->value;
    one->value = two->value;
    two->value = temp;
}

// Sorts the integers in the list into ascending order. Do NOT move the nodes, just the integers.
void IntList::selection_sort()
{
    IntNode* out = head;
    IntNode* in  = nullptr;

    while (out != nullptr)
    {
        IntNode* min = out;

        in = out->next;
        while (in != nullptr)
        {
            if (in->value < min->value)
            {
                min = in;
            }

            in = in->next;
        }

        swap(out, min);
        
        out = out->next;
    }
}

// Inserts a data value (within a new node) in an ordered list. Assumes the list is already sorted
// in ascending order (i.e., Do not sort the list first, assume the list is already is sorted.)
// This function loops through the list until if finds the correct position for the new data value
// and then inserts the new IntNode in that location. This function may NOT ever sort the list.
void IntList::insert_ordered(int value)
{
    IntNode* node = new IntNode(value);

    if (head == nullptr)
    {
        head = node;
        tail = node;
    }
    else
    {
        if (value <= head->value)
        {
            push_front(value);
        }
        else
        {
            IntNode* previous_node = head;
            IntNode* current_node = head;

            while (current_node != nullptr)
            {
                if (current_node->value < value)
                {
                    previous_node = current_node;
                    current_node = current_node->next;
                }
                else
                {
                    break;
                }
            }

            previous_node->next = node;
            node->next = current_node;
        }
    }
}

// Removes all duplicate data values (actually removes the nodes that contain the values) within 
// the list. Always remove just the later value within the list when a duplicate is found. This
// function may NOT ever sort the list.
void IntList::remove_duplicates()
{
    if (head == tail)
    {
        return;
    }
    else
    {
        IntNode* outer_node     = head;
        IntNode* inner_node     = nullptr;
        IntNode* duplicate_node = nullptr;
        IntNode* previous_node  = nullptr;

        while (outer_node != nullptr)
        {
            previous_node = outer_node;

            inner_node = outer_node->next;

            while (inner_node != nullptr)
            {
                if (inner_node->value == outer_node->value)
                {
                    duplicate_node = inner_node;
                    previous_node->next = inner_node->next;
                    inner_node = inner_node->next;

                    if (duplicate_node == tail)
                    {
                        tail = previous_node;
                    }

                    delete duplicate_node;
                    duplicate_node = nullptr;
                }
                else
                {
                    previous_node = inner_node;
                    inner_node = inner_node->next;
                }
            }

            outer_node = outer_node->next;
        }
    }
}

