//Greedy
//TLE
//47 / 48 test cases passed.
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        int given = 0;
        vector<int> candies(n);

        int min_ele = *min_element(ratings.begin(), ratings.end());
                
        for(int i = 0; i < ratings.size(); ++i){
            if(ratings[i] == min_ele){
                candies[i] = 1;
                ++given;
            }
        }
        
        // for(const int& candy : candies){
        //     cout << candy << " ";
        // }
        // cout << endl;
        
        while(given < n){
            for(int i = 0; i < n; ++i){
                // cout << "i: " << i << endl;
                
                if(candies[i]) continue;
                
                int candy = 1;
                
                if(i == 0 || ratings[i] <= ratings[i-1]){
                    //don't need to consider left
                    // cout << "a" << endl;
                }else if(candies[i-1] != 0){
                    //it's left child is already given candy
                    candy = max(candy, candies[i-1]+1);
                    // cout << "b" << endl;
                }else{
                    //must wait unitl child i-1 is given candy
                    // cout << "c" << endl;
                    continue;
                }
                
                
                if(i == n-1 || ratings[i] <= ratings[i+1]){
                    //don't need to consider right
                    // cout << "d" << endl;
                }else if(candies[i+1] != 0){
                    //must consider right, and right is given candy
                    candy = max(candy, candies[i+1]+1);
                    // cout << "e" << endl;
                }else{
                    //must consider right, but right is not given candy
                    // cout << "f" << endl;
                    continue;
                }
                
                candies[i] = candy;
                ++given;
            }
        }
        
        // for(const int& candy : candies){
        //     cout << candy << " ";
        // }
        // cout << endl;
        
        return accumulate(candies.begin(), candies.end(), 0);
    }
};

//Approach 1: Brute Force
//TLE
//47 / 48 test cases passed.
//time: O(N^2), space: O(N)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        //give each child one candy at first time
        vector<int> candies(n, 1);
        
        bool stop = false;
        while(!stop){
            stop = true;
            for(int i = 0; i < n; ++i){
                if(i > 0 && ratings[i] > ratings[i-1]){
                    if(candies[i] <= candies[i-1]){
                        stop = false;
                        candies[i] = candies[i-1]+1;
                    }
                }
                if(i < n-1 && ratings[i] > ratings[i+1]){
                    if(candies[i] <= candies[i+1]){
                        stop = false;
                        candies[i] = candies[i+1]+1;
                    }
                }
            }   
        }
        
        return accumulate(candies.begin(), candies.end(), 0);
    }
};

//Approach 2: Using two arrays
//Runtime: 40 ms, faster than 85.56% of C++ online submissions for Candy.
//Memory Usage: 18.6 MB, less than 5.93% of C++ online submissions for Candy.
//time: O(N), space: O(N)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        vector<int> left2right(n, 1);
        vector<int> right2left(n, 1);
        
        for(int i = 1; i < n; ++i){
            if(ratings[i] > ratings[i-1]){
                /*
                left2right[i-1] is update before left2right[i],
                so left2right[i-1] >= left2right[i],
                so we don't need to write:
                left2right[i] = max(left2right[i], left2right[i-1]+1);
                */
                left2right[i] = left2right[i-1]+1;
            }
        }
        
        for(int i = n-2; i >= 0; --i){
            if(ratings[i] > ratings[i+1]){
                right2left[i] = right2left[i+1]+1;
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; ++i){
            ans += max(left2right[i], right2left[i]);
        }
        
        return ans;
    }
};

//Approach 3: Using one array
//Runtime: 40 ms, faster than 85.56% of C++ online submissions for Candy.
//Memory Usage: 18.1 MB, less than 5.93% of C++ online submissions for Candy.
//time: O(N), space: O(N)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        vector<int> candies(n, 1);
        
        for(int i = 1; i < n; ++i){
            if(ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1]+1;
            }
        }
        
        for(int i = n-2; i >= 0; --i){
            if(ratings[i] > ratings[i+1]){
                //here candies[i] could > candies[i+1], so we need the max(..., ...) here
                candies[i] = max(candies[i], candies[i+1]+1);
            }
        }
        
        return accumulate(candies.begin(), candies.end(), 0);
    }
};

//Approach 4: Single Pass Approach with Constant Space, slope based
//not understand
//Runtime: 32 ms, faster than 98.43% of C++ online submissions for Candy.
//Memory Usage: 17.5 MB, less than 5.93% of C++ online submissions for Candy.
//time: O(N), space: O(1)
class Solution {
public:
    int count(int n){
        return n * (n+1) / 2;
    }
    
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        if(n <= 1) return n;
        
        int candies = 0;
        int up = 0, down = 0;
        int old_slope = 0, new_slope;
        
        for(int i = 1; i < n; ++i){
            if(ratings[i] > ratings[i-1]){
                new_slope = 1;
            }else if(ratings[i] == ratings[i-1]){
                new_slope = 0;
            }else{
                new_slope = -1;
            }
            
            if((old_slope >0 && new_slope == 0) ||
              (old_slope < 0 && new_slope >= 0)){
                candies += count(up) + count(down) + max(up, down);
                up = down = 0;
            }
            
            if(new_slope > 0){
                ++up;
            }else if(new_slope < 0){
                ++down;
            }else{
                //new_slope == 0
                ++candies;
            }
            
            old_slope = new_slope;
        }
        
        candies += count(up) + count(down) + max(up, down) + 1;
        
        return candies;
    }
};

//slope-based
//https://leetcode.com/problems/candy/discuss/135698/Simple-solution-with-one-pass-using-O(1)-space
//Runtime: 40 ms, faster than 85.56% of C++ online submissions for Candy.
//Memory Usage: 17.5 MB, less than 5.93% of C++ online submissions for Candy.
//time: O(N), space: O(1)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        if(n <= 1) return n;
        
        //up: how many transitions are going up
        int up = 0;
        //down: how many transitions are going down
        int down = 0;
        //record the mountain peak
        int peak = 0;
        
        //candy for 0th child?
        int ans = 1;
        
        for(int i = 1; i < n; ++i){
            if(ratings[i] > ratings[i-1]){
                ++up;
                peak = up;
                down = 0;
                //the mountain's foot must be >= 1
                ans += (1+up);
            }else if(ratings[i] == ratings[i-1]){
                up = down = peak = 0;
                ans += 1;
            }else{
                //ratings[i] < ratings[i-1]
                ++down;
                up = 0;
                /*
                consider [0,1,20,9,8,7],
                when we are at 9, down = 1,
                when we are at 8, down = 2,
                when we are at 7, down = 3
                
                actually 9 should have 3 candy,
                8 should have 2 candy,
                7 should have 1 candy,
                
                we program as this because the sum are equivalent
                */
                ans += down;
                if(peak < down){
                    /*
                    peak must >= down,
                    if it's smaller, we need to make it higher
                    */
                    ++ans;
                }
            }
        }
        
        return ans;
    }
};
