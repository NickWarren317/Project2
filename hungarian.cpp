#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
class graph{
  public:
    //adjacenecy matrix for flow rates between nodes
    vector<vector<float>> adj_matrix;

    vector<float> row_mins;
    int r_size;
    int c_size;


    graph(vector<vector<float>> cities){
        //hold rows and columns
        r_size = cities.size();
        c_size = cities[0].size();
        printf("%d %d\n", r_size, c_size);
        vector<float> temp_vec;

        for(int x = 0; x < r_size; x++){
            float min=99999;
            for(int y = 0; y < c_size; y++){
                //add to adjacency matrix
                if(min > cities[x][y]){
                    min = cities[x][y];
                }
                temp_vec.push_back(cities[x][y]);
            }
            row_mins.push_back(min);
            //push to map vector
            adj_matrix.push_back(temp_vec);
            temp_vec.clear();
        }
    }
    void printMatrix(){
        printf("\n");
        for(int x = 0; x < r_size; x++){
            for(int y = 0; y < c_size; y++){
                printf("%3.2f ", adj_matrix[x][y]);
            }
            printf("\n");
        }
        printf("\n");
    }
    void minimizeGraph(){
        //subtract row minimum
        for(int y = 0; y < r_size; y++){
            for(int x = 0; x < c_size; x++){
                adj_matrix[y][x] = adj_matrix[y][x] - row_mins[y];
            }
        }
               
        //get column minimums
        
        for(int x = 0; x < c_size; x++){
            float temp_min = 99999;
            for(int y = 0; y < r_size; y++){
                if(adj_matrix[y][x] < temp_min){
                    temp_min = adj_matrix[y][x];
                }
            }
            for(int y = 0; y < r_size; y++){
                adj_matrix[y][x] = adj_matrix[y][x] - temp_min;
            }
          }
        }
    };



int zeroCover(vector<vector<float>> & graph){
    int ans = 0;
    //cover them zeroes

    return ans;
}

void replaceZeroes(vector<vector<float>> * graph){
    //take lowest uncovered and add it to the intersected nodes

}

float computeCost(vector<vector<float>> * graph){
    float cost = 0;

    return cost;
    //computes minimum cost
    
}
//doesnt work in this case unfortunatly
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

int main(){
    vector<vector<float>> map = {{1,2,3},
                                 {3,1,6},
                                 {7,2,4},
                                 {8,5,7}};
    graph g1 = graph(map);
    g1.printMatrix();
    g1.minimizeGraph();
    g1.printMatrix();
    return 0;
}