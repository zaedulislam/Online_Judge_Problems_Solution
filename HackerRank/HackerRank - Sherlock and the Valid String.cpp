// HackerRank - Sherlock and the Valid String.cpp

#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    
    int freq[30];
    int I, len = s.length();
    
    for(I = 0; I < 30; I++)
        freq[I] = 0;
    
    for(I = 0; I < len; I++)
        freq[s[I] - 'a']++;
    
    vector<int> vi;
    for(I = 0; I < 26; I++)
    {
        if(freq[I] > 0)
            vi.push_back(freq[I]);
    }
    
    sort(vi.begin(), vi.end());
    
    int cnt = 0;
    int x = vi[0];
    for(I = 1; I < vi.size(); I++)
    {
        if(vi[I] != x)
            cnt++;
    }
    
    if(cnt == 0)
        return "YES";
    if(cnt > 1)
        return "NO";
    else if(vi[vi.size() - 1] - 1 == x)
        return "YES";
    else
        return "NO";
    
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
