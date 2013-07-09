//Not ideal solution
//but has the idea and passes all test cases

class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

       if(n == 0)
            return 1;
        
        if(x == 1)
        {
            return 1;
        }

        if(x == -1)
        {
            return n%2==1?-1:1;
        }
        
        if(n < 0)
            return 1.0/pow(x,-n);
            
        if(n == 1)
            return x;
            
        vector<int> powers;
        vector<int> power_values;
        vector<double> values;
        const int N = 100;
        for(int i = 0; i < N; ++i)
        {
            powers.push_back(i);
        }
        
        power_values.push_back(1);
        power_values.push_back(2);
        for(int i = 2; i < N; ++i)
        {
            power_values.push_back(power_values[i-1]*2);
        }
        
        values.push_back(x);
        for(int i = 1; i < N; ++i)
        {
            values.push_back(values[i-1]*values[i-1]);
        }
        
        double temp = 1;
        while(n != 1 && n != 0 )
        {
            int x = log2(n);
            n = n - power_values[x];
            temp *= values[x];
        }
        if(n == 1)
            return temp * x;
        
        return temp;
    }
};
