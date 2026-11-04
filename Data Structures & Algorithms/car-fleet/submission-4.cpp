class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int,int,greater<int>> m;

        for(int i = 0; i < position.size(); i++) {
            m[position[i]] = speed[i];
        }

        double minIt = 0, fleets = 0;
        for(auto &[pos,speed] : m) {
            double iteractions =  (double)(target - pos) / speed;
            if(iteractions > minIt) {
                fleets++;
                minIt = iteractions;
            }
        }

        return fleets;
    }
};
