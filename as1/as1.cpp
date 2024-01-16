#include <iostream>
using namespace std;

int main() {

    /* Inititalizing variables */

    int rm = 0;
    int gm = 0;
    int bm = 0;
    int quantity = 0;
    int input = 0;
    int total = 0;

    /* Loop for the user to add/remive/print marbles or exit the program */
    /* If the user inputs 4 the program ends */
    while (input != 4) {
        cout << "Type 1 to add marbles, 2 to remove marbles, 3 to print the marbles, 4 to end the program" << endl;
        cin >> input;

        /* Adding marbles */
        if (input == 1) {
            cout << "How many red marbles do you want to add?" << endl;
            cin >> quantity;
            rm = rm + quantity;

            cout << "How many green marbles do you want to add?" << endl;
            cin >> quantity;
            gm = gm + quantity;

            cout << "How many blue marbles do you want to add?" << endl;
            cin >> quantity;
            bm = bm + quantity;

            total = rm + gm + bm;
        }

        /* Removing marbles */
        else if (input == 2) {
            cout << "How many red marbles do you want to remove?" << endl;
            cin >> quantity;
            rm = rm - quantity;

            cout << "How many green marbles do you want to remove?" << endl;
            cin >> quantity;
            gm = gm - quantity;

            cout << "How many blue marbles do you want to remove?" << endl;
            cin >> quantity;
            bm = bm - quantity;

            total = rm + gm + bm;
        }

        /* Printing marbles */
        else if (input == 3) {
            cout << "The number of red marbles is: " << rm << endl;
            cout << "The number of green marbles is: " << gm << endl;
            cout << "The number of blue marbles is: " << bm << endl;
            cout << "The total number of marbles is: " << total << endl;
        }

        /* Making sure input is between 1-4*/
        else {
            cout << "Please enter a number from 1 to 4 " << endl;
        }
    }

    return 0;
}
