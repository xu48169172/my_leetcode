/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };
int* boundaryOfBinaryTree(struct TreeNode* root, int* returnSize)
{
    
}

int main()
{
    struct TreeNode* root = NULL;
    int returnSize = 0;
    int *out = boundaryOfBinaryTree(root, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", out[i]);
    }
    printf("\n");
}

#if 0
[开心IT面试题] realloc用法

    C++面试题中另一个大板块——内存管理，主要有malloc(free)、new(delete)、calloc、realloc等。今天来说说realloc的用法。



1、头文件

#include <stdlib.h> 有些编译器需要#include <malloc.h>，在TC2.0中可以使用alloc.h头文件



2、realloc()函数原型

void *realloc(void *mem_address, unsigned int newsize)

指针名 = (数据类型*) realloc (要改变内存大小的指针名， 新的大小)

该函数将mem_address所指向的内存块大小扩大到newsize，原有内存中的内容将保持不变。如果重新分配成功则返回指向新分配内存的指针，否则返回空指针NULL。



3、realloc()使用举例

 

    char *first, *second;//声明两个指向char的指针
    first = (char *)malloc(sizeof(char));//先使用malloc分配内存
    if(first == NULL)
    {
        //分配失败
    }else
    {
        //分配成功
    }

    //代码操作

    second = (char *)realloc(first, 2*sizeof(char));//使用realloc重新分配扩大内存
    if(second == NULL)
    {
        //分配失败
    }else
    {
        //分配成功
        first = second;
    }
 



4、使用要点

a)新的大小一定要大于原来的大小 ，不然的话会导致数据丢失！

b)返回值可能与原指针不同，如果是不同的话，那么realloc完成后，原指针指向的旧内存已被自动free释放掉了；

c)如果返回值NULL，则分配不成功，原指针指向的内存还没有被自动free释放掉，要求程序员free；

d)如果没有足够可用的内存用来完成重新分配（扩大原来的内存块或者分配新的内存块），则返回NULL，而原来的内存块保持不变，不会释放也不会移动。

此时，原来指向的内存还没有free掉，而现在又会找不到原地址，所以在重新分配时，先将新分配的地址赋值给一个新变量second，然后判断secon是否为空，若为空表示分配失败，若不为空给表示分配成功，此时再把second赋值给first。

注意避免first =(char*)realloc(first,2*sizeof(char));这种写法，这种操作会造成realloc分配失败后，first原先所指向的内存地址丢失。

d)传递给realloc的指针必须是先前通过malloc()、calloc()、或realloc()分配的；

b)当传给realloc的指针是空指针(0)时，realloc作用相当于malloc；

c)当传给realloc的新大小是0时，realloc作用相当于free，返回NULL；



5、工作机制

realloc是从堆上分配内存的，当扩大一块内存空间时，realloc会直接从堆上现存的数据后面的那些字节中获得附加的字节，先判断当前的指针是否有足够的连续空间，如果有，扩大mem_address指向的地址，并且返回原地址。

如果空间不够，；但如果数据后面的字节不够的话，先按照新大小分配空间，将原有数据拷贝到新分配的内存块上，而老的内存块会自动free释放掉，同时返回新分配的内存区域首地址。
#endif