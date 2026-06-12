class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int, int>> pair;
    for(int i = 0; i < position.size(); i++){
        pair.push_back({position[i], speed[i]});
    }
    sort(pair.rbegin(), pair.rend());

    stack<double> time;
    
    double fastestcartime = (double)(target - pair[0].first) / pair[0].second;
    time.push((double)(target - pair[0].first) / pair[0].second);
    for(int i = 1; i < position.size(); i++){
        
        time.push((double)(target - pair[i].first) / pair[i].second);
        
        if(time.size() > 1 && time.top() <= fastestcartime){
            time.pop();
        }
        else fastestcartime = time.top();
    }



    return time.size();
        
    }
};
