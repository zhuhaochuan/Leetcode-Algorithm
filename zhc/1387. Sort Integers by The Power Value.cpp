
struct node
{
    int index, weight;
    node(int x,int y):index(x),weight(y){}
};
 
struct cmp
{
    bool operator()(node* a,node* b)
    {
        if(a->weight == b->weight)  return a->index < b->index;
        else return a->weight < b->weight;
    }
};

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        unordered_map<int,int> map;
        //大根堆 解决从小到大的第k个
        priority_queue<node*,vector<node*>,cmp> big;
        if(lo==hi&&lo==1) return 1;
        for(int cur=lo;cur<=hi;++cur) {
            if(!map.count(cur)){
                int count = 0;
                int temp = cur;
                while(temp!=1) {
                    if(temp&1) {
                        temp = 3*temp + 1;
                        if(map.count(temp)){
                            count += map[temp];
                            count++;
                            break;
                        }else {
                            count++;
                        }
                    }else {
                        temp /= 2;
                        if(map.count(temp)) {
                            count += map[temp];
                            count++;
                            break;
                        }else {
                            count++;
                        }
                    }
                }
                map[cur] = count;
            }
            int count = map[cur];
            node* no = new node(cur,count);
            if(big.size()<k) big.push(no);
            else {
                node* t = big.top();
                if(no->weight<t->weight||(no->weight==t->weight&&no->index<t->index)){
                    big.pop();
                    big.push(no);
                }
            }
        }
        return big.top()->index;


    }
};



