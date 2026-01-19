class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        

        int w1 = abs(ax1-ax2);
        int h1 = abs(ay1-ay2);
        int area_1 = w1 * h1;

        int w2 = abs(bx1-bx2);
        int h2 = abs(by1-by2);
        int area_2 = w2 * h2;

        int w_overlap = max(0, min(ax2, bx2) - max(ax1, bx1));
        int h_overlap = max(0, min(ay2, by2) - max(ay1, by1));

        int area_overlap = w_overlap * h_overlap;

        int area = area_1 + area_2 - area_overlap;

        return area; 

    }
};