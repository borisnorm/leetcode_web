class Solution {
public:
    int brokenCalc(int startValue, int target) {
        
        int steps = 0;

        //逆向操作
        while (startValue < target)
        {
            if (target % 2 == 1)
            {
               target++;
            }
            else
            {
               target /= 2;
            }
            steps++;
        }

        // startValue >= target

        steps += (startValue - target);

        return steps;
    }
};