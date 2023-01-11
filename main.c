#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "algo.h"

int main(int argc, char const *argv[])
{
    pnode head = NULL;

    int node_id;
    int amount_of_cities,dest,weight,res,i,city;
    char input;
    int amount_of_Nodes;

    if(scanf("%c",&input)!=EOF){
        while (input == 'A' || input == 'B' || input =='D' || input=='S'|| input == 'T')
        {
            if (input == 'A')
            {
                //Build a new Graph with the given amount of nodes
                scanf("%d",&amount_of_Nodes);
                build_graph_cmd(&head,amount_of_Nodes);

                scanf("%s",&input);
                while (input == 'n')
                {
                    // Find the node
                    scanf("%d",&node_id);
                    pnode currentNode = getNode(&head,node_id);
                    // Add the edges to the node
                    while(scanf("%d",&dest) == 1){
                        scanf("%d",&weight);
                        addEdge(currentNode,dest,weight,&head);
                    }
                    if(scanf("%c",&input)==EOF)
                        input = 'N';
                }
            }
            if (input == 'B')
            {
                scanf("%d",&node_id);
                pnode currentNode = getNode(&head,node_id);
                if(currentNode != NULL){
                    while (currentNode->edges != NULL)
                        removeEdge(currentNode);
                }
                else{
                    add_node(&head,node_id);
                    currentNode = getNode(&head,node_id);
                    amount_of_Nodes++;
                }
                // Add the edges to the node
                while(scanf("%d",&dest) == 1){
                    scanf("%d",&weight);
                    addEdge(currentNode,dest,weight,&head);
                }
                if(scanf("%c",&input)==EOF)
                    input = 'N';
                if(input == ' '){
                    if(scanf("%c",&input)==EOF)
                        input = 'N';
                }
            }
            if (input == 'D')
            {
                //Remove the incoming edges
                scanf("%d",&node_id);
                node *count = head;
                while (count != NULL) {
                    removeEdge2(count, node_id);
                    count = count->next;
                }
                removeNode(&head,node_id);
                amount_of_Nodes--;
                if(scanf("%c",&input)==EOF)
                    input = 'N';
                if(input == ' '){
                    if(scanf("%c",&input)==EOF)
                        input = 'N';
                }
            }
            if (input == 'S')
            {
                scanf("%d",&node_id);
                scanf("%d",&dest);
                //find the shortest distance
                res = dijkstra(&head, amount_of_Nodes,node_id,dest);
                printf("Dijsktra shortest path: %d \n",res);
                if(scanf("%c",&input)==EOF)
                    input = 'N';
                if(input == ' '){
                    if(scanf("%c",&input)==EOF)
                        input = 'N';
                }
            }
            if (input == 'T')
            {
                //Collect the cities in an array
                scanf("%d",&amount_of_cities);
                int *cities = (int*)malloc(sizeof(int)*amount_of_cities);
                if(cities==NULL){
                    printf("No Memory");
                    exit(0);
                }
                for (i = 0; i < amount_of_cities; i++)
                {
                    scanf("%d",&city);
                    cities[i] = city;
                }
                res = TSP(&head,cities,amount_of_cities, amount_of_Nodes);
                printf("TSP shortest path: %d \n",res);
                if(scanf("%c",&input)==EOF)
                    input = 'N';
                if(input == ' '){
                    if(scanf("%c",&input)==EOF)
                        input = 'N';
                }
            }
        }
    }
    removeGraph(&head);

    return 0;
}
