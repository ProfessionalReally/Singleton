#pragma once
#include <iostream>
using namespace std;


// �������� �� ����� ������ ���������� ������ Singleton
class Singleton
{
private:
    // ����������� ���������� ����������, ������� ������ ��������� ��������� ������.
    // � ���� ���������� ���� ������ �� ������� ������� ������, ��� ���
    // ��� ��������� ��� private. �� ������� ������ ������� ������� � ���������� ���.
    static Singleton* _instance;

    // ��������� ������ ������, ����� ����� ���� ����� ������
    int d;

protected:
    // ����������� ������, ����������� ��� protected, ��� ���� �����:
    // - ���������� ���� ������� ��������� ������ ��������������� ���������� new;
    // - ����� ���� ����������� ������ ����� �� ������ �������.
    Singleton()
    {
        d = 0;
    }

public:
    // ����������� �����, ������������ ��������� ������ Singleton.
    // ����� ������ ��������, �� ������ �� ���������
    static Singleton* Instance()
    {
        if (_instance == nullptr) // ��� �� ����� ������ ��������� ������
        {
            // ���� ���, �� ������� ������������ ��������� � ������� ���.
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

    // ���������� ������
    ~Singleton()
    {
        delete _instance;
    }
};

// ������������� ���������� ����������� ���������� _instance,
Singleton* Singleton::_instance = nullptr;

