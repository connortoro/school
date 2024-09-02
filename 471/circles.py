input1 = [(1, 3, 0.7), (2, 3, 0.4), (3, 3, 0.9)] #true
input2 = [(1.5, 1.5, 1.3), (4, 4, 0.7)] #false
input3 = [(0.5, 0.5, 0.5), (1.5, 1.5, 1.1), (0.7, 0.7, 0.4), (4, 4, 0.7)] #false
input4 = [(1.5, 1.5, 1.1), (0.7, 0.7, 0.4), (4, 4, 0.7), (5, 4, 1)] #false, two separate clusters

# Returns true if the two circles intersect, false if they don't
def circles_intersect(circle1, circle2):
    x1, y1, r1 = circle1
    x2, y2, r2 = circle2
    dist = (abs((x2 - x1) ** 2) + abs((y2 - y1) ** 2)) ** 0.5
    rdiff = abs(r1 - r2)
    if dist <= r1 + r2 and dist >= rdiff:
        return True
    return False

# Returns true if set of edges form a connected graph, false if they don't (using depth first search)
def is_connected(edges, n):
    edge_map = {}
    for x, y in edges:
        if x not in edge_map:
            edge_map[x] = set()
        if y not in edge_map:
            edge_map[y] = set()
        edge_map[x].add(y)
        edge_map[y].add(x)

    visited = set()
    def dfs(circle):
        if circle not in edge_map:
            return
        visited.add(circle)
        for adj_circle in edge_map[circle]:
            if adj_circle not in visited:
                dfs(adj_circle)

    dfs(0)
    return n == len(visited)


# Returns true if set of circles form a cluster, false if they don't
def forms_cluster(circles):
    edges = []
    for i, circle_a in enumerate(circles):
        for j, circle_b in enumerate(circles):
            if circles_intersect(circle_a, circle_b) and i != j and (i, j):
                edges.append((i, j))
    return is_connected(edges , len(circles))





# print("------TEST CIRCLES INTERSECT---------")
# print("True == " + str(circles_intersect((1, 3, 0.7), (2, 3, 0.4))))
# print("False == " + str(circles_intersect((1.5, 1.5, 1.3), (4, 4, 0.7))))
# print("False == " + str(circles_intersect((1, 1, 10), (1.5, 1.5, 2))))
# print("True == " + str(circles_intersect((1, 1, 3), (1, 1, 3))))

print("------TEST FORMS CLUSTER---------")
print("True == " + str(forms_cluster(input1)))
print("False == " + str(forms_cluster(input2)))
print("False == " + str(forms_cluster(input3)))
print("False == " + str(forms_cluster(input4)))

