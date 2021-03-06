#include <iostream>
#include <list>
#include <windows.h>
#include <fstream>

using namespace std;

list <string> lista; //utworzenie listy przechowujacej listę słówek
int wybor;

//---------------------

void wyswietl()
{
    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<" ZAWARTOSC LISTY: "<<endl;
    cout<<"---------------------------"<<endl;

    for(list<string>::iterator i=lista.begin(); i!= lista.end(); ++i)
       cout<<*i<<" ";

    cout<<endl;
    cout<<"---------------------------"<<endl<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

//-------- 1 ------------

void push_front()
{
    string slowo;
    cout<<"Podaj jakie s\210\242wko wstawic na pocz\245tek listy: ";
    cin>>slowo;
    lista.push_front(slowo);
}

//--------- 2 -----------

void push_back()
{
    string slowo;
    cout<<"Podaj jakie s\210\242wko wstawic na koniec listy: ";
    cin>>slowo;
    lista.push_back(slowo);
}

//---------- 3 ---------

void pop_front()
{
    cout<<"Nast\245pi usuni\251cie s\210\242wka z pocz\245tku listy";
    Sleep(2000);
    lista.pop_front();
}

//---------- 4 ---------

void pop_back()
{
    cout<<"Nast\245pi usuni\251cie s\210\242wka z konca listy";
    Sleep(2000);
    lista.pop_back();
}

//---------- 5 ----------

void size()
{
    cout<<"S\210\242wek na li\230cie: "<<lista.size();
    Sleep(2000);
}

//---------- 6 ----------

void max_size()
{
    cout<<"Max s\210\242w na li\230cie: "<<lista.max_size();
    Sleep(5000);
}

//---------- 7 ----------

void empty()
{
    cout<<"Czy lista pusta? -> ";
    if (lista.empty()==1) cout<<"TRUE"; else cout<<"FALSE";
    Sleep(2000);
}

//---------- 8 ----------

void remove()
{
    string slowo;
    cout<<"Usun z listy wszystkie s\210\242wka zawieraj\245ce: ";
    cin>>slowo;
    lista.remove(slowo);
}

//---------- 9 ----------

void sort()
{
    cout<<"Nast\245pi posortowanie listy! ";
    lista.sort();
    Sleep(2000);
}

//---------- 10 ----------

void reverse()
{
    cout<<"Nastapi odwrocenie kolejnosci liczb!";
    lista.reverse();
    Sleep(2000);
}

//---------- 11 ----------

void exit()
{

    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    cout<<"Koniec programu!"<<endl;
    Sleep(500);
    }
//------------------------
void druk()
{

    if (lista.size()==0) cout<<"Brak listy do wydruku."<< endl;
    else
    ofstream plik( "print.txt" );
    fstream plik;
    plik.open("print.txt",ios::out|ios::app);

    for(list<string>::iterator i=lista.begin(); i!= lista.end(); ++i)
       plik<<*i<<endl;
    plik.close();
    cout<<"Zapisano list\251 w pliku."<<endl;
    Sleep(2000);
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
}
//------------------------
int main()
{

do
{

wyswietl();

cout << " MENU GLOWNE LISTY:"<<endl;
cout << "---------------------------"<<endl;
cout << "1.  push_front"<<endl;
cout << "2.  push_back"<<endl;
cout << "3.  pop_front"<<endl;
cout << "4.  pop_back"<<endl;
cout << "5.  size"<<endl;
cout << "6.  max_size"<<endl;
cout << "7.  empty"<<endl;
cout << "8.  remove"<<endl;
cout << "9.  sort"<<endl;
cout << "10. reverse"<<endl;
cout << "11. exit"<<endl;
cout << "---------------------------"<<endl;
cout << "Wybor: ";
cin >> wybor;

    switch (wybor)
    {
        case 1:  push_front(); break;
        case 2:  push_back();  break;
        case 3:  pop_front();  break;
        case 4:  pop_back();   break;
        case 5:  size();       break;
        case 6:  max_size();   break;
        case 7:  empty();      break;
        case 8:  remove();     break;
        case 9:  sort();       break;
        case 10: reverse();    break;
        case 11: exit();druk(); break;

        default:
        cout<<"POMYLKA!";
        Sleep(2000);
        break;
    }

}
while(wybor!=11);

    return 0;
}
