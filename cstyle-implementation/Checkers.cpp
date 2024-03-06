#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#define GET_DECIMAL(value) ((float)value / 8 - floor(value / 8))
#define GET_ROW(value) (value / 8)
#define GET_COL(value) (value % 8)

/*
*                                            Start Position
*
*       | A | B | C | D | E | F | G | H |						   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
*    ---|---|---|---|---|---|---|---|---|						---|---|---|---|---|---|---|---|---|
*     8 |   | B |   | B |   | B |   | B |   0  - 7				 0 |   | B |   | B |   | B |   | B |
*     7 | B |   | B |   | B |   | B |   |   8  - 15				 1 | B |   | B |   | B |   | B |   |
*     6 |   | B |   | B |   | B |   | B |   16 - 23				 2 |   | B |   | B |   | B |   | B |
*     5 |   |   |   |   |   |   |   |   |   24 - 31				 3 |   |   |   |   |   |   |   |   |
*     4 |   |   |   |   |   |   |   |   |   32 - 39				 4 |   |   |   |   |   |   |   |   |
*     3 | W |   | W |   | W |   | W |   |   40 - 47				 5 | W |   | W |   | W |   | W |   |
*     2 |   | W |   | W |   | W |   | W |   48 - 55				 6 |   | W |   | W |   | W |   | W |
*     1 | W |   | W |   | W |   | W |   |   56 - 63				 7 | W |   | W |   | W |   | W |   |
*/

void MinLogEntry();
void FullGameLogEntry(std::ofstream&, short int*, short int*);
bool CanAct(short int*, short int*, const short int Weight = 1);
short int* FindAddressInArray(const short int, short int*, short int*);
template<typename T>
void BubbleSort(T*) noexcept;
bool CanMove(const short int, const short int, short int*) noexcept;
bool CanEat(const short int, short int, short int*, short int*, const short int);

std::ofstream Minlog{};
std::string Entry{"Starting positions."};

int main()
{
	srand(time(nullptr));
	std::ofstream Fullgamelog("fullgamelog.txt");
	Minlog.open("minlog.txt");
	bool bHasMoved{true};
	if (Minlog.is_open() && Fullgamelog.is_open())
	{
		short int W[12] = { 40, 42, 44, 46, 49, 51, 53, 55, 56, 58, 60, 62 };
		short int B[12] = { 1, 3, 5, 7, 8, 10, 12, 14, 17, 19, 21, 23 };
		FullGameLogEntry(Fullgamelog, W, B);
		MinLogEntry();
		while (bHasMoved)
		{
			bHasMoved = CanAct(W, B);
			FullGameLogEntry(Fullgamelog, W, B);
			MinLogEntry();

			bHasMoved |= CanAct(B, W, -1);
			FullGameLogEntry(Fullgamelog, W, B);
			MinLogEntry();
		}
	}
	else
	{
		std::cout << "Failed to open log files.\nExiting..." << std::endl;
		exit(0);
	}
	Minlog.close();
	Fullgamelog.close();
}

void MinLogEntry()
{
	Minlog << Entry << std::endl;
	Entry.clear();
}

void FullGameLogEntry(std::ofstream& FullGameLog, short int* W, short int* B)
{
	static short int Round{ 0 };
	FullGameLog << "TURN " << Round << ": " << Entry <<"\n" <<
		"   | A | B | C | D | E | F | G | H |\n" <<
		"---|---|---|---|---|---|---|---|---|\n";
	for (size_t i = 0; i < 8; ++i)
	{
		FullGameLog << " " << 8 - i << " |";
		for (size_t j = 0; j < 8; ++j)
		{
			if (FindAddressInArray(i * 8 + j, W, &W[11]))
			{
				FullGameLog << " W |";
			}
			else if (FindAddressInArray(i * 8 + j, B, &B[11]))
			{
				FullGameLog << " B |";
			}
			else
				FullGameLog << "   |";
		}
		FullGameLog << "\n";
	}
	FullGameLog << "\n\n";
	Round++;
}

bool CanAct(short int* Ally, short int* Enemy, const short int Weight)
{
	short int Tries{0};
	short int Intention; // pawn is the number of the pawn in the ally array, intention where I want to go to
	while (Tries < 100)
	{
		const auto Pawn = rand() % 12;
		if (Ally[Pawn] <= -1) // pawn is eaten
		{
			Tries++;
			continue;
		}
		if (GET_DECIMAL(Ally[Pawn]) == 0.875) // easternmost edge
		{
			Intention = Ally[Pawn] + (Weight > 0 ? -9 : 7);
		}
		else if (GET_DECIMAL(Ally[Pawn]) == 0) // westernmost edge
		{
			Intention = Ally[Pawn] + (Weight > 0 ? -7 : 9);
		}
		else
		{
			Intention = Ally[Pawn] - Weight * ((rand() % 2) == 0 ? 7 : 9);
		}
		if (Intention < 0 || Intention > 63) // can't surpass horizontal axis
		{
			continue;
		}
		if (CanEat(Intention, Pawn, Ally, Enemy, Weight))
		{
			std::string Tmp = (Weight > 0 ? "W@" : "B@"); // who
			Tmp += Entry;
			Entry = Tmp;
			return true;
		}
		else if (Tries > 36 && !FindAddressInArray(Intention, Ally, &Ally[11]) && !FindAddressInArray(Intention, Enemy, &Enemy[11]))
		{
			Entry = (Weight > 0 ? "W@" : "B@"); // who
			Entry += static_cast<char>((GET_COL(Ally[Pawn]) + 97)); // row origin
			Entry += static_cast<char>((8 - GET_ROW(Ally[Pawn]) + '0')); // col origin
			Entry += "-";
			Entry += static_cast<char>((GET_COL(Intention) + 97)); // row end
			Entry += static_cast<char>((8 - GET_ROW(Intention) + '0')); // col end
			return CanMove(Intention, Pawn, Ally);
		}
		Tries++;
	}
	return false;
}

bool CanMove(const short int Intention, const short int Pawn, short int* Ally) noexcept
{
	Ally[Pawn] = Intention;
	BubbleSort(Ally);
	return true;
}

bool CanEat(const short int Intention, short int Pawn, short int* Ally, short int* Enemy, const short int Weight)
{
	if (FindAddressInArray(Intention, Enemy, &Enemy[11])) // an enemy at intention
	{
		if ((GET_DECIMAL(Intention) != 0.875) && (GET_DECIMAL(Intention) != 0.0) && (Intention / 8 != 0) && (Intention / 8 != 7)) // if the enemy is not at an edge
		{
			const auto JumpTo = Weight < 0 ? (GET_COL(Intention) > GET_COL(Ally[Pawn]) ? Intention + 9 : Intention + 7) : (GET_COL(Intention) > GET_COL(Ally[Pawn]) ? Intention - 7 : Intention - 9);
			short int* EnemyPosition{ FindAddressInArray(JumpTo, Enemy, &Enemy[11]) }; // is there an enemy at the pos to jump to 
			if (!EnemyPosition && !FindAddressInArray(JumpTo, Ally, &Ally[11]))
			{
				Entry += static_cast<char>((GET_COL(Ally[Pawn]) + 97)); // row origin
				Entry += static_cast<char>((8 - GET_ROW(Ally[Pawn])) + '0'); // col origin
				Entry += ":";
				Entry += static_cast<char>(GET_COL(Intention) + 97); // enemy row
				Entry += static_cast<char>((8 - GET_ROW(Intention)) + '0'); // enemy col
				Entry += ":";
				Entry += static_cast<char>(GET_COL(JumpTo) + 97); // landed row
				Entry += static_cast<char>((8 - GET_ROW(JumpTo)) + '0'); // landed col
				Entry += " ";
				CanMove(JumpTo, Pawn, Ally);
				Pawn = FindAddressInArray(JumpTo, Ally, &Ally[11]) - Ally; // recalculating pawn because of sort
				*FindAddressInArray(Intention, Enemy, &Enemy[11]) = -1;
				BubbleSort(Enemy);
				if (CanEat(JumpTo + 7, Pawn, Ally, Enemy, Weight < 0 ? Weight : -Weight))
				{
					return true;
				}
				else if (CanEat(JumpTo + 9, Pawn, Ally, Enemy, Weight < 0 ? Weight : -Weight))
				{
					return true;
				}
				else if ((CanEat(JumpTo - 7, Pawn, Ally, Enemy, Weight > 0 ? Weight : -Weight)))
				{
					return true;
				}
				else if ((CanEat(JumpTo - 9, Pawn, Ally, Enemy, Weight > 0 ? Weight : -Weight)))
				{
					return true;
				}
				else return true;
			}
		}
	}
	return false;
}

short int* FindAddressInArray(const short int Pos, short int* Start, short int* End)
{
	const auto Index = (End - Start) / 2;
	if (Pos == Start[Index])
	{
		return &Start[Index];
	}
	else if (Start == End)
	{
		return nullptr;
	}
	else if (Pos < Start[Index])
	{
		return FindAddressInArray(Pos, Start, &Start[Index]);
	}
	else
	{
		return FindAddressInArray(Pos, &Start[Index + 1], End);
	}
}

template<typename T>
void BubbleSort(T* OutArray) noexcept
{
	for (size_t i = 0; i < 11; ++i)
	{
		for (size_t j = 0; j < 11 - i; ++j)
		{
			if (OutArray[j] > OutArray[j + 1])
			{
				const T tmp = OutArray[j];
				OutArray[j] = OutArray[j + 1];
				OutArray[j + 1] = tmp;
			}
		}
	}
}
