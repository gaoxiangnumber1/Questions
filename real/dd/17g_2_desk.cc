#include <stdio.h>
#include <algorithm>
using namespace std;

struct Customer
{
	int size_;
	int cost_;
};
bool CompareBySize(const Customer &lhs, const Customer &rhs)
{
	return lhs.size_ < rhs.size_;
}
bool CompareByCost(const Customer &lhs, const Customer &rhs)
{
	return lhs.cost_ > rhs.cost_;
}

int main()
{
	const int kCaseMax = 50010, kIntMin = 0x80000000;
	int desk[kCaseMax];
	Customer customer[kCaseMax];
	int desk_number, customer_number;
	while(scanf("%d %d", &desk_number, &customer_number) == 2)
	{
		for(int index = 0; index < desk_number; ++index)
		{
			scanf("%d", &desk[index]);
		}
		for(int index = 0; index < customer_number; ++index)
		{
			scanf("%d %d", &customer[index].size_, &customer[index].cost_);
		}

		sort(desk + 0, desk + desk_number);
		sort(customer + 0, customer + customer_number, CompareBySize);
		int cost = 0;
		for(int desk_index = 0, customer_index = 0; desk_index < desk_number; )
		{
			int desk_size = desk[desk_index];
			int customer_last = customer_index;
			for(; customer_last < customer_number &&
			        customer[customer_last].size_ <= desk_size;
			        ++customer_last);
			sort(customer + customer_index, customer + customer_last, CompareByCost);
			for(; desk_index < desk_number && desk[desk_index] == desk_size; ++desk_index)
			{
				if(customer_index < customer_last)
				{
					cost += customer[customer_index].cost_;
					customer[customer_index].cost_ = kIntMin;
					++customer_index;
				}
				else
				{
					for(; desk_index < desk_number && desk[desk_index] == desk_size;
					        ++desk_index);
					break;
				}
			}
		}
		printf("%d\n", cost);
	}
}
/*
3 5 2 4 2 1 3 3 5 3 7 5 9 1 10
3 1 1 2 3 10 1
3 3 4 5 6 1 1 2 2 3 3
3 5 4 5 6 7 100 5 5 4 0 3 100 6 6

20
0
6
111
*/
////////////
链接：https://www.nowcoder.com/questionTerminal/d2cced737eb54a3aa550f53bb3cc19d0
来源：牛客网

import java.util.*; public class Main {    public static void main(String[] args) {        Scanner sc = new Scanner(System.in);        while (sc.hasNext()) {            int n = sc.nextInt();            int m = sc.nextInt();            int[] disk = new int[n]; //桌子数组            for (int i = 0; i < n; i ++) {                disk[i] = sc.nextInt();            }            Arrays.sort(disk); // 桌子容纳量从小到大排序            PriorityQueue<Customer> queue = new PriorityQueue<>(); // 将客人按消费额降序加入优先级队列            for (int i = 0; i < m; i ++) {                int b = sc.nextInt();                int c = sc.nextInt();                if(b <= disk[n - 1]) queue.add(new Customer(b, c)); // 如果人数小于桌子最大容纳量,加入队列            }            boolean[] visited = new boolean[n]; // 记录桌子是否被占用            long sum = 0; // 记录总盈利            int count = 0; // 记录已使用的桌子数            while ( ! queue.isEmpty()) {                Customer customer = queue.poll();                for (int i = 0; i < n; i ++) { // 为客人分配桌子                    if(customer.peopleCount <= disk[i] && ! visited[i]) {                        sum += customer.moneyCount;                        visited[i] = true;                        count ++;                        break;                    }                }                if(count == n) break;            }            System.out.println(sum);        }    }     static class Customer implements Comparable<Customer> {        private int peopleCount;        private int moneyCount;         public Customer(int peopleCount, int moneyCount) {            this.peopleCount = peopleCount;            this.moneyCount = moneyCount;        }         @Override        public int compareTo(Customer o) {            if(o.moneyCount > this.moneyCount) return 1;            else if(o.moneyCount < this.moneyCount) return - 1;            return 0;        }    }}


链接：https://www.nowcoder.com/questionTerminal/d2cced737eb54a3aa550f53bb3cc19d0
来源：牛客网

#include <iostream> #include <algorithm> #include <vector> using namespace std;    struct node{     intb,c; };    intn,m; longlongans; vector<node> v; vector<node> mp;    intcomp1(node x, node y){     if(x.c == y.c) {         returnx.b < y.b;     }     returnx.c > y.c;  };    intcomp2(node x, node y){     returnx.b < y.b; };    intfind(node x){     intf;     inta=0;     intb=n-1;     while(b>a){         f=(b+a)/2;         if(mp[f].b==x.b){             mp.erase(mp.begin()+f);             n--;             returnx.c;         }         elseif(mp[f].b<x.b)             a=f+1;         else             b=f;     }     if( b==a && mp[a].b>=x.b){         mp.erase(mp.begin()+a);         n--;         returnx.c;     }     return0; };       intmain(){     scanf("%d%d",&n,&m);     for(inti = 0; i < n; i++){         intx;         scanf("%d",&x);         node tmp;         tmp.b = x;         tmp.c = 1;         mp.push_back(tmp);     }     sort(mp.begin(),mp.end(),comp2);     for(inti = 0; i < m; i++){         intx, y;         scanf("%d%d",&x,&y);         node tmp;         tmp.b = x, tmp.c = y;         v.push_back(tmp);     }     sort(v.begin(),v.end(),comp1);     ans=0;     for(inti=0;i<m;i++){         intx;         x=find(v[i]);         ans=ans+x;         if(n<0)             break;     }     printf("%lld\n",ans); }
