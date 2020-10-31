#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <utility>

using namespace std;

struct Node {
    bool visited;
    bool special;
    vector<int> nbor_node_inds;
    int dist_from_goal;
    Node(): visited(false), dist_from_goal(0), special(false) {}

};

int get_shortest_path_length(Node * nodes, int dest_ind)
{
    list<pair<int, int>> stack;
    stack.push_back(make_pair(dest_ind, 0));

    int shortest_path_length = 0;
    
    while(true)
    {
        pair<int, int> curr_pair = stack.front();
        stack.pop_front();
        int curr_ind = curr_pair.first;
        int curr_dist = curr_pair.second;

        nodes[curr_ind].visited = true;
        nodes[curr_ind].dist_from_goal = curr_dist;

        if(curr_ind == 1)
        {
            return curr_dist;
        }
        
        for(int i = 0; i < nodes[curr_ind].nbor_node_inds.size(); i++)
        {
            int nbor_ind = nodes[curr_ind].nbor_node_inds[i];
            if(nodes[nbor_ind].visited != true)
            {
                stack.push_back(make_pair(nbor_ind, curr_dist + 1)); 
            }
        }
    }
}

int main()
{
    int n = 0, m = 0, k = 0;
    cin >> n >> m >> k;

    Node nodes[n + 1];

    for (int i = 0; i < k; i++)
    {
        int special_ind = 0;
        cin >> special_ind;
        nodes[special_ind].special = true;
    }

    for(int i = 0; i < m; i++)
    {
        int source_ind = 0, dest_ind = 0;
        cin >> source_ind >> dest_ind;

        nodes[source_ind].nbor_node_inds.push_back(dest_ind);
        nodes[dest_ind].nbor_node_inds.push_back(source_ind);
    }

    int shortest_path_length = get_shortest_path_length(nodes, n);
    bool unconnected_nice = false;
    bool directly_connected_nice = false;

    for(int i = 1; i < (n + 1); i++)
    {
        if(nodes[i].special && !nodes[i].visited)
        {
            unconnected_nice = true;
            break;
        }
    }

    if(!unconnected_nice)
    {
        for(int i = 1; i < (n + 1); i++)
        {
            if(nodes[i].special)
            {
                for(int j = 0; j < nodes[i].nbor_node_inds.size() - 1; j++)
                {
                    int nbor_node_index = nodes[i].nbor_node_inds[j];
                    if(nodes[nbor_node_index].special == true)
                    {
                        directly_connected_nice = true;
                        break;
                    }
                }
            }
        }
    }

    if(unconnected_nice || directly_connected_nice)
    {
        cout << shortest_path_length << endl;
    }
    else
    {

    }

    if(!unconnected_nice)
    {
        
    }
}
