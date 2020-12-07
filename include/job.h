//
// Created by Sebastian Kamraj on 07/12/2020.
//

#ifndef NEHALGORITHM_JOB_H
#define NEHALGORITHM_JOB_H
#include <iostream>
using namespace std;


class Job {
private:
    int numbermachine = 0;
    int numberproces = 0;
    int valueofproces = 0;
public:


    void setnumbermachine(int number);

    void setnumberproces(int number);

    void setvalueproces(int number);

    int getnumbermachine();
    int getnumberproces();

    int getvalue();

    friend ostream &operator<<(ostream &out, const Job object);

    bool operator<(const Job &first) const  {
        return (valueofproces > first.valueofproces);
    }

};



#endif //NEHALGORITHM_JOB_H
