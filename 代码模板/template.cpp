//基础算法：



1.快排：
int partition(int q[], int n, int start, int end)
{
    int small = start;
    int x = q[start];
    for (int i = start + 1; i <= end; i ++)
        if (q[i] < x)
        {
            small ++;
            if (i != small)
                swap(q[small], q[i]);
        }
    swap(q[small], q[start]);
    return small;
}

void q_sort(int l, int r, int q[])
{
    if (l >= r) return ;

    int i = l - 1, j = r + 1;
    int x = q[(l + r) >> 1];

    while (i < j)
    {
        do i ++; while(q[i] < x);
        do j --; while(q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }

    q_sort(l, j, q);
    q_sort(j + 1, r, q);
}

2.归并排序
const int N  = 100010;
void merge_sort(int q[], int l, int r)
{
    if (l >= r) return ;

    int mid = (l + r) >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    int tmp[N];
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j]) tmp[ k ++ ] = q[ i ++ ];
        else tmp[ k ++ ] = q[ j ++ ];
    }

    while (i <= mid) tmp[ k ++ ] = q[ i ++ ];
    while (j <= r) tmp[ k ++ ] = q[ j ++ ];

    for (i = l, j = 0; i < r; i ++, j ++) q[i] = tmp[j];
    
    return 0;
}

3.二分
bool check(int x){
    return true or false;
}

int binary_search(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}

4. 字符串分割：
vector<string> split(string str, string pattern)
{
    string::size_type pos;
    vector<string> result;
    str += pattern;//扩展字符串以方便操作
    int size = str.size();
    for (int i = 0; i < size; i++)
    {
        pos = str.find(pattern, i);
        if (pos < size)
        {
            std::string s = str.substr(i, pos - i);
            result.push_back(s);
            i = pos + pattern.size() - 1;
        }
    }
    return result;
}

