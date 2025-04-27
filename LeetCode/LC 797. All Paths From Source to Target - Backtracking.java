class Solution {
    public void DFS(int currentNode, int destinationNode, ArrayList<Integer> currentPath, List<List<Integer>> allPaths, int[][] graph) {
        if (currentNode == destinationNode) {
            allPaths.add(new ArrayList<Integer>(currentPath));
            return;
        }

        for (int neighborNode : graph[currentNode]) {
            currentPath.add(neighborNode);

            DFS(neighborNode, destinationNode, currentPath, allPaths, graph);

            currentPath.removeLast();
        }
    }

    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        int n = graph.length;

        List<List<Integer>> allPaths = new ArrayList<>();

        ArrayList<Integer> currentPath = new ArrayList<>();

        currentPath.add(0);

        DFS(0, n - 1, currentPath, allPaths, graph);

        return allPaths;
    }
}
