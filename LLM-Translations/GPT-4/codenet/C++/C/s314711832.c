#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

#define MIN(a, b) ((a < b) ? a : b)
#define INF INT_MAX
#define N 100000

typedef struct edge {
  int source;
  int target;
  int weight;
} edge;

void add_edge(edge *edges, int *edge_count, int source, int target, int weight) {
  edges[*edge_count].source = source;
  edges[*edge_count].target = target;
  edges[*edge_count].weight = weight;
  (*edge_count)++;
}

int main() {
  int V, E, r;

  scanf("%d %d %d", &V, &E, &r);

  edge *edges = (edge *) malloc(E * sizeof(edge));
  int edge_count = 0;

  for (int i = 0; i < E; i++) {
    int source, target, distance;
    scanf("%d %d %d", &source, &target, &distance);
    add_edge(edges, &edge_count, source, target, distance);
  }

  //initialize distances array
  int distances[N];
  int prev_distances[N] = {0};

  for (int i = 0; i < N; i++) {
    distances[i] = INF ;
  }

  distances[r] = 0;

  for (int i = 1; i < V; i++) {
    for (int j=0; j< V; j++) {
      prev_distances[j] = distances[j];  
    }
    
    for (int j = 0; j < edge_count; j++) {
      edge current_edge = edges[j];
      distances[current_edge.target] = MIN(distances[current_edge.source] + current_edge.weight, distances[current_edge.target]);
    }

    bool same = true;
    for (int j=0; j< V; j++) {
      if (distances[j] != prev_distances[j]) {
        same = false;
        break;
      }
    }

    if (same) break;
  }

  for (int i = 0; i < V; i++) {
    if (distances[i] == INF) {
      printf("INF\n");
    } else {
      printf("%d\n", distances[i]);
    }
  }

  free(edges);
}

// 
