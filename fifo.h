#include <string>
#include <ostream>

class fifo_string {
private:
	struct _item {
		_item *n;
		_item *p;
		const char* str;
		_item(const char* str);
	};
	_item *push_pointer;
	_item *take_pointer;
public:
	fifo_string();
	~fifo_string();
	void push(const char* item);
	std::string peak() const;
	std::string take();
	std::string get(int i) const;
	int count();
	friend std::ostream &operator<< (std::ostream &, fifo_string &);
};

std::ostream &operator<< (std::ostream & out, fifo_string & fifo);
