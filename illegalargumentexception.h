#ifndef ILLEGALARGUMENTEXCEPRION_H
#define ILLEGALARGUMENTEXCEPRION_H


class IllegalArgumentExceprion{
private:
    string message;
public:
    IllegalArgumentExceprion( string message ){
        this->message = message;
    }
    string getMessage(){
        return this->message;
    }
};

#endif // ILLEGALARGUMENTEXCEPRION_H
