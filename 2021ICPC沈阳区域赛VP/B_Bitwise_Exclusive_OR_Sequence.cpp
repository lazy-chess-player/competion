#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// 定义一个并查集结构，支持按位异或关系
struct UnionFind
{
    int n;                    // 节点数量
    vector<int> parent;       // 父节点
    vector<ll> xor_to_parent; // 当前节点与父节点的异或值

    // 构造函数，初始化并查集
    UnionFind(int size) : n(size), parent(size + 1), xor_to_parent(size + 1, 0)
    {
        for (int i = 0; i <= n; ++i)
        {
            parent[i] = i; // 初始每个节点的父节点是自己
        }
    }

    // 查找根节点，并同时计算当前节点到根节点的异或值
    int find_set(int x)
    {
        if (parent[x] != x)
        {
            int original_parent = parent[x];
            parent[x] = find_set(parent[x]);                    // 路径压缩
            xor_to_parent[x] ^= xor_to_parent[original_parent]; // 更新异或值
        }
        return parent[x];
    }

    // 合并两个节点，并设定 a_u XOR a_v = w
    // 返回是否合并成功，若发现矛盾则返回false
    bool union_set(int x, int y, ll w)
    {
        int fx = find_set(x);
        int fy = find_set(y);
        if (fx == fy)
        {
            // 如果x和y已经在同一个集合中，需要检查异或关系是否一致
            if ((xor_to_parent[x] ^ xor_to_parent[y]) != w)
            {
                return false; // 矛盾，无法合并
            }
            else
            {
                return true; // 已经满足关系，无需合并
            }
        }
        else
        {
            // 将fx的父节点设为fy，并更新异或值
            parent[fx] = fy;
            xor_to_parent[fx] = xor_to_parent[x] ^ xor_to_parent[y] ^ w;
            return true;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    UnionFind uf(n);
    bool inconsistent = false; // 标记是否存在矛盾

    // 处理所有约束条件
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        if (!uf.union_set(u, v, w))
        {
            inconsistent = true; // 检测到矛盾
            break;
        }
    }

    if (inconsistent)
    {
        cout << "-1";
        return 0;
    }

    // 创建一个数组来统计每个根节点的变量数量
    // 以及每个根节点在各位上为1的数量
    // 因为n和m较大，这里使用全局数组以避免栈溢出
    // count_bits[root][bit] 表示根为root的集合中，第bit位为1的数量
    // 最大bit位是30，因为w < 2^30
    const int MAX_ROOTS = n + 1;
    const int MAX_BITS = 30;
    vector<vector<int>> count_bits(n + 1, vector<int>(MAX_BITS, 0));
    vector<int> group_size(n + 1, 0); // 记录每个根节点所在集合的大小

    // 遍历所有变量，找出其根节点，并统计各位上的1的数量
    for (int x = 1; x <= n; ++x)
    {
        int root = uf.find_set(x);    // 找到变量x的根节点
        ll c_i = uf.xor_to_parent[x]; // a_x XOR a_root
        for (int b = 0; b < MAX_BITS; ++b)
        {
            if ((c_i >> b) & 1)
            {
                count_bits[root][b] += 1; // 该位为1的数量加一
            }
        }
        group_size[root] += 1; // 增加该集合的大小
    }

    ll total_sum = 0; // 最终的最小总和

    // 遍历所有可能的根节点
    for (int root = 1; root <= n; ++root)
    {
        if (group_size[root] == 0)
        {
            continue; // 如果该根节点没有任何变量，跳过
        }
        // 对于每个集合，计算在各个位上最小的贡献
        for (int b = 0; b < MAX_BITS; ++b)
        {
            int cnt = count_bits[root][b]; // 该位为1的数量
            int sz = group_size[root];     // 该集合的大小
            // 选择 a_root 的第b位为0还是1，以最小化该位的总和
            // 如果选择0，贡献为 cnt * 2^b
            // 如果选择1，贡献为 (sz - cnt) * 2^b
            // 取较小者
            ll option0 = (ll)cnt * (1LL << b);
            ll option1 = (ll)(sz - cnt) * (1LL << b);
            total_sum += min(option0, option1);
        }
    }

    cout << total_sum;
}
