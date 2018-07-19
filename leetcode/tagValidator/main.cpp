#include "header.h"

class Solution {
public:
    bool isValid(string code) {
        while(code.find("<![CDATA[") != string::npos)
        {
            int pos = code.find("<![CDATA[");
            int endPos = code.substr(pos).find("]]>");
            if(endPos == string::npos) return false;
            code.replace(pos, endPos + 3, endPos + 3, ' ');
        }

        return validateClosedTag(code, 0, code.size() - 1);
    }

    bool validateTagName(const auto& tagName)
    {
        if(tagName.size() < 1 || tagName.size() > 9) return false;
        for(char c : tagName)
            if(!isupper(c)) return false;
        return true;
    }

    bool validateClosedTag(string& code, int startIdx, int endIdx)
    {
        if(code[startIdx] != '<') return false;
        int i = startIdx + 1;
        while(i <= endIdx && code[i] != '>') ++i;
        if(i > endIdx) return false;

        const auto& tagName = code.substr(startIdx + 1, i - startIdx - 1);
        if(!validateTagName(tagName)) return false;

        if(endIdx - i < tagName.size() + 3 ||
            code.substr(endIdx - tagName.size() - 2, tagName.size() + 3) != "</" + tagName + ">") return false;

        return validateTagContent(code, i + 1, endIdx - tagName.size() - 3);
    }

    bool validateTagContent(string& code, int startIdx, int endIdx)
    {
        if(startIdx > endIdx) return true;

        for(int i = startIdx; i <= endIdx;)
        {
            if(code[i] != '<')
            {
                ++i;
                continue;
            }

            if(i + 1 > endIdx || code[i + 1] == '/') return false;

            if(code[i + 1] != '/')
            {
                int j = i + 1;
                while(j <= endIdx && code[j] != '>') ++j;
                if(j > endIdx) return false;
                const auto& tagName = code.substr(i + 1, j - i - 1);
                if(!validateTagName(tagName)) return false;

                string startTag = "<" + tagName + ">";
                string endTag = "</" + tagName + ">";
                int cnt = 1;
                const auto& t = code.substr(j, endIdx - j + 1);

                int fromIdx = 0;
                while(cnt != 0)
                {
                    int pos1 = t.find(startTag, fromIdx);
                    int pos2 = t.find(endTag, fromIdx);

                    if(pos1 == string::npos && pos2 == string::npos) break;
                    if(pos1 == string::npos)
                    {
                        fromIdx = pos2 + 1;
                        --cnt;
                    }
                    else if(pos2 == string::npos)
                    {
                        fromIdx = pos1 + 1;
                        ++cnt;
                    }
                    else
                    {
                        fromIdx = min(pos1, pos2) + 1;
                        cnt += pos1 < pos2 ? 1 : -1;
                    }
                }

                if(cnt != 0) return false;

                if(!validateClosedTag(code, i, j + fromIdx + tagName.size() + 1)) return false;
                i = j + fromIdx + tagName.size() + 2;
            }
        }
        return true;
    }
};


int main()
{
    Solution s;
    cout<<s.isValid("<DIV>This is the first line <![CDATA[<div>]]></DIV>")<<endl;
    cout<<s.isValid("<A> <A><![CDATA[</A>]]>  </A> </A>")<<endl;
    cout<<s.isValid("<A> <Z> <Z> </Z> </Z> </A>")<<endl;
}
