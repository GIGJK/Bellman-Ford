#include <stdio.h>
#include <stdlib.h>

#define inf 2147483647

struct graph
{
	int start;
	int end;
	int weight;
};

typedef struct graph graph_t;


int min(int first, int second)
{
	return (first < second) ? first : second;
}

int main(void)
{
	int count_e, count_v;
	printf("Enter count of vertices: ");
	scanf("%d", &count_v);

	printf("Enter count of edges: ");
	scanf("%d", &count_e);

	int* array_distances = (int*) malloc(count_v-1);
	graph_t* array_graphs = (graph_t*) malloc(count_e-1);

	printf("\n*Enter graph' edges*\n\n");
	for(int i = 0; i < count_e; i++)
	{
		printf("Enter graph' start, end, weight for %d's edge: ", i+1);
		scanf("%d %d %d", &array_graphs[i].start,
			       	  &array_graphs[i].end,
				  &array_graphs[i].weight
				  );
	}

	for(int i = 0; i < count_v; i++){ array_distances[i] = inf; }

	int start, end;

	printf("Where to go from? :");
	scanf("%d", &start);
	array_distances[start-1] = 0;

	printf("Where to go? :");
	scanf("%d", &end);

	/* Bellman-Ford */
	for(int i = 0; i < count_v - 1; i++){
		for(int j = 0; j < count_e; j++){

			array_distances[array_graphs[j].end-1] = min(
					(int)(array_distances[array_graphs[j].end-1]),
					(int)(array_distances[array_graphs[j].start-1] + array_graphs[j].weight));

		}
	}
	/* Free memory */
	free(array_graphs);

	if(array_distances[end-1] == inf)
		printf("No way to %d\n", end);
	else
		printf("Shortest part from %d to %d equal %d\n", start, end, array_distances[end-1]);

	printf("Print all ways form %d?(y/n): ", start);
	getchar();
	char key = getchar();

	while(1)
	{
		if (key == 'N' || key == 'n')
		{
			printf("\vGoodbye...\n\n");
			break;
		}else if(key == 'Y' || key == 'y')
		{
			for(int i = 0; i < count_v; i++)
			{
				if (array_distances[i] == inf)
					printf("No way from %d to %d.\n", start, i+1);
				else
				printf("Way from %d to %d equal %d.\n", start, i+1, array_distances[i]);
			}
			break;
		}
		else
		{
			printf("\nEnter y or n: ");
			key = getchar();
			getchar();
		}
	}

	/* Free memory */
	free(array_distances);
	return printf("\nBellman-Ford closed.\n"), 0;
}
