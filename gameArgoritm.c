#include <stdio.h>

int main() {
	
	// dX, dY : 북, 동, 남, 서 
	int n, m, x, y, direction, turn = 0, count = 0, dX[4] = {0, 1, 0, -1}, dY[4] = {1, 0, -1, 0};
	
	// n 세로, m 가로 
	scanf("%d %d", &n, &m);
	
	if( 3 > n || m > 150 )
		return 1;
		
	scanf("%d %d %d", &x, &y, &direction);
	
	int map[n][m], visit[n][m];
	
	// 값 반환 받아 맵 만들기 
	for(int i = 0; i < n; i++) {
		for(int j = 0 ; j < m; j++) {
			int result;
			scanf("%d", &result);
			map[n][j] = result;
			
		}
	}
	
	// 방문 시작 
	while(1) {
		// 왼쪽으로 방향 한번 회전하기 
		if( direction-- == 0 )
			direction = 3;
		
		//이동 후의 x, y 좌표	
		int nX, nY;
		nX = x + dX[direction];
		nY = y + dY[direction];
		
		// 육지이면서 방문 하지 않은 곳이면 방문하기 
		if( visit[nX][nY] == 0 && map[nX][nY] == 0 ) {
			// 방문 완료 
			visit[x][y] = 1;
			x = nX;
			y = nY;
			count++;
			turn = 0; 
			
		} else {
			// 4방향 모두 갈수 없는 곳이라면 뒤로 돌아가기 
			if( ++turn == 4) {
				// 이동 전의 x, y 좌표 
				nX = x + dX[direction];
				nY = y + dY[direction];
				
				// 방문하지 않은 곳이라면 뒤로 돌아가고 그렇지 않으면 else 문을 수행하여 종료 
				if( visit[nX][nY] == 0 ) {
					x = nX;
					y = nY;
				} else{
					break;
				}
				
				// 4방향 모두 돌았으니 다시 0으로 초기화 
				turn = 0;
			}
			
		}
		
	} 
	
	// 결과 출력	
	printf("%d", count);

	return 0;
}
