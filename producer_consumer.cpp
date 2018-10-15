#include<iostream>
using namespace std;

int n=5;
int count=0;
int mutex=1;
int full=0;
int empty=5;
int arr[10];

int signal(int s){
  return ++s;
}

int wait(int s){
    return --s;
}

void producer(void) {
  mutex=wait(mutex);
  full=signal(full);
  empty=wait(empty);
  count++;
  cout<<"Producer produced item "<<count<<'\n';
  mutex=signal(mutex);
  cout<<full<<'\n';
  cout<<empty<<'\n';

}

void consumer(void) {
  mutex=wait(mutex);
  full=wait(full);
  empty=signal(empty);
  cout<<"Consumer consumed item "<< count<<'\n';
  count--;
  mutex=signal(mutex);
  cout<<full<<'\n';
  cout<<empty<<'\n';
}



int main(){
  int choice;
  void producer();
  void consumer();
  int wait(int);
  int signal(int);
  cout<<"\n1.Produce Item\n2.Consume Item\n3.Exit\n";
  while(1)
  {
      cout<<"\nEnter your choice: ";
      cin>>choice;
      switch(choice)
      {
          case 1:
                  if((mutex==1)&&(empty!=0) )
                      producer();
                  else
                      cout<<"Buffer filled completely!\n";
                  break;
          case 2:
                  if((mutex==1)&&(full!=0))
                      consumer();
                  else{
                    cout<<"Buffer is empty!";
                  }

                  break;
          case 3:
                  cout << "Exiting!" << '\n';
                  break;
      }
  }

  return 0;

}
