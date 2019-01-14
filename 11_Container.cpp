class Solution {
public:
    int maxArea(vector<int>& height) {
        int len=height.size();
        int max=0;
        int temp=0;
        int s=0;//start
        int e=len-1;//end
        int heights=0;
        int heighte=0;

        while(s<e){
            heights=height[s];
            heighte=height[e];
            if(heights<heighte){
                temp=computeArea(heights,(e-s));
                max=max>temp?max:temp;
                s++;
            }
            else{
                temp=computeArea(heighte,(e-s));
                max=max>temp?max:temp;
                e--;
            }
        }
        return max;
    }
    int computeArea(int x, int y){
        return x*y;
    }
};