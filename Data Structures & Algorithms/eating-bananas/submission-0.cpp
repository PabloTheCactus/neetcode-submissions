class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        long long currenthours = 0;
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());// розіменовуємо бо max_element вертає ітератор
        while (low <= high)
        {
            currenthours = 0;
            int mid = low + (high - low) / 2;
            for (auto i : piles) {
                currenthours += ceil(static_cast<double>(i) / mid);// ceil заукруглює значення до більшого
            }
            if (currenthours > h) {
                low = mid + 1;
            }
            else if (currenthours <= h) {
                high = mid - 1;
            }

        }
        return low;
    }
};