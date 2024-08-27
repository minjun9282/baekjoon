#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    string s;
    cin >> s;

    int idx_four, idx_five;
    while (true) {
        idx_four = s.find("PS4");
        idx_five = s.find("PS5");

        if (idx_four == string::npos && idx_five == string::npos) {
            break;
        }

        if (idx_four != string::npos && (idx_five == string::npos || idx_four < idx_five)) {
            if (idx_four + 2 < s.length()) {
                s.erase(idx_four + 2, 1);
            }
        } 
        else if (idx_five != string::npos && (idx_four == string::npos || idx_five <= idx_four)) {
            if (idx_five + 2 < s.length()) {
                s.erase(idx_five + 2, 1);
            }
        }
    }
    cout << s << '\n';
    
    return 0;
}
