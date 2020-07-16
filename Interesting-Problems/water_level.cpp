#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#define log(x) { std::cout<<x<<" "; }
#define br() { std::cout<<std::endl; }

int n = 7;
int curr;
int inp[7][7] = {
    {494,  88,  89, 770, 984, 726, 507},
    {340, 959, 220, 301, 639, 280, 290},
    {666, 906, 632, 824, 127, 505, 787},
    {673, 499, 843, 172, 193, 613, 154},
    {544, 211, 124,  60, 575, 572, 389},
    {635, 170, 174, 946, 593, 314, 300},
    {620, 167, 931, 780, 416, 954, 275},
};

char out[7][7];

bool checkEdge(std::pair<int, int> p, int n) {
    int f = p.first;
    int s = p.second;

    return (f==0 || f==n || s==0 || s==n)?true:false;
}

std::pair<int, int> getNext(std::pair<int, int> p, std::pair<int, int> prev) {
    std::vector<std::pair<int,int>> sides = {};
    sides.push_back(std::make_pair(p.first-1,p.second));
    sides.push_back(std::make_pair(p.first,p.second+1));
    sides.push_back(std::make_pair(p.first+1,p.second));
    sides.push_back(std::make_pair(p.first,p.second-1));

    int min = 9999;
    std::pair<int,int> toReturn;
    bool isSet = false;
    do {
        for(std::pair<int, int> x: sides) {
            if(curr>=inp[x.first][x.second] && out[x.first][x.second]!='W') {
                if(inp[x.first][x.second]<min) {
                    toReturn=x;
                    min = inp[x.first][x.second];
                    isSet = true;
                }
            };
        }

        if(isSet) return toReturn;
        curr++;
    } while(true);
}

void printArray() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            log(out[i][j]);
        }
        br();
    }
}

int main() {
    int mid = (n/2);
    std::pair<int,int> p = std::make_pair(mid, mid);
    std::pair<int,int> prev = std::make_pair(0, 0);
    curr = inp[p.first][p.second];

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            out[i][j] = '.';
        }
    }

    while(!checkEdge(p, n-1)) {
        out[p.first][p.second] = 'W';
        std::pair<int,int> temp = getNext(p, prev);
        prev = p;
        p = temp;
    } 
    out[p.first][p.second] = 'W';
    printArray();

    return 0;
}