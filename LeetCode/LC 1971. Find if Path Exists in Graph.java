import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public boolean DFS(int currenNode, int destinationNode, boolean[] visited, Map<Integer, List<Integer>> graph) {
        visited[currenNode] = true;

        if (currenNode == destinationNode) {
            return true;
        }

        for (int neighborNode : graph.get(currenNode)) {
            if (!visited[neighborNode]) {
                if (DFS(neighborNode, destinationNode, visited, graph)) {
                    return true;
                }
            }
        }

        return false;
    }

    public boolean validPath(int n, int[][] edges, int source, int destination) {
        boolean[] visited = new boolean[n];
        Map<Integer, List<Integer>> graph = new HashMap<>();

        for (int i = 0; i < n; i++) {
            visited[i] = false;
        }

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph.computeIfAbsent(u, val -> new ArrayList<>()).add(v);
            graph.computeIfAbsent(v, val -> new ArrayList<>()).add(u);
        }

        return DFS(source, destination, visited, graph);
    }
}
