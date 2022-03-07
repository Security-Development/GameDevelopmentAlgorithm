#include <stdio.h>

int main() {
	
	// dX, dY : ��, ��, ��, �� 
	int n, m, x, y, direction, turn = 0, count = 0, dX[4] = {0, 1, 0, -1}, dY[4] = {1, 0, -1, 0};
	
	// n ����, m ���� 
	scanf("%d %d", &n, &m);
	
	if( 3 > n || m > 150 )
		return 1;
		
	scanf("%d %d %d", &x, &y, &direction);
	
	int map[n][m], visit[n][m];
	
	// �� ��ȯ �޾� �� ����� 
	for(int i = 0; i < n; i++) {
		for(int j = 0 ; j < m; j++) {
			int result;
			scanf("%d", &result);
			map[n][j] = result;
			
		}
	}
	
	// �湮 ���� 
	while(1) {
		// �������� ���� �ѹ� ȸ���ϱ� 
		if( direction-- == 0 )
			direction = 3;
		
		//�̵� ���� x, y ��ǥ	
		int nX, nY;
		nX = x + dX[direction];
		nY = y + dY[direction];
		
		// �����̸鼭 �湮 ���� ���� ���̸� �湮�ϱ� 
		if( visit[nX][nY] == 0 && map[nX][nY] == 0 ) {
			// �湮 �Ϸ� 
			visit[x][y] = 1;
			x = nX;
			y = nY;
			count++;
			turn = 0; 
			
		} else {
			// 4���� ��� ���� ���� ���̶�� �ڷ� ���ư��� 
			if( ++turn == 4) {
				// �̵� ���� x, y ��ǥ 
				nX = x + dX[direction];
				nY = y + dY[direction];
				
				// �湮���� ���� ���̶�� �ڷ� ���ư��� �׷��� ������ else ���� �����Ͽ� ���� 
				if( visit[nX][nY] == 0 ) {
					x = nX;
					y = nY;
				} else{
					break;
				}
				
				// 4���� ��� �������� �ٽ� 0���� �ʱ�ȭ 
				turn = 0;
			}
			
		}
		
	} 
	
	// ��� ���	
	printf("%d", count);

	return 0;
}
