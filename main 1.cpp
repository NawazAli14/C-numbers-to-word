#include <iostream>
#include <string>
using namespace std;
 
const string EMPTY = "";
 
const string X[] = { EMPTY, "One ", "Two ", "Three ", "Four ", "Five ",
                "Six ", "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ",
                "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ",
                "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen " };
 
const string Y[] = { EMPTY, EMPTY, "Twenty ", "Thirty ", "Forty ", "Fifty ",
                "Sixty ", "Seventy ", "Eighty ", "Ninety " };
 
string convertToDigit(unsigned long long n, string suffix)
{
    if (n == 0) {
        return EMPTY;
    }
 
    if (n > 19) {
        return Y[n / 10] + X[n % 10] + suffix;
    }
    else {
        return X[n] + suffix;
    }
}
 
string convert(unsigned long long n)
{
    string res;
 
    res = convertToDigit((n % 100), "");
 
    if (n > 100 && n % 100) {
        res = "and " + res;
    }
 
    res = convertToDigit(((n / 100) % 10), "Hundred ") + res;
 
    res = convertToDigit(((n / 1000) % 100), "Thousand, ") + res;
 
    res = convertToDigit(((n / 100000) % 100), "Lakh, ") + res;
 
    res = convertToDigit((n / 10000000) % 100, "Crore, ") + res;
 
    res = convertToDigit((n / 1000000000) % 100, "Billion, ") + res;
 
    size_t pos;
    while ((pos = res.find(", and")) != string::npos) {
        res.replace(pos, 1, "");
    }
 
    res.pop_back();            
    if (res[res.size()-1] == ',') {
        res.pop_back();        
    }
 
    return res;
}
 
int main()
{
    int choice=0;
    do{
        cout<<"Press 1 to convert numbers to words"<<endl;
        cout<<"Press 2 to Exit"<<endl;
        cout<<"Enter your Choice :";
        cin>>choice;
        if(choice==1){
            cout<<"Enter a number number :";
            int num=0;
            cin>>num;
            cout << convert(num) << endl;
        }
        else if(choice>2){
            cout<<"Invalid Choice"<<endl;
        }
        
    }
    while(choice!=2);
 
    return 0;
}