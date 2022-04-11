/*归并排序之无哨兵版本*/
#include<iostream>
using namespace std;
#include<vector>
#include<bits/stdc++.h>
void Merge(vector<int>&Array,int front,int mid,int end)
{

    vector<int>LeftSubArray(Array.begin()+front,Array.begin()+mid+1);
    vector<int>RightSubArray(Array.begin()+mid+1,Array.begin()+end+1);
    int idxLeft = 0, idxRight=0;

    for (int i = front; i <= end; i++)
    {
        if(idxLeft==LeftSubArray.size())
        {
            Array[i] = RightSubArray[idxRight];
            idxRight++;
        }
        else if(idxRight == RightSubArray.size())
        {
            Array[i] = LeftSubArray[idxLeft];
            idxLeft++;
        }
        else
        {
            if(LeftSubArray[idxLeft]<=RightSubArray[idxRight])
            {
                Array[i] = LeftSubArray[idxLeft];
                idxLeft++;
            }
            else
            {
                Array[i] = RightSubArray[idxRight];
                idxRight++;
            }
        }
    }
}
void MergeSort(vector<int>&Array,int front,int end)
{
    if(front<end)
    {
        int mid = front + (end-front)/2;
        MergeSort(Array,front,mid);
        MergeSort(Array,mid+1,end);
        Merge(Array,front,mid,end);
    }


}


int main()
{

    vector<int>A{5,4,3,2,1};
    MergeSort(A,0,A.size()-1);
    for(auto i :A)
    {
        cout<<i<<endl;
    }


}
