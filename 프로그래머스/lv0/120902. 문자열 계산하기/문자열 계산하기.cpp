#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    vector<string> words;
    stringstream sstream(my_string);
    string word;
     while(getline(sstream, word, ' '))
    {
        words.push_back(word);
    }
    answer += stoi(words[0]);
    for(int i = 1; i < words.size(); i += 2){
        if(words[i] == "+"){
            answer += stoi(words[i + 1]);
        }
        else{
            answer -= stoi(words[i + 1]);
        }
    }
    return answer;
}