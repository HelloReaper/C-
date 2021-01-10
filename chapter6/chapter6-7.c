#include<stdio.h>
#include<stdlib.h>
// 交换
void Exchange(int **pj, int tr, int tc, int n) {
    n++;
    if (1 <= tr && tr <= n / 2 && 1 <= tc && tc <= n) {
        pj[tr][tc] += pj[n - tr][n - tc];
        pj[n - tr][n - tc] = pj[tr][tc] - pj[n - tr][n - tc];
        pj[tr][tc] -= pj[n - tr][n - tc];
    }
}
 
int main(){
 
    int n, i = 0, j = 0, **pj;
    int tr, tc;
 
    printf("输入魔方矩阵的阶层：");
        scanf("%d",&n);
    // 初始化二维数组
    pj = (int**)malloc(sizeof(int **) * (n + 1));
    for (i = 0; i < (n + 1); i++)
        pj[i] = (int*)malloc(sizeof(int *) *  (n + 1));
 
    // n为奇数时
    if (n % 2 == 1) {
        // 1.将1放至第一行中间
        i = 1; j = n / 2 + 1;
        pj[1][n / 2 + 1] = 1;
 
        // 2.沿右上45°，依次放置剩下的数
        for (int k = 2; k <= n * n; k++) {
            // 行数上移，列数右移，即右上45°移动
            tr = i - 1; tc = j + 1;
 
            // 条件一：若超出，则回绕
            if (tr < 1) tr = n;
            if (tc > n) tc = 1;
            // 条件二：若有数据，则放在上一个数字之下
            if (0 < pj[tr][tc] && pj[tr][tc] <= n * n) {
                tr = i + 1; tc = j;
                if (tr < 0) tr = n;
            }
            pj[tr][tc] = k;
            i = tr; j = tc;
        }
 
    }
    // n为4的倍数时
    else if (n % 4 == 0) {
        i = 1; j = 1;
 
        // 1.先将数据从上到下，从左到右填入
        for (int k = 1; k <= n * n; k++) {
            pj[i][j++] = k;
            if (j > n) { j = 1; i++; }
        }
 
        // 2.将方阵的所有4*4子方阵中的两对角线上的数
        // 关于大方阵中心作中心对称交换
 
        i = 1; j = 1;
        for (size_t r = 0; r < n / 4 + 1; r++) {
            for (size_t c = 0; c < n / 4 + !(r % 2); c++) {
 
                tr = 2 * r + i;
                tc = 4 * c + r % 2 * 2 + j;
 
                Exchange(pj, tr, tc, n);
                Exchange(pj, tr - 1, tc, n);
                Exchange(pj, tr, tc - 1, n);
                Exchange(pj, tr - 1, tc - 1, n);
            }
        }
 
    }
 
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            printf("%d\t", pj[i][j]);
        printf("\n");
    }
}