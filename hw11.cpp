// YOUR_STUDENT_ID

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int charToValue(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';

    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 10;

    if (c >= 'a' && c <= 'z')
        return c - 'a' + 10;

    return -1;
}

char valueToChar(int x)
{
    if (x < 10)
        return '0' + x;

    return 'A' + x - 10;
}

bool validNumber(string s, int base)
{
    if (s.empty())
        return false;

    for (char c : s)
    {
        int x = charToValue(c);

        if (x < 0 || x >= base)
            return false;
    }

    return true;
}

int toDecimal(string s, int base)
{
    int value = 0;

    for (char c : s)
    {
        value = value * base + charToValue(c);
    }

    return value;
}

string fromDecimal(int value, int base)
{
    if (value == 0)
        return "0";

    string result;

    while (value > 0)
    {
        int digit = value % base;
        result += valueToChar(digit);
        value /= base;
    }

    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    int targetBase;

    getline(cin, input);
    cin >> targetBase;

    if (targetBase < 2 || targetBase > 36)
    {
        cout << "ERROR: invalid target base\n";
        return 0;
    }

    int left = input.find('(');
    int right = input.find(')');

    if (left == string::npos ||
        right == string::npos ||
        right != input.size() - 1)
    {
        cout << "ERROR: invalid format\n";
        return 0;
    }

    string number = input.substr(0, left);
    string baseString = input.substr(left + 1, right - left - 1);

    int sourceBase = stoi(baseString);

    if (sourceBase < 2 || sourceBase > 36)
    {
        cout << "ERROR: invalid source base\n";
        return 0;
    }

    bool negative = false;

    if (number[0] == '+' || number[0] == '-')
    {
        negative = number[0] == '-';
        number.erase(0, 1);
    }

    int dot = number.find('.');

    if (dot != string::npos &&
        number.find('.', dot + 1) != string::npos)
    {
        cout << "ERROR: more than one decimal point\n";
        return 0;
    }

    string integerPart;
    string fractionPart;

    if (dot == string::npos)
    {
        integerPart = number;
    }
    else
    {
        integerPart = number.substr(0, dot);
        fractionPart = number.substr(dot + 1);
    }

    if (integerPart.empty())
        integerPart = "0";

    if (!validNumber(integerPart, sourceBase))
    {
        cout << "ERROR: invalid digit\n";
        return 0;
    }

    if (!fractionPart.empty() &&
        !validNumber(fractionPart, sourceBase))
    {
        cout << "ERROR: invalid digit\n";
        return 0;
    }

    int integerValue = toDecimal(integerPart, sourceBase);

    string answer = fromDecimal(integerValue, targetBase);

    int numerator = 0;
    int denominator = 1;

    for (char c : fractionPart)
    {
        numerator = numerator * sourceBase + charToValue(c);
        denominator *= sourceBase;
    }

    string fractionAnswer;

    map<int, int> seen;

    int position = 0;

    while (numerator != 0 && position < 20)
    {
        if (seen.count(numerator))
        {
            int start = seen[numerator];

            fractionAnswer.insert(
                fractionAnswer.begin() + start,
                '['
            );

            fractionAnswer += ']';

            break;
        }

        seen[numerator] = position;

        numerator *= targetBase;

        int digit = numerator / denominator;

        numerator %= denominator;

        fractionAnswer += valueToChar(digit);

        position++;
    }

    if (numerator != 0 && position == 20)
        fractionAnswer += "...";

    bool zero = (integerValue == 0 && fractionPart.empty());

    if (!fractionPart.empty())
    {
        bool fractionZero = true;

        for (char c : fractionPart)
        {
            if (charToValue(c) != 0)
            {
                fractionZero = false;
                break;
            }
        }

        if (integerValue == 0 && fractionZero)
            zero = true;
    }

    if (zero)
        negative = false;

    if (negative)
        cout << "-";

    cout << answer;

    if (!fractionAnswer.empty())
        cout << "." << fractionAnswer;

    cout << "(" << targetBase << ")\n";

    return 0;
}
