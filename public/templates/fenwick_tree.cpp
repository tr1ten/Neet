#include<bits/stdc++.h>
#include <vector>
typedef long long ll;
class BIT {
private:
    std::vector<int> nums;
    int LOG;
public:
    BIT(int n) {
    	LOG = (int)log2(n)+1;
        nums.resize((1ll<<LOG) + 1);
    }
    void update(int i, int val) {
        i += 1;
        while (i < nums.size()) {
            nums[i] += val;
            i += (i & (-i));
        }
    }
    int sum(int i) {
        int r = 0;
        // i += 1, not needed here since we need sum of rank less than i rank[0...i-1]
        while (i > 0) {
            r += nums[i];
            i -= (i & (-i));
        }
        return r;
    }
    // max index where sum A[0...ind] < x,return index of first number greator than or equal to x
    int lower(int x){
        ll pref = 0;
        int ind = 0;
        for(int i=LOG;i>=0;i--){
            if(nums[ind + (1ll<<i)] + pref<x){
                pref += nums[ind + (1ll<<i)];
                ind += 1ll<<i;
            }
        }
        return ind; // 0  based
    }
    
};

#include <cassert>

int main() {
    BIT bit(5);
    bit.update(0, 1);
    bit.update(1, 2);
    bit.update(2, 3);
    bit.update(3, 4);
    bit.update(4, 5);
    assert(bit.sum(0) == 0);
    assert(bit.sum(1) == 1);
    assert(bit.sum(2) == 3);
    assert(bit.sum(3) == 6);
    assert(bit.sum(4) == 10);
    assert(bit.sum(5) == 15);
    assert(bit.lower(1) == 1);
    assert(bit.lower(2) == 2);
    assert(bit.lower(3) == 2);
    return 0;
}