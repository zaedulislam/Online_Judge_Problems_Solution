class Solution {
    private enum Colors {
        WHITE, GREY, BLACK
    }

    private Colors[] status;

    public boolean leadsToDestination(int n, int[][] edges, int source, int destination) {
        ArrayList<ArrayList<Integer>> graph = buildDirectedGraph(n, edges);
        status = new Colors[n];
        Arrays.fill(status, Colors.WHITE);


        return DFS(n, source, destination, status, graph);
    }

    private boolean DFS(int n, int currentNode, int destinationNode, Colors[] status, ArrayList<ArrayList<Integer>> graph) {
        if (status[currentNode] != Colors.WHITE) {
            if (status[currentNode] == Colors.GREY) {
                return false;
            } else {
                return true;
            }
        }

        if (graph.get(currentNode).isEmpty()) {
            if (currentNode == destinationNode) {
                return true;
            }

            return false;
        }

        status[currentNode] = Colors.GREY;

        boolean isValid = true;

        for (int neighborNode : graph.get(currentNode)) {
            isValid = isValid & DFS(n, neighborNode, destinationNode, status, graph);

            if (!isValid) {
                return false;
            }
        }

        status[currentNode] = Colors.BLACK;
        return true;
    }

    private ArrayList<ArrayList<Integer>> buildDirectedGraph(int n, int[][] edges) {
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }


        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph.get(u).add(v);
        }

        return graph;
    }
}
