#include <iostream>

class ResourceContainer
{
private:
    int* data;
    int size;

public:
    ResourceContainer(int s)
    {
        size = s;
        data = new int[size];
        std::cout << "Constructor called\n";
    }

    ResourceContainer(const ResourceContainer& other)
    {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; ++i)
            data[i] = other.data[i];
        std::cout << "Copy constructor called\n";
    }

    ResourceContainer& operator=(const ResourceContainer& other)
    {
        if (this != &other)
        {
            delete[] data;
            size = other.size;
            data = new int[size];
            for (int i = 0; i < size; ++i)
                data[i] = other.data[i];
        }
        std::cout << "Copy assignment operator called\n";
        return *this;
    }

    ~ResourceContainer()
    {
        delete[] data;
        std::cout << "Destructor called\n";
    }

    void FillRandom()
    {
        for (int i = 0; i < size; ++i)
            data[i] = rand() % 100;
    }

    void Print()
    {
        for (int i = 0; i < size; ++i)
            std::cout << data[i] << " ";
        std::cout << "\n";
    }
};


int main()
{
    ResourceContainer a(5);
    a.FillRandom();
    a.Print();

    ResourceContainer b = a; 
    b.Print();

    ResourceContainer c(10);
    c = a;
    c.Print();

}
