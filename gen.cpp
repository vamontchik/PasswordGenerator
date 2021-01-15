#include <vector>
#include <iostream>
#include <random>

using namespace std;

vector<char> constructBase()
{
    vector<char> all;

    // lowercase
    for (char i = 'a'; i <= 'z'; ++i) { all.push_back(i); }

    // uppercase
    for (char i = 'A'; i <= 'Z'; ++i) { all.push_back(i); }

    // numbers
    for (char i = '0'; i <= '9'; ++i) { all.push_back(i); }

    return all;
}

vector<char> constructSpecial()
{
    // special
    vector<char> special =
    {
        '`',
        '~',
        '!',
        '@',
        '#',
        '$',
        '%',
        '^',
        '&',
        '*',
        '(',
        ')',
        '-',
        '_',
        '=',
        '+',
        '[',
        '{',
        ']',
        '}',
        '\\',
        '|',
        ';',
        ':',
        '\'',
        '\"',
        ',',
        '<',
        '.',
        '>',
        '/',
        '?'
    };
    return special;
}

void generate(string & pass, vector<char> & fromVec, uniform_int_distribution<int> & dist, mt19937_64 & gen, int amount)
{
    for (int i = 0; i < amount; ++i)
    {
        int rand_index = dist(gen);
        pass.push_back(fromVec.at(rand_index));
    }
}

int main()
{
    cout << "Num base characters: ";

    int baseAmount;
    cin >> baseAmount;

    cout << "Num special characters: ";

    int specialAmount;
    cin >> specialAmount;

    vector<char> base = constructBase();
    vector<char> special = constructSpecial();

    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<int> distBase(0, base.size() - 1);
    uniform_int_distribution<int> distSpecial(0, special.size() - 1);

    string pass;
    generate(pass, base, distBase, gen, baseAmount);
    generate(pass, special, distSpecial, gen, specialAmount);
    
    shuffle(pass.begin(), pass.end(), gen);

    cout << pass << endl;

    return 0;
}