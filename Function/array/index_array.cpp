#include <iostream> 

using namespace std; 

int main() {
    int a[10];
    int n=10;

    for(int i=0;i<=n;i++){
        cout<<"array element are :"<<a[i]<<endl;
    }
    return 0;

    int index[10]={1,2,3,4,5,6,7,8,9,4};
    cout<<"array value at index 2"<<index[2]<<endl;
    cout<<"array value at index 5"<<index[5]<<endl;


    int arr[10]={1};
    int n=10;

    for(int i=0;i<=n;i++){
        cout<<"array element are :"<<a[i]<<endl;
    } 

    int initialioze[10]={2,7};
    int n=10;

    for(int i=0;i<=n;i++){
        cout<<"array element are :"<<a[i]<<endl;
    } 

    int size[10];
    int sizeoff=sizeof(size)/sizeof(int);
    cout<<"size of array is:"<<sizeoff<<endl;

    char ch[5]={'mihir'};
    char str;
    for(int i=1; i <=str; i++){
        cout<<"string value in array:"<<ch[i]<<endl;
    }


       return 0;


}

