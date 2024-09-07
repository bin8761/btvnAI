#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void tomau( int a[MAX][MAX], int n , int colors[MAX] ) {
	bool avacolor[MAX];				//mang theo doi cac mau da duoc su dung 
	
	for(int i = 0 ; i < n ; i++){	//khoi tao cac dinh chua to mau 	
		avacolor[i] = -1 ;
	}
	
	colors[0] = 0 ;					//gan mau dau tien la 0 
	
	for(int u = 1 ; u < n ; u++){
		
		for(int i = 0 ; i < n ; i++){	//dat mau cua cac dinh ke thanh khong kha dung
			avacolor[i] = false ;
		}
		
		for(int v = 0 ; v < n ; v++){
			if ( a[u][v] == 1 ){
				if ( colors[v] != -1 ){
					avacolor[colors[v]] = true ;
				}
			}
		}
		
		int color = 0 ;					//tim mau chua duoc su dung 
		while (color < n) {
			if ( !avacolor[color] ){
				break ;
			}
			color++ ;
		}
		
		colors[u] = color ;
	}
}

int main(){
	int a[MAX][MAX] = {0} ;
	int n = 4 ;
	
	a[0][1] = 1; a[1][0] = 1;
    a[0][2] = 1; a[2][0] = 1;
    a[1][3] = 1; a[3][1] = 1;
    a[2][3] = 1; a[3][2] = 1;
    
    int colors[MAX] ;
    
    tomau( a , n , colors );
    
    printf("Mau cua cac dinh:\n");
    for (int i = 0; i < n; i++) {
        printf("Dinh %d: Mau %d\n", i, colors[i]);
    }
    
    return 0;
    
}

