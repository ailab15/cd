import java.util.*;
public class TopDownParser { 
    public static void main(String[] args) { 
    // Example grammar: S -> A, A -> aA | ε 
    Map<String, Set<String>> firstSets = new HashMap<>(); 
    Map<String, Set<String>> followSets = new HashMap<>(); 
    // Construct FIRST sets 
    firstSets.put("S", new HashSet<>()); 
    firstSets.put("A", new HashSet<>()); 
    firstSets.get("S").add("a"); 
    firstSets.get("A").add("a"); 
    firstSets.get("A").add("ε"); 
    // Construct FOLLOW sets 
    followSets.put("S", new HashSet<>()); 
    followSets.put("A", new HashSet<>()); 
    followSets.get("S").add("$"); 
    followSets.get("A").add("$"); 
    followSets.get("A").add("a"); 
    // Construct parse table 
    Map<String, Map<String, String>> parseTable = new HashMap<>(); 
    parseTable.put("S", new HashMap<>()); 
    parseTable.put("A", new HashMap<>()); 
    parseTable.get("S").put("a", "A"); 
    parseTable.get("A").put("a", "aA"); 
    parseTable.get("A").put("$", "ε"); 
    // Print FIRST sets 
    System.out.println("FIRST sets:"); 
    for (Map.Entry<String, Set<String>> entry : firstSets.entrySet()) { 
    System.out.println(entry.getKey() + ": " + entry.getValue()); 
    } 
    // Print FOLLOW sets 
    System.out.println("\nFOLLOW sets:"); 
    for (Map.Entry<String, Set<String>> entry : followSets.entrySet()) { 
    System.out.println(entry.getKey() + ": " + entry.getValue()); 
    } 
    // Print parse table 
    System.out.println("\nParse Table:"); 
    for (Map.Entry<String, Map<String, String>> entry : parseTable.entrySet()) { 
    String nonTerminal = entry.getKey(); 
    Map<String, String> actions = entry.getValue(); 
    System.out.println("Non-Terminal: " + nonTerminal); 
    System.out.println("Actions: " + actions); 
    } 
    } 
    } 