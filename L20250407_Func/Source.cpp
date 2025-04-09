#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <conio.h>

#define MAX_CARD_COUNT		52
using namespace std;

enum PlayerNum
{
	Player1 = 0,
	Player2,
	Player3,
	Player4,
	MaxPlayerNum,
};
enum CardType
{
	Spade = 0,
	Diamond,
	Heart,
	Clover,
	MaxCardNum,
};
class Card
{
public:
	CardType MyCardType;
	int MyCardNum;
	int MyCardScore;
	string CardPattern[4] = { "¢¼", "¡ß", "¢¾", "¢À" };
	Card(CardType _CardType, int _CardNum)
	{
		MyCardType = _CardType;
		MyCardNum = _CardNum;
		MyCardScore = 0;
	}
	string CardPrint(bool _Visible = true)
	{
		string CardNum;
		switch (MyCardNum)
		{
			case 0:
				CardNum = "A";
				break;
			case 11:
				CardNum = "J";
				break;
			case 12:
				CardNum = "Q";
				break;
			case 13:
				CardNum = "K";
				break;
			default:
				CardNum = to_string(MyCardNum);
				break;
		}
		string Result;
		if (_Visible == true)
		{
			Result = CardPattern[MyCardType] + " " + CardNum;
		}
		else
		{
			Result = "? ?";
		}
		return Result;
	}
	int ScoreCal()
	{
		switch (MyCardNum)
		{
			case 11:
				MyCardScore = 10;
				break;
			case 12:
				MyCardScore = 10;
				break;
			case 13:
				MyCardScore = 10;
				break;
			default:
				MyCardScore = MyCardNum + 1;
				break;
		}
		return MyCardScore;
	}
};
class Deck
{
public:
	vector<Card> MyCards;
	void Initialize()
	{
		for (int CardTypeNum = 0; CardTypeNum < MaxCardNum; CardTypeNum++)
		{
			for (int CardNum = 0; CardNum < MAX_CARD_COUNT / MaxCardNum; CardNum++)
			{
				Card NewCard((CardType)CardTypeNum, CardNum);
				MyCards.push_back(NewCard);
			}
		}
	}
	void ShowDeckList()
	{
		for (int i = 0; i < MAX_CARD_COUNT; i++)
		{
			cout << MyCards[i].CardPrint() << endl;
		}
	}
};
class Player
{
public:
	PlayerNum MyPlayerNum;
	vector<Card> MyHand;
	int MyScore = 0;
	bool IsBust()
	{
		if (MyScore > 21)
		{
			return true;
		}
		return false;
	}
	void PrintMyHand(bool _Visible = true)
	{
		for (int i = 0; i < MyHand.size(); i++)
		{
			cout << MyHand[i].CardPrint(_Visible) + ", ";
		}
		cout << endl;
	}
	int GetMyScore()
	{
		for (int i = 0; i < MyHand.size(); i++)
		{
			MyScore += MyHand[i].ScoreCal();
		}
		return MyScore;
	}
	void PlayMyTurn()
	{
		cout << to_string(MyPlayerNum) << endl;
		cout << "hit";
	}
};
class Dealer : public Player
{
public:
	Deck MyDeck;
	PlayerNum PlayerTurn = (PlayerNum)0;
	void GetNewDeck()
	{
		MyDeck = Deck();
		MyDeck.Initialize();
	}
	void ShuffleDeck()
	{
		srand((unsigned int)time(NULL));
		for (int i = 0; i < MAX_CARD_COUNT * 100; i++)
		{
			int First = rand() % MAX_CARD_COUNT;
			int Second = rand() % MAX_CARD_COUNT;
			Card Temp = MyDeck.MyCards[First];
			MyDeck.MyCards[First] = MyDeck.MyCards[Second];
			MyDeck.MyCards[Second] = Temp;
		}
	}
	void HandOutCard(Player& _TargetPlayer)
	{
		_TargetPlayer.MyHand.push_back(MyDeck.MyCards.back());
		MyDeck.MyCards.pop_back();
	}
	void SetMyPlayerNum(int _MaxPlayer)
	{
		MyPlayerNum = (PlayerNum)_MaxPlayer;
	}
};

void ShowAllPlayerCards(vector<Player> _TargetPlayerVector)
{
	for (int i = 0; i < _TargetPlayerVector.size(); i++)
	{
		if (_TargetPlayerVector[i].MyPlayerNum < _TargetPlayerVector.size())
		{
			cout << "Player " + to_string(_TargetPlayerVector[i].MyPlayerNum + 1) << endl;
			_TargetPlayerVector[i].PrintMyHand();
		}
		else
		{
			cout << "Dealer" << endl;
			_TargetPlayerVector[i].PrintMyHand();
		}
		cout << "======================" << endl;
	}
}
void GamePlay()
{
	// Instantiate Dealer Get New Deck, Init, Shuffle
	Dealer Dealer1;
	Dealer1.GetNewDeck();
	Dealer1.ShuffleDeck();

	//Get Max Player Number
	int MaxPlayer = 0;
	while (true)
	{
		cout << "Plz Input The Player Number(Max Player 4) : ";
		cin >> MaxPlayer;
		cin.ignore();
		if (MaxPlayer > 0 && MaxPlayer < MaxPlayerNum + 1)
		{
			break;
		}
		cout << "Invalid Input Entered. Plz Try Again" << endl;
		cout << "Press Any Key To Continue" << endl;
		_getch();
		system("cls");
	}
	system("cls");

	//Instantiate Player At PlayerVector
	vector<Player> PlayerVector;
	for (int i = 0; i < MaxPlayer; i++)
	{
		Player NewPlayer;
		NewPlayer.MyPlayerNum = (PlayerNum)i;

		//Draw Two Cards
		Dealer1.HandOutCard(NewPlayer);
		Dealer1.HandOutCard(NewPlayer);

		PlayerVector.push_back(NewPlayer);
	}
	//Set Dealer's PlayerNum
	Dealer1.SetMyPlayerNum(MaxPlayer);
	//Dealer Get Card
	Dealer1.HandOutCard(Dealer1);
	Dealer1.HandOutCard(Dealer1);
	//Dealer Push Back In PlayerVector
	PlayerVector.push_back(Dealer1);
	ShowAllPlayerCards(PlayerVector);

}


int main()
{
	GamePlay();

	return 0;
}