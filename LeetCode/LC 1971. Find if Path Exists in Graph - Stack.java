class Solution {
    public boolean DFS(int currentNode, int destinationNode, int n, Map<Integer, List<Integer>> graph) {
        boolean[] visited = new boolean[n];
        Arrays.fill(visited, false);

        Stack<Integer> stack = new Stack<>();
        stack.push(currentNode);

        while (!stack.isEmpty()) {
            currentNode = stack.pop();

            if (currentNode == destinationNode) {
                return true;
            }

            if (visited[currentNode]) {
                continue;
            }

            visited[currentNode] = true;

            for (int neighborNode : graph.get(currentNode)) {
                stack.push(neighborNode);
            }
        }

        return false;
    }

    public boolean validPath(int n, int[][] edges, int source, int destination) {
        Map<Integer, List<Integer>> graph = new HashMap<>();

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph.computeIfAbsent(u, val -> new ArrayList<>()).add(v);
            graph.computeIfAbsent(v, val -> new ArrayList<>()).add(u);
        }

        return DFS(source, destination, n, graph);
    }
}
