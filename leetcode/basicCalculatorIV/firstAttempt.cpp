#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <list>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <memory>
#include <iterator>

using namespace std;

class Solution {
public:
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        std::unordered_map<std::string, int> m;
        for(int i = 0; i < evalvars.size(); ++i)
        {
            m[evalvars[i]] = evalints[i];
        }

        const auto& r = impl(expression, m, 0, expression.size());
        vector<string> res;
        for(const auto& e : r)
        {
            std::string temp = (e.sign == -1 ? "-" : "") + std::to_string(e.val);
            if(e.type == 0)
            {
                res.emplace_back(temp);
            }
            else
            {
                for(const auto& s : e.str)
                {
                    temp += "*" + s;
                }
                res.emplace_back(temp);
            }
        }

        return res;
    }

    struct Exp{
        Exp(int t, int si, int v, const std::string& s = std::string()):
            type(t), sign(si), val(v)
        {
            if(!s.empty()) str.insert(s);
        }

        bool operator<(const Exp& r) const
        {
            if(type == r.type)
            {
                if(type == 1)
                {
                    if(str.size() == r.str.size()) return str < r.str;
                    return str.size() > r.str.size();
                }
                return false;
            }

            return type > r.type;
        }

        std::string toString()
        {
            std::stringstream ss;
            ss <<"type: " << type <<" sign: " << sign << " val: " << val << " vars: ";
            for(auto i : str)
            {
                ss << i << ", ";
            }

            return ss.str();
        }

        int type; // 0: num 1: var
        int sign;
        int val;
        std::multiset<string> str;
    };

    std::vector<Exp> impl(const std::string& exp, std::unordered_map<std::string, int>& m, int startIdx, int endIdx)
    {
        //std::cout<<exp.substr(startIdx, endIdx-startIdx)<<std::endl;
        std::vector<std::vector<Exp>> v;
        int sign = 1;
        bool multiply = false;

        for(int i = startIdx; i < endIdx;)
        {
            char c = exp[i];
            if(c == ' ')
            {
                ++i;
                continue;
            }
            else if(std::isalpha(c))
            {
                int j = i;
                while(exp[j] != ' ' && j < endIdx) ++j;
                const std::string& var = exp.substr(i, j - i);
                if(multiply)
                {
                    auto& last = v.back();
                    if(m.find(var) != m.end())
                    {
                        int value = m[var];
                        for(auto& e : last)
                        {
                            e.sign *= sign;
                            e.val *= value;
                        }
                    }
                    else
                    {
                        for(auto& e : last)
                        {
                            e.sign *= sign;
                            e.str.insert(var);
                            e.type = 1;
                        }
                    }
                }
                else
                {
                    if(m.find(var) != m.end())
                    {
                        v.push_back({Exp(0, sign, m[var], "")});
                    }
                    else
                    {
                        v.push_back({Exp(1, sign, 1, var)});
                    }
                }

                i = j;
            }
            else if(std::isdigit(c))
            {
                int j = i;
                while(exp[j] != ' ' && j < endIdx) ++j;
                int val = std::stoi(exp.substr(i, j - i));
                if(multiply)
                {
                    auto& last = v.back();
                    for(auto& e : last)
                    {
                        e.sign *= sign;
                        e.val *= val;
                    }
                }
                else
                {
                    v.push_back({Exp(0, sign, val, "")});
                }
                i = j;
            }
            else if(c == '+')
            {
                sign = 1;
                multiply = false;
                ++i;
            }
            else if(c == '-')
            {
                sign = -1;
                multiply = false;
                ++i;
            }
            else if(c == '*')
            {
                multiply = true;
                ++i;
            }
            else if(c == '(')
            {
                int cnt = 1;
                int j = i + 1;
                while(cnt != 0)
                {
                    if(exp[j] == '(') ++cnt;
                    if(exp[j] == ')') --cnt;
                    ++j;
                }
                //std::cout<<"before"<<std::endl;
                auto t = impl(exp, m, i + 1, j - 1);
                //std::cout<<"t size "<<t.size()<<std::endl;
                if(sign == -1)
                {
                    for(auto& e : t)
                    {
                        e.sign *= -1;
                    }
                }

                if(multiply)
                {
                    std::vector<Exp> result;
                    multiple(v.back(), t, result);

                    v.pop_back();
                    if(!result.empty()) v.emplace_back(result);
                }
                else
                {
                    v.emplace_back(t);
                }

                i = j;
            }
        }

        std::vector<Exp> res;
        for(auto& vv : v)
        {
            for(auto& e : vv)
            {
                res.emplace_back(e);
            }
        }

        sortAndCompute(res);

        return res;
    }

    void multiple(const vector<Exp>& a, const vector<Exp>& b, vector<Exp>& res)
    {
        for(int i = 0; i < a.size(); ++i)
        {
            for(int j = 0; j < b.size(); ++j)
            {
                int type = 1;
                if(a[i].type == 0 && b[j].type ==0) type = 0;
                int val = a[i].sign * a[i].val * b[j].sign * b[j].val;
                if(val != 0)
                {
                    int sign = val / std::abs(val);
                    val = std::abs(val);

                    Exp e(type, sign, val);

                    std::multiset<string> s;
                    if(!a[i].str.empty() || !b[j].str.empty())
                    {
                        for(const auto& e : a[i].str)
                        {
                            s.insert(e);
                        }

                        for(const auto& e : b[j].str)
                        {
                            s.insert(e);
                        }
                    }

                    e.str = s;

                    res.push_back(e);
                }
            }
        }

        sortAndCompute(res);
    }

    void sortAndCompute(vector<Exp>& res)
    {
        std::sort(res.begin(), res.end());

        for(int i = 1; i < res.size();)
        {
            if(res[i].type == res[i - 1].type)
            {
                if(res[i].type == 0 || res[i].str == res[i - 1].str)
                {
                    int temp = res[i].sign * res[i].val + res[i - 1].sign * res[i- 1].val;
                    if(temp != 0)
                    {
                        res[i - 1].val = std::abs(temp);
                        res[i - 1].sign = temp < 0 ? -1 : 1;
                        res.erase(res.begin() + i);
                    }
                    else
                    {
                        res.erase(res.begin() + i - 1);
                        res.erase(res.begin() + i - 1);
                        --i;
                    }
                    continue;
                }
            }

            ++i;
        }
    }
};

int main() {
    Solution s;
    /*vector<string> a{"e"};
    vector<int> b{1};
    const auto& r = s.basicCalculatorIV("e + 8 - a + 5", a, b);
    vector<string> a{"e", "temperature"};
    vector<int> b{1, 12};
    const auto& r = s.basicCalculatorIV("e - 8 + temperature - pressure", a, b);*/
    vector<string> a;
    vector<int> b;
    //const auto& r = s.basicCalculatorIV("(e + 8) * (e - 8)", a, b);
    //const auto& r = s.basicCalculatorIV("7 - 7", a, b);
    const auto& r = s.basicCalculatorIV("a * b * c + b * a * c * 4", a, b);
    //const auto& r = s.basicCalculatorIV("((a - b) * (b - c) + (c - a)) * ((a - b) + (b - c) * (c - a))", a, b);
    //vector<string> a{"a","d","e","f","h","i","m","n","o","q","r","s","t","u","v","aa","ab","ac","ae","af","ag","ah","ai","am","an","ap","aq","at","aw","ax","ba","bd","bj","bm","bn","bo","bq","bs","bu","bv","bw","bx","by","bz","cc","ce","cg","ch","ci","cj","cl","cm","cn","co","cp","cr","cs","ct","cv","cy","da","db","dc","de","df","dg","di","dn","do","dp","dr","du","dw","dy","dz","ea","eb","ec","ee","ei","ej","el","em","eo","ep","eq","es","ew","ex","ey","fb","ff","fg","fi","fj","fl","fm","fo","fq","fs","fv","fw","ga","gc","gd","gg","gj","gm","gp","gs","gw","gx","gy","hb","hd","hf","hh","hi","hj","hl","hm","ho","hs","hu","hv","hx","ic","ie","ig","ih","ii","ij","in","io","ir","is","iu","iv","iw","iy","iz","ja","jc","jd","je","ji","jj","jk","jl","jm","jo","jq","jr","jt","jw","kb","kc","ke","kf","kj","kk","kl","kn","ko","kp","kr","ks","ku","kw","lb","le","lg","li","lj","ll","ln","lr","ls","lt","lu","lw","lx","ly","ma","mb","me","mf","mi","mm","mn","ms","mt","mu","mv","my","mz","na","nb","ne","nf","ng","nk","nl","nn","no","np","nr","ns","nt","nu","nx","nz","oa","oc","od","oe","of","og","oh","oi","ok","ol","os","ot","ou","ov","ox","pa","pb","pe","pg","ph","pj","pl","pm","pr","ps","pt","pu","pw","py","pz","qa","qb","qc","qg","qh","ql","qn","qq","qr","qs","qt","qv","qx","ra","rb","rc","re","rf","ri","rk","rl","rm","rp","rr","rv","rw","rx","ry","rz","sa","sb","se","sf","sh","si","sn","so","sr","sv","ta","tc","td","tf","ti","tm","tn","to","tp","tr","tt","tu","tw","tx","tz","ua","uc","ue","uf","ug","uj","ul","um","un","uo","up","ur","uz","ve","vg","vh","vp","vs","vu","vw","wb","wd","wf","wi","wj","wn","wp","wq","wr","wu","wx","wy","wz","xb","xc","xd","xe","xh","xi","xl","xo","xw","xx","ye","yh","yi","yj","yl","ym","ys","yt","yu","yx","yz","zb","zd","zg","zh","zj","zk","zl","zp","zr","zs","zu","zw","zx","zz"};
    //vector<int> b{0,3,4,5,7,8,12,13,14,16,17,18,19,20,21,31,32,33,35,36,37,38,39,43,44,46,0,3,6,7,15,18,24,27,28,29,31,33,35,36,37,38,39,40,1,3,5,6,7,8,10,11,12,13,14,16,17,18,20,23,30,31,32,34,35,36,38,43,44,45,0,3,5,7,8,14,15,16,18,22,23,25,26,28,29,30,32,36,37,38,46,3,4,6,7,9,10,12,14,16,19,20,29,31,32,35,38,41,44,0,4,5,6,14,16,18,20,21,22,24,25,27,31,33,34,36,46,1,3,4,5,6,10,11,14,15,17,18,19,21,22,28,30,31,32,36,37,38,39,40,42,44,45,0,3,13,14,16,17,21,22,23,25,26,27,29,30,32,34,44,0,2,4,5,7,9,13,14,15,16,18,19,20,27,28,31,32,35,39,40,45,46,0,1,4,5,11,12,15,16,17,21,22,24,25,26,28,29,30,31,34,36,42,44,45,46,0,1,2,3,5,6,13,14,15,16,18,26,27,30,32,33,35,37,38,43,44,45,46,1,3,4,10,11,12,16,17,21,23,26,27,28,29,31,33,41,42,43,45,46,2,4,5,6,9,11,15,16,17,18,19,25,26,29,30,32,33,38,39,42,46,9,11,12,14,17,21,22,23,24,26,28,29,31,32,34,40,42,44,45,46,2,4,5,6,7,8,10,18,28,30,31,39,42,44,46,9,11,13,16,17,21,23,24,25,28,31,32,33,40,41,42,43,46,0,3,6,14,15,27,30,31,32,34,35,41,42,43,46,1,8,10,13,14,16,17,18,22,24,25,27,29,30,32};
    //const auto& r = s.basicCalculatorIV("((az * 10 + op * 11 - nx) * (bl * ie + ed * 3 + cf) + nu * tz - (wz - 14 - 44 + 33 * fp)) * (4 + 17 - wj)", a, b);
    //vector<string> a{"a","d","e","f","h","i","m","n","o","q","r","s","t","u","v","aa","ab","ac","ae","af","ag","ah","ai","am","an","ap","aq","at","aw","ax","ba","bd","bj","bm","bn","bo","bq","bs","bu","bv","bw","bx","by","bz","cc","ce","cg","ch","ci","cj","cl","cm","cn","co","cp","cr","cs","ct","cv","cy","da","db","dc","de","df","dg","di","dn","do","dp","dr","du","dw","dy","dz","ea","eb","ec","ee","ei","ej","el","em","eo","ep","eq","es","ew","ex","ey","fb","ff","fg","fi","fj","fl","fm","fo","fq","fs","fv","fw","ga","gc","gd","gg","gj","gm","gp","gs","gw","gx","gy","hb","hd","hf","hh","hi","hj","hl","hm","ho","hs","hu","hv","hx","ic","ie","ig","ih","ii","ij","in","io","ir","is","iu","iv","iw","iy","iz","ja","jc","jd","je","ji","jj","jk","jl","jm","jo","jq","jr","jt","jw","kb","kc","ke","kf","kj","kk","kl","kn","ko","kp","kr","ks","ku","kw","lb","le","lg","li","lj","ll","ln","lr","ls","lt","lu","lw","lx","ly","ma","mb","me","mf","mi","mm","mn","ms","mt","mu","mv","my","mz","na","nb","ne","nf","ng","nk","nl","nn","no","np","nr","ns","nt","nu","nx","nz","oa","oc","od","oe","of","og","oh","oi","ok","ol","os","ot","ou","ov","ox","pa","pb","pe","pg","ph","pj","pl","pm","pr","ps","pt","pu","pw","py","pz","qa","qb","qc","qg","qh","ql","qn","qq","qr","qs","qt","qv","qx","ra","rb","rc","re","rf","ri","rk","rl","rm","rp","rr","rv","rw","rx","ry","rz","sa","sb","se","sf","sh","si","sn","so","sr","sv","ta","tc","td","tf","ti","tm","tn","to","tp","tr","tt","tu","tw","tx","tz","ua","uc","ue","uf","ug","uj","ul","um","un","uo","up","ur","uz","ve","vg","vh","vp","vs","vu","vw","wb","wd","wf","wi","wj","wn","wp","wq","wr","wu","wx","wy","wz","xb","xc","xd","xe","xh","xi","xl","xo","xw","xx","ye","yh","yi","yj","yl","ym","ys","yt","yu","yx","yz","zb","zd","zg","zh","zj","zk","zl","zp","zr","zs","zu","zw","zx","zz"};
    //vector<int> b{0,3,4,5,7,8,12,13,14,16,17,18,19,20,21,31,32,33,35,36,37,38,39,43,44,46,0,3,6,7,15,18,24,27,28,29,31,33,35,36,37,38,39,40,1,3,5,6,7,8,10,11,12,13,14,16,17,18,20,23,30,31,32,34,35,36,38,43,44,45,0,3,5,7,8,14,15,16,18,22,23,25,26,28,29,30,32,36,37,38,46,3,4,6,7,9,10,12,14,16,19,20,29,31,32,35,38,41,44,0,4,5,6,14,16,18,20,21,22,24,25,27,31,33,34,36,46,1,3,4,5,6,10,11,14,15,17,18,19,21,22,28,30,31,32,36,37,38,39,40,42,44,45,0,3,13,14,16,17,21,22,23,25,26,27,29,30,32,34,44,0,2,4,5,7,9,13,14,15,16,18,19,20,27,28,31,32,35,39,40,45,46,0,1,4,5,11,12,15,16,17,21,22,24,25,26,28,29,30,31,34,36,42,44,45,46,0,1,2,3,5,6,13,14,15,16,18,26,27,30,32,33,35,37,38,43,44,45,46,1,3,4,10,11,12,16,17,21,23,26,27,28,29,31,33,41,42,43,45,46,2,4,5,6,9,11,15,16,17,18,19,25,26,29,30,32,33,38,39,42,46,9,11,12,14,17,21,22,23,24,26,28,29,31,32,34,40,42,44,45,46,2,4,5,6,7,8,10,18,28,30,31,39,42,44,46,9,11,13,16,17,21,23,24,25,28,31,32,33,40,41,42,43,46,0,3,6,14,15,27,30,31,32,34,35,41,42,43,46,1,8,10,13,14,16,17,18,22,24,25,27,29,30,32};
    //const auto& r = s.basicCalculatorIV("((el + e * qe) - (nu + 30) + (10 + sh - 31)) - ((35 * jo - yi) * (16 * 16 + ts * dc) * (mk - zl) - (wu - qa * xm + 14 + 30) + (eg + xr * fi + 11 * d)) * ((yx - 24 - qm - 24 + dn) - (oe - vb + jw) + ed + (ma - 22)) - (7 - (lr - 13 + 19 + gb) - dh) - ((it - ap) + (27 - bo - ai - zg) * sl)", a, b);
    for(auto i : r)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
