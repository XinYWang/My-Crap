/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstring>

using namespace std;

class String{
    public:
        String(const char* str = nullptr);
        String(const String &other);
        ~String(void);
        String &operator = (const String &other);
    private:
        char *m_data;
};

String::String(const char* str){
    if(str == nullptr){
        m_data = new char[1];
        *m_data = '\0';
    }
    else{
        int length = strlen(str);
        m_data = new char[length + 1];
        strcpy(m_data, str);
    }
    cout << "Create done"<< endl;
}

String::~String(void){
    delete [] m_data;
    cout << "Delete done"<< endl;
}

String::String(const String &other){
    int length = strlen(other.m_data);
    m_data = new char[length+1];
    strcpy(m_data, other.m_data);
    cout << "Copy done"<< endl;
}

String & String::operator =(const String &other){
    if(this == &other)
        return *this;
    delete [] m_data;
    int length = strlen(other.m_data);   
     m_data = new char[length+1];
    strcpy(m_data, other.m_data);
    cout << "Equal done"<< endl;
    return *this;
}

int main()
{
    cout<<"Hello World"<<endl;
    String fstStr = "Hi, there";
    String sndStr = "alright";
    String trdStr = fstStr;
    return 0;
}

