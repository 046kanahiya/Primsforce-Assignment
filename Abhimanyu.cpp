#include <bits/stdc++.h>
using namespace std;

// Number of enemies in Chakravyuha
int max_enemies = 11; 

// Power of Abhimanyu
int power;  

// Checking if Abhimanyu can cross the Chakravyuha
bool canCrossChakrvyuha(vector<int>& enemyPower, int initialPower, int skipsHave, int rechargeHave, int enemy, int behind) {
    // Checking If Abhimanyu successfully cross Chakravyuha
    if (enemy == max_enemies)
        return true;
    
    bool check = false;  

    // Checking If he is capable of recharging and his current power is less than any enemy
    if (rechargeHave > 0 && initialPower < power)
        check = check | canCrossChakrvyuha(enemyPower, power, skipsHave, rechargeHave - 1, enemy, behind);

    // Checking If he can capably handle the enemy coming from behind.
    if (initialPower >= behind) {
        initialPower -= behind;
        behind = 0;
    } else
        return false;

    // Checking If Abhimanyu can skip this enemy
    if (skipsHave > 0)
        check = check | canCrossChakrvyuha(enemyPower, initialPower, skipsHave - 1, rechargeHave, enemy + 1, behind); 

    // Checking If he can fight without the recharge or skip.
    if (initialPower >= enemyPower[enemy]) {
        
        // Checking for the position K3 and K7 
        if (enemy == 2 || enemy == 6)
            behind = enemyPower[enemy] / 2;

        check = check | canCrossChakrvyuha(enemyPower, initialPower - enemyPower[enemy], skipsHave, rechargeHave, enemy + 1, behind); 
    }

    return check;
}

int main() {
    vector<int> enemyPower(max_enemies); 

    cout << "Enter the Power of enemies :" << endl;
    for (int i = 0; i < max_enemies; i++)
        cin >> enemyPower[i];
    cout << "Enter the initial Power of Abhimanyu :" << endl;
    int skipsHave, rechargeHave;  
    cin >> power;
    cout << "Enter the number of skips Abhimanyu has:" << endl;
    cin >> skipsHave; // a: Total number of skips he has
    cout << "Enter the number of times Abhimanyu can recharge:" << endl;
    cin >> rechargeHave; // b: Number of times he can recharge himself
    
    
    // Assigning maximum skips and maximum recharges up to 11
    skipsHave = min(skipsHave, max_enemies);  
    rechargeHave = min(rechargeHave, max_enemies); 
    
    // Power of enemy attacking from behind
    int behind = 0; 

    if (canCrossChakrvyuha(enemyPower, power, skipsHave, rechargeHave, 0, behind))
        cout << "Yes, Abhimanyu can cross the Chakravyuha" << endl;
    else
        cout << "No, Abhimanyu cannot cross the Chakravyuha" << endl;

    return 0;
}

/* 
Test Case 1 (Pass):

enemyPower = {3, 5, 8, 7, 4, 6, 9, 2, 1, 5, 4}
power = 20
skipsHave = 3
rechargeHave = 1

Output:
Yes, Abhimanyu can cross the Chakravyuha

Test Case 2 (Fail):

enemyPower = {2, 8, 9, 6, 7, 3, 9, 4, 5, 10, 6}
power = 12
skipsHave = 1
rechargeHave = 1

Output:
No, Abhimanyu cannot cross the Chakravyuha
*/
