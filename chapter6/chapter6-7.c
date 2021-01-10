#include<stdio.h>
#include<stdlib.h>
// ����
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
 
    printf("����ħ������Ľײ㣺");
        scanf("%d",&n);
    // ��ʼ����ά����
    pj = (int**)malloc(sizeof(int **) * (n + 1));
    for (i = 0; i < (n + 1); i++)
        pj[i] = (int*)malloc(sizeof(int *) *  (n + 1));
 
    // nΪ����ʱ
    if (n % 2 == 1) {
        // 1.��1������һ���м�
        i = 1; j = n / 2 + 1;
        pj[1][n / 2 + 1] = 1;
 
        // 2.������45�㣬���η���ʣ�µ���
        for (int k = 2; k <= n * n; k++) {
            // �������ƣ��������ƣ�������45���ƶ�
            tr = i - 1; tc = j + 1;
 
            // ����һ���������������
            if (tr < 1) tr = n;
            if (tc > n) tc = 1;
            // ���������������ݣ��������һ������֮��
            if (0 < pj[tr][tc] && pj[tr][tc] <= n * n) {
                tr = i + 1; tc = j;
                if (tr < 0) tr = n;
            }
            pj[tr][tc] = k;
            i = tr; j = tc;
        }
 
    }
    // nΪ4�ı���ʱ
    else if (n % 4 == 0) {
        i = 1; j = 1;
 
        // 1.�Ƚ����ݴ��ϵ��£�����������
        for (int k = 1; k <= n * n; k++) {
            pj[i][j++] = k;
            if (j > n) { j = 1; i++; }
        }
 
        // 2.�����������4*4�ӷ����е����Խ����ϵ���
        // ���ڴ������������ĶԳƽ���
 
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