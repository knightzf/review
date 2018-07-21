#include "header.h"

struct Exp
{
    Exp(int v) : val(v)
    {
    }

    Exp(int v, const auto& param) : val(v)
    {
        params.insert(param);
    }

    int val;
    multiset<string> params;

    string debug()
    {
        stringstream ss;
        ss << val;
        for(const auto& s : params)
            ss <<" "<< s;
        return ss.str();
    }

    bool operator<(const Exp& rhs) const
    {
        if(params.size() > rhs.params.size()) return true;
        if(params.size() == rhs.params.size()) return params < rhs.params;
        return false;
    }
};

class Solution {
private:
    std::unordered_map<std::string, int> m;
public:
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        m.clear();
        for(int i = 0; i < evalvars.size(); ++i)
        {
            m[evalvars[i]] = evalints[i];
        }

        const auto& r = impl(expression, 0, expression.size());
        vector<string> res;
        for(const auto& exp : r)
        {
            if(exp.val == 0) continue;
            string t = to_string(exp.val);
            for(const auto& str : exp.params)
                t += "*" + str;
            res.emplace_back(t);
        }
        return res;
    }

    vector<Exp> impl(const string& expression, int startIdx, int endIdx)
    {
        vector<vector<Exp>> res;
        string opers;
        for(int i = startIdx; i < endIdx;)
        {
            if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
            {
                opers += expression[i];
                ++i;
                continue;
            }

            if(expression[i] == '(')
            {
                int j = i + 1;
                int cnt = 1;
                while(j < endIdx && cnt != 0)
                {
                    if(expression[j] == '(') ++cnt;
                    else if(expression[j] == ')') --cnt;
                    ++j;
                }
                res.emplace_back(impl(expression, i + 1, j - 1));
                i = j;
            }
            else if(isalpha(expression[i]))
            {
                int j = i + 1;
                while(j < endIdx && isalpha(expression[j])) ++j;
                const auto& param = expression.substr(i, j - i);
                res.emplace_back(m.count(param) ? vector<Exp>{Exp(m[param])} : vector<Exp>{Exp(1, param)});
                i = j;
            }
            else if(isdigit(expression[i]))
            {
                int j = i + 1;
                while(j < endIdx && isdigit(expression[j])) ++j;
                res.emplace_back(vector<Exp>{Exp(stoi(expression.substr(i, j - i)))});
                i = j;
            }
            else ++i;

            if(!opers.empty())
            {
                if(opers[0] == '*' && res.size() == 2)
                {
                    calc(res, 0, 1, '*');
                    opers.clear();
                    res.pop_back();
                }
                else if(opers.size() == 2 && res.size() == 3)
                {
                    if(opers[1] == '*') calc(res, 1, 2, '*');
                    else {
                        calc(res, 0, 1, opers[0]);
                        opers[0] = opers[1];
                        res[1] = res[2];
                    }
                    opers.pop_back();
                    res.pop_back();
                    /*for(auto& r : res)
                    {
                        cout<<r[0].debug()<<" | ";
                    }
                    cout<<endl;*/
                }
            }
        }

        if(res.size() == 2) calc(res, 0, 1, opers[0]);
        return res[0];
    }

    void calc(vector<vector<Exp>>& v, int first, int second, char oper)
    {
        if(oper == '*') return multiply(v, first, second);
        else if(oper == '-') {
            for_each(v[second].begin(), v[second].end(), [](auto& exp){
                        exp.val *= -1;
                     });
        }
        add(v, first, second);
    }

    void multiply(vector<vector<Exp>>& v, int first, int second)
    {
        vector<Exp> res;
        for(int i = 0; i < v[first].size(); ++i)
        {
            for(int j = 0; j < v[second].size(); ++j)
            {
                Exp t(v[first][i].val * v[second][j].val);
                if(t.val == 0) continue;
                t.params = v[first][i].params;
                t.params.insert(v[second][j].params.begin(), v[second][j].params.end());
                res.emplace_back(t);
            }
        }
        v[first] = res;
        cleanup(v[first]);
    }

    void add(vector<vector<Exp>>& v, int first, int second)
    {
        v[first].insert(v[first].end(), v[second].begin(), v[second].end());
        cleanup(v[first]);
    }

    void cleanup(vector<Exp>& v)
    {
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size();)
        {
            int j = i + 1;
            while(j < v.size() && v[j].params == v[i].params)
            {
                v[i].val += v[j].val;
                v.erase(v.begin() + j);
            }
            i = j;
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
    //const auto& r = s.basicCalculatorIV("a * b * c + b * a * c * 4", a, b);
    const auto& r = s.basicCalculatorIV("a * b - b * a", a, b);
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
