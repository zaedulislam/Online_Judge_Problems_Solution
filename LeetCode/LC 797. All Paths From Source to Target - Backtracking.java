class Solution {
    public void backtrack(int currentNode, int targetNode, ArrayList<Integer> currentPath, List<List<Integer>> allPaths, int[][] graph) {
        if (currentNode == targetNode) {
            allPaths.add(new ArrayList<Integer>(currentPath));
            return;
        }

        for (int neighborNode : graph[currentNode]) {
            currentPath.add(neighborNode);

            backtrack(neighborNode, targetNode, currentPath, allPaths, graph);

            currentPath.removeLast();
        }
    }

    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        int n = graph.length;

        List<List<Integer>> allPaths = new ArrayList<>();

        ArrayList<Integer> currentPath = new ArrayList<>();

        currentPath.add(0);

        backtrack(0, n - 1, currentPath, allPaths, graph);

        return allPaths;
    }
}
