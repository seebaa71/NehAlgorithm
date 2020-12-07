//
// Created by Sebastian Kamraj on 07/12/2020.
//
#include "functionsOfAlg.h"

void NehQue(vector<Job> tab, int np, int *tabhelp) {
    Job example;
    vector<Job> nehque;
    int nmhelp = 1;

    while (nmhelp != np + 1) {
        int tmp = 0;
        int valueproces = 0;
        while (tmp != tab.size()) {
            if (tab[tmp].getnumberproces() == nmhelp) {
                valueproces = valueproces + tab[tmp].getvalue();
            }
            tmp++;
        }
        example.setvalueproces(valueproces);
        example.setnumberproces(nmhelp);
        nehque.push_back(example);
        nmhelp++;

    }
    sort(nehque.begin(), nehque.end());
    for (int i = 0; i < np; i++) {
        tabhelp[i] = nehque[i].getnumberproces();
    }

}

int NehAlgorithm(vector<Job> tab, int *tabhelp, int np, int nm) {
    int timmachine[nm];
    int Cmax1 = 0;
    for (int i = 1; i < nm + 1; i++) {
        timmachine[i] = 0;
    }


    for (int j = 0; j < np ;j++)
    {
        for (int i = 1; i < nm + 1; i++) {
            int tmp = 0;
            while ((tabhelp[j] != tab[tmp].getnumberproces()) || (i != tab[tmp].getnumbermachine())) {
                tmp++;
            }

            if (i == 1 ) {
                timmachine[i] = timmachine[i] + tab[tmp].getvalue();

            } else {
                if (timmachine[i - 1] >= timmachine[i] && j != 0) {
                    timmachine[i] = timmachine[i] + (timmachine[i - 1] - timmachine[i]);
                    timmachine[i] = timmachine[i] + tab[tmp].getvalue();

                } else if (timmachine[i - 1] < timmachine[i] && j != 0) {
                    timmachine[i] = timmachine[i] + tab[tmp].getvalue();


                }
                if (i == nm && j == 0) {
                    for (int k = nm; k != 1; k--) {
                        timmachine[k] = timmachine[k] + timmachine[k - 1];
                    }
                }
            }
            if (i == nm) {
                Cmax1 = timmachine[i];
            }


        }
    }


    return Cmax1;

}
