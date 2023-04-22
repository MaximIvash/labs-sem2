#include <iostream>
using namespace std;

namespace mi
{
    class String
    {
    private:
        size_t i_size;
        char* i_str = nullptr;


    public:
        String() = default;

        String(const char* str) : i_size(strlen(str)), i_str(new char[i_size + 1]) // fast initialization
        {
            copy(str, str + i_size + 1, i_str);
        }

        String(String& old) : String(old.i_str) // delegating function
        {

        }

        String& operator = (const String& other)
        {
            if (i_str != nullptr)
                delete[] i_str;
            i_size = other.i_size;
            i_str = new char[i_size + 1];
            copy(other.i_str, other.i_str + i_size + 1, this->i_str);
            return *this;
        }

        String& operator += (const String& term)
        {
            i_size = this->i_size + term.i_size;
            auto temp = i_str;
            i_str = new char[i_size + 1];
            copy(temp, temp + strlen(temp), i_str);
            copy(term.i_str, term.i_str + term.i_size + 1, i_str + strlen(temp));
            delete[] temp;
            return *this;
        }

        String operator + (const String& term)
        {
            String tmp;
            tmp = *this;
            tmp += term;
            return tmp;
        }

        bool operator == (const String& str2)
        {
            return strcmp(this->i_str, str2.i_str) == 0;
        }

        bool operator > (const String& str2)
        {
            return strcmp(this->i_str, str2.i_str) > 0;
        }

        bool operator < (const String& str2)
        {
            return strcmp(this->i_str, str2.i_str) < 0;
        }

        char& operator [] (size_t i)
        {
            return i_str[i];
        }

        char* Find(const char& req)
        {
            for (int i = 0; i < i_size; i++)
            {
                if (i_str[i] == req)
                {
                    return (char*)i_str[i];
                }
            }
        }

        size_t& Length()
        {
            return i_size;
        }

        char* C_str()
        {
            return i_str;
        }

        void print()
        {
            for (int i = 0; i < i_size; i++)
            {
                cout << i_str[i];
            }
            cout << '\n';
        }

        char* at(size_t i)
        {
            if (i <= i_size)
            {
                return (char*)i_str[i];
            }
        }

        ~String()
        {
            if (i_str != nullptr)
            {
                delete[] i_str;
            }
        }

        friend ostream& operator << (ostream& output, mi::String& s);

        friend istream& operator >> (istream& input, String& str);

    };

    ostream& operator << (ostream& output, String& str)
    {
        output << str.i_str;
        return output;
    }

    istream& operator >> (std::istream& input, String& str)
    {
        char* tmp = new char[1000000000];
        input >> tmp;
        str.i_size = strlen(tmp);
        str.i_str = new char[str.i_size + 1];
        copy(tmp, tmp + strlen(tmp) + 1, str.i_str);
        delete[] tmp;
        return input;
    }
}

int main()
{
    mi::String s("Hello, it's me!");
    s.print();
    mi::String s1(",12345");
    s += s1;
    s.print();
    mi::String s2;
    s2 = s + s1;
    s2.print();
    char m = s2[8];
    cout << s2[8] << "\t" << m << "\n";
    mi::String s3;
    cin >> s3;
    cout << s3;
    return 0;
}

