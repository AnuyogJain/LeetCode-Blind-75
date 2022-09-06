class Solution {
public:
    int getSum(int x, int y) {
        unsigned int a = x;
        unsigned int b = y;
        while (b != 0) {
            int temp = a;
            
            a ^= b;
            b &= temp;
            b <<= 1;
        }
        
        return a;
    }
};
