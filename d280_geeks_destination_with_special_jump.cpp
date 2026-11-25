/*
Geek starts at position 0 on the positive X-axis and needs to reach or pass position d on the positive X-axis.
Geek normally follows a repeating movement pattern:
Move forward by a units, taking a seconds.
Move backward by b units, taking b seconds.
Geek also has a special jump that moves him exactly j units forward in 1 second. He can use it at any time, even
in the middle of a forward or backward movement, and the journey ends immediately after the jump.
Given five integers a, b, d, l, and r. For every integer j in the range [l, r], find the minimum time required for
Geek to reach or pass position d. He may either use the special jump or reach the destination using normal movement
alone, whichever takes less time.
Return the sum of the minimum times for all jump lengths from l to r. Since, the answer can be large, return modulo 109 + 7. 
Note: Each jump length is considered independently.

Examples:
Input: a = 2, b = 1, d = 5, l = 3, r = 4
Output: 5
Explanation: 
For j = 3, Geek moves 2 units forward, then takes a jump of 3 units to reach the destination. The minimum time required is 3 seconds.
For j = 4, Geek moves 1 unit forward, then takes a jump of 4 units to reach the destination. The minimum time required is 2 seconds.
Total sum for the range [l, r] = 3 + 2 = 5.

Input: a = 4, b = 2, d = 8, l = 2, r = 4
Output: 26
Explanation:
For j = 2, Geek moves 4 units forward, then 2 units backward. She then moves 4 units forward again and takes a jump of 2 units to
reach the destination. The minimum time required is 11 seconds.
For j = 3, Geek moves 4 units forward, then 2 units backward. She then moves 3 units forward and takes a jump of 3 units to reach
the destination. The minimum time required is 10 seconds.
For j = 4, Geek moves 4 units forward, then takes a jump of 4 units to reach the destination. The minimum time required is 5 seconds.
Total sum for the range [l, r] = 11 + 10 + 5 = 26.

Constraints:
a ≤ 10
0 < b < a
a < d ≤ 108
0 < l ≤ r
r < d
*/
#include<iostream>
using namespace std;







// TC : O(1) SC : O(1)
class Solution {
public:
    const long long MOD = 1000000007;
    long long solve(int a, int b, int c, int d) {
        int remaining = d - c;
    
        if (remaining <= 0)
            return 1;
    
        if (remaining <= a)
            return remaining + 1;
    
        int net = a - b;
        long long distance = remaining - a;
        long long cycles = (distance + net - 1) / net;
    
        return remaining + 2LL * b * cycles + 1;
    }
    
    long long summ(int a, int b, long long t) {
        long long first = a + 2;
        long long cycleTime = a + b;
    
        if (t < first)
            return 0;
    
        long long count = (t - first) / cycleTime + 1;
        long long last = first + (count - 1) * cycleTime;
    
        long long term1 = (b % MOD) * (count % MOD) % MOD;
        term1 = term1 * ((first + last) % MOD) % MOD;
    
        long long term2 = (count % MOD) * (2LL * b - 1) % MOD;
        term2 = term2 * (2LL * b) % MOD;
        term2 = term2 * ((MOD + 1) / 2) % MOD;
    
        return (term1 + term2) % MOD;
    }
    
    long long prefix(int a, int b, long long t) {
        long long total = (t % MOD) * ((t + 1) % MOD) % MOD;
        total = total * ((MOD + 1) / 2) % MOD;
    
        return (total - summ(a, b, t) + MOD) % MOD;
    }
    
    int minTime(int a, int b, int d, int l, int r) {
        long long t1 = solve(a, b, l, d);
        long long t2 = solve(a, b, r + 1, d);
        
        return (prefix(a, b, t1) - prefix(a, b, t2) + MOD) % MOD;
    }
};