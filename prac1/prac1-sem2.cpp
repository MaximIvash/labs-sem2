#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class cypher
{
private:
    vector <int> m_fibonachi;
    vector <int> m_key;
    vector <int> m_Mainkey;

    bool CheckKey(vector <int> your_key)
    {
        sort(your_key.begin(), your_key.end());
        for (int i = 0; i < your_key.size(); i++)
        {
            for (int j = i + 1; j < your_key.size(); j++)
            {
                if ((your_key[i] == your_key[j]))
                {
                    cout << "error!";
                    return false;
                }
            }
        }
        for (int i = 0; i < your_key.size(); i++)
        {
            int tmp = 0;
            for (int j = 0; j < m_fibonachi.size(); j++)
            {
                if (your_key[i] == m_fibonachi[j])
                {
                    tmp += 1;
                }
            }
            if (tmp == 0)
            {
                cout << "error!";
                return false;
            }
        }
        return true;

    }

    vector <int> MainKey(vector<int> Vec)
    {
        sort(Vec.begin(), Vec.end());
        return Vec;
    }

    vector <string> SplitSentence(const string& str)
    {
        vector <string> words;
        string tmp = "";
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ')
            {
                tmp += str[i];
            }
            else if (str[i] == ' ')
            {
                words.push_back(tmp);
                tmp = "";
            }

        }
        words.push_back(tmp);
        return words;
    }

public:
    cypher()
    {
        m_fibonachi.push_back(0);
        m_fibonachi.push_back(1);
        for (int i = 2; i < 30; i++)
        {
            m_fibonachi.push_back(m_fibonachi[i - 1] + m_fibonachi[i - 2]);
        }
    }
    void Set_Key(const vector <int>& your_key)
    {

        if ((your_key.size() <= 30) && (CheckKey(your_key)))
        {
            m_key = your_key;
            m_Mainkey = MainKey(m_key);
        }
        else
        {
            cout << "key does not match conditions" << endl;

        }
    }

    vector<int> Get_Key()
    {
        return m_key;
    }

    string encode(const string& str)
    {
        vector <string> words = SplitSentence(str);
        if (words.size() != m_key.size())
        {
            cout << "error! The number of words must be equal to the number of digits" << endl;
        }
        string EncodedStr;
        if (words.size() == m_key.size())
        {
            for (int i = 0; i < words.size(); i++)
            {
                for (int j = 0; j < words.size(); j++)
                {
                    if (m_key[i] == m_Mainkey[j])
                    {
                        EncodedStr += words[j];
                        if (i != words.size() - 1)
                        {
                            EncodedStr += " ";
                        }
                    }
                }

            }
        }
        return EncodedStr;
    }

    string decode(const string& str)
    {
        vector <string> words = SplitSentence(str);
        if (words.size() != m_key.size())
        {
            cout << "error! The number of words must be equal to the number of digits" << endl;
        }
        string DecodedStr;
        if (words.size() == m_key.size())
        {
            for (int i = 0; i < words.size(); i++)
            {
                for (int j = 0; j < words.size(); j++)
                {
                    if (m_Mainkey[i] == m_key[j])
                    {
                        DecodedStr += words[j];
                        if (i != words.size() - 1) 
                        {
                            DecodedStr += " ";
                        }
                    }
                }
            }
        }
        return DecodedStr;
    }


    ~cypher() {}

};

int main()
{
    cypher main;
    string txt = "Hello, my name is Maxim.";
    main.Set_Key({ 8, 2, 1, 5, 3 });
    string str;
    str = main.encode(txt);
    cout << str << endl;
    cout << main.decode(str) << endl;
}