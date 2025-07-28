#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

vector <pair<int, int>> msearch(vector <pair<int, int>> vec, int t){

    for(int i = 0; i < vec.size(); i++){
        if(vec[i].first == t){
            vec[i].second += 1;
            return vec;
        }
    }
    vec.push_back({t, 1});
    return vec;
}

vector <pair<int, int>> del(vector <pair<int, int>> vec, int t){
    int tar = 0;
    for(int i = 1; i < vec.size(); i++){
        if(vec[tar].second > vec[i].second) tar = i;
    }
    vector <pair<int, int>> temp;
    for(int i = 0; i < vec.size(); i++){
        if(i != tar){
            temp.push_back({vec[i].first, vec[i].second});
        }
    }
    temp.push_back({t, 1});
    return temp;
}

vector <pair<int, int>> search(vector <pair<int, int>> vec, int t){

    for(int i = 0; i < vec.size(); i++){
        if(vec[i].first == t){
            vec[i].second += 1;
            return vec;
        }
    }
    return del(vec, t);
}

int main(){
    cin >> n >> m;
    vector <pair<int, int>> vec;
    
    for(int i = 0; i < m; i++){
        int t;
        cin >> t;
        if(vec.size() < n){
            vec = msearch(vec, t);
        }else{
            vec = search(vec, t);
        }
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i].first << ' ';
    }
    return 0;
}