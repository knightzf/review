#include "header.h"

class Solution {
public:
    bool isRationalEqual(string S, string T) {
        int sa, ta;
        if(S.find('.') != -1)
            sa = stoi(S.substr(0, S.find('.')));
        else
            sa = stoi(S);

        if(T.find('.') != -1)
            ta = stoi(T.substr(0, T.find('.')));
        else
            ta = stoi(T);

        string sb = " ";
        if(S.find('(') != -1)
            sb = S.substr(S.find('.') + 1, S.find('(') - S.find('.') - 1);
        else if(S.find('.') != -1)
            sb = S.substr(S.find('.') + 1);

        string tb = " ";
        if(T.find('(') != -1)
            tb = T.substr(T.find('.') + 1, T.find('(') - T.find('.') - 1);
        else if(T.find('.') != -1)
            tb = T.substr(T.find('.') + 1);

        string sc = " ";
        if(S.find('(') != -1)
            sc = S.substr(S.find('(') + 1, S.find(')') - S.find('(') - 1);

        string tc = " ";
        if(T.find('(') != -1)
            tc = T.substr(T.find('(') + 1, T.find(')') - T.find('(') - 1);

        //cout<<sa<<" "<<ta<<" "<<sb<<" "<<tb<<" "<<sc<<" "<<tc<<endl;
        if(!sc.empty() && sc == string(sc.size(), '9'))
        {
            sc = " ";
            bool found = false;
            for(int i = sb.size() - 1; i >= 0; --i)
            {
                if(sb[i] != '9')
                {
                    sb = sb.substr(0, i)  + char(sb[i] + 1);
                    found = true;
                    break;
                }
            }
            if(found == false)
            {
                sb = " ";
                ++sa;
            }
        }
        if(!sc.empty() && sc == string(sc.size(), '0')) sc = " ";

        if(!tc.empty() && tc == string(tc.size(), '9'))
        {
            tc = " ";
            bool found = false;
            for(int i = tb.size() - 1; i >= 0; --i)
            {
                if(tb[i] != '9')
                {
                    tb = tb.substr(0, i) + char(tb[i] + 1);
                    found = true;
                    break;
                }
            }
            if(found == false)
            {
                tb = " ";
                ++ta;
            }
        }
        if(!tc.empty() && tc == string(tc.size(), '0')) tc = " ";

        cout<<sa<<" "<<ta<<" "<<sb<<" "<<tb<<" "<<sc<<" "<<tc<<endl;

        string s = sb, t = tb;
        for(int i = 0; i < 10; ++i)
        {
            s += sc;
            t += tc;
        }

        cout<<">"<<s<<"<"<<endl;
        cout<<">"<<t<<"<"<<endl;

        return sa == ta && s.substr(0, 10) == t.substr(0, 10);
    }
};

int main()
{
    Solution s;
    //cout<<s.isRationalEqual("0.(52)", "0.5(25)")<<endl;
    //cout<<s.isRationalEqual("0.1666(6)", "0.166(66)")<<endl;
    //cout<<s.isRationalEqual("0.9(9)", "1.")<<endl;
    //cout<<s.isRationalEqual("0.9(9)", "1")<<endl;
    //cout<<s.isRationalEqual("0.(0)", "0")<<endl;
    //cout<<s.isRationalEqual("1.9(0)", "1.8(9)")<<endl;
    cout<<s.isRationalEqual("0.08(9)", "0.09")<<endl;
}
