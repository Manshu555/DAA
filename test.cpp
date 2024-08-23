#include <iostream>
using namespace std;

bool canBobWin(int N, int X, int Y, string S) {
    int aliceX = 0, aliceY = 0;

    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') aliceX++;
        else if (S[i] == 'L') aliceX--;
        else if (S[i] == 'U') aliceY++;
        else if (S[i] == 'D') aliceY--;
        
        if (aliceX == X && aliceY == Y) return true;
        if (X < aliceX) X++;
        else if (X > aliceX) X--;
        
        if (Y < aliceY) Y++;
        else if (Y > aliceY) Y--;
    }
    return (X == aliceX && Y == aliceY);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, X, Y;
        cin >> N >> X >> Y;
        string S;
        cin >> S;
        
        if (canBobWin(N, X, Y, S)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
