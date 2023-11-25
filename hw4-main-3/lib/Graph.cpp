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
    const auto& it = _adjList.find(vertex);
    if(it == _adjList.end()){
        return nullopt;
    }else{
        return it->second;
    }
}


#endif // GRAPH_CPP