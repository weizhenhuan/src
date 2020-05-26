#include<cstdio>
#include<iostream>
#include<map>
#include<queue>
using namespace std;
map<int, int> vis;
map<int, int> step;
queue<int> q;
int state;
int r, c;
int mat[3][3];
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };
void input() {
	int temp = 0;
	int m;
	for (int i = 0; i < 9; i++) {
		cin >> m;
		temp = temp * 10 + m;
	}
	state = temp;
}
int can_move(int m, int d) {
	for (int i = 2; i >= 0; i--) {
		for (int j = 2; j >= 0; j--) {
			mat[i][j] = m % 10;
			m /= 10;
			if (mat[i][j] == 0) {
				r = i;   c = j;
			}
		}
	}
	if ((c == 0 && d == 3) || (c == 2 && d == 1) || (r == 0 && d == 0) || (r == 2 && d == 2))
		return 0;
	else return 1;
}
int move_to(int m, int i) {
	int temp = 0;
	int dr = r + dir[i][0];
	int dc = c + dir[i][1];	
	mat[r][c] = mat[dr][dc];
	mat[dr][dc] = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			temp = temp * 10 + mat[i][j];
		}
	}
	return temp;
}
int bfs(int state) {
	q.push(state);
	vis[state] = 1;
	step[state] = 0;
	while (q.size()) {
		int m = q.front();
		q.pop();
		if (m == 123456780)	return step[m];
		for (int i = 0; i < 4; i++) {
			if (can_move(m,i)) {
				int p = move_to(m, i);
				if (!vis[p]) {
					vis[p] = 1;
					step[p] = step[m] + 1;
					q.push(p);
				}
			}
		}
	}
	return -1;
}
int main() {
	input();
	int ans = bfs(state);
	cout << ans << endl;
	return 0;
}