# Bacic Components:
Node: Fundamental unit of a tree
Edge: Conenction between two nodes
Root: Topmost element
Parent: A node having children
Child: A node directly conencted to another node 
Sibling: Nodes that share same parent
Leaf: External nodes with no children
Internal Node: Node with atleast one child

# Structural Terms:
Subtree: a tree formed by a node and all its descendants
Ancestor: Any node on the path from the room to a given node
Descendant: Any node reachable by following child links from a given node
Path: A sequence of nodes where each adjacent pair is connected
Path length: The number of edges in a path

# Measurement Terms:
Depth: Distance from the root to that node
Height (Node): Longest path from that node down to a leaf
Height (Tree): Height of the root node, or the max depth in the tree
Degree (Node): Number of children that node has
Degree (Tree): Maximum degree of any node in the tree

# Traversal Terms:
Preorder: Root -> Left -> Right
Inorder: Left -> Root -> Right
Postorder: Left -> Right -> Root
Level Order: Visit nodes level by level from top to bottom

Depth First Search : Explore as far as possible along each branch before backtracking
Breadth First Search: Explore all neightbours at that current depth before moving deeper

# Applications:

Your computer's file system is organized as a tree. Folders are internal nodes, files are leaves, and the root directory is the tree's root. This makes navigation, searching, and organization intuitive.

B-trees and B+ trees are extensively used in databases to index records, allowing quick searches, insertions, and deletions even with millions of entries.

Git uses tree structures to represent commits, branches, and file hierarchies, tracking changes over time.

BST: Used for maintaining sorted data with efficient search (O(log n)). Applications include dictionary implementations, symbol tables in compilers, and autocomplete features.

Heaps: Implement priority queues used in scheduling algorithms, Dijkstra's shortest path algorithm, and event-driven simulations. Operating systems use heaps for task scheduling.

Routers use tree structures (particularly tries) to quickly determine the best path for data packets across the internet.

Network designs often use spanning trees to prevent loops while ensuring all devices remain connected.

Huffman Coding: Uses binary trees to create optimal prefix codes for data compression, reducing file sizes for images, videos, and text.
