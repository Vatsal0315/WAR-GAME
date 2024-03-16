#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;


class Card
{
    private:
        char suit;
        char rank;
    public:
        Card()
        {
            rank = ' ';
            suit = ' ';
        }
        Card(char r, char s)
        {
            rank = r;
            suit = s;
        };

        void display()
        {
            if(rank == 'T') 
            {
                cout << "10" << suit << " ";
            }
            else
            {
                cout << rank << suit << " ";
            }
        }
        int compare(Card w)
        {
            if ((rank == 'J' || rank == 'Q' || rank == 'K') && (w.rank == 'T'))
         {
             return 1;
         }
             else if ((rank == 'T') && (w.rank == 'J' || w.rank == 'Q' || w.rank == 'K'))
         {
             return -1;
         }
            else if (rank > w.rank) 
        {
                return 1;
        }   else if (rank < w.rank) 
        {
                return -1;
        }   else 
        {
                return 0;
        }
        }
};

class Deck
{
    private:
        Card cards[52];
        int card;
    public:
    Deck() {
        char suits[] = {'C', 'S', 'D', 'H'};
        char ranks[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

        int index = 0;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 13; ++j) {
                cards[index++] = Card(ranks[j], suits[i]);
            }
        }
        card = 0;
    }

    Card deal() 
    {
         if (isEmpty()) 
         {   
             throw 'E';
         }
         else
         {
             card++;
             return cards[card];
         }
    }


        void display()  
        {
            for (int i = 0; i < 52; i++) 
            {
            cards[i].display();
            if ((i + 1) % 13 == 0) 
            {
                cout << "\n";
            }
            }
        }
        void shuffle()
        {
    
            srand(time(0));
    
            for(int i = 0; i < 52; i++)
        {
            int x = rand() % (i + 1); 
        
            Card a = cards[i];
            cards[i] = cards[x];
            cards[x] = a;
        }

        card = -1 ; 
        }

        bool isEmpty() const
            {
                return card >= 52;
            }
};

int main() 
{
    // 1) A new deck will be created
    Deck deck;

    // 2)	The program will ask for the names of the 2 players.
    string firstPlayer, secondPlayer;
    int numGames;
    cout << "Enter the name of the first player: ";
    cin >> firstPlayer;
    cout << "Enter the name of the second player: ";
    cin >> secondPlayer;
    cout << "How many games will they play? ";
    cin >> numGames;

    // 3)	The unshuffled deck will be displayed on the screen
    cout << "Original deck: \n";
    deck.display();

    // 4)	The deck will be shuffled.
    deck.shuffle();

    //5)	The shuffled deck will display on the screen.
    cout << "\nShuffled deck: \n";
    deck.display();

    int firstPlayerWins = 0, secondPlayerWins = 0, Gametie = 0;
    
     //6)	26 games will be played, announcing the winner of each game. Ties are possible as well.

    try
    {
        for (int i = 0; i < numGames; i++) 
    {
        
        Card playercard1 = deck.deal();
        Card playercard2 = deck.deal();
        cout << "\nGame " << i + 1 << ":\n";
        cout << "------------" << "\n";

        cout << firstPlayer << " => ";
        playercard1.display();
        cout << "\n" << secondPlayer << " => ";
        playercard2.display();
        
 

        int score = playercard1.compare(playercard2);
        if (score == 1) {
            cout << "\n" << "\t" << firstPlayer << " => Winner\n";
            firstPlayerWins++;
        } else if (score == -1) {
            cout << "\n" << "\t" << secondPlayer << " => Winner \n";
            secondPlayerWins++;
        } else {
            cout << "\nTie game\n";
            Gametie++;
        }
    }

    }
    catch(char e)
    {
        if (e == 'E')
        {
            cout << "\nError - Deck is empty." << endl;
            
        }
        
    }
// 7)	After all 26 games are played the program will print the statistics.
cout << "\n" << "------Final Stats-------" << "\n";
cout << "\t" << firstPlayer << " vs. " << secondPlayer<< "\n";
cout << "Wins"<< "\t" << firstPlayerWins << "          "<< secondPlayerWins << "\n";
cout << "Losses"<< "\t" << secondPlayerWins << "          " << firstPlayerWins << "\n";
cout << "Ties  "<<"\t" << Gametie << "           " << Gametie << "\n";

return 0;
}
