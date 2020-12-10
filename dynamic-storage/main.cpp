#include <iostream>
#include <cstdlib>

#if _WIN32
#include <conio.h>
#endif

class DynamicStorage
{
public:
    DynamicStorage()
    : _id(0)
    , _value(0)
    {
        static int instanceID = 0;
        _instanceID = ++instanceID;
    }

    DynamicStorage(int id, char value)
    : _id(id)
    , _value(value)
    {
        static int instanceID = 0;
        _instanceID = ++instanceID;
    }

    void set(int id, char value)
    {
        _id = id;
        _value = value;
    }

    int getId()
    {
        return _id;
    }

    char getValue()
    {
        return _value;
    }

    int getInstanceID()
    {
        return _instanceID;
    }

private:
    int _id;
    char _value;
    int _instanceID;

protected:
};

void showMenu(int &selectedIdx);
void changeStore(DynamicStorage *&storage1, DynamicStorage *&storage2, DynamicStorage *&storage3, DynamicStorage *&mainStorage);
void setStore(DynamicStorage *mainStorage);
void showStore(DynamicStorage *mainStorage);

int main(int argv, char *argc[])
{
    DynamicStorage *storage1 = new DynamicStorage();
    DynamicStorage *storage2 = new DynamicStorage();
    DynamicStorage *storage3 = new DynamicStorage(15, 'c');
    DynamicStorage *mainStorage = new DynamicStorage();

    while (true)
    {
        int selectedIdx = 0;
        showMenu(selectedIdx);

        switch (selectedIdx)
        {
        case 1:
            setStore(mainStorage);
            break;
        case 2:
            changeStore(storage1, storage2, storage3, mainStorage);
            break;
        case 3:
            showStore(mainStorage);
            break;
        }

        char willContinueKey = ' ';

        do
        {
            std::cout << std::endl;
            std::cout << "Do you want to try again? (y/n)" << std::endl;
            std::cin >> willContinueKey;

            std::cout << std::endl;
            std::cout << std::endl;
        } 
        while (willContinueKey != 'y' && willContinueKey != 'n');

        if (willContinueKey == 'n')
        {
            break;
        }
    }

    std::cout << std::endl;
    std::cout << "Thanks for playing!" << std::endl;

#if _WIN32
    _getch();
#endif;

    return 0;
}

void showMenu(int &selectedIdx)
{
    std::cout << "Welcome to the Dynamic Storage Mechanism Subsystem!" << std::endl;
    std::cout << std::endl;

    std::cout << "1 - Set values to current store." << std::endl;
    std::cout << "2 - Change current selected store." << std::endl;
    std::cout << "3 - Show current value store." << std::endl;
    std::cout << std::endl;

    std::cin >> selectedIdx;
}

void changeStore(DynamicStorage *&storage1, DynamicStorage *&storage2, DynamicStorage *&storage3, DynamicStorage *&mainStorage)
{
    if (mainStorage == NULL)
    {
        std::cout << "Current store is pointing at nothing." << std::endl;
    }

    std::cout << "What store would you like to use? (1-3 only)" << std::endl;

    int selectedIdx = 0;
    std::cin >> selectedIdx;

    if (storage1->getInstanceID() == selectedIdx)
    {
        mainStorage = storage1;
    }
    else if (storage2->getInstanceID() == selectedIdx)
    {
        mainStorage = storage2;
    }
    else if (storage3->getInstanceID() == selectedIdx)
    {
        mainStorage = storage3;
    }

    std::cout << "New store value is " << mainStorage->getInstanceID() << std::endl;
}

void setStore(DynamicStorage *mainStorage)
{
    int num = 0;
    char letter = ' ';

    std::cout << "Current store value to change is " << mainStorage->getInstanceID() << std::endl;
    
    std::cout << "Enter new number." << std::endl;
    std::cin >> num;

    std::cout << "Enter new letter." << std::endl;
    std::cin >> letter;

    mainStorage->set(num, letter);

    std::cout << "New values have been set." << std::endl;
    std::cout << std::endl;
}

void showStore(DynamicStorage *mainStorage)
{
    std::cout << "Current store value is " << mainStorage->getInstanceID() << std::endl;
    std::cout << "Store's number is " << mainStorage->getId() << std::endl;
    std::cout << "Store's letter is " << mainStorage->getValue() << std::endl;
    std::cout << std::endl;
}