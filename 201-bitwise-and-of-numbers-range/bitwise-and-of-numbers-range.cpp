class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;

        //控制条件是 left < right, shift 的时候 由于 left 与 right 在 前向 bit 中 0, 1的不同造成 left < right, 知道 公共前缀被发现 才停下里
        // 找公共前缀
        while (left < right)
        {
           left  >>= 1;
           right >>= 1;
           shift++;
        }
        // 恢复位数
        return left << shift;
    }
};