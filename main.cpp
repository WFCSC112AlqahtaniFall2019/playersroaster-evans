#include <iostream>
#include <vector>
using namespace std;

struct Player {
  string playerName;
  int jerseyNumber;
  int playerRating;
};

void initialize(vector<Player>& v, int numberOfPlayers) {

    for (int i = 0; i < numberOfPlayers; ++i) {

        cout << "Enter player " << i + 1 << "'s name:" << endl;
        cin >> v.at(i).playerName;

        cout << "Enter player " << i + 1 << "'s jersey number:" << endl;
        cin >> v.at(i).jerseyNumber;

        cout << "Enter player " << i + 1 << "'s rating:" << endl;
        cin >> v.at(i).playerRating;
        cout << endl;
    }

}

void output(const vector<Player>& v, int numberOfPlayers) {

    cout << "ROSTER" << endl;
    for (int i = 0; i < numberOfPlayers; ++i) {
        cout << "Player " << i + 1 << " -- Name: " << v.at(i).playerName << " -- Jersey number: "
             << v.at(i).jerseyNumber << ", Rating: " << v.at(i).playerRating << endl;
    }
    cout << endl;


        cout << "MENU" << endl;
        cout << "a - Add player" << endl;
        cout << "d - Remove player" << endl;
        cout << "u - Update player rating" << endl;
        cout << "r - Output players above a rating" << endl;
        cout << "o - Output roster" << endl;
        cout << "q - Quit" << endl << endl;

        cout << "Choose an option:" << endl;


}

void addPlayer(vector<Player>& v, int numberOfPlayers) {

    cout << "Enter a new player's name: " << endl;
    cin >> v.at(numberOfPlayers).playerName;

    cout << "Enter a new player's jersey number:" << endl;
    cin >> v.at(numberOfPlayers).jerseyNumber;


    cout << "Enter the player's rating:" << endl;
    cin >> v.at(numberOfPlayers).playerRating;
    cout << endl;
}
void deletePlayer(vector<Player>& v, int playerNumber) {
    //find the player using her/his jersey number
    for (int i = 0; i < v.size(); ++i) {
        if (playerNumber == v.at(i).jerseyNumber) {
            playerNumber = i;
        }

        for (i = 0; i < v.size() - 1; ++i) {
            if (i >= playerNumber - 1) {
                v.at(i).playerName = v.at(i + 1).playerName;
                v.at(i).jerseyNumber = v.at(i + 1).jerseyNumber;
                v.at(i).playerRating = v.at(i + 1).playerRating;
            }
        }
        v.pop_back();
        cout << endl;
    }
}
void updateRating(vector<Player>& v, int playerNumber, int rating){

    for (int i = 0; i < v.size(); ++i) {
        if (v.at(i).jerseyNumber == playerNumber) {
            v.at(i).playerRating = rating;
        }
    }
    cout << endl;
    }

void aboveRating(const vector<Player>& v, int rating) {

    cout << "ABOVE " << rating << endl;
    for (int i = 0; i < v.size(); ++i) {
        if (v.at(i).playerRating > rating) {
            cout << "Player " << i + 1 << " -- Jersey number: "
                 << v.at(i).jerseyNumber << ", Rating: "
                 << v.at(i).playerRating << endl;
        }
    }
    cout << endl;

}

int main() {

    vector<string> Names(5);
    vector<int> jerseyNums(5);
    vector<int> ratingNums(5);
    vector<Player> playerList(200);

    unsigned int i;
    string playerName;
    int playerJersy;
    int playerRating;
    char menuOp;
    int numberOfPlayers;

    //initialize the roasters

    cout << "How many players on the team?" << endl;
    cin >> numberOfPlayers;

    initialize(playerList, numberOfPlayers);

    output(playerList, numberOfPlayers);

        //Add
       while (menuOp != 'q') {

           cin >> menuOp;

           if (menuOp == 'a') {
               addPlayer(playerList, numberOfPlayers);
               numberOfPlayers++;
           }

               //Delete
           else if (menuOp == 'd') {
               cout << "Enter a jersey number:" << endl;
               cin >> playerJersy;

               deletePlayer(playerList, playerJersy);
               numberOfPlayers--;
           }

               //Update
           else if (menuOp == 'u') {
               cout << "Enter a jersey number:" << endl;
               cin >> playerJersy;

               cout << "Enter a new rating for player:" << endl;
               cin >> playerRating;

               updateRating(playerList, playerJersy, playerRating);
           }

               // > Rating
           else if (menuOp == 'r') {
               cout << "Enter a rating:" << endl;
               cin >> playerRating;
               cout << endl;

               aboveRating(playerList, playerRating);

           }

               //output
           else if (menuOp == 'o') {
               output(playerList, numberOfPlayers);
           }

           else if (menuOp == 'q') {
               return 0;
           }
       }

    return 0;
}
