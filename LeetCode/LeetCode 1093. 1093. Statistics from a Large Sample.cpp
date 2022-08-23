

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        vector<double> ans;
        double minimum = -1;
        double maximum = -1;
        
        double mean = 0.00;
        double mode = 0;
        int totalElementCount = 0;
        int len = count.size();
        
        for(int i = 0; i < len; i++){
            //cout << "i: " << i << endl;
            if(minimum == -1){
                minimum = count[i];
            }
            if(count[i] != 0){
                maximum = i;
                mode = max(mode, i * 1.00);
                totalElementCount += count[i];
            }
                
        }
        cout << "Total: " << totalElementCount << endl;
        // int sum = 0;
        for(int i = 0; i < len; i++){
            // sum += (count[i] * i);
            if(count[i] != 0){
                // double x = (count[i] *  / totalElementCount);
                mean += (((count[i] * 1.00) / totalElementCount) * (i * 1.00));
                // cout << "mean: " << mean << endl;
                // cout << "x: " << x << endl;
                if()
            }
           
        }
        
        // cout << "sum: " << sum << ", avg: " << (sum / totalElementCount) << endl;
        
        cout << "minimum: " << minimum << ", maximum: " << maximum  << ", mean: " << mean << ", mode: " << mode << endl;
        
        return ans;
    }
};
