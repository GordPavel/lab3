#ifndef MEN_H
#define MEN_H

#include <iostream>
#include <algorithm>
#include <sstream>
#include<vector>

using namespace std;

class Man{
private:
    string lastName;
    string telephoneNumber;
    string birthDate;
public:
    Man(string lastName , string telephoneNumber , string birthDate ){
        this->lastName = lastName;
        this->telephoneNumber = telephoneNumber;
        this->birthDate = birthDate;
    };
    string toString(){
        string str = "";
        str += this->lastName + " " + this->telephoneNumber + " " + this->birthDate;
        return str;
    }
    string getLastName(){
        return this->lastName;
    }
    string getTelephoneNumber(){
        return this->telephoneNumber;
    }
    string getBirthDate(){
        return this->birthDate;
    }
};

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

#endif // MEN_H
