#include <iostream> 
using namespace std; 

int main() {
    int num1,num2;
    int ch;

    cout<<"enter the value of no 1:"<<endl;
    cin>>num1;

    cout<<"enter the value of num2:"<<endl;
    cin>>num2;

    cout<<"case 1. +"<<endl<<"case 2. -"<<endl<<"case 3. *"<<endl<<"case 4. /"<<endl;
    cin>>ch;


    switch (2*ch)
    {

    case 2: 
        int c = num1+num2;
        cout<<"addition of two no :"<<c<<endl;
        break;

    case 4:
        switch (ch)
        {
        case 4:
        int c = num1-num2;
        cout<<"subtraction of two no :"<<c<<endl;
            break;
        
        default:
            break;
        }
     case 6:
        int c = num1*num2;
        cout<<"Multiplication of two no :"<<c<<endl;
            break;
     case 8:
        int c = num1/num2;
        cout<<"Divition of two no :"<<c<<endl;
            break;
    
    default:cout<<"exit"<<endl;
        break;
    }
    return 0;
}