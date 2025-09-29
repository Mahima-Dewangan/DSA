#include<bits/stdc++.h>
using namespace std;



// optima solution : using slow and fast pointer

int help(int n)
{
    int sum =0;
    while(n)
    {
        int rem=n%10;
        sum+= pow(rem , 2);
        n=n/10;
    }
    
    return sum;
}

bool happy_number(int n)
{
    
    
        int slow = n;
        int fast = n;


    do{
        slow = help(slow);
        fast = help(help(fast));
    }while(slow!= fast);

    return slow==1;
}

int main ()
{
    int n;
    cout<<"/nenter the number";
    cin >> n;

    cout<<"\n is the number "<<n<<" a happy number ? "<<happy_number(n);

}