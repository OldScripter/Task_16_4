#include <iostream>
#include <vector>

enum tones
{
    DO = 2,
    RE = 4,
    MI = 8,
    FA = 16,
    SO = 32,
    LA = 64,
    SI = 128
};

std::vector<int> melody;

std::string SequenceToTones(int sequence)
{
    std::string result = "";
    if (sequence & DO) result += "DO ";
    if (sequence & RE) result += "RE ";
    if (sequence & MI) result += "MI ";
    if (sequence & FA) result += "FA ";
    if (sequence & SO) result += "SO ";
    if (sequence & LA) result += "LA ";
    if (sequence & SI) result += "SI ";

    return result;
}

bool GetTonesFromKeyboard()
{
    std::cout << "Please enter the notes sequence (format XXX):\n";
    std::string input;
    std::cin >> input;

    if (input.size() != 3) return false;

    int sequence = 0;

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] < '1' || input[i] > '7') return false;
        else if (input[i] == '1') sequence |= DO;
        else if (input[i] == '2') sequence |= RE;
        else if (input[i] == '3') sequence |= MI;
        else if (input[i] == '4') sequence |= FA;
        else if (input[i] == '5') sequence |= SO;
        else if (input[i] == '6') sequence |= LA;
        else if (input[i] == '7') sequence |= SI;
    }

    melody.push_back(sequence);
    return true;
}

void PrintMelody()
{
    for (int i = 0; i < melody.size(); i++)
    {
        std::cout << SequenceToTones(melody[i]) << "\n";
    }
}

int main()
{

    while (melody.size() < 3)
    {
        if (GetTonesFromKeyboard())
            std::cout << "Sequence is written. Next one...\n";
        else
        {
            std::cout << "Bad input! Try again. Example 123.\n";
        }
    }

    PrintMelody();

    return 0;
}
