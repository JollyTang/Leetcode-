#include<stdio.h>
#include<stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* returned;
    *returnSize = 2;
    returned = (int*)malloc(2*sizeof(int));
    for(int i = 0;i < numsSize;i++){
        for(int j = i+1;j<numsSize;j++){
            if(*(nums + i) + *(nums + j) == target){
                *returned = i;
                *(returned + 1) = j;
                return returned;
            }
        }
    }
    return returned;
}

// int main(){
//     int a[] = {2,7,11,15};
//     int* nums = a;
//     int* returned = twoSum(nums,4,9);
//     for(int i = 0;i<2;i++){
//         printf("%d ",*(returned + i));
//     }

// }
