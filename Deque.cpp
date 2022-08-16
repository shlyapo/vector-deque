#include "Vector.h"
#include <iostream>

using namespace std;

class Deque : public Vector
{
public:
    int size, back, index, element, index2, element2, find_index, j, element_ahead;
    int* mas;
    int* mas2;
    Deque(int size, int back, int index, int element, int index2,
        int element2, int find_index, int j):
        Vector(size)
    {
        element_ahead = 0;
        this->size = size;
        this->mas = new int[size];
        for (int i = 0; i < size; i++)
            mas[i] = i;
    }
    void SetDeque()
    {
        if (size != 0)
            Vector::SetVector();
    }
    void change_length()
    {
        if (size != 0)
            Vector::change_length();
    }
    void push_back()
    {
        if (size != 0)
            Vector::push_back(back);
    }
    void insert_index()
    { 
        if (size != 0)
            Vector::insert_index(index, element);
    } 
    int delete_index()
    {
        if (size != 0)
            Vector::delete_index(index2);
    }
    void clear()
    {
        if (size != 0)
            Vector::clear();
    }
            void delete_back()
        {
                if (size != 0)
                    Vector::delete_back();
            }
            void find_element()
        {
                if (size != 0)
                    Vector::find_element(element2);
            }
        void ahead_element(int element_ahead)
    {
        this->element_ahead = element_ahead;
        j = 1;
        change_length();
        for (int i = size; i > 0; i--)
        {
            mas2[i] = mas2[i - 1];
            mas2[0] = element_ahead;
        }
        for (int i = 0; i < size + j; j++)
            cout << mas2[i] << endl;
    }
    void delete_ahead()
    {
        j = -1;
        for (int i = size-j; i > 0; i--)
            mas[i-1] = mas[i];
        change_length();
        for (int i = 0; i < size - j; i++)
            cout << mas2[i] << endl;
    }
    ~Deque()
    {
        delete[] mas;
        delete[] mas2;
    }
    Deque(const Deque& other)
    {
        this->size = other.size;
        this->mas = new int[size];
        for (int i = 0; i < this->size; i++)
            this->mas[i] = other.mas[i];
    }
        Deque& operator=(Deque& other)
        {
            delete[] this->mas;
            this->size = other.size;
            this->mas = new int[this->size];

            for (int i = 0; i < this->size; i++)
                this->mas[i] = other.mas[i];
            return *this;
        }
};
 
