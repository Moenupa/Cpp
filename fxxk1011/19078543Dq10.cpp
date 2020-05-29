/*
Below are the answers to Q1

Q: Input “stack_cats” will output “true” or “false”?
A: false

Q: Input “step_on_no_pets” will output “true” or “false”?
A: true

Q: Input “v” will get true or false?
A: true

*/

/*
Below are the answers to Q2

Q: What is the recursive relationship?
A: for Sn(C[1]-C[n]) compare C[i+1] and C[n-i] with i's range:0~n/2;
   if true then proceed to increase i by 1, loop;
   if false then break and return false
   additionally the recursive loop would break if reaching any o fthe base cases.

Q: What is the base case of this program?
A: S1 with only 1 character (which returns true);
   or S2 with two identical characters (returns true);
   or S2 with two different characters (returns false).

*/

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

bool is_alphabet(char s)
{
    return ((s >= 97 && s <= 122/*a-z*/) || (s >= 65 && s <= 90/*A-Z*/));
}

bool is_palindrome(char *s)
{
    // separate case for shortest strings
    if (strlen(s) <= 1) { return true; }

    // get first and last alphabetical character, converted to lowercase
    int length = strlen(s);
    int i = 0;
    for (i = 0; !is_alphabet(s[i]); i++);
    char first = tolower(s[i]);
    for (i = 1; !is_alphabet(s[length - i]); i++);
    char last = tolower(s[length - i]);

    if (first == last)
    {
        char shorter[100];
        strncpy(shorter, s+1, length-2);
        shorter[length-2] = '\0';
        return is_palindrome(shorter);
    }
    else
    {
        return false;
    }
}

int main()
{
    char sentence[100] = "not null";
    while (strlen(sentence) > 1)
    {
        cout << "Enter a string: ";
        cin.getline(sentence, 100, '\n');
        cout << sentence << " palindrome ";

        if (!is_palindrome(sentence)) { cout << "false "; }
        else cout << "true" << endl;
    }
    return 0;
}