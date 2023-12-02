#ifndef GRAPH_CPP
#define GRAPH_CPP

#include "Graph.hpp"
#include "GraphNode.hpp"
#include <queue>
#include "set"

using namespace std;

// TODO: Implement all other methods defined in Graph.hpp here


template<typename T>
void Graph<T>::addVertex(T vertex) {
    auto t = _vertices.find(vertex); // 查找vertex
    if (t == _vertices.end()) { // 没有找到vertex
        _vertices[vertex] = GraphNode(vertex);  // 加点，加边
        _adjList[vertex] = set<T>();
    }
}

template<typename T>
void Graph<T>::addEdge(T from, T to) {
    // 查找from点对应的集合在不在
    auto t = _adjList.find(from);
    if (t == _adjList.end()) { // 没有找到
        // 创建这个集合 - 方式1
//       _adjList[from] = set<T>();
//       _adjList[from].insert(to);
        // 创建这个集合 - 方式2
        _adjList[from] = set<T>({to});
    } else {
        _adjList[from].insert(to);
    }
}

template<typename T>
Graph<T>::Graph(const std::map<T, std::set<T>> &adjList) {
    for (const auto &it: adjList) {
        // 加点
        addVertex(it.first);
        for (const T &neighbor: it.second) {   // 遍历邻居
            addVertex(neighbor);    // 将邻居加入点的链表
            addEdge(it.first, neighbor); // 将邻居加入边的链表
        }
    }
}

template<typename T>
Graph<T>::Graph(const std::vector<std::pair<T, T>> &edges) {
    for (const pair<T, T> &each_edge: edges) {
        addVertex(each_edge.first); // 加点
        addVertex(each_edge.second); // 加点
        addEdge(each_edge.first, each_edge.second); // 加边
    }
}

template<typename T>
int Graph<T>::size() const {
    return _vertices.size();
}


template<typename T>
bool Graph<T>::hasEdge(T from, T to) const {
    // 先查看from是否在邻接表中
    auto it1 = _adjList.find(from);
    if (it1 == _adjList.end()) { // 找不到from点
        return false;
    }
//    auto it2 = it1->second.find(to);
//    if(it2 == it1->second.end()){ // 没找到
//        return false;
//    }
//    return true;
    return it1->second.find(to) != it1->second.end();
}

template<typename T>
std::optional<std::set<T>> Graph<T>::getNeighbors(T vertex) const {
    const auto &it = _adjList.find(vertex);
    if (it == _adjList.end()) {
        return nullopt;
    } else {
        return it->second;
    }
}

template<typename T>
std::list<T> Graph<T>::DFS() {
    // 第一步，找到入度为0的节点
    map<T, int> count; // 某个点到达T点的次数
    list <T> record;
    int time = 0;
    for (auto it: _adjList) {
        // it->first
        for (T neighbor: it.second) {
            if (count.find(neighbor) == count.end()) {
                count[neighbor] = 1;
            } else {
                count[neighbor]++;
            }
        }
    }
    for (auto it: _adjList) {
        if (count[it.first] == 0) {
            // 入读为0的节点，开始dfs访问该节点
            if (_vertices.find(it.first)->second.color == White) {// 判断节点是否是白色
                DFS_visit(it.first, time, record);
            }

        }
    }
    return record;
}

template<typename T>
void Graph<T>::DFS_visit(const T &u, int &time, std::list<T> &record) {
    time++;
    auto it1 = _vertices.find(u);
    GraphNode<T> &cur_node = it1->second;
    cur_node.color = Gray;
    cur_node.discovery_time = time;

    auto it2 = _adjList.find(u);
    for (T neighbor: it2->second) {
        if (_vertices.find(neighbor)->second.color == White) {
            DFS_visit(neighbor, time, record);
        }
    }
//    cout<<u<<endl;
    time++;
    cur_node.finish_time = time;
    cur_node.color = Black;
    record.push_front(u);
}

template<typename T>
std::vector<T> Graph<T>::BFS(T start) {
    queue<T>q;  // 定义队列
    set<T>state; // 定义状态变量，表示是否已经入过队列
    vector<T> result;

    q.push(start);
    state.insert(start);

    while (!q.empty()){
        T cur = q.front(); // 拿到队头元素
        q.pop();    // 将该元素从队头移出
        result.push_back(cur);

        auto it = _adjList.find(cur);
        for(T neighbor:it->second){ // it->second 就是邻居集合
            auto it2 = state.find(neighbor);
            if(it2==state.end()){   // 该邻居节点未入过队列
                q.push(neighbor);
                state.insert(neighbor); // 标记该邻居已经入过队列
            }
        }
    }
//    for (int i = 0; i < result.size(); ++i) {
//        cout<<result[i]<<endl;
//    }

    return result;
}

//template<typename T>
//vector<char> Graph<T>::shortestPath(T start, T end) {
//    queue<T>q;  // 定义队列
//    set<T>state; // 定义状态变量，表示是否已经入过队列
//    vector<T> result;
//    map<T,int>dis;
//    dis[start] = 0;
//
//    q.push(start);
//    state.insert(start);
//
//    while (!q.empty()){
//        T cur = q.front(); // 拿到队头元素
//        q.pop();    // 将该元素从队头移出
//        result.push_back(cur);
//        if(cur==end){
//            return result;
//        }
//        auto it = _adjList.find(cur);
//        for(T neighbor:it->second){ // it->second 就是邻居集合
//            auto it2 = state.find(neighbor);
//            if(it2==state.end()){   // 该邻居节点未入过队列
//                q.push(neighbor);
//                state.insert(neighbor); // 标记该邻居已经入过队列
//                dis[neighbor] = dis[cur]+1;
//            }
//        }
//    }
//    return result;
//}

template<typename T>
vector<char> Graph<T>::shortestPath(T start, T end) {
    queue<T>q;  // 定义队列
    set<T>state; // 定义状态变量，表示是否已经入过队列
    vector<char> result;
    /* 祖先 置为 空*/
    auto it1 = _vertices.find(start);
    it1->second.predecessor = nullopt;

    q.push(start);
    state.insert(start);

    while (!q.empty()){
        T cur = q.front(); // 拿到队头元素
        q.pop();    // 将该元素从队头移出
        if(cur==end){
            break;
        }
        auto it = _adjList.find(cur);
        for(T neighbor:it->second){ // it->second 就是邻居集合
            auto it2 = state.find(neighbor);
            if(it2==state.end()){   // 该邻居节点未入过队列
                q.push(neighbor);
                state.insert(neighbor); // 标记该邻居已经入过队列
                auto it2 = _vertices.find(neighbor);    // 设置祖先
                it2->second.predecessor = cur;
            }
        }
    }

    auto it3 = _vertices.find(end);
    result.push_back(end);
    auto predecessor = it3->second.predecessor;
    while (predecessor.has_value()){
        T parent = predecessor.value();
        result.push_back(parent);
        predecessor = _vertices.find(parent)->second.predecessor;
    }
    std::reverse(result.begin(), result.end());
//    for (int i = 0; i < result.size(); ++i) {
//        cout<<result[i]<<endl;
//    }
    return result;
}

#endif // GRAPH_CPP