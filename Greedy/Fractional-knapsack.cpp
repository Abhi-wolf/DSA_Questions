#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

bool cmp(pair<double, Item> a, pair<double, Item> b)
{
    return a.first > b.first;
}

double factionalKnapsack(int W, Item arr[], int n)
{
    vector<pair<double, Item>> vec;
    double totalValue = 0;

    for (int i = 0; i < n; i++)
    {
        double perUnitValue = (1.0 * arr[i].value) / arr[i].weight;
        pair<double, Item> p = make_pair(perUnitValue, arr[i]);
        vec.push_back(p);
    }

    for (int i = 0; i < n; i++)
    {
        if (vec[i].second.weight > W)
        {
            totalValue += (W * vec[i].first);
            W = 0;
        }
        else
        {
            totalValue += vec[i].second.value;
            W -= vec[i].second.weight;
        }
    }

    return totalValue;
}

int main()
{
    Item arr[3] = {{60, 10}, {100, 20}, {120, 30}};
    cout << "Answer = " << factionalKnapsack(50, arr, 3) << endl;

    Item arr2[2] = {{60, 10}, {100, 20}};
    cout << "Answer = " << factionalKnapsack(50, arr2, 2) << endl;

    Item arr3[4] = {{6, 2}, {8, 6}, {10, 9}, {8, 3}};
    cout << "Answer = " << factionalKnapsack(5, arr3, 4) << endl;
    return 0;
}