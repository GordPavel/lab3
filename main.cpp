#include"mainwindow.h"
#include<QApplication>
#include<iostream>
#include<cstring>
#include<fstream>
#include<stdlib.h>
#include"illegalargumentexception.h"
#include"man.h"
using namespace std;

vector<string> &split(const string &s, char delim, vector<string> &elems){
    stringstream ss( s );
    string item;
    while ( getline( ss, item , delim ) )
        elems.push_back(item);
    return elems;
}

vector<string> split(const string &s, char delim){
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

int main(int argc, char *argv[]){
    vector<Man*> men;
    men.push_back( new Man( "A" , "+1111111111" , "11.11.11" ) );
    men.push_back( new Man( "B" , "+2222222222" , "22.22.22" ) );
    men.push_back( new Man( "C" , "+3333333333" , "33.33.33" ) );
    men.push_back( new Man( "D" , "+4444444444" , "44.44.44" ) );

    string cmd;
    cout <<
    "Здравствуйте. Если хотите вывести в файл, наберите команду \"-файл {название файла}\". Он сохранится на рабочем столе. Если хотите вывести в консоль, наберите команду \"-консоль\". Если хотите вывести в отдельное окно, наберите команду \"-окно\". Если хотите добавить нового человека, наберите команду \"-новый {фамилия слитно или через _} {номер телефона} {дата рождения}\". .\n";
    vector<string> words;

enterCmd:{
    try{
        getline( cin , cmd );
        string file( "-файл" ) , console( "-консоль" ) , window( "-окно" ), newMan( "-новый" ), end( "*" );
        words = split( cmd , ' ');
        if( strcmp( words[ 0 ].c_str() , file.c_str() ) == 0 ){
            ofstream out( "/Users/pavelgordeev/Desktop/" + words[ 1 ] + ".txt", ios::app);
            foreach ( Man* men , men )
                out << men->getLastName() << " " << men->getTelephoneNumber() << " " << men->getBirthDate() << '\n';
            out.close();
        }else if( strcmp( words[ 0 ].c_str() , console.c_str() ) == 0 ){
            foreach ( Man* men , men )
                cout << men->getLastName() << " " << men->getTelephoneNumber() << " " << men->getBirthDate() << '\n';
        }else if( strcmp( words[ 0 ].c_str() , window.c_str() ) == 0 ){
            QApplication a(argc, argv);
            MainWindow w( 0 , men );
            w.show();
            a.exec();
        }else if( strcmp( words[ 0 ].c_str() , newMan.c_str() ) == 0 ){
            men.push_back( new Man( words[ 1 ] , words[ 2 ] , words[ 3 ]  ) );
        }else if( strcmp( words[ 0 ].c_str() , end.c_str() ) == 0 ){
            return 0;
        }else{
            throw IllegalArgumentExceprion( "Неправильная команда ° " + cmd );
        }
    }catch( IllegalArgumentExceprion e ){
        cout << e.getMessage() << '\n';
        cout << "Введите ещё раз команду." << '\n';
        goto enterCmd;
    }
        cout << "Введите новую команду, если хотите выполнить ещё какие-то действия или *, если хотите закончить." << '\n';
        goto enterCmd;
    }
    return 0;
}
