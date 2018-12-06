
#include<bits/stdc++.h>
using namespace std;
vector<int> pages;
bool search(vector<int> arr, int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
         return true;
    return false;
}
int main()
{
int n,w,ff;
int indexpos;
cout<<"enter number of pages"<<endl;
cin>>n;
cout<<"enter all the pages"<<endl;
for(int i=0;i<n;i++)
{
cin>>w;
pages.push_back(w);
}
cout<<"enter frame length\n";
cin>>ff;
int pagefault=ff;
vector<int> frames;
for(int i=0;i<ff;i++){
 frames.push_back(pages[i]);
 }
for(int i=ff;i<n;i++)
{

if(!search(frames,pagefault,pages[i])){
++pagefault;
frames[indexpos]=pages[i];
indexpos+=1;
if(indexpos>=ff)
   indexpos=0;

}

}
cout<<endl;
cout<<pagefault;
return 0;


}



