#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
class graph {
  public:
    //adjacenecy matrix for flow rates between nodes
    vector<vector<float>> adj_matrix;

    vector<float> row_mins;

    vector<int> Zrows, Zcols;

    int y_size;
    int x_size;

    int num_zeroes;


    graph(vector<vector<float>> cities){
        //hold rows and columns
        y_size = cities.size();
        x_size = cities[0].size();
        printf("%d %d\n", y_size, x_size);
        vector<float> temp_vec;
        num_zeroes = 0;

        Zrows = vector<int>(x_size,0);
        Zcols = vector<int>(y_size,0);


        for(int x = 0; x < y_size; x++){
            float min=99999;
            for(int y = 0; y < x_size; y++){
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
        for(int x = 0; x < y_size; x++){
            for(int y = 0; y < x_size; y++){
                printf("%3.2f ", adj_matrix[x][y]);
            }
            printf("\n");
        }
        printf("\n");
    }
    void minimizeGraph(){
        //subtract row minimum
        for(int y = 0; y < y_size; y++){
            for(int x = 0; x < x_size; x++){
                adj_matrix[y][x] = adj_matrix[y][x] - row_mins[y];
            }
        }
               
        //get column minimums
        
        for(int x = 0; x < x_size; x++){
            float temp_min = 99999;
            for(int y = 0; y < y_size; y++){
                if(adj_matrix[y][x] < temp_min){
                    temp_min = adj_matrix[y][x];
                }
            }
            for(int y = 0; y < y_size; y++){
                adj_matrix[y][x] = adj_matrix[y][x] - temp_min;
                if(adj_matrix[y][x] == 0){
                    num_zeroes++;
                    Zrows[y]++;
                    Zcols[x]++;
                }
            }
          }
        }

        int zeroCover(){
            int ans = 0;
            vector<bool> markedRows(y_size,false);
            vector<bool> markedCols(x_size,false);
            
            bool zeroesFound = true;

            while(zeroesFound){
                bool workFlag = false;
                zeroesFound = false;
                //iterate rows checking for exactly one unmarked zero.
                for(int r = 0; r < y_size; r++){
                    if(Zrows[r] == 1 && !markedRows[r]){
                      for(int c = 0; c < x_size; c++){
                        if(adj_matrix[r][c] == 0 && !markedCols[c]){
                            for(int i = 0; i < y_size; i++) if(adj_matrix[i][c] == 0) Zrows[i]--;
                            markedCols[c] = true;
                            workFlag = true;
                            printf("Marking col %d\n",c);
                            zeroesFound = true;
                            Zcols[c] = 0;
                            ans++;
                        }
                     }
                    }
                }
                     /*
                     for(int c = 0; c < x_size; c++){
                        if(adj_matrix[r][c] == 0 && Zrows[r] == 1 && !markedCols[c] && !markedRows[r]){
                            markedCols[c] = true;
                            workFlag = true;
                            printf("Marking col %d\n",r);
                            currentZ = currentZ - Zcols[c];
                            //Zrows[r]--;
                        }
                     }
                     */
                
                //iterate cols checking for exactly one unmarked zero in an unmarked row.
                for(int c = 0; c < x_size; c++){
                    for(int r = 0; r < y_size; r++){
                        if(adj_matrix[r][c] == 0 && Zcols[c] == 1 && !markedRows[r] && !markedCols[c]){
                            for(int i = 0; i < x_size; i++) if(adj_matrix[r][i] == 0) Zcols[i]--;
                            markedRows[r] = true;
                            workFlag = true;
                            zeroesFound = true;
                            printf("Marking row %d\n",r);
                            ans++;
                        }
                    }
                }
                //FIX ME
                if(!workFlag){
                    for(int c = 0; c < x_size; c++){
                      if(!markedCols[c]){
                        for(int r = 0; r < y_size; r++){
                            if(adj_matrix[r][c] == 0 && !markedRows[r]){
                                if(Zrows[r] > Zrows[c]){
                                    for(int i = 0; i < x_size; i++) if(adj_matrix[r][i] == 0) Zcols[i]--;
                                    markedRows[r] = true;
                                    ans++;
                                    zeroesFound = true;
                                    printf("Marking row: %d\n",r);
                                } else {
                                    for(int i = 0; i < y_size; i++) if(adj_matrix[i][c] == 0) Zrows[i]--;
                                    markedCols[c] = true;
                                    ans++;
                                    zeroesFound = true;
                                    printf("Marking col: %d\n",c);
                                }
                            }
                          }
                      }
                    }
                }
            }
            return ans;
        
        }
    };

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
    vector<vector<float>> map = {{1,2,3,1,5,9},
                                 {3,1,6,9,2,1},
                                 {7,2,4,12,5,1},
                                 {8,5,7,3,7,4},
                                 {8,7,7,12,7,19}};
    graph g1 = graph(map);
    g1.printMatrix();
    g1.minimizeGraph();
    g1.printMatrix();
    g1.zeroCover();

    printf("%d %d\n", g1.num_zeroes,g1.Zcols[0]);

    return 0;
}