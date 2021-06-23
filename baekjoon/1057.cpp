#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, kim, lim;
    cin >> N >> kim >> lim;
    int round = 0;
    while(true){
        if (kim < lim){
            if((kim + 1 == lim) && (lim % 2 == 0)){
                round += 1;
                break;
            }
            else{
                if(kim % 2 == 0){
                    kim = kim / 2;
                }
                else{
                    kim = kim / 2 + 1;
                }
                if(lim % 2 == 0){
                    lim = lim / 2;
                }
                else{
                    lim = lim / 2 + 1;
                }
                round += 1;
            }
        }
        else{
            if((lim + 1 == kim) && (kim % 2 == 0)){
                round += 1;
                break;
            }
            else{
                if(kim % 2 == 0){
                    kim = kim / 2;
                }
                else{
                    kim = kim / 2 + 1;
                }
                if(lim % 2 == 0){
                    lim = lim / 2;
                }
                else{
                    lim = lim / 2 + 1;
                }
                round += 1;
            }
        }
    }
    cout << round << '\n';

    return 0;
}