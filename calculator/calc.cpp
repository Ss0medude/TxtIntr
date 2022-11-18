#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <cstdlib>
void help()
{
    std::cout << "Параметры:\n'-s' Сумма\n'-v' Вычитание\n'-h' Вызов инструкции \nКол-во операндов: 3-5  \n";
    exit(1);
}

int main(int argc, char **argv)
{
    int st=0, a=0,a1=0, a2=0;
    for (int i=1; i<argc; i++) {
        a=strtol(argv[i], nullptr, 10);
        if (a!=0 and st==0) {
            a1=a;
            st=1;
            continue;
        }
        if (a!=0 and st!=0) {
            a2+=a;
            st+=1;
        }
    }
    if((st<3)or(st>5)) {
        help();
    }
    int opt, sd=0;
    while((opt = getopt(argc, argv, "svh")) != -1) {
        switch(opt) {
        case 's':
            if (sd == 0) {
            	std::cout << "Сумма: " << a1+(a2) << std::endl;
            	sd+=1;
            }
            break;
        case 'v':
            if (sd == 0) {
            	std::cout << "Вычитание: " << a1-(a2) << std::endl;
            	sd+=1;
            }
            break;
        case 'h':
            help();
        }
    }
    if (sd == 0) {
        help();
    }
}
