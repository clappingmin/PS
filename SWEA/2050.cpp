#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    cin >> input;

    for (int i = 0; i < input.size(); i++)
    {
        int num = 1;
        for (char c = 'A'; c <= 'Z'; c++)
        {   
            if (input[i] == c){
                printf("%d ",num);
                break;
            }
            num++;
        }
    }
    return 0;
}