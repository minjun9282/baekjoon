#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;;
    cin >> str;
    // . 빈칸 -> 7개
    // @ 로봇 있는 빈칸 -> 1개
    // # 박스 있는 빈칸 -> 1개
    // ! 박스 놓아야 하는 칸 -> 1개
    // 로봇: 인접한 빈칸으로 이동, 박스를 밀고 박스가 있던 칸으로 이동
    int robot_idx, box_idx, target_idx;
    robot_idx = str.find('@');
    box_idx = str.find('#');
    target_idx = str.find('!');
    if (robot_idx < box_idx && box_idx < target_idx){
        cout << target_idx - robot_idx - 1 << '\n';
    }
    else if (robot_idx > box_idx && box_idx > target_idx){
        cout << robot_idx - target_idx - 1;
    }
    else{
        cout << -1 << '\n';
    }
    
    
    
    return 0;
}