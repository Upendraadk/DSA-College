import matplotlib.pyplot as plt

# Node class for AVL Tree
class Node:
    def __init__(self, key):
        self.key = key           # Value stored in node
        self.left = None         # Left child
        self.right = None        # Right child
        self.height = 1          # Height of node (leaf nodes start at height 1)

# Get height of a node, return 0 if node is None
def get_height(node):
    if node is None:
        return 0
    return node.height

# Get balance factor of node = height(left subtree) - height(right subtree)
def get_balance(node):
    if node is None:
        return 0
    return get_height(node.left) - get_height(node.right)

# Right rotation to balance the tree (used in Left-Left imbalance)
def right_rotate(y):
    x = y.left
    T2 = x.right

    # Perform rotation
    x.right = y
    y.left = T2

    # Update heights after rotation
    y.height = max(get_height(y.left), get_height(y.right)) + 1
    x.height = max(get_height(x.left), get_height(x.right)) + 1

    # Return new root
    return x

# Left rotation to balance the tree (used in Right-Right imbalance)
def left_rotate(x):
    y = x.right
    T2 = y.left

    # Perform rotation
    y.left = x
    x.right = T2

    # Update heights after rotation
    x.height = max(get_height(x.left), get_height(x.right)) + 1
    y.height = max(get_height(y.left), get_height(y.right)) + 1

    # Return new root
    return y

# Recursive insertion function to add a key to the AVL tree and balance it
def insert(node, key):
    # Perform normal BST insertion
    if node is None:
        return Node(key)

    if key < node.key:
        node.left = insert(node.left, key)
    elif key > node.key:
        node.right = insert(node.right, key)
    else:
        # Duplicate keys are not allowed in BST/AVL
        return node

    # Update height of ancestor node
    node.height = 1 + max(get_height(node.left), get_height(node.right))

    # Get balance factor to check if this node became unbalanced
    balance = get_balance(node)

    # Check and fix unbalanced cases:

    # Left Left Case
    if balance > 1 and key < node.left.key:
        return right_rotate(node)

    # Right Right Case
    if balance < -1 and key > node.right.key:
        return left_rotate(node)

    # Left Right Case
    if balance > 1 and key > node.left.key:
        node.left = left_rotate(node.left)
        return right_rotate(node)

    # Right Left Case
    if balance < -1 and key < node.right.key:
        node.right = right_rotate(node.right)
        return left_rotate(node)

    # Return the unchanged node pointer
    return node

# ---------- Visualization Logic ----------

# Recursive function to get (x,y) positions for each node to plot
def get_positions(node, depth=0, pos_dict={}, x=0):
    if node is None:
        return x
    # Traverse left subtree and assign positions
    x = get_positions(node.left, depth + 1, pos_dict, x)
    # Assign position to current node
    pos_dict[node] = (x, -depth)  # x increases left to right, y is negative depth for plotting top-down
    x += 1
    # Traverse right subtree and assign positions
    x = get_positions(node.right, depth + 1, pos_dict, x)
    return x

# Draw the AVL tree using matplotlib based on positions computed
def draw_tree(root):
    pos_dict = {}
    get_positions(root, pos_dict=pos_dict)

    fig, ax = plt.subplots()
    ax.set_title("AVL Tree Visualization")
    ax.set_axis_off()  # Hide axis

    # Draw nodes and edges
    for node, (x, y) in pos_dict.items():
        # Draw node as a circle with key inside
        ax.text(x, y, str(node.key), ha='center', va='center',
                bbox=dict(facecolor='skyblue', boxstyle='circle'))

        # Draw edges to left and right children if exist
        if node.left:
            x2, y2 = pos_dict[node.left]
            ax.plot([x, x2], [y, y2], color='gray')
        if node.right:
            x2, y2 = pos_dict[node.right]
            ax.plot([x, x2], [y, y2], color='gray')

    plt.tight_layout()
    plt.show()

# -------- Main --------
if __name__ == "__main__":
    root = None
    # Insert values into AVL tree
    for key in [10,11,12]:
        root = insert(root, key)

    # Visualize the constructed AVL tree
    draw_tree(root)
