#pragma once
#include <iostream>
using namespace std;


// —оздание не более одного экземпл€ра класса Singleton
class Singleton
{
private:
    // —татическа€ внутренн€€ переменна€, котора€ хранит одиночный экземпл€р класса.
    //   этой переменной есть доступ из методов данного класса, так как
    // она объ€влена как private. »з методов других классов доступа к переменной нет.
    static Singleton* _instance;

    // Ќекоторые данные класса, здесь могут быть любые данные
    int d;

protected:
    //  онструктор класса, объ€вленный как protected, дл€ того чтобы:
    // - невозможно было создать экземпл€р класса непосредственно оператором new;
    // - можно было наследовать данный класс из других классов.
    Singleton()
    {
        d = 0;
    }

public:
    // —татический метод, возвращающий экземпл€р класса Singleton.
    // ћетод делает проверку, не создан ли экземпл€р
    static Singleton* Instance()
    {
        if (_instance == nullptr) // Ѕыл ли ранее создан экземпл€р класса
        {
            // если нет, то создать единственный экземпл€р и вернуть его.
            _instance = new Singleton();
            return _instance;
        }
        else
        {
            return _instance;
        }
    }

    void Set(int _d)
    {
        d = _d;
    }

    void Print()
    {
        cout << "d = " << d << endl;
    }

    // ƒеструктор класса
    ~Singleton()
    {
        delete _instance;
    }
};

// »нициализаци€ внутренней статической переменной _instance,
Singleton* Singleton::_instance = nullptr;

