struct Cordinate_Compression{
        set<int>vals;
        map<int, int>val_to_cord, cord_to_val;
        void init(set<int>s){
                vals = s;
                int idx = 1;
                for(auto i : vals){
                        cord_to_val[idx] = i;
                        val_to_cord[i] = idx++;
                }
        }
        int incr(int x){
                return val_to_cord[x];
        }
        int decr(int idx){
                return cord_to_val[idx];
        }
};
