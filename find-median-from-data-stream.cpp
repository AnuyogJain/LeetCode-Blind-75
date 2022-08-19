class MedianFinder {
public:
    //two heaps, small is max heap and large is min heap
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        
        //make sure every num in small is <= every num in large
        if (!small.empty() && !large.empty() && (small.top() > large.top())) {
            int temp = small.top();
            small.pop();
            large.push(temp);
        }
        
        //make sure size of both heaps have difference of < 1
        if (small.size() > large.size() + 1) {
            int temp = small.top();
            small.pop();
            large.push(temp);
        }
        if (large.size() > small.size() + 1) {
            int temp = large.top();
            large.pop();
            small.push(temp);
        }
    }
    
    double findMedian() {
        //if even size
        if (small.size() > large.size()) {
            return small.top();
        }
        else if (large.size() > small.size()) {
            return large.top();
        }
        
        //if odd size
        double ans = double(small.top() + large.top()) / 2;
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
