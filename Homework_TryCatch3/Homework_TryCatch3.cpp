
#include <iostream>
#include <exception>

class CartItem
{
private:
    char* name = nullptr;
    int price;
    int stash;
public:
    CartItem(const char* _name, int _price, int _stash)
    {
        name = new char[strlen(_name) + 1];
        name[strlen(_name)] = '\0';
        for (int i = 0; i < strlen(_name); i++)
        {
            name[i] = _name[i];
        }
        try
        {
            if (_price != 0)
            {
                price = _price;
            }
            else
            {
                price = 1;
                throw std::invalid_argument(0);
            }
        }
        catch (std::invalid_argument)
        {
            std::cerr << "Price lower then 0!\n";
        }
        stash = _stash;
    }

    int getStash()
    {
        return stash;
    }
    int getPrice()
    {
        return price;
    }

    virtual ~CartItem()
    {
        if (name != nullptr)
        {
            delete[] name;
        }
    }
};
class Cart
{
private:
public:
    void add(CartItem& item, int many)
    {
        try
        {
            if (item.getStash() >= many)
            {
                std::cout << "Added succesfully!\n";
            }
            else
            {
                throw std::runtime_error(0);
            }
        }
        catch (std::runtime_error)
        {
            std::cerr << "ERROR: STASH LESS THEN ADD MUCH!\n";
        }
    }
};

class OrderProccesingException : public std::exception
{
private:
    int errorNumber;
public:
    OrderProccesingException() : exception()
    {
        errorNumber = 0;
    }
    OrderProccesingException(int _errorNumber)
    {
        errorNumber = _errorNumber;
    }

    void display()
    {
        if (errorNumber == 1)
        {
            std::cout << "To Long!\n";
        }
        else if (errorNumber == 2)
        {
            std::cout << "Try Again\n";
        }
        else if (errorNumber == 3)
        {
            std::cout << "String is empty!\n";
        }
    }
};

class Order
{
private:
public:
    void ProccesOrder(const char* string)
    {
        try
        {
            if (string == nullptr)
            {
                throw OrderProccesingException(3);
            }
            else if (strlen(string) > 15)
            {
                throw OrderProccesingException(1);
            }
            else
            {
                std::cout << "Proccesed sucesfully!\n";
            }
        }
        catch (OrderProccesingException a)
        {
            a.display();
        }
    }
};

int main()
{
    Order a;
    a.ProccesOrder("1234567890asdfghj");
}
