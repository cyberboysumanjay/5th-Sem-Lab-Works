#include<iostream>
#include<stdlib.h>
using namespace std;
int mutex=1,full=0,empty=3,p=0;
int main()
{
    int a;
    void producer();
    void consumer();
    int wait(int);
    int signal(int);
    cout<<"1 for producer\n 2 for consumer\n 3 for exit"<<endl;

    while(1)
    {
        cout<<"enter your choice"<<endl;
        cin>>a;
        switch(a)
        {

        case 1:
            if((mutex==1)&&(empty!=0))
                producer();
            else
                cout<<"buffer is full"<<endl;
            break;
        case 2:
            if((mutex==1)&&(full!=0))
                consumer();
            else
                cout<<"buffer is empty"<<endl;
            break;
        case 3:
            exit(0);
            break;



        }
    }
    return 0;
}
int wait(int s)
{
    return (--s);
}
int signal(int s)
{
    return(++s);
}

void producer()
{
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    p++;
    cout<<"producer produces ="<<p<<endl;
    mutex=signal(mutex);

}
void consumer()
{
    mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    cout<<"consued item="<<p<<endl;
    p--;
    mutex=signal(mutex);
}

