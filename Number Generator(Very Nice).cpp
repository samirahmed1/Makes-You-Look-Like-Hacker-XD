#include <iostream>
#include <windows.h>
#include <random>
#include <map>

using namespace std;

int main()
{
    HANDLE _color = GetStdHandle(STD_OUTPUT_HANDLE);
    std::random_device rd;
    std::mt19937 gen(rd());
    int minRandom = 0, maxRandom = 1000000000;


    SetConsoleTextAttribute(_color, 4);

    int index, emtey, maxcount, last, now, higest;
    int editing;
    bool once = true;
    bool first_try = true;
    bool EditingMode = false;

    maxcount = 100;

    cout<<"Type A Number If You Really Want To Start ";
    cin>>emtey;

    SetConsoleTextAttribute(_color, 6);
    cout<<"Type How Many Times You Want To Count: ";
    cin>>maxcount;

    cout<<"Type '1' To Edit The Max, Min Randomization, Or Anything"<<endl;
    cout<<"If You Dont Want To Edit Then Type Anything Rather 1: ";

    cin>>editing;

    if(editing == 1)
    {
        EditingMode = true;
    }

    if(EditingMode)
    {
        cout<<"Type Min Value: ";
        cin>>minRandom;

        cout<<"Type Max Value: ";
        cin>>maxRandom;
    }

    std::uniform_real_distribution<> distribution(minRandom, maxRandom);

    SetConsoleTextAttribute(_color, 4);
    cout<<"Are You Really Ready? Type A Number To Start"<<endl;
    cin>>emtey;

    std::map<int, int> countMap;

    while(index <= maxcount)
    {
        SetConsoleTextAttribute(_color, 10);
        int random = distribution(gen); // 1 bilion

        countMap[random]++;

        if(first_try)
        {
            random = distribution(gen);
            first_try = false;
        }

        now = random;
        if(once)
        {
            last = now;
            cout<<last<<endl;;
            once = false;
        }

        if(now < last)
        {
            last = now;
        }

        if(now > higest)
        {
            higest = now;
        }


        cout<<"- - Number - - "<<index<<", - "<<random<<endl;
        index++;
    }

    if(index >= maxcount)
    {
        // Find the most common number
        int mostCommonNumber = 0;
        int maxOccurrences = 0;
        for (const auto& pair : countMap)
        {
            if (pair.second > maxOccurrences)
            {
                mostCommonNumber = pair.first;
                maxOccurrences = pair.second;
            }
        }

        SetConsoleTextAttribute(_color, 14);
        cout<<" :P Finish "<<maxcount<<endl;
        cout<<"Smallest Number Was: "<<last<<endl;
        cout<<"Higest Number Was: "<<higest<<endl;
        cout << "Most Common Number: " << mostCommonNumber << " With " << maxOccurrences << " Occurrences" << endl;
        cout<<"Distance Between Them: "<<(higest - last)<<endl;
        SetConsoleTextAttribute(_color, 7);
    }
    return 0;
}


