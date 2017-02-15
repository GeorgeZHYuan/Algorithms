/*
   CCC 2011 S5: Switch
   solution by Sumudu Fernando

   We use a dynamic programming approach; this solution is O(N).

   First, we note that any solution can be organized into blocks,
   where a block is some set of lights which all turn off at once.
   While the order that we turn off the blocks may be important, we can
   at least assume that we handle the blocks one at a time.  It should
   also be obvious that in an optimal solution, any block must contain at
   least one light which was originally on.  Note also that a block cannot
   be longer than 7 lights.

   We shall regard the originally on lights in terms of connected groups,
   since these will always turn off together.  Considering two such groups,
   if their span (distance from the left of the leftmost group to the right
   of the rightmost one) is 4 or 5, we can always turn off all groups in that
   span by filling in the blanks.  Similarly, for spans of 6 and 7, it is
   possible to clear the span as a block as long the middle lights (3rd & 4th for
   span 6, or 4th for span 7) are off.  So, if we have such a "clearable" span of
   length s with l lights already on, it will take s-l switches to clear it as
   a block.  If the span is less than 4, we may simply take s as 4 (which means
   we'll turn on lights outside the span).  Importantly, we ignore the effect
   of such lights on groups outside the block.

   Now, we can imagine an O(N^3) algorithm, where for any two groups L and R,
   we try all "clearable" blocks inside to clear first (there are O(N) of them),
   then recurse on the left and right.

   However, it turns out that we can simply consider the groups from left to right
   (yielding a linear time algorithm).
   The reason this works is that we are not assuming anything about lights outside
   the current block, which means that we are effectively indifferent to the order
   in which blocks are cleared.  This does mean that we will consider some impossible
   cases, such as:
    10001, where we presume the two groups are cleared as separate blocks
   However, such cases will always take more switches than a larger block (in the above,
   clearing both groups in a block of span 5) so they don't affect the correctness of
   the algorithm (which is only concerned with the minimum number of switches).

   In summary, we consider groups from left to right, and try all possibilities for the
   rightmost group in the leftmost block (which must end within 7 spaces), dynamically
   solving the subproblem for the groups after that.  In the program below I've written
   the dynamic program in a bottom-up fashion (starting on the right and working backwards).
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int INF = 1000000;

int main() {
    int K; cin >> K;

    bool lights[1000];
    for (int i = 0; i < K; ++i) {
        char c; cin >> c;
        lights[i] = (c == '1');
    }

    // Find connected groups of on lights
    vector<PII> lGroups;
    lGroups.push_back(PII(0,0));

    for (int i = 0; i < K; ++i) {
        if (lights[i]) {
            if (lGroups.back().second == 0) lGroups.back().first = lGroups.back().second = i;
            ++lGroups.back().second;
        }
        else if (lGroups.back().second != 0) lGroups.push_back(PII(0,0));
    }

    // We'll have an extra entry if there were off lights at the end
    if (lGroups.back().second == 0) lGroups.pop_back();

    for (int i = 0; i < lGroups.size(); i++) {
        cout << lGroups[i].first << " "  << lGroups[i].second << endl;
    }

    int N = lGroups.size(), minSwitch[1001] = {0};
    for (int i = N-1; i >= 0; --i) {
        minSwitch[i] = INF;

        int numL = 0;

        // we try every group as the rightmost in the block until we get too far away
        for (int j = i; (j < N) && (lGroups[j].second - lGroups[i].first <= 7); ++j) {
            numL += lGroups[j].second - lGroups[j].first;
            int len = max(4, lGroups[j].second - lGroups[i].first);
            int t = len - numL;

            // for spans of 6 and 7 there are certain configurations that cannot be cleared as a block
            if ((len == 6) && lights[lGroups[i].first + 2] && lights[lGroups[i].first + 3]) t = INF;
            else if ((len == 7) && lights[lGroups[i].first + 3]) t = INF;
            minSwitch[i] = min(minSwitch[i], t + minSwitch[j+1]);
        }
    }
    for (int  i = 0; i < N; i++) cout << minSwitch[i] << " ";
}
