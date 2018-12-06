#include<iostream>
#include<stdlib.h>
using namespace std;
int wrt=1,rc,mutex;
int wait (int s)
{
return(--s);
}
int signal(int s)
{
return (++s);
}
void writer()
{
int wait(int );
int signal(int);
wrt=wait(wrt);
cout<<"Dont Come anyone (either writer or reader),I AM HERE & WRITING SOMETHING"<<endl;
wrt=signal(wrt);
}
void readerin()
{
int wait(int);
int signal(int);
mutex=wait(mutex);
rc=++rc;
if((rc==1)&&(wrt==1))
{
wrt=wait(wrt);
mutex=signal(mutex);
}
else
mutex=signal(mutex);
cout<<"I AM READING and READERS ARE ALLOWED but WRITERS are strictly prohibited"<<endl;
}
void readerout()
{
int wait(int);
int signal(int);
mutex=wait(mutex);
rc=--rc;
if(rc==0)
wrt=signal(wrt);
mutex=signal(mutex);
}

int main()
{
int mutex=1,rc=0,n;
void readerin();
void readerout();
void writer();
int wait(int);
int signal(int);
cout<<"\n1.readerin"<<"\n2.readerout"<<"\n3.writer"<<"\n4.exit"<<endl;
while(1)
{

cout<<"Enter Your Choice from above three availab choice"<<endl;
cin>>n;
switch(n)
{
case 1:
      if((mutex==1))
      readerin();
      else
      cout<<"I cant COME as there is writer inside"<<endl;
      break;
case 2:
      if((mutex==1))
      readerout();
      else
      cout<<"wait and hold"<<endl;
      break;
case 3:
     if((wrt==1))
     writer();
     else
     cout<<"not going"<<endl;
    break;
case 4:
     exit(0);
     break;
}
}
return 0;
}

