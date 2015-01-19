#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

class Rectangle {
    public:
        int lx, ly, w, h;
        Rectangle() {
            lx = ly = w = h = -1;
        }
        Rectangle(int _lx, int _ly, int _w, int _h) {
            lx = _lx;
            ly = _ly;
            w = _w;
            h = _h;
        }

        bool isOverlapp(Rectangle other) {
            bool xOverlap = ((lx <= other.lx) && (lx + w >= other.lx)) || ((lx <= other.lx + other.w) && (lx + w >= other.lx + other.w));
            bool yOverlap = ((ly <= other.ly) && (ly + h >= other.ly)) || ((ly <= other.ly + other.h) && (ly + h >= other.ly + other.h));
            return (xOverlap && yOverlap);
        }
        
        
        Rectangle findOverlap(Rectangle other) {
            //Assuming that the rectangles overlap
            vector <int> vp;
            vp.push_back(lx);
            vp.push_back(lx + w);
            vp.push_back(other.lx);
            vp.push_back(other.lx + other.w);
            
            sort(vp.begin(), vp.end());
            int resX = vp[1];
            int resW = vp[2] - vp[1];
            
            vp.clear();
            
            vp.push_back(ly);
            vp.push_back(ly + h);
            vp.push_back(other.ly);
            vp.push_back(other.ly + other.h);
            sort(vp.begin(), vp.end());
            
            int resY = vp[1];
            int resH = vp[2] - vp[1];
            
            return Rectangle(resX, resY, resW, resH);
        }
        
        void print() {
            printf("lx=%d, ly=%d, w=%d, h=%d\n", lx, ly, w, h);
        }
};

int main(int argc, char **atgv) {
    Rectangle a;
    Rectangle b;
    a.lx = atoi(atgv[1]);
    a.ly = atoi(atgv[2]);
    a.w = atoi(atgv[3]);
    a.h = atoi(atgv[4]);

    b.lx = atoi(atgv[5]);
    b.ly = atoi(atgv[6]);
    b.w = atoi(atgv[7]);
    b.h = atoi(atgv[8]);

    bool res = a.isOverlapp(b) || b.isOverlapp(a);
    printf(res ? "Overlap\n": "No Overlapp\n");
    
    if (res) {
        Rectangle r = a.findOverlap(b);
        r.print();
    }
    return 0;
}
