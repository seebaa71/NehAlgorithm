#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "job.h"
#include "functionsOfAlg.h"

using namespace std;


int main() {
    Job object;
    vector<Job> tab;
    int nm, np, p1[100][100];
    ifstream data("data.txt");
    data >> np >> nm;
    int tabhelp[np];

    for (int i = 1; i < np + 1; i++) {
        for (int j = 1; j < nm + 1; j++) {
            data >> p1[j][i];
        }
    }
    data.close();
    for (int i = 1; i < np + 1; i++) {
        for (int j = 1; j < nm + 1; j++) {
            object.setnumberproces(i);
            object.setnumbermachine(j);
            object.setvalueproces(p1[j][i]);
            tab.push_back(object);
        }
    }


    NehQue(tab,np,tabhelp);
    int tabpom[np];
    int tabpom2[np];
    int Cmax = 0, Cmaxhelp = 0;
    int permutation = 0;
    for (int i = 0; i < np +1; i++) {
        int r = i;
        Cmax = Cmaxhelp;
        int pom = 0;


        tabpom[i] = tabhelp[i];


        if (Cmaxhelp >= pom) {
              pom = NehAlgorithm(tab, tabpom, i, nm);
        Cmaxhelp = pom;


             for (int w = 0; w < i; w++) {
                 tabpom2[w] = tabpom[w];
             }

        }


        while (r != 0) {
            r--;

            if (r > 0) {
                int helpq = 0;

                helpq = tabpom[r - 1];
                tabpom[r - 1] = tabpom[r];
                tabpom[r] = helpq;
                pom = NehAlgorithm(tab, tabpom, i, nm);

                if (Cmaxhelp >= pom) {
                    Cmax = pom;

                    for (int w = 0; w < i; w++) {
                        tabpom2[w] = tabpom[w];
                    }
                }
            }
            Cmaxhelp=pom;

        }

        if (i > 0) {
            for (int w = 0; w < i ; w++) {
                tabpom[w] = tabpom2[w];
            }
        }

    }

    cout << "The best CMAX value of NEH algorithm is: " << Cmax << endl;

    for(int i=0;i<np;i++)
    {
        cout << tabpom[i] << endl;
    }


}