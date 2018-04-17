// #include "../hh/astar.hh"
//
// void calculateHeuristic(Stop* stop){
//   for (auto& e: stops{
//     tmp = (stop.localization.x - e.localization.x) *
//               (stop.localization.x - e.localization.x) +
//           (stop.localization.y - e.localization.y) *
//               (stop.localization.y - e.localization.y);
//     tmp = sqrt(tmp);
//     distances[e->returnId()] = tmp;
//   }
// }
//
// aStar(vector<Stop*> stopp){
// stops=stopp;
// }
//
// function findPath(Stop* start,Stop* stop){
// c
// }
// function A*(start,goal)
//     closedset := the empty set                 % Zbiór wierzchołków przejrzanych.
//     openset := set containing the initial node % Zbiór wierzchołków nie odwiedzonych.
//     g_score[start] := 0                        % Długość optymalnej trasy.
//     while openset is not empty
//         x := the node in openset having the lowest f_score[] value
//         if x = goal
//             return reconstruct_path(came_from,goal)
//         remove x from openset
//         add x to closedset
//         foreach y in neighbor_nodes(x)
//             if y in closedset
//                 continue
//             tentative_g_score := g_score[x] + dist_between(x,y)
//             tentative_is_better := false
//             if y not in openset
//                 add y to openset
//                 h_score[y] := heuristic_estimate_of_distance_to_goal_from(y)
//                 tentative_is_better := true
//             elseif tentative_g_score < g_score[y]
//                 tentative_is_better := true
//             if tentative_is_better = true
//                 came_from[y] := x
//                 g_score[y] := tentative_g_score
//                 f_score[y] := g_score[y] + h_score[y] % Przewidywany dystans od startu do celu przez y.
//     return failure
//
// function reconstruct_path(came_from,current_node)
//     if came_from[current_node] is set
//         p = reconstruct_path(came_from,came_from[current_node])
//         return (p + current_node)
//     else
//         return the empty path
//
//         inline double heuristic(GridLocation a, GridLocation b) {
//           return std::abs(a.x - b.x) + std::abs(a.y - b.y);
//         }
//
//         template<typename Location, typename Graph>
//         void a_star_search
//           (Graph graph,
//            Location start,
//            Location goal,
//            std::map<Location, Location>& came_from,
//            std::map<Location, double>& cost_so_far)
//         {
//           PriorityQueue<Location, double> frontier;
//           frontier.put(start, 0);
//
//           came_from[start] = start;
//           cost_so_far[start] = 0;
//
//           while (!frontier.empty()) {
//             Location current = frontier.get();
//
//             if (current == goal) {
//               break;
//             }
//
//             for (Location next : graph.neighbors(current)) {
//               double new_cost = cost_so_far[current] + graph.cost(current, next);
//               if (cost_so_far.find(next) == cost_so_far.end()
//                   || new_cost < cost_so_far[next]) {
//                 cost_so_far[next] = new_cost;
//                 double priority = new_cost + heuristic(next, goal);
//                 frontier.put(next, priority);
//                 came_from[next] = current;
//               }
//             }
//           }
//         }
