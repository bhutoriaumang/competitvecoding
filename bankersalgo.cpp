#include <iostream>
using namespace std;

bool check(int x[],int y[], int z[], int n){//Checking if the need is less than the available resources or not
    for(int i=0;i<n;i++){
        if((x[i]-z[i])>y[i])
            return false;
    }
    return true;
}

int main(){
    cout<<"Enter the number of processes and the number of number of resources\t:\t";
    int n,m;
    cin>>n>>m;//Taking the number of processes and the number of resources
    int cur[n][m],max[n][m],avl[m],f[n];
    int total = 0;
    cout<<endl;
    cout<<"Enter the currently allocated resources for each process :\n";
    for(int i=0;i<n;i++){//Taking the currently allocated resources for each process as input
        f[i] = 0;
        cout << "Resources allocated for process " << (i+1) << " is\t:\t";
        for(int j=0;j<m;j++)
            cin>>cur[i][j];
    }
    cout<<endl;
    cout<<"Enter the maximum required resources for each process :\n";
    for(int i=0;i<n;i++){//Taking the maximum resources as input
        cout << "Maximum resources required for process " << (i+1) << " is\t:\t";
        for(int j=0;j<m;j++)
            cin>>max[i][j];
    }
    cout<<endl;
    cout<<"Enter the available resources\t:\t";
    for(int i=0;i<m;i++){//Taking the available resources as input
        cin>>avl[i];
    }
    cout<<"    Process No  |   Allocated Resources   |    Max Resources\n";
    cout<<"    ----------  |   -------------------   |    -------------\n";
    for(int i=0;i<n;i++){
        cout<<"\t"<<(i+1)<<"\t|\t  ";
        for(int j=0;j<m;j++)
            cout<<cur[i][j]<<" ";
        cout<<"\t  |\t  ";
        for(int j=0;j<m;j++)
            cout<<max[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n";
    while(total<n){
        for(int i=0;i<n;i++){
            if(f[i])//Checking if the process is completed or not
                continue;
            if(check(max[i],avl,cur[i],m)){//Checking if we can allocate resources to the current process or not
                cout<< "Process "<<(i+1)<<" is finished\n";
                cout<<"Available resources :\t";
                f[i] = 1;
                total++;
                for(int j=0;j<m;j++)
                    avl[j]+=cur[i][j];
                for(int i=0;i<m;i++){
                    cout<<avl[i]<<" ";
                }
                cout<<endl<<endl;
            }
        }
    }
}