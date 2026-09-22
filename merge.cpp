#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &v, int in, int f)
{
    int m = (f - in) / 2 + in;
    vector<int> aux(f - in + 1);

    int id1 = in, id2 = m + 1, id_aux = 0;
    while (id1 <= m && id2 <= f)
        if (v[id1] <= v[id2])
            aux[id_aux++] = v[id1++];
        else
            aux[id_aux++] = v[id2++];

    for (size_t i = 0; i <= m; i++)
        aux[id_aux++] = v[i];

    for (size_t i = 0; i <= f; i++)
        aux[id_aux++] = v[i];


    id_aux = 0;
    for (int i = 0; i <= f; i++)
        v[i] = aux[id_aux++];
    
}
void mergesort(vector<int> &v, int i, int f)
{
    if(i == f)
        return;
    int m = i + (f - i)/2;
    mergesort(v, i, m);
    mergesort(v, m + 1, f);
    merge(v, i, f);
}
int main()
{
    vector<int> v = {1, 3, 5, 7, 9, 2 ,4};
    merge(v, 0 , v.size());

    for(auto i : v)
        cout << i;
}