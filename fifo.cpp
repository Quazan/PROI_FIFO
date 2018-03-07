
#include "fifo.h"

fifo_string::fifo_string()
{
	push_pointer = NULL;
	take_pointer = NULL;
}

fifo_string::~fifo_string()
{
	_item *iterator;
	while(take_pointer != NULL) 
	{
		iterator = take_pointer;
		take_pointer = take_pointer->n;
		delete iterator;	
	}
}

fifo_string::_item::_item(const char* item)
{
	str = item;
	p = n = NULL;
}

void fifo_string::push(const char* item)
{
	_item *it = new _item(item);
	if (push_pointer == NULL)
	{
		push_pointer = take_pointer = it;
	} else {
		it->p = push_pointer;
		push_pointer->n = it;
		push_pointer = it;
	}
}
std::string fifo_string::peak() const
{
	if(take_pointer == NULL)
		return "";

	return take_pointer->str;
}

std::string fifo_string::take()
{
	if (take_pointer == NULL)
                return "";

	_item* tmp = take_pointer;
	const char* str = tmp->str;
	if (take_pointer->n == NULL)
	{
		push_pointer = NULL;
		take_pointer = NULL;
	} else {
		take_pointer = take_pointer->n;
		take_pointer->p = NULL;
	}

	delete tmp;
	
	return str;
}

std::string fifo_string::get(int i) const
{
	_item *iterator = take_pointer;
	int x = 0;
	while(x < i && iterator != NULL) {
		iterator = iterator->n;
		x++;	
	}
	if (x == i)
		return iterator->str;
	else
		return "";
}

int fifo_string::count()
{
        int i = 0;
        for(_item *iterator = take_pointer; iterator != NULL; iterator = iterator->n, i++);
	return i;
}

std::ostream &operator<< (std::ostream & out, fifo_string & fifo)
{
        out << "fifo_string dump:\n";
        for (fifo_string::_item* iterator = fifo.take_pointer;iterator != NULL; iterator = iterator->n)
        {
                out << iterator->str <<"\n";
        }

        return out;
}

