#include <bits/stdc++.h>
#include <thread> 

using namespace std;

void foo(int z){
    for(int i=0; i<z; i++){
        cout<<i<<" --> thread using function pointer as callable "<<z<<"\n";
    }
}



class thread_obj { 
public: 
    void operator()(int x) 
    { 
        for (int i = 0; i < x; i++) 
                 cout <<i<< " --> Thread using function object as  callable : "<<x<<"\n"; 
    } 
}; 

int main(){
    cout << "Threads 1 and 2 and 3 operating independently" << endl; 

    thread th1(foo, 7);
    thread th2(thread_obj(), 6);

     // Define a Lambda Expression 
    auto f = [](int x) { 
        for (int i = 0; i < x; i++) 
            cout << "Thread using lambda"
             " expression as callable\n"; 
    }; 

    thread th3(f, 5);

    th1.join();
    th2.join();
    th3.join();

    return 0;
}
