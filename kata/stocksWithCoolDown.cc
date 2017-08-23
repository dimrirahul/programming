//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
#include <iostream>
#include <vector>

using namespace std;

using VI = vector<int>;
const int INVALID_POS = -1;
struct Segment {
    Segment(const VI& pricesInput) : prices(pricesInput)  {
        reset();
    }
    void reset() {
        beg = end = INVALID_POS;
    }
    bool hasBegun() const { return beg != INVALID_POS; }
    bool hasEnd() const { return end != INVALID_POS; }
    int getCost(int b, int e) const {
        return prices[e-1] - prices[b];
    }
    int getSegmentCost() const {
        return getCost(beg, end);
    }
    bool isOverlapping(const Segment& o) const {
        return (end == o.beg || beg == o.end );
    }
    void trimBeg() { beg++; }
    void trimEnd() { end--; }

    void trimSegment(Segment& o) {
        int trimLeftCost = getCost(beg, end-1) + o.getSegmentCost();
        int trimRightCost = getSegmentCost() + o.getCost(o.beg + 1, o.end);
        if (trimLeftCost > trimRightCost) {
            trimEnd();
        } else {
            o.trimBeg();
        }
    }
    int beg, end;
    const VI& prices;
};

class Solution {
    public:
        int maxProfit(VI& prices) {
            if (prices.empty()) return 0;
            Segment seg(prices);
            vector<Segment> vs;
            int pos = 0;
            while (createSegment(prices, pos, seg)) {
                if (!vs.empty()) {
                    auto it = vs.rbegin();
                    if (it->isOverlapping(seg))
                        it->trimSegment(seg);
                }
                vs.push_back(seg);
                pos = seg.end;
                seg.reset();
            }
            int res = 0;
            for (auto it : vs) {
                res += it.getSegmentCost();
            }
            return res;
        }

        bool createSegment(const VI& p, int startPos, Segment& seg) {
            int pos = startPos;
            auto isNonDecreasing = [p](int pos)->bool {
                return p[pos] <= p[pos+1];
            };
            auto isStrictlyIncreasing = [p](int pos)->bool {
                return p[pos] < p[pos+1];
            };
            for (; pos < p.size() - 1; pos++) {
                if (seg.hasBegun()) {
                    if (!isNonDecreasing(pos)) {
                        seg.end = pos + 1;
                        break;
                    }
                } else {
                    if (isStrictlyIncreasing(pos)) {
                        seg.beg = pos;
                    }
                }
            }
            if (pos == p.size() -1  && seg.hasBegun() && !seg.hasEnd()) seg.end = p.size();
            if (seg.hasEnd()) {
                return true;
            }
            return false;
        }
};

int main() {
    Solution s;
    VI prices{1, 2, 3, 0, 2};
    cout << s.maxProfit(prices);
    return 0;
}
