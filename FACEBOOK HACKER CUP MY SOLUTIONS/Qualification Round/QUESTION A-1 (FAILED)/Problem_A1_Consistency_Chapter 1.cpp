// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    int a = t;
    while (t-- > 0)
    {

        // Hey @myselfdeepdas ''BUNNY'' you can code from here --->
        string S;
        cin >> S;

        int timetaken = 0;

        int length = S.length();
        int vowel = 0;
        int consonant = 0;
        // int maxTime = 0;

        for (int i = 0; i < length; i++)
        {
            if (S.at(i) == 65 || S.at(i) == 69 || S.at(i) == 73 || S.at(i) == 79 || S.at(i) == 85)
            {
                vowel++;
            }
            else
            {
                consonant++;
            }
        }
        // ====FOR THE CASE WHEN SINGLE LETTER IS PRESSENT====//
        if (length == 1)
        {
            cout << "Case #" << a - t << ":"
                 << " " << timetaken << endl;
        }

        // ====FOR THE CASE WHEN ONLY VOWEL LETTER IS PRESSENT====//
        else if (length == vowel)
        {
            timetaken = vowel;
            cout << "Case #" << a - t << ":"
                 << " " << timetaken << endl;
        }

        // ====FOR THE CASE WHEN ONLY CONSONANT LETTER IS PRESSENT====//
        else if (consonant == length)
        {
            timetaken = consonant;
            cout << "Case #" << a - t << ":"
                 << " " << timetaken << endl;
        }
        // ====FOR THE CASE WHEN ALL MIXED LETTER IS PRESSENT====//
        else
        {
            char The1stChar, The2ndChar;

            int pos = 0;

            // kitna baar hai time

            int The1stCharTime = 0;
            int The2ndCharTime = 0;

            // phla char me jo hai phla const store

            for (int i = 0; i < S.length(); i++)
            {
                if (S.at(i) != 65 && S.at(i) != 69 && S.at(i) != 73 && S.at(i) != 79 && S.at(i) != 85)
                {
                    pos = i;
                    The1stChar = S.at(i);
                    break;
                }
            }
            // phla char me jo hai dusra const store
            for (int i = pos + 1; i < S.length(); i++)
            {
                if (S.at(i) != 65 && S.at(i) != 69 && S.at(i) != 73 && S.at(i) != 79 && S.at(i) != 85 && S.at(i) != The1stChar)
                {
                    The2ndChar = S.at(i);
                    break;
                }
            }
            // phla chr how much??
            for (int i = 0; i < S.length(); i++)
            {
                if (The1stChar == S.at(i))
                {
                    The1stCharTime++;
                }
            }
            //dusra char how much??
            for (int i = 0; i < S.length(); i++)
            {
                if (The2ndChar == S.at(i))
                {
                    The2ndCharTime++;
                }
            }

            if (The1stCharTime < The2ndCharTime)
            {
                The1stChar = The2ndChar;
                The1stCharTime = The2ndCharTime;
            }

            char VThe1stChar;
            char VThe2ndChar;

            int Vpos = 0;
            int VThe1stCharTime = 0;
            int VThe2ndCharTime = 0;
            int count = 0;

            for (int i = 0; i < S.length(); i++)
            {
                if (S.at(i) == 65 || S.at(i) == 69 || S.at(i) == 73 || S.at(i) == 79 || S.at(i) == 85)
                {
                    Vpos = i;
                    VThe1stChar = S.at(i);
                    break;
                }
            }

            for (int i = Vpos + 1; i < S.length(); i++)
            {
                if (S.at(i) == 65 && S.at(i) == 69 && S.at(i) == 73 && S.at(i) == 79 && S.at(i) == 85 && S.at(i) != VThe1stChar)
                {
                    VThe2ndChar = S.at(i);
                    break;
                }
            }

            for (int i = 0; i < S.length(); i++)
            {
                if (VThe1stChar == S.at(i))
                {
                    VThe1stCharTime++;
                }
            }

            for (int i = 0; i < S.length(); i++)
            {
                if (VThe2ndChar == S.at(i))
                {
                    VThe2ndCharTime++;
                }
            }

            if (VThe1stCharTime < VThe2ndCharTime)
            {
                VThe1stChar = VThe2ndChar;
                VThe1stCharTime = VThe2ndCharTime;
            }

            // here we initialise changing vowel -> const & Const -> vowel
            int ChangingVowelToConsonant = 0;
            int ChangingConsonanatToVowel = 0;

            ChangingVowelToConsonant = (consonant - The1stCharTime) * 2 + vowel;
            ChangingConsonanatToVowel = (vowel - VThe1stCharTime) * 2 + consonant;

            cout << "Case #" << a - t << ": " << min(ChangingVowelToConsonant, ChangingConsonanatToVowel) << " " << endl;
        }
    }

    return 0;
}
