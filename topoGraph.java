import java.util.*;

public class TopoGraph {
    private Map<String, List<String>> list;

    //Constructor to initialize the list
    public TopoGraph() {
        list = new HashMap<>();
    }

    //Method to add an edge to the graph
    public void addEdge(String u, String v) {
        list.putIfAbsent(u, new ArrayList<>());
        list.get(u).add(v);
    }

    public void addNode(String node) {
        list.putIfAbsent(node, new ArrayList<>());
    }

    // dfs  based Helper function for topological sorting
    private void topoHelper(String sourceNode, Map<String, Boolean> visited, Stack<String> stack) {

        //mark current node as visited
        visited.put(sourceNode, true);

        //Recursively visit all unvisited neighbours
        for (String v : list.getOrDefault(sourceNode, new ArrayList<>())) {
            if (!visited.getOrDefault(v, false)) {
                topoHelper(v, visited, stack);
            }
        }

        stack.push(sourceNode);
    }

    //topological sort function
    public void topoSort() {
        Map<String, Boolean> visited = new HashMap<>();
        Stack<String> stack = new Stack<>();

        //ensure all nodes are visited
        for (String node : list.keySet()) {
            if (!visited.getOrDefault(node, false)) {
                topoHelper(node, visited, stack);
            }
        }

        //print topological order
        System.out.print("Topological Sort : ");
        while (!stack.isEmpty()) {
            System.out.print(stack.pop() + " ");

        }
        System.out.println();
    }

    public static void main(String[] args) {
        TopoGraph graph = new TopoGraph();

        graph.addEdge("Underwear", "Shoes");
        graph.addEdge("Underwear", "Pants");
        graph.addEdge("Pants", "Shoes");
        graph.addEdge("Pants", "Belt");
        graph.addEdge("Shirt", "Belt");
        graph.addEdge("Shirt", "Tie");
        graph.addEdge("Tie", "Jacket");
        graph.addEdge("Socks", "Shoes");
        graph.addNode("Watch");

        // Performing Topological Sorting
        graph.topoSort();
    }
}

