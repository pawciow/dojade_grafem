// // #include "../hh/astar.hh"
// //
// // void calculateHeuristic(Stop* stop){
// //   for (auto& e: stops{
// //     tmp = (stop.localization.x - e.localization.x) *
// //               (stop.localization.x - e.localization.x) +
// //           (stop.localization.y - e.localization.y) *
// //               (stop.localization.y - e.localization.y);
// //     tmp = sqrt(tmp);
// //     distances[e->returnId()] = tmp;
// //   }
// // }
// //
// // aStar(vector<Stop*> stopp){
// // stops=stopp;
// // }
// //
// std::map<int, int>& came_from;
// std::map<int, double>& cost_so_far;
//
// function findPath(Stop* start,Stop* stop){
// int start_id=start->returnId();
//   int goal_id = stop-> returnId();
//   PriorityQueue<int, double> frontier;
//   frontier.put(start_id,0);
//   came_from[start_id]=start_id;
//   const_so_far=0;
//
//   while (!frontier.empty()) {
//     int current = frontier.get();
//
//     if (current == goal_id) {
//       break;
//     }
// iteracja po connections w przystanku
//     for (Location next : graph.neighbors(current)) {
//       double new_cost = cost_so_far[current] (+czas przejazdu graph.cost(current, next));
//
//     if (cost_so_far.find(next) == cost_so_far.end() || new_cost < cost_so_far[next]) {
//         cost_so_far[next] = new_cost;
//         double priority = new_cost + heuristic(next, goal);
//         frontier.put(next, priority);
//         came_from[next] = current;
//       }
//     }
//   }
// }
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
