//
// Created by Sebastian Kamraj on 07/12/2020.
//
#include "job.h"

void Job::setnumbermachine(int number) {
    numbermachine = number;
}

void Job::setnumberproces(int number) {
    numberproces = number;

}

void Job::setvalueproces(int number) {
    valueofproces = number;
}

int Job::getnumbermachine() {
    return numbermachine;
}

int Job::getnumberproces() {
    return numberproces;
}

int Job::getvalue() {
    return valueofproces;
}



ostream &operator<<(ostream &out, Job object) {
    out << "Number of machine is: " << object.getnumbermachine() << "Number of process is: " << object.getnumberproces()
        << "Value: " << object.getvalue();
    return out;
}