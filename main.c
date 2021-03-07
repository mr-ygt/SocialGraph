#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char vertex[10];
    struct node* next;
};
typedef struct node node;

struct Graph{
    int numVertices;
    struct node ** adjLists;
};
typedef struct Graph Graph;

struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);
struct node* createNode(int v);
int findIndex(char people[][10], char name[]);
void printGraphAsMatrix(struct Graph* graph, int M[][10]);
int degree(struct node* temp);

int main(){
	char people[10][10];
	strcpy(people[0], "Cem");
	strcpy(people[1], "Ayse");
	strcpy(people[2], "Belma");
	strcpy(people[3], "Edip");
	strcpy(people[4], "Dundar");
	strcpy(people[5], "Gamze");
	strcpy(people[6], "Ferit");
	strcpy(people[7], "Halit");
	strcpy(people[8], "Ilke");
	strcpy(people[9], "Jale");
	
	Graph * graph = createGraph(10);
    addEdge(graph, findIndex(people,people[0]), findIndex(people,people[1]));
    addEdge(graph, findIndex(people,people[0]), findIndex(people,people[6]));
    addEdge(graph, findIndex(people,people[0]), findIndex(people,people[4]));
    addEdge(graph, findIndex(people,people[1]), findIndex(people,people[6]));
    addEdge(graph, findIndex(people,people[1]), findIndex(people,people[4]));
    addEdge(graph, findIndex(people,people[1]), findIndex(people,people[2]));
    addEdge(graph, findIndex(people,people[2]), findIndex(people,people[4]));
    addEdge(graph, findIndex(people,people[2]), findIndex(people,people[3]));
    addEdge(graph, findIndex(people,people[3]), findIndex(people,people[4]));
    addEdge(graph, findIndex(people,people[3]), findIndex(people,people[5]));
    addEdge(graph, findIndex(people,people[4]), findIndex(people,people[6]));
    addEdge(graph, findIndex(people,people[4]), findIndex(people,people[5]));
    addEdge(graph, findIndex(people,people[5]), findIndex(people,people[6]));
    addEdge(graph, findIndex(people,people[5]), findIndex(people,people[7]));
    addEdge(graph, findIndex(people,people[6]), findIndex(people,people[7]));
    addEdge(graph, findIndex(people,people[7]), findIndex(people,people[8]));
    addEdge(graph, findIndex(people,people[8]), findIndex(people,people[9]));
    printGraph(graph);
    printf("\n\n");
    int M[10][10];
    printGraphAsMatrix(graph,M);
 	printf("\n\n");
 	printf("		Degree Centrality of nodes\n\n");
 	printf("Node	Score	Standardized Score\n");
 	int i = 0;
 	for(i; i < 10; i++){
 		printf("%s	%d	%d/10\n",people[i],degree(graph->adjLists[i]),degree(graph->adjLists[i]));
	 }
 	printf("\n\n");
 	
    return 0;
}
int closeness(struct node* temp, char people[][10]){	// this was not completed.
	int i =0;
	int count = 0;
	struct node* iter;
	iter = temp;
	while(iter){
		if(strcmp(people[i],iter->vertex) != 0){
			strcpy(people[i],iter->vertex);
			iter = iter->next;
			i++;
			count++;
			
		}
		
	}
	
}



int findIndex(char people[][10], char name[]){
	int i;
	for(i = 0; i < 10; i++)
		if(strcmp(people[i], name) == 0) return i;
} 

struct node* createNode(int v){	char name[10];
	char people[10][10];
	strcpy(people[0], "Cem");
	strcpy(people[1], "Ayse");
	strcpy(people[2], "Belma");
	strcpy(people[3], "Edip");
	strcpy(people[4], "Dundar");
	strcpy(people[5], "Gamze");
	strcpy(people[6], "Ferit");
	strcpy(people[7], "Halit");
	strcpy(people[8], "Ilke");
	strcpy(people[9], "Jale");
	strcpy(name,people[v]);
    node * newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->vertex,name);
    newNode->next = NULL;
    return newNode;
}
 

struct Graph* createGraph(int vertices){
    Graph * graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
 
    graph->adjLists = (node**)malloc(vertices * sizeof(node));
 
    int i;
    for (i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;
 
    return graph;
}
 
void addEdge(struct Graph* graph, int src, int dest){
    // Add edge from src to dest
    node * newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
 
    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraphAsMatrix(struct Graph* graph, int M [][10]){
	char people[10][10];
	strcpy(people[0], "Cem");
	strcpy(people[1], "Ayse");
	strcpy(people[2], "Belma");
	strcpy(people[3], "Edip");
	strcpy(people[4], "Dundar");
	strcpy(people[5], "Gamze");
	strcpy(people[6], "Ferit");
	strcpy(people[7], "Halit");
	strcpy(people[8], "Ilke");
	strcpy(people[9], "Jale");
	printf("		Representation of the graph like Adj Matrix\n\n");
	printf("	Cem	Ayse	Belma	Edip	Dundar	Gamze	Ferit	Halit	Ilke	Jale\n");
	int v;
	int z;
	int flag;
	//int M[10][10];
	for(v = 0; v < graph->numVertices; v++){
		node * temp = graph->adjLists[v];
		node * iter;
		printf("%s	",people[v]);
		iter = temp;
		for(z = 0; z < 10; z++){
			while(iter){
				if(strcmp(iter->vertex,people[z]) == 0){
					flag = 1;
					break;
				}	
				else if(strcmp(iter->vertex,people[z]) != 0)	flag = 0;
				iter = iter->next;
			}
			if(flag == 1){
				M[v][z] = 1;
				printf("1	");
			}
			else if(flag == 0){
				M[v][z] = 0;
				printf("0	");
			}
			iter = temp;
		}
		printf("\n");
	}
}

int degree(struct node* temp){
	int count = 0;
	//int i;
	//for(i = 0; i < graph->numVertices; i++){
	//	node * temp = graph->adjLists[i];
		while(temp){
			count++;
			temp = temp->next;
		}
	//}
	return count;
}
void printGraph(struct Graph* graph){
	char people[10][10];
	strcpy(people[0], "Cem");
	strcpy(people[1], "Ayse");
	strcpy(people[2], "Belma");
	strcpy(people[3], "Edip");
	strcpy(people[4], "Dundar");
	strcpy(people[5], "Gamze");
	strcpy(people[6], "Ferit");
	strcpy(people[7], "Halit");
	strcpy(people[8], "Ilke");
	strcpy(people[9], "Jale");
    int v;
    printf("\n\n		Representation of the graph like Adj list\n\n");
    for (v = 0; v < graph->numVertices; v++){
        node * temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %s\n ", people[v]);
        while (temp){
            printf("%s", temp->vertex);
            if(temp->next != NULL)
            	printf(" -> ");
            temp = temp->next;
        }
        printf("\n");
    }
}
