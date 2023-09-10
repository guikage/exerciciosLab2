#ifndef _datas_
#define _datas_

struct data{
    int dia;
    int mes;
    int ano;
};
typedef struct data Data;

Data pegaData(void);
int difdata(Data data1, Data data2);

#endif
