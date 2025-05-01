#include <stdio.h>

int Bob_sMaxStrength(int n, int pieces[n][2]) {
    int pScore = 0, sScore = 0, pMaxScore = 0, sMaxScore = 0;
    for(int i = 0; i < n; i++){
        if(pieces[i][1] == 'B'){
            pScore += pieces[i][0];
            pMaxScore += pieces[i][0];
        }
    }
    sMaxScore = pMaxScore;
    for(int i = 0; i < n; i++){
        if(pieces[i][1] == 'A'){
            pScore += pieces[i][0];
            if(pScore > pMaxScore){
                pMaxScore = pScore;
            }
    }
        else{
            pScore -= pieces[i][0];
        }
    }
    for(int i = n - 1; i >= 0; i--){
        if(pieces[i][1] == 'A'){
            sScore += pieces[i][0];
            if(sScore > sMaxScore){
                sMaxScore = sScore;
            }
        }
        else{
            sScore -= pieces[i][0];
        }
    }
    if(pMaxScore > sMaxScore){
        return pMaxScore;
    }
    else{
        return sMaxScore;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int pieces[n][2];
    for(int i = 0; i < n; i++){
        scanf("%d %c", &pieces[i][0], &pieces[i][1]);
    }
    printf("%d\n", Bob_sMaxStrength(n, pieces));
    return 0;
}

// End of Code.
