
#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
class seq {
	public:
		seq() {}
		seq(int *initVal) {
			step = 0;
			for(int i=0;i<8;i++)	val[i] = initVal[i];
		}
		void moveright() {
			step++;
            int copy[8];
            for(int i=0;i<8;i++)copy[i] = val[i];
			
            val[0] = copy[7];
            val[1] = copy[0];
            val[2] = copy[1];
            val[3] = copy[2];
            val[4] = copy[3];
            val[5] = copy[4];
            val[6] = copy[5];
            val[7] = copy[6];
		}
		void radjSwap(int i) {
			step++;
			if(i == 7 ) {
                //swap(val[0],val[7]);
            }
			else swap(val[i], val[(i + 1) ]);
		}
        void ladjSwap(int i) {
            step++;
            if(i == 0 ) {
                //swap(val[0],val[7]);
            }
			else swap(val[i], val[(i - 1) ]);
        }
		void sort(int i,int j) {
			step++;
			::sort(val+i,val+j);
        }
		int getStep() { return step; }
		bool operator < (const seq &a) const {
			for(int i=0;i<8;i++)	if(val[i] != a.val[i])	return val[i] < a.val[i];
			return false;
		}
		bool operator == (const seq &a) const{
			for(int i=0;i<8;i++)	if(val[i] != a.val[i])	return false;
			return true;
		}
	private:
		int step, val[8];
};
void updateState(seq &nextseq, queue<seq> &q, set<seq> &visseq, const seq& seqB, int &ans) {
	if(nextseq == seqB) {
		ans = nextseq.getStep();
		return;
	}
	if(visseq.count(nextseq) == 1)	return;
	q.push(nextseq);
	visseq.insert(nextseq);
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		seq seqA, seqB;
		for(int i=0;i<2;i++) {
			int initVal[8];
			for(int j = 0;j<8;j++)
				cin >> initVal[j];
			(i == 0 ? seqA : seqB) = seq(initVal);
		}

		int ans = -1;
		if(seqA == seqB)
			ans = 0;
		else {
			queue<seq> q;
			q.push(seqA);
			
			set<seq> visseq;
			visseq.insert(seqA);
            int o=1;
			while(!q.empty() && ans == -1) {
				seq now = q.front();	q.pop();
				
				seq nextseq = now;
				nextseq.moveright();
				updateState(nextseq, q, visseq, seqB, ans);

				for(int i=0;i < 8 && ans == -1;i++) {
					nextseq = now;
					nextseq.radjSwap(i);
					updateState(nextseq, q, visseq, seqB, ans);
				}
                for(int i=0;i < 8 && ans == -1;i++) {
					nextseq = now;
					nextseq.ladjSwap(i);
					updateState(nextseq, q, visseq, seqB, ans);
				}
				//nextseq = now;
				//nextseq.sort();
				//updateState(nextseq, q, visseq, seqB, ans);
                
				//for(int i=0;i < 6 && ans == -1&&o !=0 ;i++) {
                    //for(int j=i+1;j < 7 &&o !=0;i++){
                        if(o == 1) {
                            nextseq = now;
                            nextseq.sort(0,8);
                            updateState(nextseq, q, visseq, seqB, ans);
                            o=0;
                        }
                        
                    
                    
				
			}
		}
		cout << ans << endl;
	}
	return 0;
}


