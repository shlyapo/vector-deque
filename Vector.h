#include <iostream>
#include <vector>
#include <initializer_list>
#include <iterator>

using namespace std;

class Vector
{
private:
	vector<int> elem;
	int* mas;
public:

	class Iterator;

	Vector(int size)
	{
		this->size = size;
		this->mas = new int[size];
		for (int i = 0; i < size; i++)
			mas[i] = 0;
	}

	Vector(){}

	void Resize(int n)
	{
		int capacity = sizeof(mas) / sizeof(int);
		int* mas2 = new int[capacity + n];
		for (int i = 0; i < capacity; i++)
			mas2[i] = mas[i];
		for (int i = 0; i < n; i++)
			mas2[i] = 0;
		delete[] mas;
		int* mas = new int[capacity + n];
		for (int i = 0; i < capacity + n; i++)
			mas[i] = mas2[i];
		delete[] mas2;
	}

	void Push_back(int back)
	{
		int capacity = sizeof(mas) / sizeof(int);
		int* mas2 = new int[capacity + 1];
		for (int i = 0; i < capacity; i++)
			mas2[i] = mas[i];
		mas2[i] = back;
		delete[] mas;
		int* mas = new int[capacity + 1];
		for (int i = 0; i < capacity + 1; i++)
			mas[i] = mas2[i];
		delete[] mas2;
	}

	bool Empty()
	{
		if (sizeof(mas) / sizeof(int) != 0)
			return true;
		else
			return false;
	}

	int Size()
	{
		return sizeof(mas) / sizeof(int);
	}

	void Pop_back()
	{
		int capacity = sizeof(mas) / sizeof(int);
		int* mas2 = new int[capacity - 1];
		for (int i = 0; i < capacity - 1; i++)
			mas2[i] = mas[i];
		delete[] mas;
		int* mas = new int[capacity - 1];
		for (int i = 0; i < capacity - 1; i++)
			mas[i] = mas2[i];
		delete[] mas2;
	}

	Vector(const Vector& other)
	{
		this->size = other.size;
		this->mas = new int[size];
		for (int i = 0; i < this->size; i++)
			this->mas[i] = other.mas[i];
	}

	int operator[](size_t index) const
	{
		return elem[index];
	}

	int& operator[](size_t index)
	{
		return elem[index];
	}

	Iterator begin()
	{
		return Iterator(elem.data());
	}

	Iterator end()
	{
		return Iterator(elem.data() + elem.size());
	}
	~Vector()
	{
		delete[] mas;
	}
};

class Vector::Iterator: std::iterator<std::random_access_iterator_tag, int>
{
	private:
		int* obj;
public:
	Iterator() : object_(nullptr) {}

	int* operator->()
	{
		return obj;
	}

	Iterator& operator+=(const Iterator& rhs)
	{
		object_ += rhs.object;
		return *this;
	}

	Iterator& operator+(const Iterator& rhs)
	{
		object_ += rhs.object;
		return *this;
	}

	Iterator& operator-=(const Iterator& rhs)
	{
		object_ -= rhs.object;
		return *this;
	}

	Iterator& operator-(const Iterator& rhs)
	{
		object_ -= rhs.object;
		return *this;
	}

	bool operator<(const Iterator& rhs)
	{
		return *object_ < rhs.oblect_
	}

	bool operator>(const Iterator& rhs)
	{
		return object_ > rhs.oblect_
	}

	bool operator>=(const Iterator& rhs)
	{
		return object_ >= rhs.oblect_
	}

	bool operator<=(const Iterator& rhs)
	{
		return object_ <= rhs.oblect_
	}

	int& operator*()
	{
		return *object_;
	}

	int operator*() const
	{
		return *object_;
	}

	bool operator==(const Iterator& rhs) const
	{
		return object_ == rhs.object_;
	}

	bool operator!=(const Iterator& rhs) const
	{
		return object_ != rhs.object_;
	}

};

