#include <vector>
#include <stdlib.h>

using namespace std;
class graph{
  public:
    //adjacenecy matrix for flow rates between nodes
    vector<vector<float>> adj_matrix;
    vector<node> node_list;
    int size;


    graph(vector<vector<float>> cities){
        size = cities[0].size();
        vector<float> temp_vec;
        for(int x = 0; x < size; x++){
            node new_node;
            new_node.id = x;
            node_list.push_back(new_node);
            for(int y = 0; y < size; y++){
                //add to adjacency matrix
                temp_vec.push_back(cities[x][y]);
            }
            //push to map vector
            adj_matrix.push_back(temp_vec);
            temp_vec.clear();
        }
    }
    void printMatrix(){
        printf("     ");
        for(int i = 0; i < size; i++){
            printf("%3d  ", i + 1);
        }   
        printf("\n");
        printf("\n");
        for(int x = 0; x < size; x++){
            for(int y = 0; y < size; y++){
                if(y == 0){
                    printf("%3d   ",x + 1);
                }
                printf("%3.2f ", adj_matrix[x][y]);
            }
            printf("\n");
        }
        printf("\n");
    }

};
vector<vector<float>> * minimizeGraph(vector<vector<float>> * input_graph){
    //subtract row minimum

    //subtract column minimum

    return input_graph;
}

int zeroCover(vector<vector<float>> & graph){
    int ans = 0;
    //cover them zeroes

    return ans;
}

void replaceZeroes(vector<vector<float>> * graph){
    //take lowest uncovered and add it to the intersected nodes

}

float computeCost(vector<vector<float>> * graph){
    //computes minimum cost
    
}
vector<vector<float>> random_map_generator(int size, int max_distance){
    vector<float> new_row;
    vector<vector<float>> ans;

    for(int i = 0; i < size; i++){
        if(i == 0){
            new_row.push_back(0);
        } else {
            new_row.push_back(((float) rand() / (RAND_MAX)) * max_distance + 1);
        }
        
    }

    ans.push_back(new_row);
    new_row.clear();
    
    for(int y = 1; y < size; y++){
        for(int x = 0; x < size; x++){
            if(x < y){
                new_row.push_back(ans[x][y]);
            } else if(x == y){
                new_row.push_back(0);
            } else {
                new_row.push_back(((float) rand() / (RAND_MAX))*max_distance + 1);
            } 
        }
        ans.push_back(new_row);
        new_row.clear();
    }

    return ans;
}

struct node{
    int id;
};

int main(){

    return 0;
}