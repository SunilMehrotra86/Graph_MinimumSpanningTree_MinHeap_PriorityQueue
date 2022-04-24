#include<iostream>
#include<map>
#include<list>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, int> _intpair;

class myComparator
{
public:
    bool operator()(const _intpair& arg1, const _intpair& arg2)
    {
        return arg1.first > arg2.first;
    }

};

class Graph 
{

    map<int,list<pair<int,int>>> graph;
    int size;
public:
    void insertEdge(int node1, int node2, int weight)
    {
        graph[node1].push_back(make_pair(node2, weight));
        graph[node2].push_back(make_pair(node1, weight));
        size = graph.size();
    }
    void computeMSTUsingPrims() 
    {
        vector<bool> mst(size, false);
        vector<int>  key(size,INT_MAX);
        vector<int>  parent(size,-1);
        priority_queue<_intpair, vector<_intpair>, myComparator> pq;
        key[0] = 0;
        pq.push({0,graph.begin()->first});
        while (!pq.empty())
        {
            auto nodeToEvaluate = pq.top().second;
            pq.pop();
            if (mst[nodeToEvaluate])
                continue;
            mst[nodeToEvaluate] = true;

            for (auto neighboursOfNode : graph[nodeToEvaluate])
            {
                auto nodeName = neighboursOfNode.first;
                auto weight = neighboursOfNode.second;
                if (!mst[nodeName] && key[nodeName] > weight)
                {
                    key[nodeName] = weight;
                    pq.push(make_pair(weight,nodeName));
                    parent[nodeName] = nodeToEvaluate;

                }
            }
            
        }

        for (int i = 1; i <size; ++i)
        {
            cout <<parent[i]<<"----- "<<i<<"\n";
        }


    }
};

int main()
{
    Graph bg;
    bg.insertEdge(0, 1, 4);
    bg.insertEdge(0, 7, 8);
    bg.insertEdge(1, 2, 8);
    bg.insertEdge(1, 7, 11);
    bg.insertEdge(2, 3, 7);
    bg.insertEdge(2, 8, 2);
    bg.insertEdge(2, 5, 4);
    bg.insertEdge(3, 4, 9);
    bg.insertEdge(3, 5, 14);
    bg.insertEdge(4, 5, 10);
    bg.insertEdge(5, 6, 2);
    bg.insertEdge(6, 7, 1);
    bg.insertEdge(6, 8, 6);
    bg.insertEdge(7, 8, 7);
    bg.computeMSTUsingPrims();
    return 0;
}