#include<iostream>
using namespace std;

int mat[10][6];

void arrangeArrival(int num, int mat[][6])
{
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (mat[j][1] > mat[j + 1][1]) {
                for (int k = 0; k < 5; k++) {
                    swap(mat[j][k], mat[j + 1][k]);
                }
            }
        }
    }
}

void findWaitingTime(int mat[][6], int num)
{  
    int full_time[5];
    full_time[0] = mat[0][1];
    for (int i = 1; i < num ; i++)
    {    
        // mat[i][3] = mat[i-1][2] + mat[i-1][3] - mat[i][1];    
        full_time[i] = full_time[i-1] + mat[i-1][2];
        mat[i][3] = full_time[i] - mat[i][1];
        
        if (mat[i][3] < 0){
            mat[i][3] = 0;
        }

    }

}
void findTurnAroundTime(int mat[][6], int num)
{
    for (int i = 0; i < num ; i++){
            mat[i][4] = mat[i][2] + mat[i][3];
    }
    
}
void finalAnswer(int mat[][6], int num)
{
 
    findWaitingTime(mat, num);
    findTurnAroundTime(mat, num);
 
    cout << "Processes " << " Burst Time " << " Arrival Time "
         << " Waiting Time " << " Turn-Around Time "
         << "\n";
    for (int i = 0 ; i < num ; i++)
    {
        cout << " " << i+1 << "\t\t" << mat[i][2]<< "\t\t"
             <<mat[i][1] << "\t\t" << mat[i][3] << "\t\t "
             <<mat[i][4]  <<  "\t\t " << endl;
    }
 
    
}


int main(){
    int num;

    cout << "Enter number of Process: ";
    cin >> num;
  
    
    for (int i = 0; i < num; i++) {
        cout << "--------P" << i + 1 <<"--------"<< "\n";
        mat[i][0] = i+1;
    
        cout << i+1 <<" Arrival Time: ";
        cin >> mat[i][1];
        cout << i+1 << " Burst Time: ";
        cin >> mat[i][2];
    }

    for (int i = 0; i<num; i++){
        cout<<"P"<< mat[i][0]<<" ";
        cout<< mat[i][1]<<" ";
        cout<< mat[i][2]<< "\n";
    }
    arrangeArrival(num, mat);

    cout<<"Sorted with arrival time:"<<"\n";
    for (int i = 0; i<num; i++){
        cout<<"P"<< mat[i][0]<<" ";
        cout<< mat[i][1]<<" ";
        cout<< mat[i][2]<< "\n";
    }
    finalAnswer(mat, num);
    
    cout <<"avg turn around time:" ;
    int tot = 0;
    for (int i=0;i<num;i++) {
        tot = tot + mat[i][4];
    }
     cout<<(float)tot/num<<endl;
     
    cout <<"avg Waiting time:" ;
    int totw = 0;
    for (int i=0;i<num;i++) {
        totw = totw + mat[i][3];
    }
    
    //consider float
    cout<<(float)totw/num<<endl;
    return 0;
}


/*output:

Enter number of Process: 5
--------P1--------
1 Arrival Time: 2
1 Burst Time: 6
--------P2--------
2 Arrival Time: 5
2 Burst Time: 2
--------P3--------
3 Arrival Time: 1
3 Burst Time: 8
--------P4--------
4 Arrival Time: 20
4 Burst Time: 3
--------P5--------
5 Arrival Time: 4
5 Burst Time: 4
P1 2 6
P2 5 2
P3 1 8
P4 20 3
P5 4 4
Sorted with arrival time:
P3 1 8
P1 2 6
P5 4 4
P2 5 2
P4 20 3
Processes  Burst Time  Arrival Time  Waiting Time  Turn-Around Time 
 1              8               1               0                8               
 2              6               2               7                13              
 3              4               4               11               15              
 4              2               5               14               16              
 5              3               20              1                4               
avg turn around time:11.2
avg Waiting time:6.6*/
