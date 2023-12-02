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
    const auto &it = _adjList.find(vertex);
    if (it == _adjList.end()) {
        return nullopt;
    } else {
        return it->second;
    }
}

template<typename T>
std::list<T> Graph<T>::DFS() {
    // ��һ�����ҵ����Ϊ0�Ľڵ�
    map<T, int> count; // ĳ���㵽��T��Ĵ���
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
            // ���Ϊ0�Ľڵ㣬��ʼdfs���ʸýڵ�
            if (_vertices.find(it.first)->second.color == White) {// �жϽڵ��Ƿ��ǰ�ɫ
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
    queue<T>q;  // �������
    set<T>state; // ����״̬��������ʾ�Ƿ��Ѿ��������
    vector<T> result;

    q.push(start);
    state.insert(start);

    while (!q.empty()){
        T cur = q.front(); // �õ���ͷԪ��
        q.pop();    // ����Ԫ�شӶ�ͷ�Ƴ�
        result.push_back(cur);

        auto it = _adjList.find(cur);
        for(T neighbor:it->second){ // it->second �����ھӼ���
            auto it2 = state.find(neighbor);
            if(it2==state.end()){   // ���ھӽڵ�δ�������
                q.push(neighbor);
                state.insert(neighbor); // ��Ǹ��ھ��Ѿ��������
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
//    queue<T>q;  // �������
//    set<T>state; // ����״̬��������ʾ�Ƿ��Ѿ��������
//    vector<T> result;
//    map<T,int>dis;
//    dis[start] = 0;
//
//    q.push(start);
//    state.insert(start);
//
//    while (!q.empty()){
//        T cur = q.front(); // �õ���ͷԪ��
//        q.pop();    // ����Ԫ�شӶ�ͷ�Ƴ�
//        result.push_back(cur);
//        if(cur==end){
//            return result;
//        }
//        auto it = _adjList.find(cur);
//        for(T neighbor:it->second){ // it->second �����ھӼ���
//            auto it2 = state.find(neighbor);
//            if(it2==state.end()){   // ���ھӽڵ�δ�������
//                q.push(neighbor);
//                state.insert(neighbor); // ��Ǹ��ھ��Ѿ��������
//                dis[neighbor] = dis[cur]+1;
//            }
//        }
//    }
//    return result;
//}

template<typename T>
vector<char> Graph<T>::shortestPath(T start, T end) {
    queue<T>q;  // �������
    set<T>state; // ����״̬��������ʾ�Ƿ��Ѿ��������
    vector<char> result;
    /* ���� ��Ϊ ��*/
    auto it1 = _vertices.find(start);
    it1->second.predecessor = nullopt;

    q.push(start);
    state.insert(start);

    while (!q.empty()){
        T cur = q.front(); // �õ���ͷԪ��
        q.pop();    // ����Ԫ�شӶ�ͷ�Ƴ�
        if(cur==end){
            break;
        }
        auto it = _adjList.find(cur);
        for(T neighbor:it->second){ // it->second �����ھӼ���
            auto it2 = state.find(neighbor);
            if(it2==state.end()){   // ���ھӽڵ�δ�������
                q.push(neighbor);
                state.insert(neighbor); // ��Ǹ��ھ��Ѿ��������
                auto it2 = _vertices.find(neighbor);    // ��������
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