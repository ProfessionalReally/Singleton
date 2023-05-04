#include "Header.h"

void main()
{
    // Создать единственный экземпляр класса Singleton
    Singleton* obj1 = Singleton::Instance();

    if (obj1 != nullptr)
    {
        obj1->Set(255);
        obj1->Print(); // d = 255
    }

    // Попытка создания другого экземляра класса Singleton
    Singleton* obj2 = Singleton::Instance(); 

    if (obj2 != nullptr)
    {
        obj2->Set(300);
        obj2->Print();
    }

    delete obj1, delete obj2;
}