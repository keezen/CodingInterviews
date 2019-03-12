# include <iostream>
# include <cstring>
using namespace std;

class CMyString
{
public:
    CMyString(char *pData = NULL);
    CMyString(const CMyString &str);
    ~CMyString();
    char* GetString();
    CMyString& operator=(const CMyString &str);

private:
    char *m_pData;
};

CMyString::CMyString(char *pData)
{
    m_pData = NULL;
    if(pData){
        m_pData = new char[strlen(pData) + 1];
        strcpy(m_pData, pData);
    }
}

CMyString::CMyString(const CMyString &str)
{
    m_pData = NULL;
    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString()
{
    delete [] m_pData;
}

char* CMyString::GetString()
{
    return m_pData;
}

CMyString& CMyString::operator=(const CMyString &other)
{
    // copy assignment operator
    if (this != &other)
    {
        delete [] m_pData;
        m_pData = NULL;
        m_pData = new char[strlen(other.m_pData) + 1];
        strcpy(m_pData, other.m_pData);
    }
    return *this;
}


int main()
{
    char str[20] = "hello world";
    char str2[20] = "i love you";
    CMyString mstr1;
    CMyString mstr2(str);
    CMyString mstr3 = mstr2;
    CMyString mstr4(str2);

    cout << str << endl;
    cout << mstr2.GetString() << endl;
    cout << mstr3.GetString() << endl;
    cout << mstr4.GetString() << endl;

    // copy
    mstr1 = mstr3;
    cout << mstr1.GetString() << endl;
    mstr1 = mstr1;
    cout << mstr1.GetString() << endl;
    mstr1 = mstr2 = mstr4;
    cout << mstr1.GetString() << endl;
    cout << mstr2.GetString() << endl;

    return 0;
}
