/*djikstra's algorithm (monte carlo simulation)*/
#include<bits/stdc++.h>
using namespace std;
class Graph
{
public:
    /*1-D graph initialization*/
    Graph(unsigned int v): vs(v), e_(0), adjs(v * v, 0) {}

    /*return vertices in graph*/
    unsigned int V() const { return vs; }

    /* return edges in graph*/
    unsigned int E() const { return e_; }

    /* true for edge from node x to node y*/
    bool adjacent(unsigned int x, unsigned int y) const {
        return adjs[index_for(x, y)] > 0;
    }

    /*return nodes y connected to node x*/
    vector<unsigned int> neighbors(unsigned int x) const {
        vector<unsigned int> result;
        for (int i = 0; i < vs; ++i)
            if (adjacent(x, i))
                result.push_back(i);

        return result;
    }

    /* Add edge from node x to node y*/
    void add_edge(unsigned int x, unsigned int y, double weight) {
        if (weight < 0)
            throw invalid_argument("Weight of an edge can not be negative!");
        if (adjs[index_for(x, y)] == 0)
            ++e_;

        adjs[index_for(x, y)] = weight;
        adjs[index_for(y, x)] = weight;
    }

    /* Remove edge from node x to node y*/
    void remove_edge(unsigned int x, unsigned int y) {
        adjs[index_for(x, y)] = 0;
        adjs[index_for(y, x)] = 0;
        --e_;
    }

    /*return value of the edge from x to y*/
    double get_edge_value(unsigned int x, unsigned int y) {
        return adjs[index_for(x, y)];
    }

protected:
    /*  Conversion of 2-D index to 1-D array*/
    unsigned int index_for(unsigned int x, unsigned int y) const {
        if (x >= vs || y >= vs)
            throw invalid_argument("Index out of bounds!");

        return x * vs + y;
    }

private:
    const unsigned int vs;
    unsigned int e_;
    vector<double> adjs;
};


class ShortestPath {
public:
    /* compution of shortest path for graph g from the start node source to all other nodes.*/
    ShortestPath(Graph g, unsigned int source = 0):
        g_(g),
        dist_(g.V(), numeric_limits<double>::max()),
        source_(source) {
        compute();
    }
    double operator[](int idx) const {
        return dist_[idx];
    }
protected:
    /* Compution of shortest path from the given start node to all other nodes with the Dijkstra algorithms.*/
    void compute() {
        priority_queue<DistNode, vector<DistNode>, less<DistNode>> nodes;

/* starting with the source node, distance to self= 0*/
        nodes.push(make_tuple(0, source_));

        while (!nodes.empty()) {
         /*next node extraction,dist from queue*/
            double d;
            unsigned int n;
            tie(d, n) = nodes.top();
            nodes.pop();

      /* update the distance array and find the next nodes to visit*/
            if (d < dist_[n])
                dist_[n] = d;

            for (const auto& w: g_.neighbors(n)) {
                auto new_dist = dist_[n] + g_.get_edge_value(n, w);
                if (new_dist < dist_[w]) {
                    dist_[w] = new_dist;
                    nodes.push(make_tuple(new_dist, w));
                }
            }
        }
    }

private:
    Graph g_;

    /* Store final distance from source node*/
    vector<double> dist_;
    unsigned int source_;
  /*store distance from source node to a node and that node's id*/
    using DistNode = tuple<double, unsigned int>;
};


class Simulator {
public:
    /* Create a simulator with the given parameter*/
    Simulator(int num = 50, double density = 0.2,
              double distance_min = 1, double distance_max = 10,
              int times = 50):
        num_(num),
        den_(density),
        random_generator_(time(NULL)),
        distance_distribution_(distance_min, distance_max),
        existence_distribution_(0.0, 1.0) {
        double sum_avg_dist = 0;
        for (int i = 0; i < times; ++i) {
            sum_avg_dist += run_simulation();
        }
        avg_ = sum_avg_dist / times;
    }

    /* return average distance of shortest path*/
    double average_distance() const {
        return avg_;
    }

protected:
    /* Generate a graph and run the simulation.
    return the average shortest path of the generated graph*/
    double run_simulation() {
        Graph g = generate_graph();
        ShortestPath sp(g, 0);
        int count = 0;
        double sum = 0;

        for (int i = 1; i < g.V(); ++i)
            if (sp[i] < numeric_limits<double>::max()) {
                ++count;
                sum += sp[i];
            }

        return sum / count;
    }

    /* generated graph with given parameter*/
    Graph generate_graph() {
        Graph g(num_);
        for (int i = 0; i < num_ - 1; ++i)
            for (int j = i + 1; j < num_; ++j)
                if (existence_distribution_(random_generator_) < den_)
                    g.add_edge(i, j, distance_distribution_(random_generator_));

        return g;
    }

private:
    double avg_;
    int num_;
    double den_;
    mt19937 random_generator_;
    uniform_real_distribution<double> distance_distribution_;
    uniform_real_distribution<double> existence_distribution_;
};


int main()
{   cout<<"solution of assignment@2:"<<endl;
    cout << "Starting..." << endl;

    Simulator sim20;
    cout << "When density is 20%: average distance is "
         << sim20.average_distance() << endl;

    Simulator sim40(50, 0.4);
    cout << "When density is 40%: average distance is "
         << sim40.average_distance() << endl;

    return 0;
}
