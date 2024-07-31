#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <string_view>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <any>
#include <queue>

using namespace std;

int main()
{
   /* ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int NodeNum;
    cin >> NodeNum;

    int Node1;
    int Node2;

    vector<pair<int, int>> LinkedNodes;
    for (size_t i = 0; i < NodeNum - 1; ++i)
    {
        cin >> Node1 >> Node2;

        LinkedNodes.push_back(make_pair(Node1, Node2));
    }

    unordered_map<int, int> Nodes;
    for (size_t i = 0; i < NodeNum; i++)
    {
        for (size_t j = 0; j < LinkedNodes.size(); ++j)
        {
            if (i + 1 == LinkedNodes[j].first || i + 1 == LinkedNodes[j].second)
            {
                if (i + 1 == LinkedNodes[j].first)
                {
                    auto Node = Nodes.find(LinkedNodes[j].second);
                    if (Nodes.end() == Node)
                    {
                        Nodes.emplace(LinkedNodes[j].second, LinkedNodes[j].first);
                        LinkedNodes.erase(LinkedNodes.begin() + j);
                        --j;
                    }
                    else
                    {
                        Nodes.emplace(LinkedNodes[j].first, LinkedNodes[j].second);
                        LinkedNodes.erase(LinkedNodes.begin() + j);
                        --j;
                    }
                }
                else
                {
                    auto Node = Nodes.find(LinkedNodes[j].first);
                    if (Nodes.end() == Node)
                    {
                        Nodes.emplace(LinkedNodes[j].first, LinkedNodes[j].second);
                        LinkedNodes.erase(LinkedNodes.begin() + j);
                        --j;
                    }
                    else
                    {
                        Nodes.emplace(LinkedNodes[j].second, LinkedNodes[j].first);
                        LinkedNodes.erase(LinkedNodes.begin() + j);
                        --j;
                    }
                }
            }
        }
    }

    for (size_t i = 2; i <= NodeNum; i++)
    {
        cout << Nodes.find(i)->second << '\n';
    }


    return 0;*/


    ios::sync_with_stdio(false);
    int node_num;
    unordered_map<int, vector<int>> tree;
    vector<int> parent;
    vector<bool> check;
    cin >> node_num;

    parent = vector<int>(node_num + 1, 0);
    check = vector<bool>(node_num + 1, false);

    for (int i = 0; i < node_num - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        auto it = tree.find(a);
        if (it == tree.end())
            tree.insert({ a,vector<int>(1, b) });
        else
            it->second.push_back(b);

        auto it2 = tree.find(b);
        if (it2 == tree.end())
            tree.insert({ b,vector<int>(1, a) });
        else
            it2->second.push_back(a);
    }

    queue<int> que;
    que.push(1);

    while (!que.empty())
    {
        int curNode = que.front();
        check[curNode] = true;
        que.pop();

        auto it = tree.find(curNode);
        for (auto& i : it->second)
        {
            if (parent[i] == 0)
                parent[i] = curNode;

            if (check[i] == false)
                que.push(i);
        }
    }

    for (int i = 2; i < parent.size(); i++)
        cout << parent[i] << '\n';

    return 0;

} 