#include <iostream>
#include <vector>
using namespace std;

string minWindow(string S, string T) {
    vector<int> chars(128, 0);
    vector<bool> flag(128, false);

    //先统计T中的字符情况
    for(int i = 0; i < T.size(); ++i){
        cout << "T[" << i << "]:" << T[i] << int(T[i]) << " ";
        flag[T[i]] = true;
        ++chars[T[i]];
    }
    cout << endl;

    cout << "chars: ";
    for(auto i : chars){
        cout << i << " ";
    }
    cout << endl;

    cout << "flag: ";
    for(auto i : flag){
        cout << i << " ";
    }
    cout << endl;

    // 移动滑动窗口，不断更改统计数据
    int cnt = 0, l = 0, min_l = 0, min_size = S.size() + 1;
    for(int r = 0; r < S.size(); ++r){
        cout << "S[" << r << "]:" << S[r] << int(S[r]) << " -> ";
        if(flag[S[r]]){
            cout << "chars[" << S[r] << "]-1: " << chars[S[r]]-1 << " -> "; 
            if(--chars[S[r]] >= 0){
                ++cnt;
                cout << "cnt: " << cnt << " -> ";
            }

            // 若目前滑动窗口已包含T中全部字符，
            // 则尝试将l右移，在不影响结果的情况下获得最短子字符串
            while(cnt == T.size()){
                if(r-l+1 < min_size){
                    min_l = l;
                    min_size = r-l+1;
                    cout << "min_l: " << min_l << ", min_size: " << min_size << " -> ";
                }
                cout << "chars[" << S[l] << "]+1: " << chars[S[l]]+1 << " -> "; 
                if(flag[S[l]] && ++chars[S[l]] > 0){
                    --cnt;
                    cout << "cnt: " << cnt << " -> ";
                }
                ++l;
            }

        }
        cout << endl;
    }

    return "";
}

int main(){
    string S = "ADOBECODEBANC";
    string T = "ABC";
    minWindow(S, T);
    return 0;
}