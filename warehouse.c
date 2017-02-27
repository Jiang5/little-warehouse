#include "slots.h"
#include <stdio.h>
#include <stdlib.h>

int a[101]={0};//bin times
struct Top{
    int bin;
    int times;
};
struct Top top0={101,0};
struct Top top1={101,0};
struct Top top2={101,0};

void priority(int x){
    a[x]++;

    if(top0.bin==101){
        top0.times=a[x];
        top0.bin=x;
    }
    else if(top1.bin==101){
        if(x!=top0.bin){
            top1.times=a[x];
            top1.bin=x;
        }
    }
    else if(top2.bin==101){
        if(x!=top0.bin&&x!=top1.bin){
            top2.times=a[x];
            top2.bin=x;
        }
    }
    else if(a[x]>top0.times){
        if(x!=top0.bin){
          top1.times=top0.times;
          top1.bin=top0.bin;
          top0.times=a[x];
          top0.bin=x;
}
        else return;
    } 
    else if(a[x]>top1.times){
        if(x!=top1.bin){
          top2.times=top1.times;
          top2.bin=top1.bin;
          top1.times=a[x];
          top1.bin=x;
    } 
        else return;
    }
    else if(a[x]>top2.times){ 
        if(x!=top2.bin){
        top2.times=a[x];
        top2.bin=x;
    }
        else return;
    }
    top0.times=a[top0.bin];
    top1.times=a[top1.bin];
    top2.times=a[top2.bin];
}

int checkTop3(int x){
    if(x==top0.bin) return 0;    
    else if(x==top1.bin) return 1; 
    else if(x==top2.bin) return 2;
    else return 3;
}

int main(int argc, char ** argv) {
	int bin;
	initSlots();
	while(1==scanf("%d",&bin)) {
	   priority(bin);
		if (-1==findSlot(bin)) {
		    int slot=checkTop3(bin);
			getBin(bin,slot);
		}
		getWidget(bin);
	}
	printEarnings();
	return 0;
}
