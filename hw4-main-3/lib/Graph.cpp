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
    auto t = _vertices.find(vertex); // ����vertex
    if (t == _vertices.end()) { // û���ҵ�vertex
        _vertices[vertex] = GraphNode(vertex);  // �ӵ㣬�ӱ�
        _adjList[vertex] = set<T>();
    }
}

template<typename T>
void Graph<T>::addEdge(T from, T to) {
    // ����from���Ӧ�ļ����ڲ���
    auto t = _adjList.find(from);
    if (t == _adjList.end()) { // û���ҵ�
        // ����������� - ��ʽ1
//       _adjList[from] = set<T>();
//       _adjList[from].insert(to);
        // ����������� - ��ʽ2
        _adjList[from] = set<T>({to});
    } else {
        _adjList[from].insert(to);
    }
}

template<typename T>
Graph<T>::Graph(const std::map<T, std::set<T>> &adjList) {
    for (const auto &it: adjList) {
        // �ӵ�
        addVertex(it.first);
        for (const T &neighbor: it.second) {   // �����ھ�
            addVertex(neighbor);    // ���ھӼ���������
            addEdge(it.first, neighbor); // ���ھӼ���ߵ�����
        }
    }
}

template<typename T>
Graph<T>::Graph(const std::vector<std::pair<T, T>> &edges) {
    for (const pair<T, T> &each_edge: edges) {
        addVertex(each_edge.first); // �ӵ�
        addVertex(each_edge.second); // �ӵ�
        addEdge(each_edge.first, each_edge.second); // �ӱ�
    }
}

template<typename T>
int Graph<T>::size() const {
    return _vertices.size();
}


template<typename T>
bool Graph<T>::hasEdge(T from, T to) const {
    // �Ȳ鿴from�Ƿ����ڽӱ���
    auto it1 = _adjList.find(from);
    if (it1 == _adjList.end()) { // �Ҳ���from��
        return false;
    }
//    auto it2 = it1->second.find(to);
//    if(it2 == it1->second.end()){ // û�ҵ�
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