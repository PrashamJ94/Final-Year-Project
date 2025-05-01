#include<bits/stdc++.h>
using namespace std;

int Bob_sMaxStrength(vector<pair<int, char>> pieces) {
    int pScore = 0, sScore = 0, pMaxScore = 0, sMaxScore = 0;
    for(auto piece : pieces) {
        if(piece.second == 'B') {
            pScore += piece.first;
            sScore += piece.first;
        }
    }
    pMaxScore = pScore;
    sMaxScore = sScore;
    for(auto piece : pieces) {
        if(piece.second == 'A') {
            pScore += piece.first;
            if(pScore > pMaxScore) {
                pMaxScore = pScore;
            }
        } else {
            pScore -= piece.first;
        }
    }
    for(int i = pieces.size() - 1; i >= 0; i--) {
        if(pieces[i].second == 'A') {
            sScore += pieces[i].first;
            if(sScore > sMaxScore) {
                sMaxScore = sScore;
            }
        } else {
            sScore -= pieces[i].first;
        }
    }
    if(pMaxScore > sMaxScore) {
        return pMaxScore;
    }
    return sMaxScore;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, char>> pieces(n);
    for(int i = 0; i < n; i++) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    cout << Bob_sMaxStrength(pieces) << "\n";
    return 0;
} //End of Code
